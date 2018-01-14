/********************************************************************************
** Form generated from reading UI file 'group.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_H
#define UI_GROUP_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGroup
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *txtName;
    QLineEdit *edtName;

    void setupUi(QDialog *CGroup)
    {
        if (CGroup->objectName().isEmpty())
            CGroup->setObjectName(QStringLiteral("CGroup"));
        CGroup->resize(239, 74);
        buttonBox = new QDialogButtonBox(CGroup);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 40, 151, 32));
        buttonBox->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(CGroup);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 221, 27));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtName = new QLabel(horizontalLayoutWidget);
        txtName->setObjectName(QStringLiteral("txtName"));
        txtName->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtName);

        edtName = new QLineEdit(horizontalLayoutWidget);
        edtName->setObjectName(QStringLiteral("edtName"));

        horizontalLayout->addWidget(edtName);


        retranslateUi(CGroup);
        QObject::connect(buttonBox, SIGNAL(accepted()), CGroup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CGroup, SLOT(reject()));

        QMetaObject::connectSlotsByName(CGroup);
    } // setupUi

    void retranslateUi(QDialog *CGroup)
    {
        CGroup->setWindowTitle(QApplication::translate("CGroup", "Add group", Q_NULLPTR));
        txtName->setText(QApplication::translate("CGroup", "Group name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CGroup: public Ui_CGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_H
