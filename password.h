#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <QDir>
#include <QRegExp>
#include "settings.h"
#include "selectlibs.h"
#include "runngame.h"

namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(CRunGame *game,
                      QSettings *regset,
                      SelectLibs* inject,
                      CSettings *sets,
                      QWidget *parent = 0);
    ~Password();

    void setIP(QString ip);
    void setGta(QString gta);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_btnConnect_clicked();

private:
    Ui::Password *ui;
    CRunGame *game;
    QSettings *regset;
    SelectLibs* inject;
    CSettings *sets;
    QString ip;
    QString gta;
    QRegExp rx;
};

#endif // PASSWORD_H
