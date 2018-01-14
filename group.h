#ifndef GROUP_H
#define GROUP_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class CGroup;
}

class CGroup : public QDialog
{
    Q_OBJECT

public:
    explicit CGroup(QComboBox *cbox, QWidget *parent = 0);
    ~CGroup();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CGroup *ui;
    QComboBox *cbox;
};

#endif // GROUP_H
