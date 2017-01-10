#ifndef SRAUNCHER_H
#define SRAUNCHER_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QSettings>
#include <QMessageBox>
#include <QDir>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QTextCodec>

#include "sampservers.h"
#include "serverrename.h"
#include "runngame.h"

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

private slots:
    void AddToSrvList();
    void UpdateSrvInfo();

    void on_btnAddSrv_clicked();

    void on_srvList_itemClicked(QListWidgetItem *item);

    void on_btnConnect_clicked();

    void on_btnRename_clicked();

    void on_btnRemove_clicked();

    void on_srvList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btnImport_clicked();

private:
    Ui::SRauncher *ui;
    QNetworkAccessManager *manager;
    CSampServers *servers;
    QSettings *regset;
    CRunGame *game;
    bool srvNeedUpd = false;
};

#endif // SRAUNCHER_H
