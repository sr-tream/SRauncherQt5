#include "settings.h"
#include "ui_settings.h"

CSettings::CSettings(CSampServers *servers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSettings)
{
    ui->setupUi(this);
    this->setFixedSize(250, 140);
    this->servers = servers;
    regset = new QSettings("HKEY_CURRENT_USER\\SOFTWARE\\SAMP",
                           QSettings::NativeFormat);
    ui->cbAsiLoader->setChecked(regset->value("asi_loader").toBool());
    ui->cbWinMode->setChecked(regset->value("win_mode").toBool());
    ui->comboBox->setEnabled(ui->cbWinMode->isChecked());
    ui->comboBox->setCurrentIndex(regset->value("win_size").toInt());
    if (regset->value("client_port").toInt() < 2014 ||
        regset->value("client_port").toInt() > 49151)
        regset->setValue("client_port", 1337);
    ui->edtPort->setText(regset->value("client_port").toString());
    ui->edtPort->setValidator(new QIntValidator(1024, 49151, ui->edtPort));
    if (regset->value("time_update").toInt() == 0)
        regset->setValue("time_update", 1000);
    ui->dial->setValue(regset->value("time_update").toInt());
    ui->lcdNumber->setPalette(Qt::gray);
    QDesktopWidget *d = QApplication::desktop();
    QRegExp rx(R"((\d*)\*(\d*))");
    for(int i = 0; i < ui->comboBox->count(); ++i){
        if (rx.indexIn(ui->comboBox->itemText(i)) != -1){
            if (rx.cap(1).toShort() >= d->width() ||
                rx.cap(2).toShort() >= d->height()){
                ui->comboBox->removeItem(i);
                --i;
            }
        }
    }
}

CSettings::~CSettings()
{
    delete ui;
}

void CSettings::changeEvent(QEvent *e)
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
void CSettings::closeEvent(QCloseEvent * e)
{
    regset->setValue("client_port", ui->edtPort->text());
    e->accept();
}

void CSettings::on_cbAsiLoader_toggled(bool checked)
{
    regset->setValue("asi_loader", checked);
}

void CSettings::on_cbWinMode_toggled(bool checked)
{
    regset->setValue("win_mode", checked);
    ui->comboBox->setEnabled(checked);
}

void CSettings::on_btnImport_clicked()
{
    servers->Import();
    QMessageBox msgBox;
    msgBox.setText("Servers has imported.");
    msgBox.exec();
}

QString CSettings::getSize()
{
    return ui->comboBox->currentText();
}

void CSettings::on_comboBox_currentIndexChanged(int index)
{
    regset->setValue("win_size", index);
}

void CSettings::on_dial_valueChanged(int value)
{
    regset->setValue("time_update", value);
}
