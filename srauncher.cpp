#include "srauncher.h"
#include "ui_srauncher.h"

SRauncher::SRauncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SRauncher)
{
    ui->setupUi(this);
    this->setFixedSize(450, 400);
    rx.setPattern(R"((.*):(\d{1,5}))");
    ui->btnRemove->setEnabled(false);
    ui->btnRename->setEnabled(false);
    regset = new QSettings("HKEY_CURRENT_USER\\SOFTWARE\\SAMP",
                           QSettings::NativeFormat);
    ui->edtNick->setText(regset->value("PlayerName").toString());
    servers = new CSampServers(ui->edtNick->text(), ui->srvList);
    game = new CRunGame();
    inject = new SelectLibs(this);
    sets = new CSettings(servers, this);
    rename = new ServerRename(this);
    udp = nullptr;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(updateServerInfo()));
    timer->start(regset->value("time_update").toInt());
}

SRauncher::~SRauncher()
{
    QList<QListWidgetItem *> lst = ui->srvList->selectedItems();
    g_SrvList[lst.front()->text()].gta_sa = ui->edtGta->text();
    g_SrvList[lst.front()->text()].samp = ui->edtSamp->text();
    g_SrvList[lst.front()->text()].nick = ui->edtNick->text();
    g_SrvList[lst.front()->text()].comment = ui->edtComment->toPlainText();
    delete servers;
    delete ui;
}

void SRauncher::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SRauncher::on_btnAddSrv_clicked()
{
    if (rx.indexIn(ui->edtIp->text()) != -1){
        stServer srv;
        srv.name = rx.cap(1) + ":" + rx.cap(2);
        srv.gta_sa = "gta_sa.exe";
        srv.samp = "samp.dll";
        srv.nick = regset->value("PlayerName").toString();
        srv.ip = rx.cap(1);
        srv.port = rx.cap(2).toShort();
        g_SrvList[srv.name] = srv;
        QListWidgetItem *item = new QListWidgetItem(srv.name, ui->srvList);
        ui->srvList->addItem(item);

        if (udp != nullptr)
            delete udp;
        udp = new CUdpConnect(item, regset->value("client_port").toUInt(), this);
        udp->requestPing();
        udp->requestInfo();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Bad IP:Port");
        msgBox.exec();
    }
}

void SRauncher::on_srvList_itemClicked(QListWidgetItem *item)
{
    ui->btnRemove->setEnabled(true);
    ui->btnRename->setEnabled(true);
    stServer srv = g_SrvList[item->text()];
    ui->edtIp->setText(srv.ip + ":" + QString::number(srv.port));
}

void SRauncher::updateServerInfo()
{
    if (udp != nullptr){
        udp->requestPing(false);
        udp->requestInfo(false);
        udp->requestRule(false);
    }
    timer->setInterval(regset->value("time_update").toInt());
}

void SRauncher::on_btnConnect_clicked()
{
    game->reset();
    game->setGta(ui->edtGta->text());
    game->addLib(ui->edtSamp->text());

    if (regset->value("asi_loader").toBool()){
        QDir dir;
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if (fileInfo.suffix().toLower() == "asi")
                game->addLib(fileInfo.fileName());

        }
    }
    game->setWindowMode(regset->value("win_mode").toBool());
    game->setWindowSize(sets->getSize());

    QList<QString> addLibs = inject->enabledLibs();
    foreach (auto lib, addLibs) {
        game->addLib(lib);
    }

    if (rx.indexIn(ui->edtIp->text()) != -1){
        game->Connect(ui->edtNick->text(),
                      rx.cap(1),
                      rx.cap(2).toUInt());
    } else {
        QMessageBox msgBox;
        msgBox.setText("Bad IP:Port");
        msgBox.exec();
    }
}

void SRauncher::on_btnRename_clicked()
{
    QList<QListWidgetItem *> lst = ui->srvList->selectedItems();
    rename->setServer(lst.front());
    rename->show();
}

void SRauncher::on_btnRemove_clicked()
{
    QList<QListWidgetItem *> lst = ui->srvList->selectedItems();
    g_SrvList.remove(lst.front()->text());
    ui->srvList->removeItemWidget(lst.front());
    delete lst.front();
}

void SRauncher::on_srvList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->btnRemove->setEnabled(true);
    ui->btnRename->setEnabled(true);
    if (previous != nullptr){
        g_SrvList[previous->text()].gta_sa = ui->edtGta->text();
        g_SrvList[previous->text()].samp = ui->edtSamp->text();
        g_SrvList[previous->text()].nick = ui->edtNick->text();
        g_SrvList[previous->text()].comment = ui->edtComment->toPlainText();
    }
    ui->edtGta->setText(g_SrvList[current->text()].gta_sa);
    ui->edtSamp->setText(g_SrvList[current->text()].samp);
    ui->edtNick->setText(g_SrvList[current->text()].nick);
    ui->edtComment->setText(g_SrvList[current->text()].comment);

    if (udp != nullptr)
        delete udp;
    udp = new CUdpConnect(current, regset->value("client_port").toUInt(), this);
    udp->setPing(ui->tsPing);
    udp->setPlayers(ui->tsPlayers);
    udp->setTime(ui->tsTime);
    udp->setWeather(ui->tsWeather);
    udp->setMap(ui->tsMap);
    udp->setMode(ui->tsMode);
    udp->setUrl(ui->tsUrl);
    udp->setLng(ui->tsLng);
    udp->requestPing();
    udp->requestInfo();
    udp->requestRule();

    stServer srv = g_SrvList[current->text()];
    ui->edtIp->setText(srv.ip + ":" + QString::number(srv.port));
}

void SRauncher::on_btnInject_clicked()
{
    inject->show();
}

void SRauncher::on_btnSettings_clicked()
{
    sets->show();
}

void SRauncher::on_tsUrl_linkActivated(const QString &link)
{
    QMessageBox msgBox;
    msgBox.setText("Click");
    msgBox.exec();
    QDesktopServices::openUrl(QUrl("http://" + link));
}
