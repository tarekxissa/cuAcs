/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionPrint;
    QAction *actionClose;
    QAction *actionGuide;
    QAction *action_About;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *WelcomeScreen;
    QGroupBox *entranceMenu;
    QGroupBox *MenuGroupBox;
    QTextBrowser *checkingUserText;
    QPushButton *staffBtn;
    QPushButton *clientBtn;
    QTextBrowser *welcomeScreen;
    QWidget *StaffPage;
    QGroupBox *StaffMenu;
    QTextBrowser *userMenu_text;
    QGroupBox *StaffMenuBox;
    QPushButton *launchACM;
    QPushButton *animalsListBtn;
    QPushButton *viewClientsBtn;
    QPushButton *animalAddBtn;
    QPushButton *addClientBtn;
    QGroupBox *canvasStaff;
    QGroupBox *addAnimalPopUp;
    QPushButton *saveAnimalBtn;
    QGroupBox *animalForm;
    QComboBox *animalGenderField;
    QTextEdit *animalNameField;
    QComboBox *animalSpeciesField;
    QComboBox *animalColourField;
    QTextEdit *animalWeightField;
    QTextEdit *animalHeightField;
    QLabel *animalWeightLabel;
    QLabel *animalHeightLabel;
    QComboBox *animalAgeField;
    QComboBox *animalTypeField;
    QPushButton *closeAnimalBtn;
    QTextEdit *titlePopUp;
    QTextEdit *errorMessage;
    QGroupBox *viewAnimalsListPopUp;
    QTextBrowser *animalsListTitle;
    QListWidget *animalsList;
    QWidget *ClientPage;
    QGroupBox *ClientMenu;
    QTextBrowser *clientMenuText;
    QGroupBox *clientMenuBox;
    QPushButton *clientProfileBtn;
    QPushButton *editProfileBtn_2;
    QPushButton *clientAnimalsBtn;
    QGroupBox *groupBox_5;
    QLabel *labelForUserLoggedIn;
    QTextBrowser *userLoggedIn;
    QGroupBox *ClientCanvas;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 650);
        MainWindow->setStyleSheet(QStringLiteral("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName(QStringLiteral("actionGuide"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 1021, 651));
        WelcomeScreen = new QWidget();
        WelcomeScreen->setObjectName(QStringLiteral("WelcomeScreen"));
        entranceMenu = new QGroupBox(WelcomeScreen);
        entranceMenu->setObjectName(QStringLiteral("entranceMenu"));
        entranceMenu->setGeometry(QRect(210, 160, 591, 361));
        entranceMenu->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius:45px;"));
        MenuGroupBox = new QGroupBox(entranceMenu);
        MenuGroupBox->setObjectName(QStringLiteral("MenuGroupBox"));
        MenuGroupBox->setGeometry(QRect(70, 90, 451, 191));
        MenuGroupBox->setStyleSheet(QLatin1String("border: 3px solid  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;"));
        checkingUserText = new QTextBrowser(MenuGroupBox);
        checkingUserText->setObjectName(QStringLiteral("checkingUserText"));
        checkingUserText->setEnabled(false);
        checkingUserText->setGeometry(QRect(30, 20, 381, 41));
        checkingUserText->setStyleSheet(QStringLiteral("border: none;"));
        staffBtn = new QPushButton(MenuGroupBox);
        staffBtn->setObjectName(QStringLiteral("staffBtn"));
        staffBtn->setGeometry(QRect(252, 100, 141, 51));
        staffBtn->setCursor(QCursor(Qt::PointingHandCursor));
        staffBtn->setStyleSheet(QLatin1String("#staffBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#staffBtn:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        clientBtn = new QPushButton(MenuGroupBox);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setGeometry(QRect(50, 100, 141, 51));
        clientBtn->setCursor(QCursor(Qt::PointingHandCursor));
        clientBtn->setStyleSheet(QLatin1String("#clientBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#clientBtn:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        welcomeScreen = new QTextBrowser(entranceMenu);
        welcomeScreen->setObjectName(QStringLiteral("welcomeScreen"));
        welcomeScreen->setEnabled(false);
        welcomeScreen->setGeometry(QRect(100, 0, 391, 81));
        stackedWidget->addWidget(WelcomeScreen);
        StaffPage = new QWidget();
        StaffPage->setObjectName(QStringLiteral("StaffPage"));
        StaffMenu = new QGroupBox(StaffPage);
        StaffMenu->setObjectName(QStringLiteral("StaffMenu"));
        StaffMenu->setGeometry(QRect(690, 120, 281, 441));
        StaffMenu->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius: 35px;\n"
"border: 2px solid black;"));
        userMenu_text = new QTextBrowser(StaffMenu);
        userMenu_text->setObjectName(QStringLiteral("userMenu_text"));
        userMenu_text->setGeometry(QRect(20, 20, 256, 41));
        userMenu_text->setStyleSheet(QStringLiteral("border: none"));
        StaffMenuBox = new QGroupBox(StaffMenu);
        StaffMenuBox->setObjectName(QStringLiteral("StaffMenuBox"));
        StaffMenuBox->setGeometry(QRect(60, 60, 171, 341));
        StaffMenuBox->setStyleSheet(QLatin1String("border: none;\n"
"border-radius: none"));
        launchACM = new QPushButton(StaffMenuBox);
        launchACM->setObjectName(QStringLiteral("launchACM"));
        launchACM->setGeometry(QRect(15, 20, 141, 51));
        launchACM->setCursor(QCursor(Qt::PointingHandCursor));
        launchACM->setStyleSheet(QLatin1String("#launchACM{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#launchACM:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        animalsListBtn = new QPushButton(StaffMenuBox);
        animalsListBtn->setObjectName(QStringLiteral("animalsListBtn"));
        animalsListBtn->setGeometry(QRect(15, 80, 141, 51));
        animalsListBtn->setCursor(QCursor(Qt::PointingHandCursor));
        animalsListBtn->setStyleSheet(QLatin1String("#animalsListBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#animalsListBtn:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        viewClientsBtn = new QPushButton(StaffMenuBox);
        viewClientsBtn->setObjectName(QStringLiteral("viewClientsBtn"));
        viewClientsBtn->setGeometry(QRect(15, 140, 141, 51));
        viewClientsBtn->setCursor(QCursor(Qt::PointingHandCursor));
        viewClientsBtn->setStyleSheet(QLatin1String("#viewClientsBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#viewClientsBtn:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        animalAddBtn = new QPushButton(StaffMenuBox);
        animalAddBtn->setObjectName(QStringLiteral("animalAddBtn"));
        animalAddBtn->setGeometry(QRect(15, 200, 141, 51));
        animalAddBtn->setCursor(QCursor(Qt::PointingHandCursor));
        animalAddBtn->setStyleSheet(QLatin1String("#animalAddBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#animalAddBtn:hover{\n"
"\n"
"	background:   qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"\n"
"\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        addClientBtn = new QPushButton(StaffMenuBox);
        addClientBtn->setObjectName(QStringLiteral("addClientBtn"));
        addClientBtn->setGeometry(QRect(15, 260, 141, 51));
        addClientBtn->setCursor(QCursor(Qt::PointingHandCursor));
        addClientBtn->setStyleSheet(QLatin1String("#addClientBtn{\n"
"\n"
"border: 3px solid qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"\n"
"#addClientBtn:hover{\n"
"\n"
"	background:  qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        canvasStaff = new QGroupBox(StaffPage);
        canvasStaff->setObjectName(QStringLiteral("canvasStaff"));
        canvasStaff->setGeometry(QRect(10, 120, 671, 441));
        canvasStaff->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius: 25px;\n"
"border: 2px solid black;"));
        addAnimalPopUp = new QGroupBox(canvasStaff);
        addAnimalPopUp->setObjectName(QStringLiteral("addAnimalPopUp"));
        addAnimalPopUp->setEnabled(true);
        addAnimalPopUp->setGeometry(QRect(510, 420, 111, 21));
        addAnimalPopUp->setStyleSheet(QLatin1String("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
""));
        addAnimalPopUp->setCheckable(false);
        saveAnimalBtn = new QPushButton(addAnimalPopUp);
        saveAnimalBtn->setObjectName(QStringLiteral("saveAnimalBtn"));
        saveAnimalBtn->setGeometry(QRect(480, 360, 151, 51));
        saveAnimalBtn->setCursor(QCursor(Qt::PointingHandCursor));
        saveAnimalBtn->setStyleSheet(QLatin1String("#saveAnimalBtn{\n"
"	background: white;\n"
"	border-radius: 25px;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"#saveAnimalBtn:hover{\n"
"	background: #fab1a0\n"
"\n"
"}"));
        animalForm = new QGroupBox(addAnimalPopUp);
        animalForm->setObjectName(QStringLiteral("animalForm"));
        animalForm->setGeometry(QRect(20, 70, 341, 291));
        animalForm->setStyleSheet(QLatin1String("#animalForm{\n"
"\n"
"\n"
"	border:none\n"
"\n"
"}"));
        animalGenderField = new QComboBox(animalForm);
        animalGenderField->setObjectName(QStringLiteral("animalGenderField"));
        animalGenderField->setGeometry(QRect(20, 250, 141, 31));
        animalGenderField->setStyleSheet(QLatin1String("#animalGenderField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"}\n"
"#animalGenderField:hover{\n"
"	background: white;\n"
"	color: white;\n"
"\n"
"}\n"
"#QListView{\n"
"\n"
"	background: white;\n"
"}\n"
"\n"
"\n"
""));
        animalNameField = new QTextEdit(animalForm);
        animalNameField->setObjectName(QStringLiteral("animalNameField"));
        animalNameField->setEnabled(true);
        animalNameField->setGeometry(QRect(10, 10, 301, 31));
        animalNameField->setStyleSheet(QLatin1String("#animalNameField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalSpeciesField = new QComboBox(animalForm);
        animalSpeciesField->setObjectName(QStringLiteral("animalSpeciesField"));
        animalSpeciesField->setGeometry(QRect(10, 205, 301, 31));
        animalSpeciesField->setStyleSheet(QLatin1String("#animalSpeciesField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalColourField = new QComboBox(animalForm);
        animalColourField->setObjectName(QStringLiteral("animalColourField"));
        animalColourField->setGeometry(QRect(10, 168, 301, 31));
        animalColourField->setStyleSheet(QLatin1String("#animalColourField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalWeightField = new QTextEdit(animalForm);
        animalWeightField->setObjectName(QStringLiteral("animalWeightField"));
        animalWeightField->setGeometry(QRect(10, 50, 151, 31));
        animalWeightField->setStyleSheet(QLatin1String("#animalWeightField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalHeightField = new QTextEdit(animalForm);
        animalHeightField->setObjectName(QStringLiteral("animalHeightField"));
        animalHeightField->setGeometry(QRect(166, 50, 151, 31));
        animalHeightField->setStyleSheet(QLatin1String("#animalHeightField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalWeightLabel = new QLabel(animalForm);
        animalWeightLabel->setObjectName(QStringLiteral("animalWeightLabel"));
        animalWeightLabel->setGeometry(QRect(130, 55, 21, 20));
        animalWeightLabel->setStyleSheet(QLatin1String("#animalWeightLabel{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background: white;\n"
"\n"
"}"));
        animalHeightLabel = new QLabel(animalForm);
        animalHeightLabel->setObjectName(QStringLiteral("animalHeightLabel"));
        animalHeightLabel->setGeometry(QRect(292, 55, 21, 20));
        animalHeightLabel->setStyleSheet(QLatin1String("#animalHeightLabel{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background: white;\n"
"\n"
"}"));
        animalAgeField = new QComboBox(animalForm);
        animalAgeField->setObjectName(QStringLiteral("animalAgeField"));
        animalAgeField->setGeometry(QRect(10, 90, 311, 31));
        animalAgeField->setStyleSheet(QLatin1String("#animalAgeField{\n"
"	background: white;\n"
"	border-radius: 8px;\n"
"\n"
"\n"
"\n"
"}"));
        animalTypeField = new QComboBox(animalForm);
        animalTypeField->setObjectName(QStringLiteral("animalTypeField"));
        animalTypeField->setGeometry(QRect(10, 130, 311, 31));
        animalTypeField->setStyleSheet(QLatin1String("#animalTypeField{\n"
"\n"
"	border-radius:8px;\n"
"	background:white;\n"
"}"));
        closeAnimalBtn = new QPushButton(addAnimalPopUp);
        closeAnimalBtn->setObjectName(QStringLiteral("closeAnimalBtn"));
        closeAnimalBtn->setGeometry(QRect(320, 360, 151, 51));
        closeAnimalBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeAnimalBtn->setStyleSheet(QLatin1String("#closeAnimalBtn{\n"
"	background: white;\n"
"	border-radius: 25px;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"#closeAnimalBtn:hover{\n"
"	background: #fab1a0\n"
"\n"
"}"));
        titlePopUp = new QTextEdit(addAnimalPopUp);
        titlePopUp->setObjectName(QStringLiteral("titlePopUp"));
        titlePopUp->setEnabled(false);
        titlePopUp->setGeometry(QRect(180, 7, 301, 41));
        titlePopUp->setStyleSheet(QLatin1String("#titlePopUp{\n"
"\n"
"	background: white;\n"
"	border:none;\n"
"	border-radius: 8px;\n"
"\n"
"}"));
        errorMessage = new QTextEdit(addAnimalPopUp);
        errorMessage->setObjectName(QStringLiteral("errorMessage"));
        errorMessage->setGeometry(QRect(370, 140, 251, 101));
        errorMessage->setStyleSheet(QStringLiteral("background: white"));
        viewAnimalsListPopUp = new QGroupBox(canvasStaff);
        viewAnimalsListPopUp->setObjectName(QStringLiteral("viewAnimalsListPopUp"));
        viewAnimalsListPopUp->setGeometry(QRect(10, 10, 651, 421));
        viewAnimalsListPopUp->setStyleSheet(QLatin1String("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #ffeaa7, stop:1 #fab1a0);\n"
""));
        animalsListTitle = new QTextBrowser(viewAnimalsListPopUp);
        animalsListTitle->setObjectName(QStringLiteral("animalsListTitle"));
        animalsListTitle->setEnabled(true);
        animalsListTitle->setGeometry(QRect(130, 10, 411, 41));
        animalsListTitle->setStyleSheet(QLatin1String("#animalsListTitle{\n"
"		background:white;\n"
"		border-radius:15px;\n"
"}"));
        animalsList = new QListWidget(viewAnimalsListPopUp);
        new QListWidgetItem(animalsList);
        animalsList->setObjectName(QStringLiteral("animalsList"));
        animalsList->setGeometry(QRect(30, 60, 601, 341));
        animalsList->setStyleSheet(QStringLiteral("border:none"));
        stackedWidget->addWidget(StaffPage);
        ClientPage = new QWidget();
        ClientPage->setObjectName(QStringLiteral("ClientPage"));
        ClientMenu = new QGroupBox(ClientPage);
        ClientMenu->setObjectName(QStringLiteral("ClientMenu"));
        ClientMenu->setGeometry(QRect(650, 170, 321, 341));
        ClientMenu->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius: 35px;\n"
"border: 2px solid black;"));
        clientMenuText = new QTextBrowser(ClientMenu);
        clientMenuText->setObjectName(QStringLiteral("clientMenuText"));
        clientMenuText->setGeometry(QRect(20, 20, 256, 41));
        clientMenuText->setStyleSheet(QStringLiteral("border: none"));
        clientMenuBox = new QGroupBox(ClientMenu);
        clientMenuBox->setObjectName(QStringLiteral("clientMenuBox"));
        clientMenuBox->setGeometry(QRect(70, 60, 171, 201));
        clientMenuBox->setStyleSheet(QLatin1String("border: none;\n"
"border-radius: none"));
        clientProfileBtn = new QPushButton(clientMenuBox);
        clientProfileBtn->setObjectName(QStringLiteral("clientProfileBtn"));
        clientProfileBtn->setGeometry(QRect(15, 20, 141, 51));
        clientProfileBtn->setCursor(QCursor(Qt::PointingHandCursor));
        clientProfileBtn->setStyleSheet(QLatin1String("#clientProfileBtn{\n"
"\n"
"border: 3px solid #55efc4;\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#clientProfileBtn:hover{\n"
"\n"
"	background:  #55efc4;\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        editProfileBtn_2 = new QPushButton(clientMenuBox);
        editProfileBtn_2->setObjectName(QStringLiteral("editProfileBtn_2"));
        editProfileBtn_2->setGeometry(QRect(15, 80, 141, 51));
        editProfileBtn_2->setCursor(QCursor(Qt::PointingHandCursor));
        editProfileBtn_2->setStyleSheet(QLatin1String("#editProfileBtn_2{\n"
"\n"
"border: 3px solid #55efc4;\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#editProfileBtn_2:hover{\n"
"\n"
"	background:  #55efc4;\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        clientAnimalsBtn = new QPushButton(clientMenuBox);
        clientAnimalsBtn->setObjectName(QStringLiteral("clientAnimalsBtn"));
        clientAnimalsBtn->setGeometry(QRect(15, 140, 141, 51));
        clientAnimalsBtn->setCursor(QCursor(Qt::PointingHandCursor));
        clientAnimalsBtn->setStyleSheet(QLatin1String("#clientAnimalsBtn{\n"
"\n"
"border: 3px solid #55efc4;\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"#clientAnimalsBtn:hover{\n"
"\n"
"	background:  #55efc4;\n"
"	color:#555;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        groupBox_5 = new QGroupBox(ClientPage);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(680, 50, 261, 101));
        groupBox_5->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius: 35px;\n"
"border: 2px solid black;"));
        labelForUserLoggedIn = new QLabel(groupBox_5);
        labelForUserLoggedIn->setObjectName(QStringLiteral("labelForUserLoggedIn"));
        labelForUserLoggedIn->setGeometry(QRect(30, 10, 161, 20));
        labelForUserLoggedIn->setStyleSheet(QLatin1String("border:none\n"
""));
        userLoggedIn = new QTextBrowser(groupBox_5);
        userLoggedIn->setObjectName(QStringLiteral("userLoggedIn"));
        userLoggedIn->setGeometry(QRect(30, 40, 191, 31));
        ClientCanvas = new QGroupBox(ClientPage);
        ClientCanvas->setObjectName(QStringLiteral("ClientCanvas"));
        ClientCanvas->setGeometry(QRect(30, 130, 591, 401));
        ClientCanvas->setStyleSheet(QLatin1String("background: #fff;\n"
"border-radius: 65px;"));
        stackedWidget->addWidget(ClientPage);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionGuide);
        menuHelp->addAction(action_About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionGuide->setText(QApplication::translate("MainWindow", " Guide", Q_NULLPTR));
        action_About->setText(QApplication::translate("MainWindow", " About Us", Q_NULLPTR));
        entranceMenu->setTitle(QString());
        MenuGroupBox->setTitle(QString());
        checkingUserText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#555555;\">Are you a client or staff member?</span></p></body></html>", Q_NULLPTR));
        staffBtn->setText(QApplication::translate("MainWindow", "Staff", Q_NULLPTR));
        clientBtn->setText(QApplication::translate("MainWindow", "Client", Q_NULLPTR));
        welcomeScreen->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#555555;\">Welcome to CUACS!</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600; color:#555555;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty;"
                        " margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        StaffMenu->setTitle(QString());
        userMenu_text->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#555555;\">User Menu</span></p></body></html>", Q_NULLPTR));
        StaffMenuBox->setTitle(QString());
        launchACM->setText(QApplication::translate("MainWindow", "Launch ACM", Q_NULLPTR));
        animalsListBtn->setText(QApplication::translate("MainWindow", "View Animals List", Q_NULLPTR));
        viewClientsBtn->setText(QApplication::translate("MainWindow", "View Clients List", Q_NULLPTR));
        animalAddBtn->setText(QApplication::translate("MainWindow", "Add Animal", Q_NULLPTR));
        addClientBtn->setText(QApplication::translate("MainWindow", "Add Client", Q_NULLPTR));
        canvasStaff->setTitle(QString());
#ifndef QT_NO_ACCESSIBILITY
        addAnimalPopUp->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        addAnimalPopUp->setTitle(QString());
        saveAnimalBtn->setText(QApplication::translate("MainWindow", "Save Animal", Q_NULLPTR));
        animalForm->setTitle(QString());
        animalGenderField->clear();
        animalGenderField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select Gender", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Male", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Female", Q_NULLPTR)
        );
        animalNameField->setPlaceholderText(QApplication::translate("MainWindow", "Name of the Animal ex. \"Leo\" or \"Billy\"", Q_NULLPTR));
        animalSpeciesField->clear();
        animalSpeciesField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select the type of species", Q_NULLPTR)
        );
        animalColourField->clear();
        animalColourField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select the colour of the animal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Black", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Blue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Brown", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cream", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Crimson", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Gray", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Green", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Orange", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Pink", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Purple", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Red", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Violet", Q_NULLPTR)
         << QApplication::translate("MainWindow", "White", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Yellow", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Bicolor", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tricolor", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Colorful", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Colorless / Transparency", Q_NULLPTR)
        );
        animalWeightField->setPlaceholderText(QApplication::translate("MainWindow", "Animal Weight", Q_NULLPTR));
        animalHeightField->setPlaceholderText(QApplication::translate("MainWindow", "Animal Height", Q_NULLPTR));
        animalWeightLabel->setText(QApplication::translate("MainWindow", "KG", Q_NULLPTR));
        animalHeightLabel->setText(QApplication::translate("MainWindow", "CM", Q_NULLPTR));
        animalAgeField->clear();
        animalAgeField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select the age of the animal(MO=Months old)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1-3 MO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4-6 MO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7-9 MO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10-12 MO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1-2 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3-4 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5-6 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7-8 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9-10 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11-12 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12-13 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14-15 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "15-16 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16-17 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "18-19 YO", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20 YO", Q_NULLPTR)
        );
        animalTypeField->clear();
        animalTypeField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select the Type of animal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cat", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Dog", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Parrot", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Finch", Q_NULLPTR)
        );
        closeAnimalBtn->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        titlePopUp->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600; color:#2e3436;\">Adding An Animal</span></p></body></html>", Q_NULLPTR));
        errorMessage->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#cc0000;\">Oops! Something went wrong. Please try again, make sure to fill out all the forms correclty as specified in the place holders for each text field</span></p></body></html>", Q_NULLPTR));
        viewAnimalsListPopUp->setTitle(QString());
        animalsListTitle->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Animals Availiable For Adoption</span></p></body></html>", Q_NULLPTR));

        const bool __sortingEnabled = animalsList->isSortingEnabled();
        animalsList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = animalsList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Name             Type              Species              Colour              Age              Gender", Q_NULLPTR));
        animalsList->setSortingEnabled(__sortingEnabled);

        ClientMenu->setTitle(QString());
        clientMenuText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#555555;\">User Menu</span></p></body></html>", Q_NULLPTR));
        clientMenuBox->setTitle(QString());
        clientProfileBtn->setText(QApplication::translate("MainWindow", "View Profile", Q_NULLPTR));
        editProfileBtn_2->setText(QApplication::translate("MainWindow", "Edit Profile", Q_NULLPTR));
        clientAnimalsBtn->setText(QApplication::translate("MainWindow", "View Animals List", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        labelForUserLoggedIn->setText(QApplication::translate("MainWindow", "Current User logged in:", Q_NULLPTR));
        userLoggedIn->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Recklesskilla911</p></body></html>", Q_NULLPTR));
        ClientCanvas->setTitle(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
