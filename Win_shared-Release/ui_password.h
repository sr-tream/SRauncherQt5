/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

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

class Ui_Password
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *txtPass;
    QLineEdit *edtPass;
    QPushButton *btnConnect;

    void setupUi(QDialog *Password)
    {
        if (Password->objectName().isEmpty())
            Password->setObjectName(QStringLiteral("Password"));
        Password->resize(400, 50);
        horizontalLayoutWidget = new QWidget(Password);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtPass = new QLabel(horizontalLayoutWidget);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtPass);

        edtPass = new QLineEdit(horizontalLayoutWidget);
        edtPass->setObjectName(QStringLiteral("edtPass"));

        horizontalLayout->addWidget(edtPass);

        btnConnect = new QPushButton(horizontalLayoutWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(btnConnect);


        retranslateUi(Password);
        QObject::connect(edtPass, SIGNAL(returnPressed()), btnConnect, SLOT(click()));

        QMetaObject::connectSlotsByName(Password);
    } // setupUi

    void retranslateUi(QDialog *Password)
    {
        Password->setWindowTitle(QApplication::translate("Password", "Advanced connect", nullptr));
        txtPass->setText(QApplication::translate("Password", "Password:", nullptr));
        btnConnect->setText(QApplication::translate("Password", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Password: public Ui_Password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
