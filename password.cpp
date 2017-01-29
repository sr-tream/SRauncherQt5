#include "password.h"
#include "ui_password.h"

Password::Password(CRunGame *game,
                   QSettings *regset,
                   SelectLibs* inject,
                   CSettings *sets,
                   QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    this->game = game;
    this->regset = regset;
    this->inject = inject;
    this->sets = sets;
    ui->setupUi(this);
    this->setFixedSize(400, 50);
    rx.setPattern(R"((.*):(\d{1,5}))");
}

Password::~Password()
{
    delete ui;
}

void Password::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Password::setIP(QString ip)
{
    this->ip = ip;
}

void Password::setGta(QString gta)
{
    this->gta = gta;
}

void Password::on_btnConnect_clicked()
{    game->reset();
     game->setGta(gta);
     game->addLib("samp.dll");
     game->setPassword(ui->edtPass->text());
     ui->edtPass->setText("");

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
     game->setWindowTop(regset->value("win_pos").toBool());

     QList<QString> addLibs = inject->enabledLibs();
     foreach (auto lib, addLibs) {
         game->addLib(lib);
     }

     if (rx.indexIn(ip) != -1){
         game->Connect(ip, rx.cap(1), rx.cap(2).toUInt());
     } else {
         QMessageBox msgBox;
         msgBox.setText("Bad IP:Port");
         msgBox.exec();
     }
    this->close();
}
