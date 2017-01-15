#ifndef SERVERRENAME_H
#define SERVERRENAME_H

#include <QDialog>
#include <QListWidgetItem>

#include "sampservers.h"

namespace Ui {
class ServerRename;
}

class ServerRename : public QDialog
{
    Q_OBJECT

public:
    explicit ServerRename(QWidget *parent = 0);
    ~ServerRename();

    void setServer(QListWidgetItem *srv, QString group);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ServerRename *ui;
    QListWidgetItem *srv;
    stServer old;
};

#endif // SERVERRENAME_H
