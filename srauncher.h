#ifndef SRAUNCHER_H
#define SRAUNCHER_H

#include <QMainWindow>
#include <QApplication>
#include <QListWidgetItem>
#include <QSettings>
#include <QMessageBox>
#include <QDir>
#include <QRegExp>
#include <QDesktopServices>
#include <QTextCodec>
#include <QTimer>
#include <QTranslator>

#include "sampservers.h"
#include "serverrename.h"
#include "selectlibs.h"
#include "runngame.h"
#include "udpconnect.h"
#include "settings.h"
#include "group.h"
#include "password.h"

namespace Ui {
class SRauncher;
}

class SRauncher : public QMainWindow
{
    Q_OBJECT

public:
    explicit SRauncher(QWidget *parent = 0);
    ~SRauncher();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

    QTranslator translate;

private slots:
    void updateServerInfo();

    void on_btnAddSrv_clicked();

    void on_srvList_itemClicked(QListWidgetItem *item);

    void on_btnConnect_clicked();

    void on_btnRename_clicked();

    void on_btnRemove_clicked();

    void on_srvList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btnInject_clicked();

    void on_btnSettings_clicked();

    void on_tsUrl_linkActivated(const QString &link);

    void on_cbGroup_currentIndexChanged(const QString &arg1);

    void on_btnGroupRemove_clicked();

    void on_btnGroupAdd_clicked();

    void on_btnDebug_clicked();

    void on_toolButton_clicked();

private:
    Ui::SRauncher *ui;
    CSampServers *servers;
    QSettings *regset;
    CRunGame *game;
    CUdpConnect* udp;
    SelectLibs* inject;
    CSettings *sets;
    ServerRename* rename;
    QTimer *timer;
    CGroup *groupMgr;
    Password *pass;
    QRegExp rx;
};

#endif // SRAUNCHER_H
