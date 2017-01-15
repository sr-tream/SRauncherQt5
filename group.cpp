#include "group.h"
#include "ui_group.h"

CGroup::CGroup(QComboBox *cbox, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CGroup)
{
    this->cbox = cbox;
    ui->setupUi(this);
    this->setFixedSize(240, 75);
}

CGroup::~CGroup()
{
    delete ui;
}

void CGroup::changeEvent(QEvent *e)
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

void CGroup::on_buttonBox_accepted()
{
    if (cbox != nullptr){
        bool isDefined = false;
        for (int j = 0; j < cbox->count(); ++j)
            if (cbox->itemText(j) == ui->edtName->text()){
                isDefined = true;
                break;
            }
        if (!isDefined)
            cbox->addItem(ui->edtName->text());
    }
    ui->edtName->setText("");
}
