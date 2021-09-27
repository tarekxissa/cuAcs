#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Our customized API's
#include "animalcareshelter.h"
#include "animalheaders.h"
#include "server.h"
#include <vector>

//Built in API's
#include <QListWidget>
#include <QMainWindow>
#include <QTableWidget>
#include <QTextStream>
#include <QCompleter>
#include <QDirModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTextStream& qStdout();

    vector<string> newAnimalInfo;

private slots:
    void on_staffBtn_clicked();

    void on_clientBtn_clicked();

    void on_addClientBtn_clicked();

    void on_animalAddBtn_clicked();

    void on_closeAnimalBtn_clicked();

    void on_saveAnimalBtn_clicked();


    void on_animalTypeField_currentTextChanged(const QString &arg1);

    void on_animalsListBtn_clicked();

    void on_nextInfoBtn_clicked();

    void on_backInfoBtn_clicked();

    void on_closeClientBtn_clicked();

    void on_saveClientBtn_clicked();

    void on_viewClientsBtn_clicked();

    void on_animalNextBtn_clicked();

    void on_animalBackBtn_clicked();

    void on_clientAnimalsBtn_clicked();

    void on_backToMenuFromStaffBtn_clicked();

    void on_backToMainMenuFromClientViewBtn_clicked();








    void on_animalsListTable_cellPressed(int row, int column);

    void on_viewAnimalDetailsBtn_clicked();

    void on_backViewAnimalsBtn_clicked();

    void on_backToNonPhysBtn_clicked();

    void on_animalNextPhysBtn_clicked();

    void on_backViewAnimalsToClientBtn_clicked();

    void on_animalViewDetailClientBtn_clicked();

    void on_animalsListFromClientView_cellPressed(int row, int column);

    void on_viewClientDetailsBtn_clicked();

    void on_backtoClientsListBtn_clicked();

    void on_clientListTable_cellPressed(int row, int column);

    void on_editAnimalDetailsBtn_clicked();

    void on_saveAnimalsEditsBtn_clicked();

    void on_clientProfileBtn_clicked();

    void on_editClientProfileBtn_clicked();

    void on_cancelClientEditsBtn_clicked();

    void on_saveClientProfileEditsBtn_clicked();

    void on_backPrefenecesBtn_clicked();

    void on_setAnimalPreferencesBtn_clicked();

    void on_savePreferencesBtn_clicked();

    void on_backToProfileFromPhysPageBtn_clicked();

    void on_saveClientPhysicalPreferencesBtn_clicked();

    void on_setPhysPreferencesBtn_clicked();

    void on_backToProfileFromViewRanksAndPrefecnesBtn_clicked();

    void on_viewRanksAndPreferencesBtn_clicked();

    void on_loginBtn_clicked();

    void on_backToCharacterTraitsBtn_clicked();

    void on_nextToClientNonPhysPreBtn_clicked();

    void on_mainMenuBtnFromLogin_clicked();

    void on_launchACM_clicked();

    void on_backToMatchesSummaryBtn_clicked();

    void on_viewDetailedMatchBtn_clicked();

    void on_closeAnimalsListBtn_clicked();

    void on_closeClientsViewBtn_clicked();

    void on_closeAcmPageBtn_clicked();




    void on_matchesList_cellPressed(int row, int column);

private:

    /*Attrubites/Composition*/
    Ui::MainWindow *ui;
    Server *database;
    AnimalCareShelter animalsClientsList; //This is for animals and clients models.
    int rowTable,columnTable; // This is for finding which animal or client was clicked in the table.

    int clientLoggedIn; // This keeps track of the client that is logged in.

    //Animal autocompleter non-physical attributes
    QCompleter *invidualisimOptions;
    QCompleter *activenessOptions;
    QCompleter *intelliegenceOptions;
    QCompleter *affectionisimOptions;
    QCompleter *disciplineOptions;
    QCompleter *assertivenessOptions;
    QCompleter *spaciousnessOptions;
    QCompleter *energeticOptions;
    QCompleter *dirNoctOptions;
    QCompleter *habitatPreOptions;
    QCompleter *playfullnessOptions;
    QCompleter *appetiteOptions;

    //QStringLists for all non-physical attrubutes. Those are useful that when u want to check the user's input, compared to the data in the combobox.
     QStringList invidulaismList;
     QStringList activenessList;
     QStringList intelligenceList;
     QStringList affectionatismList;
     QStringList disciplinedList;
     QStringList assertiveList;
     QStringList spaciousList;
     QStringList energeticList;
     QStringList nocturnalList;
     QStringList habitatList;
     QStringList playfullnessList;
     QStringList appetiteList;

    //End of  autocompleter non-physical attributes

    //Animal autocompleter basic info attributes
    QCompleter *colourOptions;
    QCompleter *genderOptions;
    QCompleter *typesOptions;
    QCompleter *speciesOptions;
    QCompleter *ageOptions;

    //QStringLists for all basic info. Those are useful that when u want to check the user's input, compared to the data in the combobox.
    QStringList coloursList;
    QStringList animalTypes;
    QStringList genderList;
    QStringList ageList;

    //End of  autocompleter  basic info attributes

    //Animal autocompleter phyiscal attributes
    QCompleter *physFieldOne;
    QCompleter *physFieldTwo;
    QCompleter *physFieldThree;


   //QStringLists for all physical attriubtes info. Those are useful that when u want to check the user's input, compared to the data in the combobox.
    QStringList buildList;
    QStringList furLengthList;
    QStringList furColourList;
    QStringList beakLengthList;
    QStringList wingSpanList;
    QStringList beakColourList;
    QStringList finnSizeList;
    QStringList bodyPatternList;
    QStringList bodyLengthList;
    QStringList scaleList;

    //End of  autocompleter  phyiscal attributes


    //animation
    QMovie * movie;

    /*End of Attrubites*/

    /*Methods*/
    void clearFields(int);
    void updateAnimalListUI();
    void showTheCorrectWindow(int*);
    void initClientList();
    void updateClientList();
    void updateAnimalListFromClientView();
    void displayAnimalDetails();
    void displayAnimalDetailsFromClient();
    void displayClientDetails();
    void enableAnimalEdits(bool);
    void renderSpeciesAndPhysAttributes();
    void saveNewEdits();
    void displayClientProfileDetails();
    void enableClientEdits(bool);
    void saveClientNewEdits();
    void updateRanksAndPreferencesUI();
    void updateAcmMatchesUI();
    void updateAcmMatchesDetailedUI();
    void delay(int);

    /*End of Methods*/
};

#endif // MAINWINDOW_H
