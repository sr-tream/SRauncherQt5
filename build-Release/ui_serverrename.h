/********************************************************************************
** Form generated from reading UI file 'serverrename.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERRENAME_H
#define UI_SERVERRENAME_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerRename
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *ServerRename)
    {
        if (ServerRename->objectName().isEmpty())
            ServerRename->setObjectName(QStringLiteral("ServerRename"));
        ServerRename->resize(560, 43);
        layoutWidget = new QWidget(ServerRename);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 541, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(ServerRename);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(ServerRename);
    } // setupUi

    void retranslateUi(QDialog *ServerRename)
    {
        ServerRename->setWindowTitle(QApplication::translate("ServerRename", "Rename", Q_NULLPTR));
        label->setText(QApplication::translate("ServerRename", "Server name:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ServerRename", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerRename: public Ui_ServerRename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERRENAME_H
