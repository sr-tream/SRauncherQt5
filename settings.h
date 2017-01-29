#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QRegExp>

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

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::CSettings *ui;
    QSettings *regset;
    CSampServers* servers;

    uint win_size = 0;
    uint win_pos = 0;

    void UpdateWinSettings();
};

#endif // SETTINGS_H
