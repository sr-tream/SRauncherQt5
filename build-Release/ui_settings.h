/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
        CSettings->setWindowTitle(QApplication::translate("CSettings", "Settings", Q_NULLPTR));
        cbAsiLoader->setText(QApplication::translate("CSettings", "Using custom asi loader", Q_NULLPTR));
        cbWinMode->setText(QApplication::translate("CSettings", "Run game in window mode", Q_NULLPTR));
        btnImport->setText(QApplication::translate("CSettings", "Import servers", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CSettings", "640*360", Q_NULLPTR)
         << QApplication::translate("CSettings", "640*480", Q_NULLPTR)
         << QApplication::translate("CSettings", "800*480", Q_NULLPTR)
         << QApplication::translate("CSettings", "800*600", Q_NULLPTR)
         << QApplication::translate("CSettings", "848*480", Q_NULLPTR)
         << QApplication::translate("CSettings", "960*540", Q_NULLPTR)
         << QApplication::translate("CSettings", "1024*600", Q_NULLPTR)
         << QApplication::translate("CSettings", "1024*768", Q_NULLPTR)
         << QApplication::translate("CSettings", "1152*864", Q_NULLPTR)
         << QApplication::translate("CSettings", "1200*600", Q_NULLPTR)
         << QApplication::translate("CSettings", "1280*720", Q_NULLPTR)
         << QApplication::translate("CSettings", "1280*768", Q_NULLPTR)
         << QApplication::translate("CSettings", "1280*1024", Q_NULLPTR)
         << QApplication::translate("CSettings", "1366*768", Q_NULLPTR)
         << QApplication::translate("CSettings", "1440*900", Q_NULLPTR)
         << QApplication::translate("CSettings", "1400*1050", Q_NULLPTR)
         << QApplication::translate("CSettings", "1536*960", Q_NULLPTR)
         << QApplication::translate("CSettings", "1536*1024", Q_NULLPTR)
         << QApplication::translate("CSettings", "1600*900", Q_NULLPTR)
         << QApplication::translate("CSettings", "1600*1024", Q_NULLPTR)
         << QApplication::translate("CSettings", "1600*1200", Q_NULLPTR)
         << QApplication::translate("CSettings", "1680*1050", Q_NULLPTR)
         << QApplication::translate("CSettings", "1920*1080", Q_NULLPTR)
         << QApplication::translate("CSettings", "1920*1200", Q_NULLPTR)
         << QApplication::translate("CSettings", "2048*1080", Q_NULLPTR)
        );
        txtPort->setText(QApplication::translate("CSettings", "Local port:", Q_NULLPTR));
        edtPort->setText(QApplication::translate("CSettings", "1337", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CSettings", "Renewal time", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("CSettings", "Center", Q_NULLPTR)
         << QApplication::translate("CSettings", "Top", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class CSettings: public Ui_CSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
