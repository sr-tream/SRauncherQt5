#include "srauncher.h"
#include "ui_srauncher.h"

SRauncher::SRauncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SRauncher)
{
    ui->setupUi(this);
    this->setFixedSize(450, 380);
    ui->edtPort->setValidator(new QIntValidator(0, 65535, this));
    ui->btnRemove->setEnabled(false);
    ui->btnRename->setEnabled(false);
    manager = new QNetworkAccessManager(this);
    regset = new QSettings("HKEY_CURRENT_USER\\SOFTWARE\\SAMP",
                           QSettings::NativeFormat);
    ui->edtNick->setText(regset->value("PlayerName").toString());
    ui->cbLoader->setChecked(regset->value("asi_loader").toBool());
    servers = new CSampServers(ui->edtNick->text(), ui->srvList);
    game = new CRunGame();
    inject = new SelectLibs(this);
}

SRauncher::~SRauncher()
{
    regset->setValue("asi_loader", ui->cbLoader->isChecked());
    QList<QListWidgetItem *> lst = ui->srvList->selectedItems();
    g_SrvList[lst.front()->text()].gta_sa = ui->edtGta->text();
    g_SrvList[lst.front()->text()].samp = ui->edtSamp->text();
    g_SrvList[lst.front()->text()].nick = ui->edtNick->text();
    g_SrvList[lst.front()->text()].comment = ui->edtComment->toPlainText();
    delete servers;
    delete game;
    delete regset;
    delete manager;
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

void SRauncher::AddToSrvList()
{
    QNetworkReply *reply=
      qobject_cast<QNetworkReply *>(sender());

    if (reply->error() == QNetworkReply::NoError)
    {
      // Получаем содержимое ответа
      QByteArray content= reply->readAll();

      // Реализуем преобразование кодировки
      // (зависит от кодировки сайта)
      QTextCodec *codec = QTextCodec::codecForName("cp1251");

      // Выводим результат
      stServer srv;
      srv.name = codec->toUnicode(content.data());
      bool _next = true;
      foreach (auto it, g_SrvList)
          if (it.name == srv.name)
              _next = false;
      if (_next){

          srv.ip = ui->edtIp->text();
          srv.port = ui->edtPort->text().toShort();
          srv.gta_sa = "gta_sa.exe";
          srv.samp = "samp.dll";
          srv.nick = regset->value("PlayerName").toString();
          ui->srvList->addItem(codec->toUnicode(content.data()));
          g_SrvList[srv.name] = srv;
      }
      ui->edtIp->setText("");
      ui->edtPort->setText("");
      ui->edtIp->setEnabled(true);
      ui->edtPort->setEnabled(true);
      ui->btnAddSrv->setEnabled(true);
    }

    // разрешаем объекту-ответа "удалится"
    reply->deleteLater();
}

void SRauncher::UpdateSrvInfo()
{
    if (!srvNeedUpd)
        return;
    srvNeedUpd = false;

    QNetworkReply *reply=
      qobject_cast<QNetworkReply *>(sender());

    if (reply->error() == QNetworkReply::NoError)
    {
      QByteArray content= reply->readAll();
      QTextCodec *codec = QTextCodec::codecForName("cp1251");

      ui->srvInfo->setText(codec->toUnicode(content.data()));
    }

    reply->deleteLater();
}

void SRauncher::on_btnAddSrv_clicked()
{
    if (ui->edtPort->text().isEmpty())
        ui->edtPort->setText("7777");
    ui->edtIp->setEnabled(false);
    ui->edtPort->setEnabled(false);
    ui->btnAddSrv->setEnabled(false);
    // берем адрес введенный в текстовое поле
    QUrl url("http://samp.prime-hack.net/?ip=" + ui->edtIp->text() +
             "&port=" + ui->edtPort->text() + "&info=name");

    // создаем объект для запроса
    QNetworkRequest request(url);

    // Выполняем запрос, получаем указатель на объект
    // ответственный за ответ
    QNetworkReply* reply=  manager->get(request);

    // Подписываемся на сигнал о готовности загрузки
    connect( reply, SIGNAL(finished()),
             this, SLOT(AddToSrvList()) );
}

void SRauncher::on_srvList_itemClicked(QListWidgetItem *item)
{
    ui->btnRemove->setEnabled(true);
    ui->btnRename->setEnabled(true);

    stServer srv = g_SrvList[item->text()];
    QUrl url("http://samp.prime-hack.net/?ip=" + srv.ip +
             "&port=" + QString::number(srv.port) + "&info=bingui");

    ui->edtIp->setText(srv.ip);
    ui->edtPort->setText(QString::number(srv.port));

    QNetworkRequest request(url);
    QNetworkReply* reply=  manager->get(request);
    connect( reply, SIGNAL(finished()),
             this, SLOT(UpdateSrvInfo()) );
    ui->srvInfo->setText("Please wait, information is updating...");
    srvNeedUpd = true;
}

void SRauncher::on_btnConnect_clicked()
{
    game->setGta(ui->edtGta->text());
    game->addLib(ui->edtSamp->text());

    if (ui->cbLoader->isChecked()){
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

    QList<QString> addLibs = inject->enabledLibs();
    foreach (auto lib, addLibs) {
        game->addLib(lib);
    }

    game->Connect(ui->edtNick->text(),
                  ui->edtIp->text(),
                  ui->edtPort->text().toUInt());
}

void SRauncher::on_btnRename_clicked()
{
    QList<QListWidgetItem *> lst = ui->srvList->selectedItems();
    ServerRename* dlg = new ServerRename(lst.front(), this);
    dlg->show();
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
}

void SRauncher::on_btnImport_clicked()
{
    servers->Import();
    QMessageBox msgBox;
    msgBox.setText("Servers has imported.");
    msgBox.exec();
}

void SRauncher::on_btnInject_clicked()
{
    inject->show();
}
