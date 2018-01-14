/********************************************************************************
** Form generated from reading UI file 'selectlibs.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLIBS_H
#define UI_SELECTLIBS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectLibs
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *txtDisabled;
    QLabel *txtOnline;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *lstDisable;
    QListWidget *lstEnable;

    void setupUi(QDialog *SelectLibs)
    {
        if (SelectLibs->objectName().isEmpty())
            SelectLibs->setObjectName(QStringLiteral("SelectLibs"));
        SelectLibs->resize(400, 260);
        horizontalLayoutWidget = new QWidget(SelectLibs);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtDisabled = new QLabel(horizontalLayoutWidget);
        txtDisabled->setObjectName(QStringLiteral("txtDisabled"));
        txtDisabled->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtDisabled);

        txtOnline = new QLabel(horizontalLayoutWidget);
        txtOnline->setObjectName(QStringLiteral("txtOnline"));
        txtOnline->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtOnline);

        horizontalLayoutWidget_2 = new QWidget(SelectLibs);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 29, 381, 221));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lstDisable = new QListWidget(horizontalLayoutWidget_2);
        lstDisable->setObjectName(QStringLiteral("lstDisable"));
        lstDisable->setSortingEnabled(true);

        horizontalLayout_2->addWidget(lstDisable);

        lstEnable = new QListWidget(horizontalLayoutWidget_2);
        lstEnable->setObjectName(QStringLiteral("lstEnable"));
        lstEnable->setSortingEnabled(true);

        horizontalLayout_2->addWidget(lstEnable);


        retranslateUi(SelectLibs);

        QMetaObject::connectSlotsByName(SelectLibs);
    } // setupUi

    void retranslateUi(QDialog *SelectLibs)
    {
        SelectLibs->setWindowTitle(QApplication::translate("SelectLibs", "Additional inject", Q_NULLPTR));
        txtDisabled->setText(QApplication::translate("SelectLibs", "Disabled:", Q_NULLPTR));
        txtOnline->setText(QApplication::translate("SelectLibs", "Enabled:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectLibs: public Ui_SelectLibs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLIBS_H
