#include "serverrename.h"
#include "ui_serverrename.h"

ServerRename::ServerRename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerRename)
{
    ui->setupUi(this);
    this->setFixedSize(560, 43);
}

ServerRename::~ServerRename()
{
    delete ui;
}

void ServerRename::setServer(QListWidgetItem *srv)
{
    this->srv = srv;
    old = g_SrvList[srv->text()];
    ui->lineEdit->setText(srv->text());
}

void ServerRename::changeEvent(QEvent *e)
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

void ServerRename::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == old.name){
        this->close();
        return;
    }
    foreach (auto it, g_SrvList)
        if (it.name == ui->lineEdit->text())
            ui->lineEdit->setText(ui->lineEdit->text() + "#double");
    srv->setText(ui->lineEdit->text());
    g_SrvList[srv->text()] = old;
    g_SrvList.remove(old.name);
    g_SrvList[srv->text()].name = srv->text();
    this->close();
}
