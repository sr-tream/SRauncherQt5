/********************************************************************************
** Form generated from reading UI file 'srauncher.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRAUNCHER_H
#define UI_SRAUNCHER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRauncher
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *txtNick;
    QLineEdit *edtNick;
    QPushButton *btnSettings;
    QListWidget *srvList;
    QFrame *line;
    QPushButton *btnAddSrv;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *txtGta;
    QLineEdit *edtGta;
    QLabel *txtComment;
    QTextEdit *edtComment;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *txtIp;
    QLineEdit *edtIp;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnConnect;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnDebug;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnInject;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *txtPlayers;
    QLabel *tsPlayers;
    QLabel *txtPing;
    QLabel *tsPing;
    QLabel *txtTime;
    QLabel *tsTime;
    QLabel *txtWeather;
    QLabel *tsWeather;
    QLabel *txtMap;
    QLabel *tsMap;
    QLabel *txtMode;
    QLabel *tsMode;
    QLabel *txtUrl;
    QLabel *tsUrl;
    QLabel *txtLng;
    QLabel *tsLng;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *txtGroup;
    QComboBox *cbGroup;
    QPushButton *btnGroupAdd;
    QPushButton *btnGroupRemove;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnRemove;
    QPushButton *btnRename;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *SRauncher)
    {
        if (SRauncher->objectName().isEmpty())
            SRauncher->setObjectName(QStringLiteral("SRauncher"));
        SRauncher->resize(450, 466);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SRauncher->sizePolicy().hasHeightForWidth());
        SRauncher->setSizePolicy(sizePolicy);
        SRauncher->setMinimumSize(QSize(0, 0));
        SRauncher->setMaximumSize(QSize(10000, 111100));
        SRauncher->setBaseSize(QSize(418, 370));
        SRauncher->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(SRauncher);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(10000, 100000));
        centralWidget->setBaseSize(QSize(418, 349));
        centralWidget->setContextMenuPolicy(Qt::NoContextMenu);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, -1, 431, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtNick = new QLabel(horizontalLayoutWidget);
        txtNick->setObjectName(QStringLiteral("txtNick"));
        txtNick->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(txtNick);

        edtNick = new QLineEdit(horizontalLayoutWidget);
        edtNick->setObjectName(QStringLiteral("edtNick"));

        horizontalLayout->addWidget(edtNick);

        btnSettings = new QPushButton(horizontalLayoutWidget);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(btnSettings);

        srvList = new QListWidget(centralWidget);
        srvList->setObjectName(QStringLiteral("srvList"));
        srvList->setGeometry(QRect(10, 60, 281, 191));
        srvList->setSortingEnabled(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(290, 110, 161, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnAddSrv = new QPushButton(centralWidget);
        btnAddSrv->setObjectName(QStringLiteral("btnAddSrv"));
        btnAddSrv->setGeometry(QRect(300, 63, 141, 23));
        btnAddSrv->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(300, 130, 141, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        txtGta = new QLabel(formLayoutWidget);
        txtGta->setObjectName(QStringLiteral("txtGta"));

        formLayout->setWidget(0, QFormLayout::LabelRole, txtGta);

        edtGta = new QLineEdit(formLayoutWidget);
        edtGta->setObjectName(QStringLiteral("edtGta"));

        formLayout->setWidget(0, QFormLayout::FieldRole, edtGta);

        txtComment = new QLabel(centralWidget);
        txtComment->setObjectName(QStringLiteral("txtComment"));
        txtComment->setGeometry(QRect(240, 250, 201, 16));
        txtComment->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        edtComment = new QTextEdit(centralWidget);
        edtComment->setObjectName(QStringLiteral("edtComment"));
        edtComment->setGeometry(QRect(240, 270, 201, 123));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(300, 30, 141, 29));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        txtIp = new QLabel(horizontalLayoutWidget_2);
        txtIp->setObjectName(QStringLiteral("txtIp"));

        horizontalLayout_2->addWidget(txtIp);

        edtIp = new QLineEdit(horizontalLayoutWidget_2);
        edtIp->setObjectName(QStringLiteral("edtIp"));

        horizontalLayout_2->addWidget(edtIp);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 160, 141, 96));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_4->addWidget(btnConnect);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_4->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnDebug = new QPushButton(layoutWidget);
        btnDebug->setObjectName(QStringLiteral("btnDebug"));
        btnDebug->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_6->addWidget(btnDebug);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnInject = new QPushButton(layoutWidget);
        btnInject->setObjectName(QStringLiteral("btnInject"));
        btnInject->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_3->addWidget(btnInject);


        verticalLayout->addLayout(horizontalLayout_3);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 260, 221, 182));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setVerticalSpacing(4);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        txtPlayers = new QLabel(formLayoutWidget_2);
        txtPlayers->setObjectName(QStringLiteral("txtPlayers"));
        txtPlayers->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtPlayers->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, txtPlayers);

        tsPlayers = new QLabel(formLayoutWidget_2);
        tsPlayers->setObjectName(QStringLiteral("tsPlayers"));
        tsPlayers->setCursor(QCursor(Qt::ArrowCursor));
        tsPlayers->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, tsPlayers);

        txtPing = new QLabel(formLayoutWidget_2);
        txtPing->setObjectName(QStringLiteral("txtPing"));
        txtPing->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, txtPing);

        tsPing = new QLabel(formLayoutWidget_2);
        tsPing->setObjectName(QStringLiteral("tsPing"));
        tsPing->setCursor(QCursor(Qt::ArrowCursor));
        tsPing->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, tsPing);

        txtTime = new QLabel(formLayoutWidget_2);
        txtTime->setObjectName(QStringLiteral("txtTime"));
        txtTime->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, txtTime);

        tsTime = new QLabel(formLayoutWidget_2);
        tsTime->setObjectName(QStringLiteral("tsTime"));
        tsTime->setCursor(QCursor(Qt::ArrowCursor));
        tsTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, tsTime);

        txtWeather = new QLabel(formLayoutWidget_2);
        txtWeather->setObjectName(QStringLiteral("txtWeather"));
        txtWeather->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, txtWeather);

        tsWeather = new QLabel(formLayoutWidget_2);
        tsWeather->setObjectName(QStringLiteral("tsWeather"));
        tsWeather->setCursor(QCursor(Qt::ArrowCursor));
        tsWeather->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, tsWeather);

        txtMap = new QLabel(formLayoutWidget_2);
        txtMap->setObjectName(QStringLiteral("txtMap"));
        txtMap->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, txtMap);

        tsMap = new QLabel(formLayoutWidget_2);
        tsMap->setObjectName(QStringLiteral("tsMap"));
        tsMap->setCursor(QCursor(Qt::ArrowCursor));
        tsMap->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, tsMap);

        txtMode = new QLabel(formLayoutWidget_2);
        txtMode->setObjectName(QStringLiteral("txtMode"));
        txtMode->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, txtMode);

        tsMode = new QLabel(formLayoutWidget_2);
        tsMode->setObjectName(QStringLiteral("tsMode"));
        tsMode->setCursor(QCursor(Qt::ArrowCursor));
        tsMode->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, tsMode);

        txtUrl = new QLabel(formLayoutWidget_2);
        txtUrl->setObjectName(QStringLiteral("txtUrl"));
        txtUrl->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtUrl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, txtUrl);

        tsUrl = new QLabel(formLayoutWidget_2);
        tsUrl->setObjectName(QStringLiteral("tsUrl"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        tsUrl->setPalette(palette);
        QFont font;
        font.setItalic(false);
        font.setUnderline(false);
        tsUrl->setFont(font);
        tsUrl->setCursor(QCursor(Qt::ArrowCursor));
        tsUrl->setMouseTracking(false);
        tsUrl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tsUrl->setOpenExternalLinks(true);
        tsUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, tsUrl);

        txtLng = new QLabel(formLayoutWidget_2);
        txtLng->setObjectName(QStringLiteral("txtLng"));
        txtLng->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(7, QFormLayout::LabelRole, txtLng);

        tsLng = new QLabel(formLayoutWidget_2);
        tsLng->setObjectName(QStringLiteral("tsLng"));
        tsLng->setCursor(QCursor(Qt::ArrowCursor));
        tsLng->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, tsLng);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 30, 281, 29));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        txtGroup = new QLabel(horizontalLayoutWidget_3);
        txtGroup->setObjectName(QStringLiteral("txtGroup"));
        txtGroup->setMaximumSize(QSize(45, 16777215));
        txtGroup->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(txtGroup);

        cbGroup = new QComboBox(horizontalLayoutWidget_3);
        cbGroup->setObjectName(QStringLiteral("cbGroup"));
        cbGroup->setMinimumSize(QSize(120, 0));
        cbGroup->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(cbGroup);

        btnGroupAdd = new QPushButton(horizontalLayoutWidget_3);
        btnGroupAdd->setObjectName(QStringLiteral("btnGroupAdd"));
        btnGroupAdd->setMaximumSize(QSize(30, 16777215));
        btnGroupAdd->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(btnGroupAdd);

        btnGroupRemove = new QPushButton(horizontalLayoutWidget_3);
        btnGroupRemove->setObjectName(QStringLiteral("btnGroupRemove"));
        btnGroupRemove->setMaximumSize(QSize(50, 16777215));
        btnGroupRemove->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(btnGroupRemove);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(300, 90, 141, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnRemove = new QPushButton(horizontalLayoutWidget_4);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setMaximumSize(QSize(50, 16777215));
        btnRemove->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(btnRemove);

        btnRename = new QPushButton(horizontalLayoutWidget_4);
        btnRename->setObjectName(QStringLiteral("btnRename"));
        btnRename->setMaximumSize(QSize(90, 16777215));
        btnRename->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(btnRename);

        SRauncher->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SRauncher);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy1);
        SRauncher->setMenuBar(menuBar);

        retranslateUi(SRauncher);
        QObject::connect(srvList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), btnConnect, SLOT(click()));

        QMetaObject::connectSlotsByName(SRauncher);
    } // setupUi

    void retranslateUi(QMainWindow *SRauncher)
    {
        SRauncher->setWindowTitle(QApplication::translate("SRauncher", "SRauncher", Q_NULLPTR));
        txtNick->setText(QApplication::translate("SRauncher", "Nick:", Q_NULLPTR));
        btnSettings->setText(QApplication::translate("SRauncher", "Settings", Q_NULLPTR));
        btnAddSrv->setText(QApplication::translate("SRauncher", "Add/move server", Q_NULLPTR));
        txtGta->setText(QApplication::translate("SRauncher", "gta_sa:", Q_NULLPTR));
        edtGta->setText(QApplication::translate("SRauncher", "gta_sa.exe", Q_NULLPTR));
        txtComment->setText(QApplication::translate("SRauncher", "Comment:", Q_NULLPTR));
        txtIp->setText(QApplication::translate("SRauncher", "IP:", Q_NULLPTR));
        edtIp->setText(QApplication::translate("SRauncher", "127.0.0.1:7777", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("SRauncher", "Connect", Q_NULLPTR));
        toolButton->setText(QApplication::translate("SRauncher", "...", Q_NULLPTR));
        btnDebug->setText(QApplication::translate("SRauncher", "Debug mode", Q_NULLPTR));
        btnInject->setText(QApplication::translate("SRauncher", "Additional inject", Q_NULLPTR));
        txtPlayers->setText(QApplication::translate("SRauncher", "Players: ", Q_NULLPTR));
        tsPlayers->setText(QString());
        txtPing->setText(QApplication::translate("SRauncher", "Ping: ", Q_NULLPTR));
        tsPing->setText(QString());
        txtTime->setText(QApplication::translate("SRauncher", "Time: ", Q_NULLPTR));
        tsTime->setText(QString());
        txtWeather->setText(QApplication::translate("SRauncher", "Weather: ", Q_NULLPTR));
        tsWeather->setText(QString());
        txtMap->setText(QApplication::translate("SRauncher", "Map: ", Q_NULLPTR));
        tsMap->setText(QString());
        txtMode->setText(QApplication::translate("SRauncher", "Mode: ", Q_NULLPTR));
        tsMode->setText(QString());
        txtUrl->setText(QApplication::translate("SRauncher", "URL: ", Q_NULLPTR));
        tsUrl->setText(QString());
        txtLng->setText(QApplication::translate("SRauncher", "Language:", Q_NULLPTR));
        tsLng->setText(QString());
        txtGroup->setText(QApplication::translate("SRauncher", "Group:", Q_NULLPTR));
        btnGroupAdd->setText(QApplication::translate("SRauncher", "Add", Q_NULLPTR));
        btnGroupRemove->setText(QApplication::translate("SRauncher", "remove", Q_NULLPTR));
        btnRemove->setText(QApplication::translate("SRauncher", "remove", Q_NULLPTR));
        btnRename->setText(QApplication::translate("SRauncher", "rename", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SRauncher: public Ui_SRauncher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRAUNCHER_H
