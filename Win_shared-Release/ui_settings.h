/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSettings
{
public:
    QCheckBox *cbAsiLoader;
    QCheckBox *cbWinMode;
    QPushButton *btnImport;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *txtPort;
    QLineEdit *edtPort;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QComboBox *comboBox_2;

    void setupUi(QDialog *CSettings)
    {
        if (CSettings->objectName().isEmpty())
            CSettings->setObjectName(QStringLiteral("CSettings"));
        CSettings->resize(313, 142);
        cbAsiLoader = new QCheckBox(CSettings);
        cbAsiLoader->setObjectName(QStringLiteral("cbAsiLoader"));
        cbAsiLoader->setGeometry(QRect(10, 10, 191, 16));
        cbAsiLoader->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cbWinMode = new QCheckBox(CSettings);
        cbWinMode->setObjectName(QStringLiteral("cbWinMode"));
        cbWinMode->setGeometry(QRect(10, 30, 191, 17));
        cbWinMode->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        btnImport = new QPushButton(CSettings);
        btnImport->setObjectName(QStringLiteral("btnImport"));
        btnImport->setGeometry(QRect(10, 110, 191, 23));
        btnImport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        comboBox = new QComboBox(CSettings);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(80, 50, 121, 21));
        comboBox->setMaximumSize(QSize(16777215, 100));
        horizontalLayoutWidget = new QWidget(CSettings);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 191, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtPort = new QLabel(horizontalLayoutWidget);
        txtPort->setObjectName(QStringLiteral("txtPort"));
        txtPort->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtPort);

        edtPort = new QLineEdit(horizontalLayoutWidget);
        edtPort->setObjectName(QStringLiteral("edtPort"));

        horizontalLayout->addWidget(edtPort);

        groupBox = new QGroupBox(CSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(210, 10, 91, 121));
        groupBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 71, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dial = new QDial(layoutWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMinimum(250);
        dial->setMaximum(3000);
        dial->setSingleStep(50);
        dial->setPageStep(250);
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchesVisible(true);

        verticalLayout->addWidget(dial);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(4);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setProperty("intValue", QVariant(250));

        verticalLayout->addWidget(lcdNumber);

        comboBox_2 = new QComboBox(CSettings);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEnabled(false);
        comboBox_2->setGeometry(QRect(10, 50, 71, 21));

        retranslateUi(CSettings);
        QObject::connect(dial, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(cbWinMode, SIGNAL(toggled(bool)), comboBox_2, SLOT(setEnabled(bool)));
        QObject::connect(cbWinMode, SIGNAL(toggled(bool)), comboBox, SLOT(setEnabled(bool)));

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CSettings);
    } // setupUi

    void retranslateUi(QDialog *CSettings)
    {
        CSettings->setWindowTitle(QApplication::translate("CSettings", "Settings", nullptr));
        cbAsiLoader->setText(QApplication::translate("CSettings", "Using custom asi loader", nullptr));
        cbWinMode->setText(QApplication::translate("CSettings", "Run game in window mode", nullptr));
        btnImport->setText(QApplication::translate("CSettings", "Import servers", nullptr));
        comboBox->setItemText(0, QApplication::translate("CSettings", "640*360", nullptr));
        comboBox->setItemText(1, QApplication::translate("CSettings", "640*480", nullptr));
        comboBox->setItemText(2, QApplication::translate("CSettings", "800*480", nullptr));
        comboBox->setItemText(3, QApplication::translate("CSettings", "800*600", nullptr));
        comboBox->setItemText(4, QApplication::translate("CSettings", "848*480", nullptr));
        comboBox->setItemText(5, QApplication::translate("CSettings", "960*540", nullptr));
        comboBox->setItemText(6, QApplication::translate("CSettings", "1024*600", nullptr));
        comboBox->setItemText(7, QApplication::translate("CSettings", "1024*768", nullptr));
        comboBox->setItemText(8, QApplication::translate("CSettings", "1152*864", nullptr));
        comboBox->setItemText(9, QApplication::translate("CSettings", "1200*600", nullptr));
        comboBox->setItemText(10, QApplication::translate("CSettings", "1280*720", nullptr));
        comboBox->setItemText(11, QApplication::translate("CSettings", "1280*768", nullptr));
        comboBox->setItemText(12, QApplication::translate("CSettings", "1280*1024", nullptr));
        comboBox->setItemText(13, QApplication::translate("CSettings", "1366*768", nullptr));
        comboBox->setItemText(14, QApplication::translate("CSettings", "1440*900", nullptr));
        comboBox->setItemText(15, QApplication::translate("CSettings", "1400*1050", nullptr));
        comboBox->setItemText(16, QApplication::translate("CSettings", "1536*960", nullptr));
        comboBox->setItemText(17, QApplication::translate("CSettings", "1536*1024", nullptr));
        comboBox->setItemText(18, QApplication::translate("CSettings", "1600*900", nullptr));
        comboBox->setItemText(19, QApplication::translate("CSettings", "1600*1024", nullptr));
        comboBox->setItemText(20, QApplication::translate("CSettings", "1600*1200", nullptr));
        comboBox->setItemText(21, QApplication::translate("CSettings", "1680*1050", nullptr));
        comboBox->setItemText(22, QApplication::translate("CSettings", "1920*1080", nullptr));
        comboBox->setItemText(23, QApplication::translate("CSettings", "1920*1200", nullptr));
        comboBox->setItemText(24, QApplication::translate("CSettings", "2048*1080", nullptr));

        txtPort->setText(QApplication::translate("CSettings", "Local port:", nullptr));
        edtPort->setText(QApplication::translate("CSettings", "1337", nullptr));
        groupBox->setTitle(QApplication::translate("CSettings", "Renewal time", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("CSettings", "Center", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("CSettings", "Top", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CSettings: public Ui_CSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
