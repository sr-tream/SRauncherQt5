#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QCloseEvent>

#include "sampservers.h"

namespace Ui {
class CSettings;
}

class CSettings : public QDialog
{
    Q_OBJECT

public:
    explicit CSettings(CSampServers* servers, QWidget *parent = 0);
    ~CSettings();

    QString getSize();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

private slots:
    void on_cbAsiLoader_toggled(bool checked);

    void on_cbWinMode_toggled(bool checked);

    void on_btnImport_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_dial_valueChanged(int value);

private:
    Ui::CSettings *ui;
    QSettings *regset;
    CSampServers* servers;
};

#endif // SETTINGS_H
