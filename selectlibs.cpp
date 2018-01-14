#include "selectlibs.h"
#include "ui_selectlibs.h"

SelectLibs::SelectLibs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectLibs)
{
    ui->setupUi(this);
    this->setFixedSize(400, 260);
    QDir dir;
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Name);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if ((fileInfo.suffix().toLower() == "asi" ||
             fileInfo.suffix().toLower() == "dll") &&
             fileInfo.fileName().toLower() != "ogg.dll" &&
             fileInfo.fileName().toLower() != "eax.dll" &&
             fileInfo.fileName().toLower() != "samp.dll" &&
             fileInfo.fileName().toLower() != "vorbis.dll" &&
             fileInfo.fileName().toLower() != "vorbisFile.dll" &&
             fileInfo.fileName().toLower() != "vorbisHooked.dll")
            ui->lstDisable->addItem(fileInfo.fileName());

    }
}

SelectLibs::~SelectLibs()
{
    delete ui;
}

QList<QString> SelectLibs::enabledLibs()
{
    QList<QString> libs;
    for (int i = 0; i < ui->lstEnable->count() ; ++i){
        QModelIndex *model_index = new QModelIndex(ui->lstEnable->model()->index(i,0) );
        QString lib = model_index->data(Qt::DisplayRole).toString();
        libs.push_back(lib);
    }
    return libs;
}

void SelectLibs::changeEvent(QEvent *e)
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

void SelectLibs::on_lstDisable_itemDoubleClicked(QListWidgetItem *item)
{
    ui->lstEnable->addItem(item->text());
    ui->lstDisable->removeItemWidget(item);
    delete item;
}

void SelectLibs::on_lstEnable_itemDoubleClicked(QListWidgetItem *item)
{
    ui->lstDisable->addItem(item->text());
    ui->lstEnable->removeItemWidget(item);
    delete item;
}
