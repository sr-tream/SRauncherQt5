#ifndef SELECTLIBS_H
#define SELECTLIBS_H

#include <QDialog>
#include <QDir>
#include <QListWidgetItem>
#include <QList>
#include <Windows.h>

namespace Ui {
class SelectLibs;
}

class SelectLibs : public QDialog
{
    Q_OBJECT

public:
    explicit SelectLibs(QWidget *parent = 0);
    ~SelectLibs();

    QList<QString> enabledLibs();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_lstDisable_itemDoubleClicked(QListWidgetItem *item);

    void on_lstEnable_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::SelectLibs *ui;
};

#endif // SELECTLIBS_H
