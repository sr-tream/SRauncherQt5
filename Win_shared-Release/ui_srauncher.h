/********************************************************************************
** Form generated from reading UI file 'srauncher.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRauncher
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_5;
    QLabel *txtNick;
    QLineEdit *edtNick;
    QPushButton *btnSettings;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *txtGroup;
    QComboBox *cbGroup;
    QPushButton *btnGroupAdd;
    QPushButton *btnGroupRemove;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnInject;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *srvList;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *txtIp;
    QLineEdit *edtIp;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddSrv;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnRemove;
    QPushButton *btnRename;
    QFrame *line;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout;
    QLabel *txtGta;
    QLineEdit *edtGta;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnConnect;
    QToolButton *toolButton;
    QPushButton *btnDebug;
    QHBoxLayout *horizontalLayout_10;
    QGridLayout *gridLayout_2;
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
    QVBoxLayout *verticalLayout_2;
    QLabel *txtComment;
    QTextEdit *edtComment;

    void setupUi(QMainWindow *SRauncher)
    {
        if (SRauncher->objectName().isEmpty())
            SRauncher->setObjectName(QStringLiteral("SRauncher"));
        SRauncher->resize(484, 512);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SRauncher->sizePolicy().hasHeightForWidth());
        SRauncher->setSizePolicy(sizePolicy);
        SRauncher->setMinimumSize(QSize(0, 0));
        SRauncher->setMaximumSize(QSize(10000, 111100));
        SRauncher->setBaseSize(QSize(418, 370));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SRauncher->setWindowIcon(icon);
        SRauncher->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(SRauncher);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(10000, 100000));
        centralWidget->setBaseSize(QSize(418, 349));
        centralWidget->setContextMenuPolicy(Qt::NoContextMenu);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        txtNick = new QLabel(centralWidget);
        txtNick->setObjectName(QStringLiteral("txtNick"));
        txtNick->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(txtNick, 0, 0, 1, 1);

        edtNick = new QLineEdit(centralWidget);
        edtNick->setObjectName(QStringLiteral("edtNick"));

        gridLayout_5->addWidget(edtNick, 0, 1, 1, 1);

        btnSettings = new QPushButton(centralWidget);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(btnSettings, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        txtGroup = new QLabel(centralWidget);
        txtGroup->setObjectName(QStringLiteral("txtGroup"));
        txtGroup->setMaximumSize(QSize(45, 16777215));
        txtGroup->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(txtGroup);

        cbGroup = new QComboBox(centralWidget);
        cbGroup->setObjectName(QStringLiteral("cbGroup"));
        cbGroup->setMinimumSize(QSize(120, 0));
        cbGroup->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(cbGroup);

        btnGroupAdd = new QPushButton(centralWidget);
        btnGroupAdd->setObjectName(QStringLiteral("btnGroupAdd"));
        btnGroupAdd->setMaximumSize(QSize(30, 16777215));
        btnGroupAdd->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(btnGroupAdd);

        btnGroupRemove = new QPushButton(centralWidget);
        btnGroupRemove->setObjectName(QStringLiteral("btnGroupRemove"));
        btnGroupRemove->setMaximumSize(QSize(50, 16777215));
        btnGroupRemove->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(btnGroupRemove);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnInject = new QPushButton(centralWidget);
        btnInject->setObjectName(QStringLiteral("btnInject"));
        btnInject->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_5->addWidget(btnInject);


        horizontalLayout_8->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        srvList = new QListWidget(centralWidget);
        srvList->setObjectName(QStringLiteral("srvList"));
        srvList->setMinimumSize(QSize(0, 250));
        srvList->setSortingEnabled(true);

        horizontalLayout_3->addWidget(srvList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtIp = new QLabel(groupBox);
        txtIp->setObjectName(QStringLiteral("txtIp"));

        horizontalLayout_2->addWidget(txtIp);

        edtIp = new QLineEdit(groupBox);
        edtIp->setObjectName(QStringLiteral("edtIp"));

        horizontalLayout_2->addWidget(edtIp);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btnAddSrv = new QPushButton(groupBox);
        btnAddSrv->setObjectName(QStringLiteral("btnAddSrv"));
        btnAddSrv->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        verticalLayout_4->addWidget(btnAddSrv);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setMaximumSize(QSize(16777215, 16777215));
        btnRemove->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(btnRemove);

        btnRename = new QPushButton(groupBox);
        btnRename->setObjectName(QStringLiteral("btnRename"));
        btnRename->setMaximumSize(QSize(16777215, 16777215));
        btnRename->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_7->addWidget(btnRename);


        verticalLayout_4->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 0));
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        txtGta = new QLabel(groupBox_2);
        txtGta->setObjectName(QStringLiteral("txtGta"));

        formLayout->setWidget(0, QFormLayout::LabelRole, txtGta);

        edtGta = new QLineEdit(groupBox_2);
        edtGta->setObjectName(QStringLiteral("edtGta"));

        formLayout->setWidget(0, QFormLayout::FieldRole, edtGta);


        gridLayout_3->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnConnect = new QPushButton(groupBox_2);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_4->addWidget(btnConnect);

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_4->addWidget(toolButton);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        btnDebug = new QPushButton(groupBox_2);
        btnDebug->setObjectName(QStringLiteral("btnDebug"));
        btnDebug->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_3->addWidget(btnDebug, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(4);
        txtPlayers = new QLabel(centralWidget);
        txtPlayers->setObjectName(QStringLiteral("txtPlayers"));
        txtPlayers->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtPlayers->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtPlayers->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        gridLayout_2->addWidget(txtPlayers, 0, 0, 1, 1);

        tsPlayers = new QLabel(centralWidget);
        tsPlayers->setObjectName(QStringLiteral("tsPlayers"));
        tsPlayers->setMinimumSize(QSize(150, 0));
        tsPlayers->setCursor(QCursor(Qt::ArrowCursor));
        tsPlayers->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsPlayers, 0, 1, 1, 1);

        txtPing = new QLabel(centralWidget);
        txtPing->setObjectName(QStringLiteral("txtPing"));
        txtPing->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtPing->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtPing, 1, 0, 1, 1);

        tsPing = new QLabel(centralWidget);
        tsPing->setObjectName(QStringLiteral("tsPing"));
        tsPing->setCursor(QCursor(Qt::ArrowCursor));
        tsPing->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsPing, 1, 1, 1, 1);

        txtTime = new QLabel(centralWidget);
        txtTime->setObjectName(QStringLiteral("txtTime"));
        txtTime->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtTime, 2, 0, 1, 1);

        tsTime = new QLabel(centralWidget);
        tsTime->setObjectName(QStringLiteral("tsTime"));
        tsTime->setCursor(QCursor(Qt::ArrowCursor));
        tsTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsTime, 2, 1, 1, 1);

        txtWeather = new QLabel(centralWidget);
        txtWeather->setObjectName(QStringLiteral("txtWeather"));
        txtWeather->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtWeather->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtWeather, 3, 0, 1, 1);

        tsWeather = new QLabel(centralWidget);
        tsWeather->setObjectName(QStringLiteral("tsWeather"));
        tsWeather->setCursor(QCursor(Qt::ArrowCursor));
        tsWeather->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsWeather, 3, 1, 1, 1);

        txtMap = new QLabel(centralWidget);
        txtMap->setObjectName(QStringLiteral("txtMap"));
        txtMap->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtMap->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtMap, 4, 0, 1, 1);

        tsMap = new QLabel(centralWidget);
        tsMap->setObjectName(QStringLiteral("tsMap"));
        tsMap->setCursor(QCursor(Qt::ArrowCursor));
        tsMap->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsMap, 4, 1, 1, 1);

        txtMode = new QLabel(centralWidget);
        txtMode->setObjectName(QStringLiteral("txtMode"));
        txtMode->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtMode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtMode, 5, 0, 1, 1);

        tsMode = new QLabel(centralWidget);
        tsMode->setObjectName(QStringLiteral("tsMode"));
        tsMode->setCursor(QCursor(Qt::ArrowCursor));
        tsMode->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsMode, 5, 1, 1, 1);

        txtUrl = new QLabel(centralWidget);
        txtUrl->setObjectName(QStringLiteral("txtUrl"));
        txtUrl->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        txtUrl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtUrl, 6, 0, 1, 1);

        tsUrl = new QLabel(centralWidget);
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

        gridLayout_2->addWidget(tsUrl, 6, 1, 1, 1);

        txtLng = new QLabel(centralWidget);
        txtLng->setObjectName(QStringLiteral("txtLng"));
        txtLng->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(txtLng, 7, 0, 1, 1);

        tsLng = new QLabel(centralWidget);
        tsLng->setObjectName(QStringLiteral("tsLng"));
        tsLng->setCursor(QCursor(Qt::ArrowCursor));
        tsLng->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(tsLng, 7, 1, 1, 1);


        horizontalLayout_10->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        txtComment = new QLabel(centralWidget);
        txtComment->setObjectName(QStringLiteral("txtComment"));
        txtComment->setMinimumSize(QSize(0, 20));
        txtComment->setMaximumSize(QSize(80, 20));
        txtComment->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        verticalLayout_2->addWidget(txtComment);

        edtComment = new QTextEdit(centralWidget);
        edtComment->setObjectName(QStringLiteral("edtComment"));
        edtComment->setMaximumSize(QSize(16777215, 99999));

        verticalLayout_2->addWidget(edtComment);


        horizontalLayout_10->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout_4->addLayout(verticalLayout_5, 0, 0, 1, 1);

        SRauncher->setCentralWidget(centralWidget);

        retranslateUi(SRauncher);
        QObject::connect(srvList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), btnConnect, SLOT(click()));

        QMetaObject::connectSlotsByName(SRauncher);
    } // setupUi

    void retranslateUi(QMainWindow *SRauncher)
    {
        SRauncher->setWindowTitle(QApplication::translate("SRauncher", "SRauncher", nullptr));
        txtNick->setText(QApplication::translate("SRauncher", "Nick:", nullptr));
        btnSettings->setText(QApplication::translate("SRauncher", "Settings", nullptr));
        txtGroup->setText(QApplication::translate("SRauncher", "Group:", nullptr));
        btnGroupAdd->setText(QApplication::translate("SRauncher", "Add", nullptr));
        btnGroupRemove->setText(QApplication::translate("SRauncher", "remove", nullptr));
        btnInject->setText(QApplication::translate("SRauncher", "Additional inject", nullptr));
        groupBox->setTitle(QApplication::translate("SRauncher", "Server", nullptr));
        txtIp->setText(QApplication::translate("SRauncher", "IP:", nullptr));
        edtIp->setText(QApplication::translate("SRauncher", "127.0.0.1:7777", nullptr));
        btnAddSrv->setText(QApplication::translate("SRauncher", "Add/move server", nullptr));
        btnRemove->setText(QApplication::translate("SRauncher", "remove", nullptr));
        btnRename->setText(QApplication::translate("SRauncher", "rename", nullptr));
        groupBox_2->setTitle(QApplication::translate("SRauncher", "Run", nullptr));
        txtGta->setText(QApplication::translate("SRauncher", "gta_sa:", nullptr));
        edtGta->setText(QApplication::translate("SRauncher", "gta_sa.exe", nullptr));
        btnConnect->setText(QApplication::translate("SRauncher", "Connect", nullptr));
        toolButton->setText(QApplication::translate("SRauncher", "Password", nullptr));
        btnDebug->setText(QApplication::translate("SRauncher", "Debug mode", nullptr));
        txtPlayers->setText(QApplication::translate("SRauncher", "Players: ", nullptr));
        tsPlayers->setText(QString());
        txtPing->setText(QApplication::translate("SRauncher", "Ping: ", nullptr));
        tsPing->setText(QString());
        txtTime->setText(QApplication::translate("SRauncher", "Time: ", nullptr));
        tsTime->setText(QString());
        txtWeather->setText(QApplication::translate("SRauncher", "Weather: ", nullptr));
        tsWeather->setText(QString());
        txtMap->setText(QApplication::translate("SRauncher", "Map: ", nullptr));
        tsMap->setText(QString());
        txtMode->setText(QApplication::translate("SRauncher", "Mode: ", nullptr));
        tsMode->setText(QString());
        txtUrl->setText(QApplication::translate("SRauncher", "URL: ", nullptr));
        tsUrl->setText(QString());
        txtLng->setText(QApplication::translate("SRauncher", "Language:", nullptr));
        tsLng->setText(QString());
        txtComment->setText(QApplication::translate("SRauncher", "Comment:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRauncher: public Ui_SRauncher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRAUNCHER_H
