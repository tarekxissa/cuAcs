#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <typeinfo>
#include <QSqlQuery>
#include <string>
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include <QMessageBox>
#include <QMovie>
#include <QLabel>
#include <iostream>
#include <cstdio>
#include <stdio.h>



using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



       ui->setupUi(this);


       this->setFixedSize(QSize(1000, 650));
       database = new Server();
       database->openDataBase("/database.db");
       database->retrieve(animalsClientsList.animals,animalsClientsList.clients);
       int maxSizeForClient = animalsClientsList.clients.size();
       int maxSizeForAnimal = animalsClientsList.animals.size();
       animalsClientsList.setPreviousIDClient(animalsClientsList.clients.get(maxSizeForClient-1)->getClientId());
       animalsClientsList.setPreviousIDForAnimal(animalsClientsList.animals.get(maxSizeForAnimal-1)->getAnimalID());

       movie = new QMovie("load.gif");
//       cout << animalsClientsList.getPreviousIDClient() << endl;
//       cout << animalsClientsList.getPreviousIDForAnimal() << endl;


}

MainWindow::~MainWindow()
{


    //1. Store the array(break it down and store its elements) into a database,

    database->update(animalsClientsList.animals,animalsClientsList.clients);
    delete database;
    delete ui;


}


/*

    -1. this method is for printing a debugging.
*/
QTextStream& MainWindow::qStdout(){
    static QTextStream ts(stdout);
    return ts;
}


//===============================================> STAFF CODE LOGIC <================================================

/*
    * This function will transation you to the staff view and it will init anything that has to do with staff view,from there the staff can navigate through the program.
*/
void MainWindow::on_staffBtn_clicked()
{
    /*
     * 1. Transaition to Staff View.
     * 2. Hide all other windows, like differnt views.
     * 3  Init things needed for staff
    */

    //1.
    ui->stackedWidget->setCurrentIndex(1);

    //2.
    //Adding an animal hiding
    ui->addAnimalPopUp->hide();
    ui->addAnimalPopUp->setGeometry(10,10,661,541);
    ui->errorMessage->hide();
    ui->successMessage->hide();
    //end of adding an animal hiding

    //
    ui->viewAnimalsListPopUp->hide();
    ui->viewAnimalsListPopUp->setGeometry(10,10,661,541);


    //Adding a client ui hiding
    ui->addClientPopUp->hide();
    ui->addClientPopUp->setGeometry(10,10,661,541);
    ui->clientSucessMessage->hide();
    ui->clientErrMessage->hide();


    //Client Table
    ui->viewClientsListPopUp->hide();
    ui->viewClientsListPopUp->setGeometry(10,10,661,541);
    //End of adding a client ui hiding



    //ACM page adding ui hiding and stuff
    ui->acmPage->hide();
    ui->acmPage->setGeometry(10,10,661,541);


    //Hiding Other btns
    ui->viewAnimalDetailsBtn->hide();


    //Hiding input fields
    ui->animalPhysFinnSizeField->hide();
    ui->animalPhysScaleTypeField->hide();
    ui->animalPhysFurLengthField->hide();
    ui->animalPhysFurColourField->hide();
    ui->animalPhysWingSpanField->hide();
    ui->animalPhysBeakLengthField->hide();
    ui->animalPhysBeakColourField->hide();
    ui->animalPhysBuildField->hide();
    ui->animalPhysBodyPatternField->hide();
    ui->animalPhysBodyLengthField->hide();


    //3.



//***************Non-Physcial Attributes AutoCompleter**************************



    //AutoCompleter for animal invidualism.

    invidulaismList.clear();
    invidulaismList << "1 (barely independent)" << "2 (somewhat independent)" << "3 (moderately independent)" << "4 (independent)" << "5 (very independent)";

    invidualisimOptions = new QCompleter(invidulaismList,this);
    invidualisimOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr1->setCompleter(invidualisimOptions);

    //AutoCompleter for animal activeness.

    activenessList.clear();
    activenessList << "1 (barely active)" << "2 (somewhat active)" << "3 (moderately active)" << "4 (active)" << "5 (very active)";

    activenessOptions = new QCompleter(activenessList,this);
    activenessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr2->setCompleter(activenessOptions);


    //AutoCompleter for animal Intelligence.

    intelligenceList.clear();
    intelligenceList << "1 (barely intelligent)" << "2 (somewhat intelligent)" << "3 (moderately intelligent)" << "4 (intelligent)" << "5 (very intelligent)";

    intelliegenceOptions = new QCompleter(intelligenceList,this);
    intelliegenceOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr3->setCompleter(intelliegenceOptions);


    //AutoCompleter for animal affectionism.

    affectionatismList.clear();
    affectionatismList << "1 (barely affectionate)" << "2 (somewhat affectionate)" << "3 (moderately affectionate)" << "4 (affectionate)" << "5 (very affectionate)";

    affectionisimOptions = new QCompleter(affectionatismList,this);
    affectionisimOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr4->setCompleter(affectionisimOptions);

    //AutoCompleter for animal discpliine.
    disciplinedList.clear();
    disciplinedList << "1 (barely disciplined)" << "2 (somewhat disciplined)" << "3 (moderately disciplined)" << "4 (disciplined)" << "5 (very disciplined)";

    disciplineOptions = new QCompleter(disciplinedList,this);
    disciplineOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr5->setCompleter(disciplineOptions);


    //AutoCompleter for animal asseritnvess.

    assertiveList.clear();
    assertiveList << "1 (barely assertive)" << "2 (somewhat assertive)" << "3 (moderately assertive)" << "4 (assertive)" << "5 (very assertive)";

    assertivenessOptions = new QCompleter(assertiveList,this);
    assertivenessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr6->setCompleter(assertivenessOptions);


    //AutoCompleter for animal Spacious.

    spaciousList.clear();
    spaciousList << "1 (barely spacious)" << "2 (somewhat spacious)" << "3 (moderately spacious)" << "4 (spacious)" << "5 (very spacious)";

    spaciousnessOptions = new QCompleter(spaciousList,this);
    spaciousnessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr7->setCompleter(spaciousnessOptions);


    //AutoCompleter for animal Engeritc.

    energeticList.clear();
    energeticList << "1 (barely energetic)" << "2 (somewhat energetic)" << "3 (moderately energetic)" << "4 (energetic)" << "5 (very energetic)";

    energeticOptions = new QCompleter(energeticList,this);
    energeticOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr8->setCompleter(energeticOptions);

    //AutoCompleter for animal Nocturnal.
    nocturnalList.clear();
    nocturnalList << "1 (barely nocturnal)" << "2 (somewhat nocturnal)" << "3 (moderately nocturnal)" << "4 (nocturnal)" << "5 (very nocturnal)";

    dirNoctOptions = new QCompleter(nocturnalList,this);
    dirNoctOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr9->setCompleter(dirNoctOptions);

    //AutoCompleter for animal habitat.

    habitatList.clear();
    habitatList << "1 (cold)" << "2 (cool)" << "3 (mild)" << "4 (warm)" << "5 (hot)";

    habitatPreOptions = new QCompleter(habitatList,this);
    habitatPreOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr10->setCompleter(habitatPreOptions);


    //AutoCompleter for animal playfulness.

    playfullnessList.clear();
    playfullnessList << "1 (barely playful)" << "2 (somewhat playful)" << "3 (moderately playful)" << "4 (playful)" << "5 (very playful)";

    playfullnessOptions = new QCompleter(playfullnessList,this);
    playfullnessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr11->setCompleter(playfullnessOptions);

    //AutoCompleter for animal appettite.

    appetiteList.clear();
    appetiteList << "1 (small appetite)" << "2 (moderate appetite)" << "3 (normal appetite)" << "4 (big appetite)" << "5 (huge appetite))";

    appetiteOptions = new QCompleter(appetiteList,this);
    appetiteOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalNonPhysicalAttr12->setCompleter(appetiteOptions);




//*************** End of Non-Physcial Attributes AutoCompleter**************************

//****************Animal Basic info. Attributes AutoCompleter**************************
    //AutoCompleter for animal colours.

    coloursList.clear();
    coloursList << "pink" << "black" << "blue" << "brown" << "cream" << "crimson" << "gray" << "green" << "orange" << "purple" <<"red"
                << "white" << "violet" << "yellow" << "bicolour" << "tricolour" <<"colourful" << "colourless/transparency";
    colourOptions = new QCompleter(coloursList,this);
    colourOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalColourDetail->setCompleter(colourOptions);

    //AutoCompleter for animal types.

    animalTypes.clear();
    animalTypes << "cat" << "dog" << "parrot" << "finch" << "frog" << "salamander" << "betta" << "goldfish" << "snake" << "lizard";
    typesOptions = new QCompleter(animalTypes,this);
    typesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalTypeDetail->setCompleter(typesOptions);


    //AutoCompleter for animal gender.

    genderList.clear();
    genderList << "male" << "female";
    genderOptions = new QCompleter(genderList,this);
    genderOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalGenderDetail->setCompleter(genderOptions);


    //AutoCompleter for animal age.

    ageList.clear();
    ageList << "1-3 mo" << "4-6 mo" << "7-9 mo" << "10-12 mo" << "1-2 yo" << "3-4 yo" << "5-6 yo" << "7-8 yo" << "9-10 yo" << "11-12 yo" << "13-14 yo"
               << "15-16 yo" << "17-18 yo" << "19-20 yo" << "21 yo";
    ageOptions = new QCompleter(ageList,this);
    ageOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->animalAgeDetail->setCompleter(ageOptions);


//**************** END OF Animal Basic info. Attributes AutoCompleter**************************
}


/*
    -1. Adds an animal to the list.
    -2. Adds the animal to the Databse.
*/
void MainWindow::on_saveAnimalBtn_clicked()
{

    //To convert to a string do the following.
    //.toUtf8().constData() on a QString


    //Animals info delcartion
    QString animalName, animalType, animalColour, animalAge, animalGender, animalSpecies,animalHeight, animalWeight;

    //Animals Non-Physical Attributes decleration
    QString individualism, activesness,intelligence,affectionism,displicine,assertiveness,spaciousness,habitat,dirunal,energy,playfulness,appetite;

    //Animals Physical Attributes decleration
    QString furLength, furColour, bodyPattern, bodyLength,build,wingSpan,beakLength,beakColour,scaleType,finnSize;

    //Animals info initilzation
    animalName = ui->animalNameField->toPlainText().trimmed().toLower();
    animalType = ui->animalTypeField->currentText().toLower();
    animalWeight =  ui->animalWeightField->toPlainText().trimmed().toLower();
    animalHeight =  ui->animalHeightField->toPlainText().trimmed().toLower();
    animalColour = ui->animalColourField->currentText().toLower();
    animalAge = ui->animalAgeField->currentText().toLower();
    animalGender = ui->animalGenderField->currentText().toLower();
    animalSpecies = ui->animalSpeciesField->currentText().toLower();

    //Animals Non-Physical Attrubuites initilzation
    individualism = ui->animalIndividualismField->currentText().toLower();
    activesness = ui->animalActivenessField->currentText().toLower();
    intelligence = ui->animalIntelligenceField->currentText().toLower();
    affectionism = ui->animalAffectionismField->currentText().toLower();
    displicine = ui->animalDisciplineField->currentText().toLower();
    assertiveness =  ui->animalAssertivenessField->currentText().toLower();
    spaciousness =  ui->animalSpaciousnessField->currentText().toLower();
    energy  = ui->animalEnergeticField->currentText().toLower();
    dirunal  = ui->animalDiurnalField->currentText().toLower();
    habitat  = ui->animalHabitatField->currentText().toLower();
    playfulness  = ui->animalPlayfulnessField->currentText().toLower();
    appetite  = ui->animalAppetiteField->currentText().toLower();


    //Animals Physical Attrubuites initilzation
    //,build,
    scaleType =  ui->animalPhysScaleTypeField->currentText().toLower();
    finnSize  =  ui->animalPhysFinnSizeField->currentText().toLower();
    furLength =  ui->animalPhysFurLengthField->currentText().toLower();
    furColour =  ui->animalPhysFurColourField->currentText().toLower();
    wingSpan  =  ui->animalPhysWingSpanField->currentText().toLower();
    beakLength=  ui->animalPhysBeakLengthField->currentText().toLower();
    beakColour=  ui->animalPhysBeakColourField->currentText().toLower();
    bodyPattern= ui->animalPhysBodyPatternField->currentText().toLower();
    bodyLength=  ui->animalPhysBodyLengthField->currentText().toLower();
    build =     ui->animalPhysBuildField->currentText().toLower();


    //DEBUGGING PURPOSES, nice and clean.
    qDebug ("animal name: %s",animalName.toUtf8().constData());
    qDebug ("animal colour: %s",animalColour.toUtf8().constData());
    qDebug ("animal age: %s",animalAge.toUtf8().constData());
    qDebug ("animal gender: %s",animalGender.toUtf8().constData());
    qDebug ("animal type: %s",animalType.toUtf8().constData());
    qDebug ("animal species: %s",animalSpecies.toUtf8().constData());
    qDebug ("animal Height: %s",animalHeight.toUtf8().constData());
    qDebug ("animal Weight: %s",animalWeight.toUtf8().constData());
    qDebug ("animal individualism: %s",individualism.toUtf8().constData());
    qDebug ("animal intelligence: %s",intelligence.toUtf8().constData());
    qDebug ("animal affectionism: %s",affectionism.toUtf8().constData());
    qDebug ("animal displicine: %s",displicine.toUtf8().constData());
    qDebug ("animal assertiveness: %s",assertiveness.toUtf8().constData());
    qDebug ("animal spaciousness: %s",spaciousness.toUtf8().constData());
    qDebug ("animal engerticness: %s",energy.toUtf8().constData());
    qDebug ("animal dirunal: %s",dirunal.toUtf8().constData());
    qDebug ("animal habitat prefernce: %s",habitat.toUtf8().constData());
    qDebug ("animal playfulness: %s",playfulness.toUtf8().constData());
    qDebug ("animal appetite: %s",appetite.toUtf8().constData());
    qDebug ("animal activesness: %s",activesness.toUtf8().constData());

    /*
     1. if the user doesn't fill out the forms properly then just display them an error message and return, so that the code is fast and efficent.
     2. if a user is correct the second time they re-input the data, then hide the error message
    */
    //2.
     ui->errorMessage->hide();
     ui->successMessage->hide();


    //1.
     if(animalName.isNull() || animalName.isEmpty() && animalName.length() < 3 || animalWeight.isNull() || animalWeight.isEmpty() && animalWeight.length() < 3 ||
        animalHeight.isNull() || animalHeight.isEmpty() && animalHeight.length() < 3 || ui->animalColourField->currentIndex() == 0 || ui->animalSpeciesField->currentIndex() == 0 ||
        ui->animalTypeField->currentIndex() == 0 || ui->animalAgeField->currentIndex() == 0 || ui->animalGenderField->currentIndex() == 0                      ||
        ui->animalIndividualismField->currentIndex() == 0 || ui->animalActivenessField->currentIndex() == 0 || ui->animalIntelligenceField->currentIndex() == 0||
        ui->animalAffectionismField->currentIndex() == 0 || ui->animalDisciplineField->currentIndex() == 0 || ui->animalAssertivenessField->currentIndex() == 0||
        ui->animalPlayfulnessField->currentIndex() == 0 || ui->animalSpaciousnessField->currentIndex() == 0 || ui->animalDiurnalField->currentIndex() == 0      ||
        ui->animalEnergeticField->currentIndex() == 0 || ui->animalHabitatField->currentIndex() == 0 || ui->animalAppetiteField->currentIndex() == 0         )
    {

         qDebug ("The user is stupid, and didn't follow the instructions properly.");
         ui->errorMessage->show();
         ui->successMessage->hide();
         return;
    }

     if(animalType == "dog" || animalType == "cat"){
          qDebug ("second block ?: %s", "true");
         if(ui->animalPhysFurLengthField->currentIndex() == 0 || ui->animalPhysFurColourField->currentIndex() == 0 || ui->animalPhysBuildField->currentIndex() == 0   ){
             qDebug ("The user is stupid, and didn't follow the instructions properly.");
             ui->errorMessage->show();
             ui->successMessage->hide();
             return;
         }
     }
     else if (animalType == "parrot" || animalType == "finch"){
         if(ui->animalPhysBeakColourField->currentIndex() == 0 || ui->animalPhysBeakLengthField->currentIndex() == 0 || ui->animalPhysWingSpanField->currentIndex() == 0   ){
             qDebug ("The user is stupid, and didn't follow the instructions properly.");
             ui->errorMessage->show();
             ui->successMessage->hide();
             return;
         }
     }
     else if (animalType == "frog" || animalType == "salamander"){
         if(ui->animalPhysBodyPatternField->currentIndex() == 0 || ui->animalPhysBodyLengthField->currentIndex() == 0 || ui->animalPhysBuildField->currentIndex() == 0   ){
             qDebug ("The user is stupid, and didn't follow the instructions properly.");
             ui->errorMessage->show();
             ui->successMessage->hide();
             return;
         }
     }
     else if (animalType == "snake" || animalType == "lizard"){
         if(ui->animalPhysBodyPatternField->currentIndex() == 0 || ui->animalPhysBodyLengthField->currentIndex() == 0 || ui->animalPhysScaleTypeField->currentIndex() == 0   ){
             qDebug ("The user is stupid, and didn't follow the instructions properly.");
             ui->errorMessage->show();
             ui->successMessage->hide();
             return;
         }
     }
     else if (animalType == "betta" || animalType == "goldfish"){
         if(ui->animalPhysBodyPatternField->currentIndex() == 0 || ui->animalPhysBodyLengthField->currentIndex() == 0 || ui->animalPhysFinnSizeField->currentIndex() == 0   ){
             qDebug ("The user is stupid, and didn't follow the instructions properly.");
             ui->errorMessage->show();
             ui->successMessage->hide();
             return;
         }
     }



    /*
     1.Empty the fields so its a nice UI and simple to use.
     2. Add the data to a List
     3. Once added to a list, call a method update list.
    */

    //1.
     clearFields(0);

    //2.
     //populate the newAnimlaInfo vector to send to the AnimalCareShelter that will use it to make a new animal

     //the 0-th index is always the animal type. used to differentiate whci type of clas to create
     newAnimalInfo.push_back(animalType.toUtf8().constData());

     //for the constructor: the name and the species
     newAnimalInfo.push_back(animalName.toUtf8().constData());
     newAnimalInfo.push_back(animalSpecies.toUtf8().constData());



     //Animal* currentAnimalBeingAdded;
     //animalType is specifying to indicate for animal constructor which type of animal to add.
     if(animalType == "dog" || animalType == "cat"){
        /*currentAnimalBeingAdded = new Mammal(animalName.toUtf8().constData(),animalSpecies.toUtf8().constData());
        currentAnimalBeingAdded->setPhysCharacteristics(build.toUtf8().constData(),furLength.toUtf8().constData(),furColour.toUtf8().constData());*/

        newAnimalInfo.push_back(build.toUtf8().constData());
        newAnimalInfo.push_back(furLength.toUtf8().constData());
        newAnimalInfo.push_back(furColour.toUtf8().constData());

     }
     else if(animalType == "snake" || animalType == "lizard"){
        /*currentAnimalBeingAdded = new Reptile(animalName.toUtf8().constData(),animalSpecies.toUtf8().constData());
        currentAnimalBeingAdded->setPhysCharacteristics(bodyLength.toUtf8().constData(),bodyPattern.toUtf8().constData(),scaleType.toUtf8().constData());*/

        newAnimalInfo.push_back(bodyLength.toUtf8().constData());
        newAnimalInfo.push_back(bodyPattern.toUtf8().constData());
        newAnimalInfo.push_back(scaleType.toUtf8().constData());
     }
     else if(animalType == "finch" || animalType == "parrot"){
        /*currentAnimalBeingAdded = new Bird(animalName.toUtf8().constData(),animalSpecies.toUtf8().constData());
        currentAnimalBeingAdded->setPhysCharacteristics(wingSpan.toUtf8().constData(),beakLength.toUtf8().constData(),beakColour.toUtf8().constData());*/

        newAnimalInfo.push_back(wingSpan.toUtf8().constData());
        newAnimalInfo.push_back(beakLength.toUtf8().constData());
        newAnimalInfo.push_back(beakColour.toUtf8().constData());
     }
     else if(animalType == "betta" || animalType == "goldfish"){
        /*currentAnimalBeingAdded= new Fish(animalName.toUtf8().constData(),animalSpecies.toUtf8().constData());
        currentAnimalBeingAdded->setPhysCharacteristics(bodyPattern.toUtf8().constData(),bodyLength.toUtf8().constData(),finnSize.toUtf8().constData());*/

        newAnimalInfo.push_back(bodyPattern.toUtf8().constData());
        newAnimalInfo.push_back(bodyLength.toUtf8().constData());
         newAnimalInfo.push_back(finnSize.toUtf8().constData());

     }
     else if(animalType == "frog" || animalType == "salamander"){
        /*currentAnimalBeingAdded = new Amphibian(animalName.toUtf8().constData(),animalSpecies.toUtf8().constData());
        currentAnimalBeingAdded->setPhysCharacteristics(bodyPattern.toUtf8().constData(),bodyLength.toUtf8().constData(),build.toUtf8().constData());*/

         newAnimalInfo.push_back(bodyPattern.toUtf8().constData());
         newAnimalInfo.push_back(bodyLength.toUtf8().constData());
         newAnimalInfo.push_back(build.toUtf8().constData());
     }

     //Age,gender,colour,height,weight,typeOfAnimal
     /* currentAnimalBeingAdded->setBasicInfo(animalAge.toUtf8().constData(),animalGender.toUtf8().constData(),animalColour.toUtf8().constData(),
                                            animalHeight.toUtf8().constData(),animalWeight.toUtf8().constData(),animalType.toUtf8().constData());*/

       //the basic info of the animal
       newAnimalInfo.push_back(animalAge.toUtf8().constData());
       newAnimalInfo.push_back(animalGender.toUtf8().constData());
       newAnimalInfo.push_back(animalColour.toUtf8().constData());
       newAnimalInfo.push_back(animalHeight.toUtf8().constData());
       newAnimalInfo.push_back(animalWeight.toUtf8().constData());
       newAnimalInfo.push_back(animalType.toUtf8().constData());


      /*currentAnimalBeingAdded->setNonPhysicalAttributes(activesness.toUtf8().constData(),playfulness.toUtf8().constData(),individualism.toUtf8().constData(),affectionism.toUtf8().constData(),intelligence.toUtf8().constData()
                                                              ,displicine.toUtf8().constData(),assertiveness.toUtf8().constData(),spaciousness.toUtf8().constData(),energy.toUtf8().constData(),dirunal.toUtf8().constData(),habitat.toUtf8().constData(),appetite.toUtf8().constData());*/


         newAnimalInfo.push_back(activesness.toUtf8().constData());
         newAnimalInfo.push_back(playfulness.toUtf8().constData());
         newAnimalInfo.push_back(individualism.toUtf8().constData());
         newAnimalInfo.push_back(affectionism.toUtf8().constData());
         newAnimalInfo.push_back(intelligence.toUtf8().constData());
         newAnimalInfo.push_back(displicine.toUtf8().constData());
         newAnimalInfo.push_back(assertiveness.toUtf8().constData());
         newAnimalInfo.push_back(spaciousness.toUtf8().constData());
         newAnimalInfo.push_back(energy.toUtf8().constData());
         newAnimalInfo.push_back(dirunal.toUtf8().constData());
         newAnimalInfo.push_back(habitat.toUtf8().constData());
         newAnimalInfo.push_back(appetite.toUtf8().constData());



      //currentAnimalBeingAdded->setNewAnimal(true);

      //animalsClientsList.animals.add(&currentAnimalBeingAdded);
//      animalsClientsList.animals.print();

        //send the request to the animalCareShelter (the factory)

         int size = animalsClientsList.animals.size();
        animalsClientsList.setPreviousIDForAnimal(animalsClientsList.animals.get(size - 1)->getAnimalID());
        animalsClientsList.makeNewAnimal(newAnimalInfo);

        //clear the vector for the next time
        newAnimalInfo.clear();


      ui->animalForm->setCurrentIndex(0); // Reset the flow of adding an animal.
      ui->successMessage->show(); // Show success





}


/*
    *This function adds a client to the viewClientsList.
*/
void MainWindow::on_saveClientBtn_clicked()
{

    //Clients Basic info decleration.
    QString clientFName, clientLName, clientAge, clientEmail, clientGender, clientPhone;

    //Clients Non-Phys Attrubuites decleration
    QString habitat, activesness ,affectionism,dirunal;


    //Clients Non-Phys Preferences for an animal decleration

    //Clients Basic info init.
    clientFName = ui->clientFNameField->toPlainText().trimmed().toLower();
    clientLName =  ui->clientLNameField->toPlainText().trimmed().toLower();
    clientAge =  ui->clientAgeField->toPlainText().trimmed().toLower();
    clientEmail = ui->clientEmailField->toPlainText().trimmed().toLower();
    clientPhone = ui->clientPhoneField->toPlainText().trimmed().toLower();
    clientGender = ui->clientGenderFIeld->currentText().toLower();


    //Clients Non-Phys Attrubuites(CharacterTraits) init.
    habitat = ui->clientHabitatPreferenceField->currentText().toLower();
    activesness = ui->clientActivenessField->currentText().toLower();
    affectionism = ui->clientAffectionismField->currentText().toLower();
    dirunal  = ui->clientDiurnalField->currentText().toLower();


    //Clients Non-Phys Preferneces for an animal(Character Traicts) init
    habitat = ui->clientHabitatPreferenceField->currentText().toLower();
    activesness = ui->clientActivenessField->currentText().toLower();
    affectionism = ui->clientAffectionismField->currentText().toLower();
    dirunal  = ui->clientDiurnalField->currentText().toLower();







    //Debugging purposes, just a nice way to see the names as inputed(from user ofc.)
    qDebug ("Client Fname: %s",clientFName.toUtf8().constData());
    qDebug ("Client Lname: %s",clientLName.toUtf8().constData());
    qDebug ("Client age: %s",clientAge.toUtf8().constData());
    qDebug ("Client email: %s",clientEmail.toUtf8().constData());
    qDebug ("Client phone: %s",clientPhone.toUtf8().constData());
    qDebug ("Client gender: %s",clientGender.toUtf8().constData());

    qDebug ("Client affectionism: %s",affectionism.toUtf8().constData());
    qDebug ("Client Habitat Preference: %s",habitat.toUtf8().constData());
    qDebug ("Client dirunal: %s",dirunal.toUtf8().constData());
    qDebug ("Client activesness: %s",activesness.toUtf8().constData());


    //Hide error and succsess mesages.
    ui->clientErrMessage->hide();
    ui->clientSucessMessage->hide();

    //Check if fields are empty, or not all fullied yet. Note also I'm checking if they're empty or deafult selects, if they are true display message error and return to stop func execution.
    if(clientFName.isNull() || clientFName.isEmpty() && clientFName.length() < 3 || clientLName.isNull() || clientLName.isEmpty() && clientLName.length() < 3 ||
       clientPhone.isNull() || clientPhone.isEmpty() && clientPhone.length() < 3 || clientEmail.isNull() || clientEmail.isEmpty() && clientEmail.length() < 3 ||
       clientGender.isNull() || clientGender.isEmpty() && clientGender.length() < 3 || clientAge.isNull() || clientAge.isEmpty() && clientAge.length() < 1    ||
       ui->clientHabitatPreferenceField->currentIndex() == 0 || ui->clientActivenessField->currentIndex() == 0 || ui->clientDiurnalField->currentIndex() == 0 ||
       ui->clientAffectionismField->currentIndex() == 0 || ui->clientNonPhysPreAppetiField->currentIndex() == 0 ||ui->clientNonPhysPreAssertField->currentIndex() == 0 ||
       ui->clientNonPhysPreDiscipField->currentIndex() == 0 || ui->clientNonPhysPreEnergeticField->currentIndex() == 0 || ui->clientNonPhysPreIndividField->currentIndex() == 0 ||
       ui->clientNonPhysPreIntelliField->currentIndex() == 0 || ui->clientNonPhysPrePlayfulField->currentIndex() == 0 || ui->clientNonPhysPreSpaciousField->currentIndex() == 0 )
    {

        //Code for the "if condition" above, starts here.

        qDebug ("The user is stupid, and didn't follow the instructions properly.");
        ui->clientErrMessage->show();
        ui->clientSucessMessage->hide();
        return;

    }

    /*
     1.Empty the fields so its a nice UI and simple to use.
     2. Add the client to a linkedList
     3. Once added to a list, call a method update list.
    */

    //1.
     clearFields(1); //important the value 1 here specifies which fields to clear


    //2.
    Client* currentClientBeingAdded = new Client(clientFName.toUtf8().constData(),clientLName.toUtf8().constData(),clientAge.toUtf8().constData(),clientEmail.toUtf8().constData(),clientPhone.toUtf8().constData(),clientGender.toUtf8().constData());
    currentClientBeingAdded->setCharacterTraits(activesness.toUtf8().constData(),affectionism.toUtf8().constData(),dirunal.toUtf8().constData(),habitat.toUtf8().constData());
    currentClientBeingAdded->setNonPhysPreferences(ui->clientNonPhysPreIndividField->currentText().toLower().toUtf8().constData(),ui->clientNonPhysPreIntelliField->currentText().toLower().toUtf8().constData(),
                                                   ui->clientNonPhysPreDiscipField->currentText().toLower().toUtf8().constData(), ui->clientNonPhysPreAssertField->currentText().toLower().toUtf8().constData(),
                                                   ui->clientNonPhysPrePlayfulField->currentText().toLower().toUtf8().constData(),ui->clientNonPhysPreEnergeticField->currentText().toLower().toUtf8().constData(),
                                                   ui->clientNonPhysPreSpaciousField->currentText().toLower().toUtf8().constData(),ui->clientNonPhysPreAppetiField->currentText().toLower().toUtf8().constData());
    currentClientBeingAdded->setNewClient(true); //add a new client <-------------- Important!

    //Fish
    Animal* betta = new Fish("betta","betta");
    betta->setType("betta");
    Animal* goldfish = new Fish("goldfish","goldfish");
    goldfish->setType("goldfish");

    //Mammals
    Animal* cat = new Mammal("cat","cat");
    cat->setType("cat");
    Animal* dog = new Mammal("dog","dog");
    dog->setType("dog");

    //Reptiles
    Animal* snake = new Reptile("snake","snake");
    snake->setType("snake");
    Animal* lizard = new Reptile("lizard","lizard");
    lizard->setType("lizard");

    //Amphibians
    Animal* frog = new Amphibian("frog","frog");
    frog->setType("frog");
    Animal* salamander = new Amphibian("salamander","salamander");
    salamander->setType("salamander");


    //Birds
    Animal* finch = new Bird("finch","finch");
    finch->setType("finch");
    Animal* parrot = new Bird("parrot","parrot");
    parrot->setType("parrot");



    currentClientBeingAdded->ranks.add(&betta);
    currentClientBeingAdded->ranks.add(&goldfish);
    currentClientBeingAdded->ranks.add(&cat);
    currentClientBeingAdded->ranks.add(&dog);
    currentClientBeingAdded->ranks.add(&snake);
    currentClientBeingAdded->ranks.add(&lizard);
    currentClientBeingAdded->ranks.add(&frog);
    currentClientBeingAdded->ranks.add(&salamander);
    currentClientBeingAdded->ranks.add(&finch);
    currentClientBeingAdded->ranks.add(&parrot);


    if (currentClientBeingAdded->getNewClient() == false){
           currentClientBeingAdded->setNewClient(true);
       }

    int size = animalsClientsList.clients.size();
    animalsClientsList.setPreviousIDClient(animalsClientsList.clients.get(size - 1)->getClientId());
    currentClientBeingAdded->incramentID(animalsClientsList.getPreviousIDClient());

    cout << "ID FOR CLIENT IS: " <<  currentClientBeingAdded->getClientId() << endl;

    animalsClientsList.clients.add(&currentClientBeingAdded);
    animalsClientsList.clients.print();




    ui->clientForm->setCurrentIndex(1); // Reset the flow of adding a client.
    ui->clientSucessMessage->show(); // Show success
}


/*
    * This function updates the animal list in order to keep the app updated(its from the Staff's view).
*/
void MainWindow::updateAnimalListUI(){


    //Clear List and update after.
    ui->animalsListTable->clear();

    //Size of animals
    int size = animalsClientsList.animals.size();

    int row =0; //Increment row so adding to the next element(in table) is easier.  - - - -  <----- first column and  first  row
    //                                                                              - - - -  <----- second column and second row thats what  i mean, you're adding by columns then rows.

    //Setting size of row for the table(based on animals)
    ui->animalsListTable->setRowCount(animalsClientsList.animals.size());
    for(int i= 0;i<size; i++){

        QTableWidgetItem *animalNameTable = new QTableWidgetItem();
        QTableWidgetItem *animalTypeTable = new QTableWidgetItem();
        QTableWidgetItem *animalSpeciesTable = new QTableWidgetItem();
        QTableWidgetItem *animalColourTable = new QTableWidgetItem();
        QTableWidgetItem *animalAgeTable = new QTableWidgetItem();
        QTableWidgetItem *animalGenderTable = new QTableWidgetItem();

        //Convert Strings to QStrings
        animalNameTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getName()));
        animalTypeTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getType()));
        animalSpeciesTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getSpecies()));
        animalColourTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getColour()));
        animalAgeTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getAge()));
        animalGenderTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getGender()));

        ui->animalsListTable->setItem(row,0,animalNameTable);
        ui->animalsListTable->setItem(row,1,animalTypeTable);
        ui->animalsListTable->setItem(row,2,animalSpeciesTable);
        ui->animalsListTable->setItem(row,3,animalColourTable);
        ui->animalsListTable->setItem(row,4,animalAgeTable);
        ui->animalsListTable->setItem(row,5,animalGenderTable);

        row++;
    }
    ui->animalsListTable->setHorizontalHeaderLabels(QStringList() << "Name" << "Type" << "Species" << "Colour" << "Age" << "Gender");






}

/*
    * This function updates the list UI in order to keep the app updated.
*/
void MainWindow::initClientList(){

    //Clear List and update after.
    ui->clientListTable->clear();

    //Size of clients
    int size = animalsClientsList.clients.size();

    int row =0; //Increment row so adding to the next element(in table) is easier.  - - - -  <----- first column and  first  row
    //                                                                              - - - -  <----- second column and second row thats what  i mean, you're adding by columns then rows.

    //Setting size of row for the table(based on clients)
    ui->clientListTable->setRowCount(animalsClientsList.clients.size());
    for(int i= 0;i<size; i++){

        QTableWidgetItem *clientFNameTable = new QTableWidgetItem();
        QTableWidgetItem *clientLNameTable = new QTableWidgetItem();
        QTableWidgetItem *clientEmailTable = new QTableWidgetItem();
        QTableWidgetItem *clientPhoneTable = new QTableWidgetItem();
        QTableWidgetItem *clientAgeTable = new QTableWidgetItem();
        QTableWidgetItem *clientGenderTable = new QTableWidgetItem();

        //Convert Strings to QStrings
        clientFNameTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getFirstName()));
        clientLNameTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getLastName()));
        clientEmailTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getEmail()));
        clientPhoneTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getPhoneNumber()));
        clientAgeTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getAge()));
        clientGenderTable->setText(QString::fromStdString(animalsClientsList.clients.get(i)->getGender()));

        ui->clientListTable->setItem(row,0,clientFNameTable);
        ui->clientListTable->setItem(row,1,clientLNameTable);
        ui->clientListTable->setItem(row,2,clientPhoneTable);
        ui->clientListTable->setItem(row,3,clientEmailTable);
        ui->clientListTable->setItem(row,4,clientAgeTable);
        ui->clientListTable->setItem(row,5,clientGenderTable);

        row++;
    }
    ui->clientListTable->setHorizontalHeaderLabels(QStringList() << "First Name" << "Last Name" << "Phone Number" << "Email Address" << "Age" << "Gender");

}

/*
    *This function shows the animals  detailed profile(from staff View)
*/
void MainWindow::displayAnimalDetails(){

    //Animal Basic info
    ui->animalNameDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getName()));
    ui->animalTypeDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getType()));
    ui->animalSpeciesDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getSpecies()));
    ui->animalColourDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getColour()));
    ui->animalAgeDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAge()));
    ui->animalGenderDetail->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getGender()));

    //Animal Non-Physcial Attrubites.
    ui->animalNonPhysicalAttr1->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getIndividualism()));
    ui->animalNonPhysicalAttr2->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getActiveness()));
    ui->animalNonPhysicalAttr3->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getIntelligence()));
    ui->animalNonPhysicalAttr4->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAffectionism()));
    ui->animalNonPhysicalAttr5->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getDiscipline()));
    ui->animalNonPhysicalAttr6->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAssertiveness()));
    ui->animalNonPhysicalAttr7->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getSpaciousness()));
    ui->animalNonPhysicalAttr8->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getEnergetic()));
    ui->animalNonPhysicalAttr9->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getDiurnalNocturnal()));
    ui->animalNonPhysicalAttr10->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getHabitatPreference()));
    ui->animalNonPhysicalAttr11->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getPlayfulness()));
    ui->animalNonPhysicalAttr12->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAppetite()));

    //Animal Physical Attributes below here after checking which animal type it is.
    //Mammals
    if(animalsClientsList.animals.get(rowTable)->getType() == "dog" || animalsClientsList.animals.get(rowTable)->getType() == "cat"){
        ui->animalAttributeOneField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBuild())); //check mark
        ui->animalAttributeTwoField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getMammalHairLength())); //check mark
        ui->animalAttributeThreeField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getMammalHairColour())); //Check mark
        //Show labels
        ui->buildLabel->show();
        ui->furColourLabel->show();
        ui->furLengthLabel->show();

        //Hide Labels not related.
        ui->bodyLengthLabel->hide();
        ui->finnsizeLabel->hide();
        ui->scaleTypeLabel->hide();
        ui->beakColourLabel->hide();
        ui->beakLengthLabel->hide();
        ui->wingSpanLabel->hide();
        ui->bodyPatternLabel->hide();
    }
    //End of Mammals

    //Birds
    else if(animalsClientsList.animals.get(rowTable)->getType() == "parrot" || animalsClientsList.animals.get(rowTable)->getType() == "finch"){

        ui->animalAttributeOneField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBeakLength())); // Check Mark
        ui->animalAttributeTwoField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getWingSpan())); //Check Mark
        ui->animalAttributeThreeField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBeakColour())); //Check Mark

        //Show labels
        ui->beakColourLabel->show();
        ui->beakLengthLabel->show();
        ui->wingSpanLabel->show();

        //Hide Labels not related.
        ui->finnsizeLabel->hide();
        ui->scaleTypeLabel->hide();
        ui->bodyPatternLabel->hide();
        ui->buildLabel->hide();
        ui->furColourLabel->hide();
        ui->furLengthLabel->hide();
        ui->bodyLengthLabel->hide();
    }
    //End of Birds

    //Amphibians
    else if(animalsClientsList.animals.get(rowTable)->getType() == "frog" || animalsClientsList.animals.get(rowTable)->getType() == "salamander"){

         ui->animalAttributeOneField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBuild())); //Check Mark
         ui->animalAttributeTwoField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); //Check Mark
         ui->animalAttributeThreeField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); //Check Mark

         //Show labels
         ui->buildLabel->show();
         ui->bodyPatternLabel->show();
         ui->bodyLengthLabel->show();


         //Hide Labels not related.
         ui->finnsizeLabel->hide();
         ui->scaleTypeLabel->hide();
         ui->wingSpanLabel->hide();
         ui->furColourLabel->hide();
         ui->furLengthLabel->hide();
         ui->beakColourLabel->hide();
         ui->beakLengthLabel->hide();

    }

    //Reptiles
    else if(animalsClientsList.animals.get(rowTable)->getType() == "snake" || animalsClientsList.animals.get(rowTable)->getType() == "lizard"){

         ui->animalAttributeOneField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getScaleType())); // Check mark
         ui->animalAttributeTwoField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); // check mark
         ui->animalAttributeThreeField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); // check mark


         //Show labels
         ui->scaleTypeLabel->show();
         ui->bodyPatternLabel->show();
         ui->bodyLengthLabel->show();


         //Hide Labels not related.
         ui->finnsizeLabel->hide();
         ui->buildLabel->hide();
         ui->wingSpanLabel->hide();
         ui->furColourLabel->hide();
         ui->furLengthLabel->hide();
         ui->beakColourLabel->hide();
         ui->beakLengthLabel->hide();


    }
    //End of Reptiles

    //Fish
    else if(animalsClientsList.animals.get(rowTable)->getType() == "betta" || animalsClientsList.animals.get(rowTable)->getType() == "goldfish"){

         ui->animalAttributeOneField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getFinnsSize())); //check mark
         ui->animalAttributeTwoField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); // check mark
         ui->animalAttributeThreeField->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); // check mark

         //Show labels
         ui->finnsizeLabel->show();
         ui->bodyPatternLabel->show();
         ui->bodyLengthLabel->show();


         //Hide Labels not related.
         ui->scaleTypeLabel->hide();
         ui->buildLabel->hide();
         ui->wingSpanLabel->hide();
         ui->furColourLabel->hide();
         ui->furLengthLabel->hide();
         ui->beakColourLabel->hide();
         ui->beakLengthLabel->hide();

    }
    //End of Fish
}


//Display details of a client.
void MainWindow::displayClientDetails(){

    //Client Basic info
    ui->clientFNameDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getFirstName()));
    ui->clientLNameDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getLastName()));
    ui->clientPhoneNumberField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getPhoneNumber()));
    ui->clientEmailAddressDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getEmail()));
    ui->clientAgeDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getAge()));
    ui->clientGenderDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getGender()));

    //Client Non-Phys Attriubtes.
    ui->clientHabitatPreferenceDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getClientHabitaPreference()));
    ui->clientActivenessDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getClientActiveness()));
    ui->clientNocturnalDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getClientDiurnalNocturnal()));
    ui->clientAffectionismDetailsField->setText(QString::fromStdString(animalsClientsList.clients.get(rowTable)->getClientAffectionism()));

}


/*
 * This function enables editing for a staff to change an animal's info.
*/
void MainWindow::enableAnimalEdits(bool isEnabled){


    if(isEnabled == true){
        //Enable Edits for Animal Basic info
        ui->animalNameDetail->setReadOnly(false);
        ui->animalSpeciesDetail->setReadOnly(true);
        ui->animalTypeDetail->setReadOnly(true);
        ui->animalColourDetail->setReadOnly(false);
        ui->animalAgeDetail->setReadOnly(false);
        ui->animalGenderDetail->setReadOnly(false);


        //Enable Edits for Non-Physical Attributes
        ui->animalNonPhysicalAttr1->setReadOnly(false);
        ui->animalNonPhysicalAttr2->setReadOnly(false);
        ui->animalNonPhysicalAttr3->setReadOnly(false);
        ui->animalNonPhysicalAttr4->setReadOnly(false);
        ui->animalNonPhysicalAttr5->setReadOnly(false);
        ui->animalNonPhysicalAttr6->setReadOnly(false);
        ui->animalNonPhysicalAttr7->setReadOnly(false);
        ui->animalNonPhysicalAttr7->setReadOnly(false);
        ui->animalNonPhysicalAttr8->setReadOnly(false);
        ui->animalNonPhysicalAttr9->setReadOnly(false);
        ui->animalNonPhysicalAttr10->setReadOnly(false);
        ui->animalNonPhysicalAttr11->setReadOnly(false);
        ui->animalNonPhysicalAttr12->setReadOnly(false);


        //Enable edits for Physical Attributes
        ui->animalAttributeOneField->setReadOnly(false);
        ui->animalAttributeTwoField->setReadOnly(false);
        ui->animalAttributeThreeField->setReadOnly(false);

        //Unable Item
        ui->animalSpeciesDetail->setEnabled(false);
        ui->animalTypeDetail->setEnabled(false);
    }
    else{
        //Disable Edits for Animal Basic info
        ui->animalNameDetail->setReadOnly(true);
        ui->animalSpeciesDetail->setReadOnly(true);
        ui->animalTypeDetail->setReadOnly(true);
        ui->animalColourDetail->setReadOnly(true);
        ui->animalAgeDetail->setReadOnly(true);
        ui->animalGenderDetail->setReadOnly(true);


        //Disable Edits for Non-Physical Attributes
        ui->animalNonPhysicalAttr1->setReadOnly(true);
        ui->animalNonPhysicalAttr2->setReadOnly(true);
        ui->animalNonPhysicalAttr3->setReadOnly(true);
        ui->animalNonPhysicalAttr4->setReadOnly(true);
        ui->animalNonPhysicalAttr5->setReadOnly(true);
        ui->animalNonPhysicalAttr6->setReadOnly(true);
        ui->animalNonPhysicalAttr7->setReadOnly(true);
        ui->animalNonPhysicalAttr7->setReadOnly(true);
        ui->animalNonPhysicalAttr8->setReadOnly(true);
        ui->animalNonPhysicalAttr9->setReadOnly(true);
        ui->animalNonPhysicalAttr10->setReadOnly(true);
        ui->animalNonPhysicalAttr11->setReadOnly(true);
        ui->animalNonPhysicalAttr12->setReadOnly(true);


        //Disable edits for Physical Attributes
        ui->animalAttributeOneField->setReadOnly(true);
        ui->animalAttributeTwoField->setReadOnly(true);
        ui->animalAttributeThreeField->setReadOnly(true);


        //Enable item

        ui->animalSpeciesDetail->setEnabled(true);
        ui->animalTypeDetail->setEnabled(true);
    }

}


/*
 *  This function will dynamiallcy render species and physical Attributes based on the the current animal Selected
 */
void MainWindow::renderSpeciesAndPhysAttributes(){


    //foodis

    //Render species
    if(ui->animalTypeDetail->text() == "cat"){

        QStringList list=(QStringList()<<"Select the type of species" <<"Persian Cat"<<"Ragdoll"<<"Bengal Cat" << "Birman" <<"American Curl" <<"Savannah Cat");

        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);

    }
    if(ui->animalTypeDetail->text() == "dog"){

          QStringList list=(QStringList()<<"Select the type of species" <<"Pitbull"<<"Siberian Husky"<<"Bulldog" << "German Shepherd" <<"Boxer" <<"Pug");
          speciesOptions = new QCompleter(list,this);
          speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
          ui->animalSpeciesDetail->setCompleter(speciesOptions);
    }
    if(ui->animalTypeDetail->text() == "parrot"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Grey Parrot"<<"Cockatiel"<<"Budgerigar" << "Sun Conure" <<"Kea" <<"Night Parrot");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);
    }
    if(ui->animalTypeDetail->text() == "finch"){
        QStringList list=(QStringList()<<"Select the type of species" <<"House Finch"<<"Purple Finch"<<"Zebra Finch" << "American Goldfinch" <<"Java Sparrow" <<"Red Crossbill");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);

    }
    if(ui->animalTypeDetail->text() == "frog"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Tailed Frog"<<"Toads"<<"Tree Frogs" << "Western Toad" <<"American Toad" <<"Fowler's toad" << "Oophaga" << "Spring peeper");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);
    }
    if(ui->animalTypeDetail->text() == "salamander"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Fire Salamander"<<"Hellbender"<<"Tiger Salamander" << "Spotted Salamander" <<"Red Salamander" <<"Alpine Salamander" << "Spring Salamander" << "Marbled Salamander");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);

    }
    if(ui->animalTypeDetail->text() == "betta"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Veiltail"<<"Crowntail"<<"Combtail" << "Double tail" <<"Spadetail" <<"Halfmoon" << "Delta" << "Super Delta" << "Rosetail");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);
    }
    if(ui->animalTypeDetail->text() == "goldfish"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Comet"<<"Fantail"<<"Lionhead" << "Oranda" <<"Ryukin" <<"Bubble Eye" << "Shubunkin" << "Black Moor");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);

    }
    if(ui->animalTypeDetail->text() == "snake"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Garter Snake"<<"Rattlesnakes"<<"Water Snakes" << "Kingsnakes" <<"Milk Snake" <<"Pythons" << "King Cobra" << "Boa constrictor" << "Ball Python");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);
    }
    if(ui->animalTypeDetail->text() == "lizard"){
        QStringList list=(QStringList()<<"Select the type of species" <<"Gold Tegu"<<"Green Anole"<<"Gila Monster" << "Green Iguana" <<"Desert Iguana" <<"Brown Anole" << "Sand Lizard" << "Marine Iguana" << "Nile Monitor");
        speciesOptions = new QCompleter(list,this);
        speciesOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->animalSpeciesDetail->setCompleter(speciesOptions);

    }

    //lazm

    //Render physical attrubites
     if(ui->animalTypeDetail->text() == "dog" || ui->animalTypeDetail->text() == "cat" ){

          buildList=(QStringList()<<"1 (thin)" << "2 (average)" << "3 (bulky)");
          furLengthList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");
          furColourList=(QStringList()<<"1 (dark brown)" << "2 (light brown)" << "3 (blonde)" << "4 (white)" << "5 (polka dot)");

         physFieldOne = new QCompleter(buildList,this);
         physFieldOne->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeOneField->setCompleter(physFieldOne);

         physFieldTwo = new QCompleter(furLengthList,this);
         physFieldTwo->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeTwoField->setCompleter(physFieldTwo);

         physFieldThree = new QCompleter(furColourList,this);
         physFieldThree->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeThreeField->setCompleter(physFieldThree);


     }
     else if(ui->animalTypeDetail->text() == "parrot" || ui->animalTypeDetail->text() == "finch" ){

          beakLengthList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");
          wingSpanList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");
          beakColourList=(QStringList()<<"1 (red)" << "2 (orange)" << "3 (yellow)" << "4 (black)" << "5 (blue)" << "6 (mixed)");






         physFieldOne = new QCompleter(beakLengthList,this);
         physFieldOne->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeOneField->setCompleter(physFieldOne);

         physFieldTwo = new QCompleter(wingSpanList,this);
         physFieldTwo->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeTwoField->setCompleter(physFieldTwo);

         physFieldThree = new QCompleter(beakColourList,this);
         physFieldThree->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeThreeField->setCompleter(physFieldThree);

     }
     else if(ui->animalTypeDetail->text() == "betta" || ui->animalTypeDetail->text() == "goldfish" ){

          finnSizeList=(QStringList()<<"1 (short)"  << "2 (medium)" << "3 (long)");
          bodyPatternList=(QStringList()<<"1 (dotted pattern)" << "2 (striped)");
          bodyLengthList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");


         physFieldOne = new QCompleter(finnSizeList,this);
         physFieldOne->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeOneField->setCompleter(physFieldOne);

         physFieldTwo = new QCompleter(bodyPatternList,this);
         physFieldTwo->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeTwoField->setCompleter(physFieldTwo);

         physFieldThree = new QCompleter(bodyPatternList,this);
         physFieldThree->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeThreeField->setCompleter(physFieldThree);
     }
     else if(ui->animalTypeDetail->text() == "frog" || ui->animalTypeDetail->text() == "salamander" ){



         buildList=(QStringList()<<"1 (thin)" << "2 (average)" << "3 (bulky)");
         bodyPatternList=(QStringList()<<"1 (dotted pattern)" << "2 (striped)");
         bodyLengthList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");

         physFieldOne = new QCompleter(buildList,this);
         physFieldOne->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeOneField->setCompleter(physFieldOne);

         physFieldTwo = new QCompleter(bodyPatternList,this);
         physFieldTwo->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeTwoField->setCompleter(physFieldTwo);

         physFieldThree = new QCompleter(bodyLengthList,this);
         physFieldThree->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeThreeField->setCompleter(physFieldThree);
     }
     else if(ui->animalTypeDetail->text() == "snake" || ui->animalTypeDetail->text() == "lizard" ){
         scaleList=(QStringList()<<"1 (smooth)" << "2 (jagged)");
         bodyPatternList=(QStringList()<<"1 (dotted pattern)" << "2 (striped)");
         bodyLengthList=(QStringList()<<"1 (short)" << "2 (medium)" << "3 (long)");

         physFieldOne = new QCompleter(scaleList,this);
         physFieldOne->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeOneField->setCompleter(physFieldOne);

         physFieldTwo = new QCompleter(bodyPatternList,this);
         physFieldTwo->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeTwoField->setCompleter(physFieldTwo);

         physFieldThree = new QCompleter(bodyLengthList,this);
         physFieldThree->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
         ui->animalAttributeThreeField->setCompleter(physFieldThree);




     }

}


void MainWindow::saveNewEdits(){



    //EROR CHECKING FOR EDITING

    //Checking for if all fields are empty or a field is empty.
    if(ui->animalNameDetail->toPlainText().trimmed().isEmpty() == true   || ui->animalColourDetail->text().trimmed().isEmpty() == true     || ui->animalAgeDetail->text().trimmed().isEmpty() == true                     ||
       ui->animalGenderDetail->text().trimmed().isEmpty() == true        || ui->animalAttributeOneField->text().trimmed().isEmpty() == true       || ui->animalAttributeTwoField->text().trimmed().isEmpty() == true      ||
       ui->animalAttributeThreeField->text().trimmed().isEmpty() == true || ui->animalNonPhysicalAttr1->text().trimmed().isEmpty() == true || ui->animalNonPhysicalAttr2->text().trimmed().isEmpty() == true              ||
       ui->animalNonPhysicalAttr3->text().trimmed().isEmpty() == true    || ui->animalNonPhysicalAttr4->text().trimmed().isEmpty() == true || ui->animalNonPhysicalAttr5->text().trimmed().isEmpty() == true              ||
       ui->animalNonPhysicalAttr6->text().trimmed().isEmpty() == true    || ui->animalNonPhysicalAttr7->text().trimmed().isEmpty() == true || ui->animalNonPhysicalAttr8->text().trimmed().isEmpty() == true              ||
       ui->animalNonPhysicalAttr9->text().trimmed().isEmpty() == true    || ui->animalNonPhysicalAttr10->text().trimmed().isEmpty() == true|| ui->animalNonPhysicalAttr11->text().trimmed().isEmpty() == true             ||
       ui->animalNonPhysicalAttr12->text().trimmed().isEmpty() == true )
    {
        qDebug ("User left fields empty!");


        QMessageBox::critical(this,"Editing Animal Error 0029XF4", "You didn't fill out the information properly, make sure to leave no empty field, and enter only information from the autocompleter");
        return;

    }


    //Checking for values if they're in range in the QCompleter. this is for  basic info and non-phsyical information.
    if(!coloursList.contains(ui->animalColourDetail->text().trimmed().toLower()) || !ageList.contains(ui->animalAgeDetail->text().trimmed().toLower()) || !genderList.contains(ui->animalGenderDetail->text().trimmed().toLower()) ||
       !invidulaismList.contains(ui->animalNonPhysicalAttr1->text().trimmed().toLower())  || !activenessList.contains(ui->animalNonPhysicalAttr2->text().trimmed().toLower()) || !intelligenceList.contains(ui->animalNonPhysicalAttr3->text().trimmed().toLower()) ||
       !affectionatismList.contains(ui->animalNonPhysicalAttr4->text().trimmed().toLower()) || !disciplinedList.contains(ui->animalNonPhysicalAttr5->text().trimmed().toLower()) || !assertiveList.contains(ui->animalNonPhysicalAttr6->text().trimmed().toLower()) ||
       !spaciousList.contains(ui->animalNonPhysicalAttr7->text().trimmed().toLower()) || !energeticList.contains(ui->animalNonPhysicalAttr8->text().trimmed().toLower()) || !nocturnalList.contains(ui->animalNonPhysicalAttr9->text().trimmed().toLower())         ||
       !habitatList.contains(ui->animalNonPhysicalAttr10->text().trimmed().toLower()) || !playfullnessList.contains(ui->animalNonPhysicalAttr11->text().trimmed().toLower()) || !appetiteList.contains(ui->animalNonPhysicalAttr12->text().trimmed().toLower())     ){

        qDebug ("User input, is invalid! Not in the options.");


        QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
        return;
    }

     //Checking for values if they're in range in the QCompleter. this is for  Phsical Attrubites
    if(ui->animalTypeDetail->text().trimmed().toLower() == "dog" || ui->animalTypeDetail->text().trimmed().toLower() == "cat" ){
        if(!buildList.contains(ui->animalAttributeOneField->text().toLower()) || !furLengthList.contains(ui->animalAttributeTwoField->text().toLower()) || !furColourList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }

    if(ui->animalTypeDetail->text().trimmed().toLower() == "parrot" || ui->animalTypeDetail->text().trimmed().toLower() == "finch" ){
        if(!beakLengthList.contains(ui->animalAttributeOneField->text().toLower()) || !wingSpanList.contains(ui->animalAttributeTwoField->text().toLower()) || !beakColourList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }

    if(ui->animalTypeDetail->text().trimmed().toLower() == "parrot" || ui->animalTypeDetail->text().trimmed().toLower() == "finch" ){
        if(!beakLengthList.contains(ui->animalAttributeOneField->text().toLower()) || !wingSpanList.contains(ui->animalAttributeTwoField->text().toLower()) || !beakColourList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }

    if(ui->animalTypeDetail->text().trimmed().toLower() == "betta" || ui->animalTypeDetail->text().trimmed().toLower() == "goldfish" ){
        if(!finnSizeList.contains(ui->animalAttributeOneField->text().toLower()) || !bodyPatternList.contains(ui->animalAttributeTwoField->text().toLower()) || !bodyLengthList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }

    if(ui->animalTypeDetail->text().toLower() == "frog" || ui->animalTypeDetail->text().toLower() == "salamander" ){
        if(!buildList.contains(ui->animalAttributeOneField->text().toLower()) || !bodyPatternList.contains(ui->animalAttributeTwoField->text().toLower()) || !bodyLengthList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }

    if(ui->animalTypeDetail->text().trimmed().toLower() == "snake" || ui->animalTypeDetail->text().trimmed().toLower() == "lizard" ){
        if(!scaleList.contains(ui->animalAttributeOneField->text().toLower()) || !bodyPatternList.contains(ui->animalAttributeTwoField->text().toLower()) || !bodyLengthList.contains(ui->animalAttributeThreeField->text().toLower())){
            qDebug ("User input, is invalid! Not in the options.");
            QMessageBox::critical(this,"Editing Animal Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options.");
            return;
        }
    }
    // END OF EROR CHECKING FOR EDITING


    // In this part we actually update the new animal info.

     qDebug ("Started from the bottom now we here.  "); //<=========== For debugging purposes.


     //Updating Animal Basic info
     animalsClientsList.animals.get(rowTable)->setName(ui->animalNameDetail->toPlainText().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setColour(ui->animalColourDetail->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setAge(ui->animalAgeDetail->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setGender(ui->animalGenderDetail->text().toUtf8().constData());



     // Updating Animal Non-Physcial Attrubites.
     animalsClientsList.animals.get(rowTable)->setIndividualism(ui->animalNonPhysicalAttr1->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setActiveness(ui->animalNonPhysicalAttr2->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setIntelligence(ui->animalNonPhysicalAttr3->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setAffectionism(ui->animalNonPhysicalAttr4->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setDiscipline(ui->animalNonPhysicalAttr5->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setAssertiveness(ui->animalNonPhysicalAttr6->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setSpaciousness(ui->animalNonPhysicalAttr7->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setEnergy(ui->animalNonPhysicalAttr8->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setDiurnalNocturnal(ui->animalNonPhysicalAttr9->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setHabitatPreference(ui->animalNonPhysicalAttr10->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setPlayfulness(ui->animalNonPhysicalAttr11->text().toUtf8().constData());
     animalsClientsList.animals.get(rowTable)->setAppetite(ui->animalNonPhysicalAttr12->text().toUtf8().constData());


     // Updating Animal Physcial Attrubites.
     if(ui->animalTypeDetail->text().toLower() == "dog" || ui->animalTypeDetail->text().toLower() == "cat" ){
            animalsClientsList.animals.get(rowTable)->setBuild(ui->animalAttributeOneField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setMammalHairLength(ui->animalAttributeTwoField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setMammalHairColour(ui->animalAttributeThreeField->text().toUtf8().constData());
     }


     if(ui->animalTypeDetail->text().toLower() == "parrot" || ui->animalTypeDetail->text().toLower() == "finch" ){
            animalsClientsList.animals.get(rowTable)->setBeakLength(ui->animalAttributeOneField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setWingSpan(ui->animalAttributeTwoField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setBeakColour(ui->animalAttributeThreeField->text().toUtf8().constData());
     }

     if(ui->animalTypeDetail->text().toLower() == "betta" || ui->animalTypeDetail->text().toLower() == "goldfish" ){
            animalsClientsList.animals.get(rowTable)->setFinnsSize(ui->animalAttributeOneField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setBodyPattern(ui->animalAttributeTwoField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setLength(ui->animalAttributeThreeField->text().toUtf8().constData());
     }

     if(ui->animalTypeDetail->text().toLower() == "frog" || ui->animalTypeDetail->text().toLower() == "salamander" ){
            animalsClientsList.animals.get(rowTable)->setBuild(ui->animalAttributeOneField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setBodyPattern(ui->animalAttributeTwoField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setLength(ui->animalAttributeThreeField->text().toUtf8().constData());
     }

     if(ui->animalTypeDetail->text().toLower() == "snake" || ui->animalTypeDetail->text().toLower() == "lizard" ){
            animalsClientsList.animals.get(rowTable)->setScaleType(ui->animalAttributeOneField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setBodyPattern(ui->animalAttributeTwoField->text().toUtf8().constData());
            animalsClientsList.animals.get(rowTable)->setLength(ui->animalAttributeThreeField->text().toUtf8().constData());
     }

     if (animalsClientsList.animals.get(rowTable)->getNewAnimal() == false){
             animalsClientsList.animals.get(rowTable)->setEdited(true);
         }


     qDebug ("User Successfully edited an animal.!");


     QMessageBox::information(this,"Succes Edit Message (STATUS: 200)", "You've successfully edited an animal");

}


void MainWindow::updateAcmMatchesUI(){


    //Clear List and update after.
    ui->matchesList->clear();

    //Size of animals
    int size = animalsClientsList.optimalSetMatches.size();

    int row =0; //Increment row so adding to the next element(in table) is easier.  - - - -  <----- first column and  first  row
    //                                                                              - - - -  <----- second column and second row thats what  i mean, you're adding by columns then rows.

    //Setting size of row for the table(based on animals)
    ui->matchesList->setRowCount(animalsClientsList.optimalSetMatches.size());
    for(int i= 0;i<size; i++){

        QTableWidgetItem *clientName = new QTableWidgetItem();
        QTableWidgetItem *animalType = new QTableWidgetItem();
        QTableWidgetItem *animalName = new QTableWidgetItem();
        QTableWidgetItem *animalSpecies = new QTableWidgetItem();


        //Convert Strings to QStrings
        clientName->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[i].getClient()->getFirstName()));
        animalName->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[i].getAnimal()->getName()));
        animalType->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[i].getAnimal()->getType()));
        animalSpecies->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[i].getAnimal()->getSpecies()));


        ui->matchesList->setItem(row,0,clientName);
        ui->matchesList->setItem(row,1,animalName);
        ui->matchesList->setItem(row,2,animalType);
        ui->matchesList->setItem(row,3,animalSpecies);


        row++;
    }
    ui->matchesList->setHorizontalHeaderLabels(QStringList() << "Client Name" << "Animal Name" << "Animal Type" << "Animal Species");



}

//===============================================> END OF STAFF CODE LOGIC <================================================

//===============================================>    CLIENT CODE LOGIC    <================================================

/*
    - The function below views the client view and from there the client can navigate
*/
void MainWindow::on_clientBtn_clicked()
{
    /*
     * 1. Authenticate the user login (only user and pass)
     * 2. Once true, redirect to the Client's UI.
    */
    ui->stackedWidget->setCurrentIndex(3);

    //2. once logged in show the UI(for now temp, change it later).

    ui->viewAnimalsFromClientView->hide();
    ui->viewAnimalsFromClientView->setGeometry(10,10,681,511);

    ui->animalViewDetailClientBtn->hide();


     ui->viewClientProfilePage->hide();


    //ui->userLoggedIn->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getFirstName()) + " " + QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getLastName()));



    //AutoCompleter for clients

    affectionatismList.clear();
    affectionatismList << "1 (barely affectionate)" << "2 (somewhat affectionate)" << "3 (moderately affectionate)" << "4 (affectionate)" << "5 (very affectionate)";
    affectionisimOptions = new QCompleter(affectionatismList,this);
    affectionisimOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientViewAffectionisimField->setCompleter(affectionisimOptions);

    nocturnalList.clear();
    nocturnalList << "1 (barely nocturnal)" << "2 (somewhat nocturnal)" << "3 (moderately nocturnal)" << "4 (nocturnal)" << "5 (very nocturnal)";
    dirNoctOptions = new QCompleter(nocturnalList,this);
    dirNoctOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientViewNocturnalField->setCompleter(dirNoctOptions);


    habitatList.clear();
    habitatList << "1 (cold)" << "2 (cool)" << "3 (mild)" << "4 (warm)" << "5 (hot)";
    habitatPreOptions = new QCompleter(habitatList,this);
    habitatPreOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientViewHabitatPreField->setCompleter(habitatPreOptions);




    activenessList.clear();
    activenessList << "1 (barely active)" << "2 (somewhat active)" << "3 (moderately active)" << "4 (active)" << "5 (very active)";
    activenessOptions = new QCompleter(activenessList,this);
    activenessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientViewActivenessField->setCompleter(activenessOptions);


    genderList.clear();
    genderList << "male" << "female";
    genderOptions = new QCompleter(genderList,this);
    genderOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientViewGenderField->setCompleter(genderOptions);



    //CPOPPPPPPPPY
    invidulaismList.clear();
    invidulaismList << "1 (barely independent)" << "2 (somewhat independent)" << "3 (moderately independent)" << "4 (independent)" << "5 (very independent)";

    invidualisimOptions = new QCompleter(invidulaismList,this);
    invidualisimOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut1->setCompleter(invidualisimOptions);

    intelligenceList.clear();
    intelligenceList << "1 (barely intelligent)" << "2 (somewhat intelligent)" << "3 (moderately intelligent)" << "4 (intelligent)" << "5 (very intelligent)";

    intelliegenceOptions = new QCompleter(intelligenceList,this);
    intelliegenceOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut2->setCompleter(intelliegenceOptions);


    disciplinedList.clear();
    disciplinedList << "1 (barely disciplined)" << "2 (somewhat disciplined)" << "3 (moderately disciplined)" << "4 (disciplined)" << "5 (very disciplined)";

    disciplineOptions = new QCompleter(disciplinedList,this);
    disciplineOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut3->setCompleter(disciplineOptions);


    assertiveList.clear();
    assertiveList << "1 (barely assertive)" << "2 (somewhat assertive)" << "3 (moderately assertive)" << "4 (assertive)" << "5 (very assertive)";

    assertivenessOptions = new QCompleter(assertiveList,this);
    assertivenessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut4->setCompleter(assertivenessOptions);



    playfullnessList.clear();
    playfullnessList << "1 (barely playful)" << "2 (somewhat playful)" << "3 (moderately playful)" << "4 (playful)" << "5 (very playful)";

    playfullnessOptions = new QCompleter(playfullnessList,this);
    playfullnessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut5->setCompleter(playfullnessOptions);


    energeticList.clear();
    energeticList << "1 (barely energetic)" << "2 (somewhat energetic)" << "3 (moderately energetic)" << "4 (energetic)" << "5 (very energetic)";

    energeticOptions = new QCompleter(energeticList,this);
    energeticOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut6->setCompleter(energeticOptions);

    spaciousList.clear();
    spaciousList << "1 (barely spacious)" << "2 (somewhat spacious)" << "3 (moderately spacious)" << "4 (spacious)" << "5 (very spacious)";

    spaciousnessOptions = new QCompleter(spaciousList,this);
    spaciousnessOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut7->setCompleter(spaciousnessOptions);


    appetiteList.clear();
    appetiteList << "1 (small appetite)" << "2 (moderate appetite)" << "3 (normal appetite)" << "4 (big appetite)" << "5 (huge appetite))";

    appetiteOptions = new QCompleter(appetiteList,this);
    appetiteOptions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->clientNonPhysPreOut8->setCompleter(appetiteOptions);
    //END COPPPY




    //Fill Clients for the login list.
    ui->avaliableClients->clear();
    for(int i=0; i< animalsClientsList.clients.size();i++){
        ui->avaliableClients->addItem(QString::fromStdString(animalsClientsList.clients.get(i)->getEmail()));
    }

}


/*
    * This function updates the animals list from Client View.
*/
void MainWindow::updateAnimalListFromClientView(){


    //Clear List and update after.
    ui->animalsListFromClientView->clear();
    ui->animalViewDetailClientBtn->hide();
    //Size of animals
    int size = animalsClientsList.animals.size();

    int row =0; //Increment row so adding to the next element(in table) is easier.  - - - -  <----- first column and  first  row
    //                                                                              - - - -  <----- second column and second row thats what  i mean, you're adding by columns then rows.

    //Setting size of row for the table(based on animals)
    ui->animalsListFromClientView->setRowCount(animalsClientsList.animals.size());

    for(int i= 0;i<size; i++){

        qDebug ("ASDAACXZCXZCZXCC SIZEASDAADSAD: %d",size);
        QTableWidgetItem *animalNameTable = new QTableWidgetItem();
        QTableWidgetItem *animalTypeTable = new QTableWidgetItem();
        QTableWidgetItem *animalSpeciesTable = new QTableWidgetItem();
        QTableWidgetItem *animalColourTable = new QTableWidgetItem();
        QTableWidgetItem *animalAgeTable = new QTableWidgetItem();
        QTableWidgetItem *animalGenderTable = new QTableWidgetItem();

        //Convert Strings to QStrings
        animalNameTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getName()));
        animalTypeTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getType()));
        animalSpeciesTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getSpecies()));
        animalColourTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getColour()));
        animalAgeTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getAge()));
        animalGenderTable->setText(QString::fromStdString(animalsClientsList.animals.get(i)->getGender()));

        ui->animalsListFromClientView->setItem(row,0,animalNameTable);
        ui->animalsListFromClientView->setItem(row,1,animalTypeTable);
        ui->animalsListFromClientView->setItem(row,2,animalSpeciesTable);
        ui->animalsListFromClientView->setItem(row,3,animalColourTable);
        ui->animalsListFromClientView->setItem(row,4,animalAgeTable);
        ui->animalsListFromClientView->setItem(row,5,animalGenderTable);

        row++;
    }
    ui->animalsListFromClientView->setHorizontalHeaderLabels(QStringList() << "Name" << "Type" << "Species" << "Colour" << "Age" << "Gender");


}

/*
 * This function displays the detailed information for an animal(from client view).
*/
void MainWindow::displayAnimalDetailsFromClient(){

    //Animal Basic info
    ui->animalNameDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getName()));
    ui->animalTypeDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getType()));
    ui->animalSpeciesDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getSpecies()));
    ui->animalColourDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getColour()));
    ui->animalAgeDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAge()));
    ui->animalGenderDetailToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getGender()));


    //Animal Non-Physcial Attrubites.
    ui->animalNonPhysicalAttr1ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getIndividualism()));
    ui->animalNonPhysicalAttr2ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getActiveness()));
    ui->animalNonPhysicalAttr3ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getIntelligence()));
    ui->animalNonPhysicalAttr4ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAffectionism()));
    ui->animalNonPhysicalAttr5ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getDiscipline()));
    ui->animalNonPhysicalAttr6ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAssertiveness()));
    ui->animalNonPhysicalAttr7ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getSpaciousness()));
    ui->animalNonPhysicalAttr8ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getEnergetic()));
    ui->animalNonPhysicalAttr9ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getDiurnalNocturnal()));
    ui->animalNonPhysicalAttr10ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getHabitatPreference()));
    ui->animalNonPhysicalAttr11ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getPlayfulness()));
    ui->animalNonPhysicalAttr12ToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getAppetite()));



    //Animal Physical Attributes


    //Mammals
    if(animalsClientsList.animals.get(rowTable)->getType() == "dog" || animalsClientsList.animals.get(rowTable)->getType() == "cat"){
        ui->animalAttributeOneFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBuild())); //check mark
        ui->animalAttributeTwoFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getMammalHairLength())); //check mark
        ui->animalAttributeThreeFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getMammalHairColour())); //Check mark
        //Show labels
        ui->buildLabelClient->show();
        ui->furColourLabelClient->show();
        ui->furLengthLabelClient->show();

        //Hide Labels not related.
        ui->bodyLengthLabelClient->hide();
        ui->finnsizeLabelClient->hide();
        ui->scaleTypeLabelClient->hide();
        ui->beakColourLabelClient->hide();
        ui->beakLengthLabelClient->hide();
        ui->wingSpanLabelClient->hide();
        ui->bodyPatternLabelClient->hide();
    }
    //End of Mammals

    //Birds
    else if(animalsClientsList.animals.get(rowTable)->getType() == "parrot" || animalsClientsList.animals.get(rowTable)->getType() == "finch"){

        ui->animalAttributeOneFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBeakLength())); // Check Mark
        ui->animalAttributeTwoFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getWingSpan())); //Check Mark
        ui->animalAttributeThreeFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBeakColour())); //Check Mark

        //Show labels
        ui->beakColourLabelClient->show();
        ui->beakLengthLabelClient->show();
        ui->wingSpanLabelClient->show();

        //Hide Labels not related.
        ui->finnsizeLabelClient->hide();
        ui->scaleTypeLabelClient->hide();
        ui->bodyPatternLabelClient->hide();
        ui->buildLabelClient->hide();
        ui->furColourLabelClient->hide();
        ui->furLengthLabelClient->hide();
        ui->bodyLengthLabelClient->hide();
    }
    //End of Birds

    //Amphibians
    else if(animalsClientsList.animals.get(rowTable)->getType() == "frog" || animalsClientsList.animals.get(rowTable)->getType() == "salamander"){

         ui->animalAttributeOneFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBuild())); //Check Mark
         ui->animalAttributeTwoFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); //Check Mark
         ui->animalAttributeThreeFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); //Check Mark

         //Show labels
         ui->buildLabelClient->show();
         ui->bodyPatternLabel->show();
         ui->bodyLengthLabelClient->show();


         //Hide Labels not related.
         ui->finnsizeLabelClient->hide();
         ui->scaleTypeLabelClient->hide();
         ui->wingSpanLabelClient->hide();
         ui->furColourLabelClient->hide();
         ui->furLengthLabelClient->hide();
         ui->beakColourLabelClient->hide();
         ui->beakLengthLabelClient->hide();

    }

    //Reptiles
    else if(animalsClientsList.animals.get(rowTable)->getType() == "snake" || animalsClientsList.animals.get(rowTable)->getType() == "lizard"){

         ui->animalAttributeOneFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getScaleType())); // Check mark
         ui->animalAttributeTwoFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); // check mark
         ui->animalAttributeThreeFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); // check mark


         //Show labels
         ui->scaleTypeLabelClient->show();
         ui->bodyPatternLabelClient->show();
         ui->bodyLengthLabelClient->show();


         //Hide Labels not related.
         ui->finnsizeLabelClient->hide();
         ui->buildLabelClient->hide();
         ui->wingSpanLabelClient->hide();
         ui->furColourLabelClient->hide();
         ui->furLengthLabelClient->hide();
         ui->beakColourLabelClient->hide();
         ui->beakLengthLabelClient->hide();


    }
    //End of Reptiles

    //Fish
    else if(animalsClientsList.animals.get(rowTable)->getType() == "betta" || animalsClientsList.animals.get(rowTable)->getType() == "goldfish"){

         ui->animalAttributeOneFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getFinnsSize())); //check mark
         ui->animalAttributeTwoFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getBodyPattern())); // check mark
         ui->animalAttributeThreeFieldToClient->setText(QString::fromStdString(animalsClientsList.animals.get(rowTable)->getLength())); // check mark

         //Show labels
         ui->finnsizeLabelClient->show();
         ui->bodyPatternLabelClient->show();
         ui->bodyLengthLabelClient->show();


         //Hide Labels not related.
         ui->scaleTypeLabelClient->hide();
         ui->buildLabelClient->hide();
         ui->wingSpanLabelClient->hide();
         ui->furColourLabelClient->hide();
         ui->furLengthLabelClient->hide();
         ui->beakColourLabelClient->hide();
         ui->beakLengthLabelClient->hide();

    }
    //End of Fish

}


/*
 * This function display the client's profile details (Client View)
*/
void MainWindow::displayClientProfileDetails(){

    //Client Basic info
    ui->clientViewFNameField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getFirstName()));
    ui->clientViewLNameField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getLastName()));
    ui->clientViewPhoneNumField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getPhoneNumber()));
    ui->clientViewEmailField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getEmail()));
    ui->clientViewAgeField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getAge()));
    ui->clientViewGenderField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getGender()));

    //Client Character Traiats Attriubtes.
    ui->clientViewHabitatPreField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientHabitaPreference()));
    ui->clientViewActivenessField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientActiveness()));
    ui->clientViewNocturnalField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientDiurnalNocturnal()));
    ui->clientViewAffectionisimField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientAffectionism()));


    //Client Non-Phys Preferences for an animal Attriubtes.
    ui->clientNonPhysPreOut1->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientIndividualismPreference()));
    ui->clientNonPhysPreOut2->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientIntelligencePreference()));
    ui->clientNonPhysPreOut3->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientDisciplinePreference()));
    ui->clientNonPhysPreOut4->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientAssertivenessPreference()));
    ui->clientNonPhysPreOut5->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientPlayfulllnessPreference()));
    ui->clientNonPhysPreOut6->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientEnergeticPreference()));
    ui->clientNonPhysPreOut7->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientSpaciousnessPreference()));
    ui->clientNonPhysPreOut8->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->getClientAppetitePreference()));



}


void MainWindow::enableClientEdits(bool isEnabled){

    if(isEnabled == true){
        //Client Basic info
        ui->clientViewFNameField->setReadOnly(false);
        ui->clientViewLNameField->setReadOnly(false);
        ui->clientViewPhoneNumField->setReadOnly(false);
        ui->clientViewEmailField->setReadOnly(false);
        ui->clientViewAgeField->setReadOnly(false);
        ui->clientViewGenderField->setReadOnly(false);

        //Client CharacterTraits Attriubtes.
        ui->clientViewHabitatPreField->setReadOnly(false);
        ui->clientViewActivenessField->setReadOnly(false);
        ui->clientViewNocturnalField->setReadOnly(false);
        ui->clientViewAffectionisimField->setReadOnly(false);


        //Client Non-Physical For an Animal Attriubtes.
        ui->clientNonPhysPreOut1->setReadOnly(false);
        ui->clientNonPhysPreOut2->setReadOnly(false);
        ui->clientNonPhysPreOut3->setReadOnly(false);
        ui->clientNonPhysPreOut4->setReadOnly(false);
        ui->clientNonPhysPreOut5->setReadOnly(false);
        ui->clientNonPhysPreOut6->setReadOnly(false);
        ui->clientNonPhysPreOut7->setReadOnly(false);
        ui->clientNonPhysPreOut8->setReadOnly(false);
    }
    else{
        //Client Basic info
        ui->clientViewFNameField->setReadOnly(true);
        ui->clientViewLNameField->setReadOnly(true);
        ui->clientViewPhoneNumField->setReadOnly(true);
        ui->clientViewEmailField->setReadOnly(true);
        ui->clientViewAgeField->setReadOnly(true);
        ui->clientViewGenderField->setReadOnly(true);

        //Client Non-Phys Attriubtes.
        ui->clientViewHabitatPreField->setReadOnly(true);
        ui->clientViewActivenessField->setReadOnly(true);
        ui->clientViewNocturnalField->setReadOnly(true);
        ui->clientViewAffectionisimField->setReadOnly(true);

        //Client Non-Physical For an Animal Attriubtes.
        ui->clientNonPhysPreOut1->setReadOnly(true);
        ui->clientNonPhysPreOut2->setReadOnly(true);
        ui->clientNonPhysPreOut3->setReadOnly(true);
        ui->clientNonPhysPreOut4->setReadOnly(true);
        ui->clientNonPhysPreOut5->setReadOnly(true);
        ui->clientNonPhysPreOut6->setReadOnly(true);
        ui->clientNonPhysPreOut7->setReadOnly(true);
        ui->clientNonPhysPreOut8->setReadOnly(true);
    }


}



/*
 * This function handles when a client is about to view their profile
*/
void MainWindow::on_clientProfileBtn_clicked()
{
    int VIEW_EDIT_PROFILE_BTN =6;
    ui->viewClientProfilePage->setCurrentIndex(0);
    ui->preferencesBox->show();
    ui->editClientProfileBtn->show();
    ui->setAnimalPreferencesBtn->show();
    displayClientProfileDetails();
    enableClientEdits(false);
    showTheCorrectWindow(&VIEW_EDIT_PROFILE_BTN);
    ui->cancelClientEditsBtn->hide();
    ui->saveClientProfileEditsBtn->hide();
}


/*
 * This function handles when a client is about to edit their profile
*/
void MainWindow::on_editClientProfileBtn_clicked()
{
    enableClientEdits(true);
    ui->preferencesBox->hide();
    ui->cancelClientEditsBtn->show();
    ui->saveClientProfileEditsBtn->show();
    ui->editClientProfileBtn->hide();
    ui->setAnimalPreferencesBtn->hide();
    ui->setPhysPreferencesBtn->hide();
    ui->viewRanksAndPreferencesBtn->hide();

}

void MainWindow::on_cancelClientEditsBtn_clicked()
{
    enableClientEdits(false);
    ui->cancelClientEditsBtn->hide();
    ui->saveClientProfileEditsBtn->hide();
    ui->editClientProfileBtn->show();
    ui->setAnimalPreferencesBtn->show();
    ui->preferencesBox->show();
    ui->setPhysPreferencesBtn->show();
    ui->viewRanksAndPreferencesBtn->show();
}

void MainWindow::saveClientNewEdits(){

    if(ui->clientViewFNameField->text().trimmed().isEmpty() == true   || ui->clientViewLNameField->text().trimmed().isEmpty() == true     || ui->clientViewAgeField->text().trimmed().isEmpty() == true         ||
       ui->clientViewEmailField->text().trimmed().isEmpty() == true        || ui->clientViewGenderField->text().trimmed().isEmpty() == true       || ui->clientViewPhoneNumField->text().trimmed().isEmpty() == true   ||
       ui->clientViewActivenessField->text().trimmed().isEmpty() == true || ui->clientViewAffectionisimField->text().trimmed().isEmpty() == true || ui->clientViewHabitatPreField->text().trimmed().isEmpty() == true ||
        ui->clientViewHabitatPreField->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut1->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut2->text().trimmed().isEmpty() == true ||
        ui->clientNonPhysPreOut3->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut4->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut5->text().trimmed().isEmpty() == true ||
        ui->clientNonPhysPreOut6->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut7->text().trimmed().isEmpty() == true || ui->clientNonPhysPreOut8->text().trimmed().isEmpty() == true)
    {
        qDebug ("User left profile fields empty!");


        QMessageBox::critical(this,"Editing Client Error 0029XF4", "You didn't fill out the information properly, make sure to leave no empty field, and enter only information from the autocompleter when shown.");
        return;

    }


    //Checking for values if they're in range in the QCompleter. this is for  basic info and non-phsyical information.
    if(!genderList.contains(ui->clientViewGenderField->text().trimmed().toLower()) || !activenessList.contains(ui->clientViewActivenessField->text().trimmed().toLower()) || !affectionatismList.contains(ui->clientViewAffectionisimField->text().trimmed().toLower()) ||
      !nocturnalList.contains(ui->clientViewNocturnalField->text().trimmed().toLower()) || !habitatList.contains(ui->clientViewHabitatPreField->text().trimmed().toLower())||
      !invidulaismList.contains(ui->clientNonPhysPreOut1->text().trimmed().toLower()) || !intelligenceList.contains(ui->clientNonPhysPreOut2->text().trimmed().toLower()) ||  !disciplinedList.contains(ui->clientNonPhysPreOut3->text().trimmed().toLower()) ||
      !assertiveList.contains(ui->clientNonPhysPreOut4->text().trimmed().toLower()) ||  !playfullnessList.contains(ui->clientNonPhysPreOut5->text().trimmed().toLower()) ||  !energeticList.contains(ui->clientNonPhysPreOut6->text().trimmed().toLower()) ||
      !spaciousList.contains(ui->clientNonPhysPreOut7->text().trimmed().toLower()) || !appetiteList.contains(ui->clientNonPhysPreOut8->text().trimmed().toLower())  ){

        qDebug ("User input is invalid! Not in the options.");
        QMessageBox::critical(this,"Editing Client Error 0319FXF1", "Invalid information! When filling out the fields, please only type or select the available information from the shown options, if avaliable.");
        return;
    }

    qDebug ("We made it ya donkeys.");

    //Updating Client Basic info
    animalsClientsList.clients.get(clientLoggedIn)->setFirstName(ui->clientViewFNameField->text().toUtf8().constData());
    qDebug ("1.");
    animalsClientsList.clients.get(clientLoggedIn)->setLastName(ui->clientViewLNameField->text().toUtf8().constData());
    qDebug ("2.");
    animalsClientsList.clients.get(clientLoggedIn)->setAge(ui->clientViewAgeField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setEmail(ui->clientViewEmailField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setGender(ui->clientViewGenderField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setPhoneNumber(ui->clientViewPhoneNumField->text().toUtf8().constData());
qDebug ("Excuted made it ya donkeys.");




    // Updating Client Characteratits Attrubites.
    animalsClientsList.clients.get(clientLoggedIn)->setClientActiveness(ui->clientViewActivenessField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientAffectionism(ui->clientViewAffectionisimField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientDiurnalNocturnal(ui->clientViewNocturnalField->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientHabitaPreference(ui->clientViewHabitatPreField->text().toUtf8().constData());


    // Updating Client Non-Physicl Preferences For an animal Attrubites.
    animalsClientsList.clients.get(clientLoggedIn)->setClientIndividualismPreference(ui->clientNonPhysPreOut1->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientIntelligencePreference(ui->clientNonPhysPreOut2->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientDisciplinePreference(ui->clientNonPhysPreOut3->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientAssertivenessPreference(ui->clientNonPhysPreOut4->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientPlayfulllnessPreference(ui->clientNonPhysPreOut5->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientEnergeticPreference(ui->clientNonPhysPreOut6->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientSpaciousnessPreference(ui->clientNonPhysPreOut7->text().toUtf8().constData());
    animalsClientsList.clients.get(clientLoggedIn)->setClientAppetitePreference(ui->clientNonPhysPreOut8->text().toUtf8().constData());


  //Update new UI.
  displayClientProfileDetails();




  //Show Success result.
  qDebug ("User input is invalid! Not in the options.");
  QMessageBox::information(this,"Succesful Edit", "You have succesfully edited your proifle.");



  animalsClientsList.clients.get(clientLoggedIn)->setEdited(true);



  enableClientEdits(false);
  ui->cancelClientEditsBtn->hide();
  ui->saveClientProfileEditsBtn->hide();
  ui->editClientProfileBtn->show();
  ui->setAnimalPreferencesBtn->show();
  ui->preferencesBox->show();
  ui->setPhysPreferencesBtn->show();
  ui->viewRanksAndPreferencesBtn->show();
}







/*
 *  This function handles when new edits are performed in client's profile.
*/
void MainWindow::on_saveClientProfileEditsBtn_clicked()
{
    saveClientNewEdits();


}


/*
 *  This function handles when new Ranks  are performed in client's profile.
*/
void MainWindow::on_savePreferencesBtn_clicked()
{

    //Check if the Ranks are equal to each other.
    if( ui->preferenceBettaField->text() == ui->preferenceCatField->text() || ui->preferenceBettaField->text() == ui->preferenceDogField->text() ||  ui->preferenceBettaField->text() == ui->preferenceFinchField->text() || ui->preferenceBettaField->text() == ui->preferenceFrogField->text() || ui->preferenceBettaField->text() == ui->preferenceGoldfisheField->text() || ui->preferenceBettaField->text() == ui->preferenceLizardField->text() || ui->preferenceBettaField->text() == ui->preferenceParrotField->text() || ui->preferenceBettaField->text() == ui->preferenceSalamanderField->text() || ui->preferenceBettaField->text() == ui->preferenceSnakeField->text() ||

        ui->preferenceCatField->text() == ui->preferenceBettaField->text() || ui->preferenceCatField->text() == ui->preferenceDogField->text() ||  ui->preferenceCatField->text() == ui->preferenceFinchField->text() || ui->preferenceCatField->text() == ui->preferenceFrogField->text() || ui->preferenceCatField->text() == ui->preferenceGoldfisheField->text() || ui->preferenceCatField->text() == ui->preferenceLizardField->text() || ui->preferenceCatField->text() == ui->preferenceParrotField->text() || ui->preferenceCatField->text() == ui->preferenceSalamanderField->text() || ui->preferenceCatField->text() == ui->preferenceSnakeField->text() ||

        ui->preferenceDogField->text() == ui->preferenceCatField->text() || ui->preferenceDogField->text() == ui->preferenceBettaField->text() || ui->preferenceDogField->text() == ui->preferenceFinchField->text() || ui->preferenceDogField->text() == ui->preferenceFrogField->text() || ui->preferenceDogField->text() == ui->preferenceGoldfisheField->text() || ui->preferenceDogField->text() == ui->preferenceLizardField->text() || ui->preferenceDogField->text() == ui->preferenceParrotField->text() || ui->preferenceDogField->text() == ui->preferenceSalamanderField->text() || ui->preferenceDogField->text() == ui->preferenceSnakeField->text() ||


        ui->preferenceFinchField->text() == ui->preferenceDogField->text() || ui->preferenceFinchField->text() ==   ui->preferenceCatField->text() || ui->preferenceFinchField->text() == ui->preferenceBettaField->text()  || ui->preferenceFinchField->text() == ui->preferenceFrogField->text() || ui->preferenceFinchField->text() == ui->preferenceGoldfisheField->text() || ui->preferenceFinchField->text() == ui->preferenceLizardField->text() || ui->preferenceFinchField->text() == ui->preferenceParrotField->text() || ui->preferenceFinchField->text() == ui->preferenceSalamanderField->text() || ui->preferenceFinchField->text() == ui->preferenceSnakeField->text() ||


        ui->preferenceFrogField->text()  ==  ui->preferenceFinchField->text()|| ui->preferenceFrogField->text()== ui->preferenceDogField->text() || ui->preferenceFrogField->text() == ui->preferenceCatField->text() || ui->preferenceFrogField->text() == ui->preferenceBettaField->text() || ui->preferenceFrogField->text() == ui->preferenceGoldfisheField->text() || ui->preferenceFrogField->text() == ui->preferenceLizardField->text() || ui->preferenceFrogField->text() == ui->preferenceParrotField->text() || ui->preferenceFrogField->text() == ui->preferenceSalamanderField->text() || ui->preferenceFrogField->text() == ui->preferenceSnakeField->text() ||


        ui->preferenceGoldfisheField->text() == ui->preferenceFrogField->text()|| ui->preferenceGoldfisheField->text()  == ui->preferenceFinchField->text()|| ui->preferenceGoldfisheField->text()== ui->preferenceDogField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceCatField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceBettaField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceLizardField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceParrotField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceSalamanderField->text() || ui->preferenceGoldfisheField->text() == ui->preferenceSnakeField->text() ||

        ui->preferenceLizardField->text() ==  ui->preferenceGoldfisheField->text()|| ui->preferenceLizardField->text() == ui->preferenceFrogField->text()|| ui->preferenceLizardField->text()  == ui->preferenceFinchField->text()|| ui->preferenceLizardField->text()== ui->preferenceDogField->text() || ui->preferenceLizardField->text() == ui->preferenceCatField->text() || ui->preferenceLizardField->text() == ui->preferenceBettaField->text()  || ui->preferenceLizardField->text() == ui->preferenceParrotField->text() || ui->preferenceLizardField->text() == ui->preferenceSalamanderField->text() || ui->preferenceLizardField->text() == ui->preferenceSnakeField->text() ||


        ui->preferenceParrotField->text() == ui->preferenceLizardField->text() || ui->preferenceParrotField->text()==  ui->preferenceGoldfisheField->text()|| ui->preferenceParrotField->text() == ui->preferenceFrogField->text()|| ui->preferenceParrotField->text()  == ui->preferenceFinchField->text()|| ui->preferenceParrotField->text()== ui->preferenceDogField->text() || ui->preferenceParrotField->text() == ui->preferenceCatField->text() || ui->preferenceParrotField->text() == ui->preferenceBettaField->text() || ui->preferenceParrotField->text() == ui->preferenceSalamanderField->text() || ui->preferenceParrotField->text() == ui->preferenceSnakeField->text() ||

        ui->preferenceSalamanderField->text() ==  ui->preferenceParrotField->text()|| ui->preferenceSalamanderField->text()  == ui->preferenceLizardField->text() || ui->preferenceSalamanderField->text()==  ui->preferenceGoldfisheField->text()|| ui->preferenceSalamanderField->text() == ui->preferenceFrogField->text()|| ui->preferenceSalamanderField->text()  == ui->preferenceFinchField->text()|| ui->preferenceSalamanderField->text()== ui->preferenceDogField->text() || ui->preferenceSalamanderField->text() == ui->preferenceCatField->text() || ui->preferenceSalamanderField->text() == ui->preferenceBettaField->text() || ui->preferenceSalamanderField->text() == ui->preferenceSnakeField->text() ||

        ui->preferenceSnakeField->text() == ui->preferenceSalamanderField->text()|| ui->preferenceSnakeField->text()== ui->preferenceParrotField->text()|| ui->preferenceSnakeField->text()  == ui->preferenceLizardField->text() || ui->preferenceSnakeField->text()==  ui->preferenceGoldfisheField->text()|| ui->preferenceSnakeField->text() == ui->preferenceFrogField->text()|| ui->preferenceSnakeField->text()  == ui->preferenceFinchField->text()|| ui->preferenceSnakeField->text()== ui->preferenceDogField->text() || ui->preferenceSnakeField->text() == ui->preferenceCatField->text() || ui->preferenceSnakeField->text() == ui->preferenceBettaField->text()){


        qDebug ("User input is invalid! User has duplicates in fields.");
        QMessageBox::critical(this,"Setting Rank Error 101F03X3M", "Invalid information! You're not allowed to have fields with same values, please only choose a unique value for each field, the values range from 1-10(Inclusive).");
        return;
    }

    if((ui->preferenceBettaField->text().toInt() < 1 || ui->preferenceBettaField->text().toInt() > 10)             ||
       (ui->preferenceCatField->text().toInt() < 1   || ui->preferenceCatField->text().toInt() > 10)               ||
       (ui->preferenceDogField->text().toInt() < 1   || ui->preferenceDogField->text().toInt() > 10)               ||
       (ui->preferenceFinchField->text().toInt() < 1   || ui->preferenceFinchField->text().toInt() > 10)           ||
       (ui->preferenceFrogField->text().toInt() < 1   || ui->preferenceFrogField->text().toInt() > 10)             ||
       (ui->preferenceGoldfisheField->text().toInt() < 1   || ui->preferenceGoldfisheField->text().toInt() > 10)   ||
       (ui->preferenceLizardField->text().toInt() < 1   || ui->preferenceLizardField->text().toInt() > 10)         ||
       (ui->preferenceParrotField->text().toInt() < 1   || ui->preferenceParrotField->text().toInt() > 10)         ||
       (ui->preferenceSalamanderField->text().toInt() < 1   || ui->preferenceSalamanderField->text().toInt() > 10) ||
       (ui->preferenceSnakeField->text().toInt() < 1   || ui->preferenceSnakeField->text().toInt() > 10))
    {

        qDebug ("User input is invalid! User has values out of range(should only be from 1-10)");
        QMessageBox::critical(this,"Setting Ran Error 01VN2M5k", "Plesae input values only ranging from 1-10 for each Field(s)");
        return;
    }


    //Compare all values to each other, and make sure they're between 1 and 10






     qDebug ("Scooby doo made it");


     //====================> Update Model and UI

     //Model
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceBettaField->text().toInt(),"betta");
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceGoldfisheField->text().toInt(),"goldfish");

     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceCatField->text().toInt(),"cat");
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceDogField->text().toInt(),"dog");

     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceSnakeField->text().toInt(),"snake");
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceLizardField->text().toInt(),"lizard");

     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceFrogField->text().toInt(),"frog");
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceSalamanderField->text().toInt(),"salamander");

     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceFinchField->text().toInt(),"finch");
     animalsClientsList.clients.get(clientLoggedIn)->ranks.setRank(ui->preferenceParrotField->text().toInt(),"parrot");




      animalsClientsList.clients.get(clientLoggedIn)->setEdited(true);


     qDebug ("User Sucessfully Set the run properly.");
     QMessageBox::information(this,"Seting Rank Success (STATUS:200)", "You've Sucessfully Set the ranks.");



}




/*
    *This function will save the client's physical attributes for each animal. and update it to the Model and UI
*/
void MainWindow::on_saveClientPhysicalPreferencesBtn_clicked()
{

    //Check if the user left any field empty. If So Destory the function(return)
    if(ui->dogFurBuildField->currentIndex() == 0 || ui->catFurBuildField->currentIndex() == 0 || ui->frogBodyLengthField->currentIndex() == 0 ||
       ui->dogFurColourField->currentIndex() == 0|| ui->catFurColourField->currentIndex() == 0|| ui->frogBodyPatternField->currentIndex() == 0||
       ui->dogFurLengthField->currentIndex() == 0|| ui->catFurLengthField->currentIndex() == 0|| ui->frogBuildField->currentIndex() == 0      ||
       ui->salamanderBodyLengthField->currentIndex() == 0 || ui->snakeBodyLengthField->currentIndex() == 0 || ui->lizardBodyLengthField->currentIndex() == 0 ||
       ui->salamanderBodyPatternField->currentIndex() == 0|| ui->snakeBodyPatternField->currentIndex() == 0|| ui->lizardBodyPatternField->currentIndex() == 0||
       ui->salamanderBuildField->currentIndex() == 0|| ui->snakeScaleTypeField->currentIndex() == 0|| ui->lizardScaleTypeField->currentIndex() == 0       ||
       ui->bettaBodyLengthField->currentIndex() == 0 || ui->goldfishBodyLengthField->currentIndex() == 0 || ui->parrotWingSpanField->currentIndex() == 0  ||
       ui->bettaBodyPatternField->currentIndex() == 0|| ui->goldfishBodyPatternField->currentIndex() == 0|| ui->parrotBeakColourField->currentIndex() == 0||
       ui->bettaFinnSizeField->currentIndex() == 0|| ui->goldfishFinnSizeField->currentIndex() == 0|| ui->parrotBeakLengthField->currentIndex() == 0      ||
       ui->finchWingSpanField->currentIndex() == 0|| ui->finchBeakColourField->currentIndex() == 0|| ui->finchBeakLengthField->currentIndex() == 0      )

    {

        qDebug ("User input is invalid! User has left an empty field(S).");
        QMessageBox::critical(this,"Setting Physical Preferences Error 001F13Y3Z", "Invalid information! You have left an empty field(s), make sure every field(s) is not empty.");
        return;
    }


    //Update Model
    for(int i =0; i<animalsClientsList.clients.get(clientLoggedIn)->ranks.size() ;i++){

        //Mammals
        if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "dog"){

            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBuild(ui->dogFurBuildField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setMammalHairColour(ui->dogFurColourField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setMammalHairLength(ui->dogFurLengthField->currentText().toLower().toUtf8().constData());
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "cat"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBuild(ui->catFurBuildField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setMammalHairColour(ui->catFurColourField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setMammalHairLength(ui->catFurLengthField->currentText().toLower().toUtf8().constData());
        }

        //Amphibians
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "frog"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->frogBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->frogBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBuild(ui->frogBuildField->currentText().toLower().toUtf8().constData());
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "salamander"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->salamanderBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->salamanderBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBuild(ui->salamanderBuildField->currentText().toLower().toUtf8().constData());
        }

        //Reptiles
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "snake"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->snakeBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->snakeBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setScaleType(ui->snakeScaleTypeField->currentText().toLower().toUtf8().constData());
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "lizard"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->lizardBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->lizardBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setScaleType(ui->lizardScaleTypeField->currentText().toLower().toUtf8().constData());
        }

        //Fish
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "betta"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->bettaBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->bettaBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setFinnsSize(ui->bettaFinnSizeField->currentText().toLower().toUtf8().constData());
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "goldfish"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBodyPattern(ui->goldfishBodyPatternField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setLength(ui->goldfishBodyLengthField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setFinnsSize(ui->goldfishFinnSizeField->currentText().toLower().toUtf8().constData());
        }

        //Bird
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "parrot"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setWingSpan(ui->parrotWingSpanField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBeakColour(ui->parrotBeakColourField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBeakLength(ui->parrotBeakLengthField->currentText().toLower().toUtf8().constData());
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "finch"){
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setWingSpan(ui->finchWingSpanField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBeakColour(ui->finchBeakColourField->currentText().toLower().toUtf8().constData());
            animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->setBeakLength(ui->finchBeakLengthField->currentText().toLower().toUtf8().constData());
        }

    }



    animalsClientsList.clients.get(clientLoggedIn)->setEdited(true);

    qDebug ("User Sucessfully Set the Non-Physical Preferences properly.");
    QMessageBox::information(this,"Seting Non-Physical Preferences Success (STATUS:200)", "You've Sucessfully Set the ranks.");





}


/*
 * This function Updates the UI for Ranks And Preferences
*/
void MainWindow::updateRanksAndPreferencesUI(){





    //Update UI

    qDebug ("First Stage ");
    //Physical Attributes
    for(int i =0; i<animalsClientsList.clients.get(clientLoggedIn)->ranks.size() ;i++){

       qDebug ("While runnig Stage ");
        //Mammals
        if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "dog"){

            cout << "loop index: "<<i<<endl;

           qDebug ("Dog testing ?");
           ui->dogBuildOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBuild()));
           ui->dogFurColourOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getMammalHairColour()));
           ui->dogFurLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getMammalHairLength()));
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "cat"){
            cout << "loop index: "<<i<<endl;
            qDebug ("Cat testing ?");
            ui->catBuildOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBuild()));
            ui->catFurColourOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getMammalHairColour()));
            ui->catFurLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getMammalHairLength()));
        }

        //Amphibians
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "frog"){
            cout << "loop index: "<<i<<endl;
            qDebug ("Frog testing ?");
            ui->frogBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->frogBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->frogBuildOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBuild()));

        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "salamander"){
            cout << "loop index: "<<i<<endl;
            qDebug ("Salamander testing ?");
            ui->salamanderBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->salamanderBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->salamanderBuildOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBuild()));
        }

        //Reptiles
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "snake"){
            cout << "loop index: "<<i<<endl;

            qDebug ("Snake testing ?");

            ui->snakeBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->snakeBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->snakeScaleTypeOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getScaleType()));
        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "lizard"){
            cout << "loop index: "<<i<<endl;
            qDebug ("lizard testing ?");
            ui->lizardBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->lizardBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->lizardScaleTypeOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getScaleType()));
        }

        //Fish
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "betta"){
            cout << "loop index: "<<i<<endl;
            qDebug ("betta testing ?");
            ui->bettaBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->bettaBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->bettaFinnSizeOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getFinnsSize()));


        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "goldfish"){
            qDebug ("Gold fish testing ?");
            ui->goldfishBodyPatternOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBodyPattern()));
            ui->goldfishBodyLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getLength()));
            ui->goldfishFinnSizeOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getFinnsSize()));
        }

        //Bird
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "parrot"){
            qDebug ("Parrot testing ?");
            ui->parrotWingSpanOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getWingSpan()));
            ui->parrotBeakColourOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBeakColour()));
            ui->parrotBeakLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBeakLength()));


        }
        else if(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getSpecies() == "finch"){
            qDebug ("Finch testing ?");
            ui->finchWingSpanOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getWingSpan()));
            ui->finchBeakColourOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBeakColour()));
            ui->finchBeakLengthOutField->setText(QString::fromStdString(animalsClientsList.clients.get(clientLoggedIn)->ranks.get(i)->getBeakLength()));
        }

    }



    //Ranks
    ui->dogPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("dog")));
    ui->catPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("cat")));

    ui->bettaPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("betta")));
    ui->goldfishPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("goldfish")));

    ui->snakePreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("snake")));
    ui->lizardPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("lizard")));

    ui->frogPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("frog")));
    ui->salamanderPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("salamander")));

    ui->finchPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("finch")));
    ui->parrotPreferenceField->setText(QString::number(animalsClientsList.clients.get(clientLoggedIn)->ranks.getRank("parrot")));









}






/*
 * This function redirects the client back to Ranks and Prefernecs Page (CLIENT VIEW)
*/
void MainWindow::on_viewRanksAndPreferencesBtn_clicked()
{
    ui->viewClientProfilePage->setCurrentIndex(3);

    //Call update on the list.

    updateRanksAndPreferencesUI();
}


//===============================================> END OF CLIENT CODE LOGIC <================================================

//===============================================> TRANSITIONS OF USER FLOW <================================================



/*
 * This function redirects the client back to main menu from login page( the very firs page)
*/
void MainWindow::on_mainMenuBtnFromLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/*
 * This function redirects the client back to their profile page from view Ranks and Preferneces to profle page.(CLIENT VIEW)
*/
void MainWindow::on_backToProfileFromViewRanksAndPrefecnesBtn_clicked()
{
    ui->viewClientProfilePage->setCurrentIndex(0);
}



/*
 * This function redirects the client to setuo their animal Physical Preferences.
*/
void MainWindow::on_setPhysPreferencesBtn_clicked()
{
  ui->viewClientProfilePage->setCurrentIndex(2);
  clearFields(3);
}


/*
 * This function redirects the client back to their profile page from set preferneces to profle page.(CLIENT VIEW)
*/
void MainWindow::on_backToProfileFromPhysPageBtn_clicked()
{
    ui->viewClientProfilePage->setCurrentIndex(0);
}




/*
 * This function redirects the client back to their profile page from ranks to profle page.(CLIENT VIEW)
*/
void MainWindow::on_backPrefenecesBtn_clicked()
{
    ui->viewClientProfilePage->setCurrentIndex(0);
}

/*
 * This function redirects the client back to their prefernecs page.(CLIENT VIEW)
*/
void MainWindow::on_setAnimalPreferencesBtn_clicked()
{
    ui->viewClientProfilePage->setCurrentIndex(1);
    clearFields(2);
}


/*
 * This function saves the new edits for an animal(from staff only).
*/
void MainWindow::on_saveAnimalsEditsBtn_clicked()
{
    saveNewEdits();
}


/*
 * ---> This function allows the staff to edit an animal
*/
void MainWindow::on_editAnimalDetailsBtn_clicked()
{
    ui->viewAnimalsListPopUp->setCurrentIndex(1);
    ui->animalViewTitle->hide();
    ui->animalEditTitle->show();
    enableAnimalEdits(true); // disable editing.
    ui->saveAnimalsEditsBtn->show();
    displayAnimalDetails();
    renderSpeciesAndPhysAttributes();
}


/*
    *This function Updates the view UI. for viewing the clients list.
*/
void MainWindow::on_viewClientsBtn_clicked()
{
    int VIEW_CLIENTS_BTN = 3;
    ui->animatePopUp->hide();
    ui->viewClientsListPopUp->setCurrentIndex(0);
    ui->viewClientDetailsBtn->hide();
    showTheCorrectWindow(&VIEW_CLIENTS_BTN);
    initClientList();
}



/*
    * This function shows the list of animals on GUI.
*/
void MainWindow::on_animalsListBtn_clicked()
{
    int VIEW_ANIMALS_LIST = 0;
    showTheCorrectWindow(&VIEW_ANIMALS_LIST);

    ui->animatePopUp->hide();
    updateAnimalListUI();
    ui->viewAnimalsListPopUp->setCurrentIndex(0);
    ui->viewAnimalDetailsBtn->hide();
    ui->editAnimalDetailsBtn->hide();
}

/*
    - The function below views the menu for adding an animal
*/
void MainWindow::on_addClientBtn_clicked()
{

    ui->animatePopUp->hide();
    int CLIENT_VIEW_BTN_ID = 2;
    showTheCorrectWindow(&CLIENT_VIEW_BTN_ID);

    //Form should be at index 1 so the staff fills the proper info.
    ui->clientForm->setCurrentIndex(0);
    clearFields(1);

    //Reset validation.
    ui->clientErrMessage->hide();
    ui->clientSucessMessage->hide();
}


/*
    - The function below views the menu for adding an animal
*/
void MainWindow::on_animalAddBtn_clicked()
{
    int ANIMAL_VIEW_BTN_ID = 1;
    showTheCorrectWindow(&ANIMAL_VIEW_BTN_ID);

    ui->animatePopUp->hide();
    //Form should be at index 1 so the staff fills the proper info(for animal).
    ui->animalForm->setCurrentIndex(0);
    clearFields(0);
    //Reset validation.
    ui->errorMessage->hide();
    ui->successMessage->hide();
}

/*
    - The function below closes the menu for adding a animal and cancels adding an animal
*/
void MainWindow::on_closeAnimalBtn_clicked(){
    ui->addAnimalPopUp->hide();
    ui->errorMessage->hide();
    ui->successMessage->hide();
    clearFields(0);

}


/*
    *This function swaps pages(going forward) for when a client fills out their info.
*/
void MainWindow::on_nextInfoBtn_clicked(){ui->clientForm->setCurrentIndex(1);}


/*
    *This function swaps pages(going backward) for when a client fills out their info.
*/
void MainWindow::on_backInfoBtn_clicked(){ui->clientForm->setCurrentIndex(0);}

/*
    *This function swaps pages(going forward) for when the staff fills out the info for animal
*/
void MainWindow::on_animalNextBtn_clicked(){ui->animalForm->setCurrentIndex(1);}

/*
    *This function swaps pages(going backward) for when the staff fills out the info for animal
*/
void MainWindow::on_animalBackBtn_clicked(){ui->animalForm->setCurrentIndex(0);}


/*
    *This function swaps pages(going backward to Non-physical attributes) for when the staff fills out the info for animal
*/
void MainWindow::on_backToNonPhysBtn_clicked()
{
    ui->animalForm->setCurrentIndex(1);
}

/*
    *This function swaps pages(going forward to physical attributes) for when the staff fills out the info for animal
*/
void MainWindow::on_animalNextPhysBtn_clicked()
{
    ui->animalForm->setCurrentIndex(2);
}

/*
    *This function swaps pages(going to main menu from staff view)
*/
void MainWindow::on_backToMenuFromStaffBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
    *This function swaps pages(going to main menu from client view)
*/
void MainWindow::on_backToMainMenuFromClientViewBtn_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}

//Client view animal details going back(on the client view, user logged in as a client).
void MainWindow::on_backViewAnimalsToClientBtn_clicked()
{
    ui->viewAnimalsFromClientView->setCurrentIndex(0);
}



/*
    *This function closes the view for adding a client. and resets the forms.
*/
void MainWindow::on_closeClientBtn_clicked()
{
    ui->addClientPopUp->hide();
    ui->clientErrMessage->hide();
    ui->clientSucessMessage->hide();
    clearFields(1);
}

//Client view animal details going forward(on the client view, user logged in as a client).
void MainWindow::on_animalViewDetailClientBtn_clicked()
{
    ui->viewAnimalsFromClientView->setCurrentIndex(1);
    displayAnimalDetailsFromClient();

}


/*
    *This function shows the animals  detailed profile(from staff View)
*/
void MainWindow::on_viewAnimalDetailsBtn_clicked()
{
   ui->viewAnimalsListPopUp->setCurrentIndex(1);
   ui->animalViewTitle->show();
   ui->animalEditTitle->hide();
   displayAnimalDetails();
   ui->saveAnimalsEditsBtn->hide();
   enableAnimalEdits(false); // disable editing.





}

/*
    *This function goes to filling out client's non-physicl  attributes
*/
void MainWindow::on_nextToClientNonPhysPreBtn_clicked()
{
    ui->clientForm->setCurrentIndex(2);
}



/*
    *This function goes back to filling out client's phsical attributes
*/
void MainWindow::on_backToCharacterTraitsBtn_clicked()
{
    ui->clientForm->setCurrentIndex(1);
}


/*
    *This function goes back to the animals list(From staff view)
*/
void MainWindow::on_backViewAnimalsBtn_clicked()
{
    ui->viewAnimalsListPopUp->setCurrentIndex(0);
}

/*
    *This function views the animals list(From the clients page).
*/
void MainWindow::on_clientAnimalsBtn_clicked()
{
    int VIEW_ANIMALS_LIST_FROM_CLIENT = 5;
    showTheCorrectWindow(&VIEW_ANIMALS_LIST_FROM_CLIENT);
    updateAnimalListFromClientView();
    ui->viewAnimalsFromClientView->setCurrentIndex(0);
}

//This function views the details of a client(going foward)
void MainWindow::on_viewClientDetailsBtn_clicked()
{
    ui->viewClientsListPopUp->setCurrentIndex(1);
    displayClientDetails();
}


//This function views the details of a client(going backward)

void MainWindow::on_backtoClientsListBtn_clicked()
{
    ui->viewClientsListPopUp->setCurrentIndex(0);
}


/*
 *  This function goes back to the matches table. (Staff VIEW)
*/
void MainWindow::on_backToMatchesSummaryBtn_clicked()
{
      ui->acmPage->setCurrentIndex(0);
}

/*
 *  This function goes to the detailed matches table. (Staff View)
*/
void MainWindow::on_viewDetailedMatchBtn_clicked()
{
      ui->acmPage->setCurrentIndex(1);
      updateAcmMatchesDetailedUI();
}

/*
 * This function closes the animals list view.
*/
void MainWindow::on_closeAnimalsListBtn_clicked()
{
    ui->viewAnimalsListPopUp->hide();
}




/*
 * This functions closes the clients view. (STAF VIEW)
*/
void MainWindow::on_closeClientsViewBtn_clicked()
{
    ui->viewClientsListPopUp->hide();
}

/*
 *  This function closes ACM Page (STAF VIEW)
*/
void MainWindow::on_closeAcmPageBtn_clicked()
{
    ui->acmPage->hide();
}


//========================================> END OF TRANSITIONS OF USER FLOW <=====================================================


/*
 * ========================================>     EVENT LISTNERS   <=====================================================================
*/


/*
    *This function determines which animal from the table was pressed to display its detailed information.(From Client View)
*/
void MainWindow::on_animalsListFromClientView_cellPressed(int row, int column)
{
    //Ignore the column.
     ui->animalViewDetailClientBtn->show();
     rowTable = row;
     columnTable = column;
}

/*
    *This function determines which animal from the table was pressed to display its detailed information.(From Staff View)
*/
void MainWindow::on_animalsListTable_cellPressed(int row, int column)
{
   //Ignore the column.
    ui->viewAnimalDetailsBtn->show();
    ui->editAnimalDetailsBtn->show();
    rowTable = row;
    columnTable = column;
}

/*
    *This function determines which client from the table was pressed to display its detailed information.(From Staff View)
*/
void MainWindow::on_clientListTable_cellPressed(int row, int column)
{
    //Ignore the column.
     ui->viewClientDetailsBtn->show();
     rowTable = row;
     columnTable = column;
}

/*
    * This event Listener function, checks what type of animal the user chooses. If they choose a dog, then all list of species for a dog appear.
    * It also shows the list of physical attributes for an animal.
*/

void MainWindow::on_animalTypeField_currentTextChanged(const QString &typeOfAnimal)
{
    //Mammals
    if(typeOfAnimal == "Dog"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Pitbull"<<"Siberian Husky"<<"Bulldog" << "German Shepherd" <<"Boxer" <<"Pug");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysFurLengthField->show(); //Attriute 1 for a dog.
        ui->animalPhysFurColourField->show(); //Attriute 2 for a dog.
        ui->animalPhysBuildField->show();     //Attriute 3 for a dog.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysBodyPatternField->hide();
        ui->animalPhysBodyLengthField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysScaleTypeField->hide();



    }
    else if(typeOfAnimal == "Cat"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Persian Cat"<<"Ragdoll"<<"Bengal Cat" << "Birman" <<"American Curl" <<"Savannah Cat");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysFurLengthField->show(); //Attriute 1 for a Cat.
        ui->animalPhysFurColourField->show(); //Attriute 2 for a Cat.
        ui->animalPhysBuildField->show();     //Attriute 3 for a Cat.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysBodyPatternField->hide();
        ui->animalPhysBodyLengthField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysScaleTypeField->hide();

    }
    // End of Mammals

    // Birds
    else if(typeOfAnimal == "Parrot"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Grey Parrot"<<"Cockatiel"<<"Budgerigar" << "Sun Conure" <<"Kea" <<"Night Parrot");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysWingSpanField->show();   //Attriute 1 for a Parrot.
        ui->animalPhysBeakLengthField->show(); //Attriute 2 for a Parrot.
        ui->animalPhysBeakColourField->show(); //Attriute 3 for a Parrot.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysBodyPatternField->hide();
        ui->animalPhysBodyLengthField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysBuildField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
    }
    else if(typeOfAnimal == "Finch"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"House Finch"<<"Purple Finch"<<"Zebra Finch" << "American Goldfinch" <<"Java Sparrow" <<"Red Crossbill");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysWingSpanField->show();   //Attriute 1 for a finch.
        ui->animalPhysBeakLengthField->show(); //Attriute 2 for a finch.
        ui->animalPhysBeakColourField->show(); //Attriute 3 for a finch.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysBodyPatternField->hide();
        ui->animalPhysBodyLengthField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysBuildField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();

    }
    // End of birds

    // Fish
    else if(typeOfAnimal == "Betta"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Veiltail"<<"Crowntail"<<"Combtail" << "Double tail" <<"Spadetail" <<"Halfmoon" << "Delta" << "Super Delta" << "Rosetail");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysFinnSizeField->show(); //Attriute 1 for a Betta.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Betta.
        ui->animalPhysBodyPatternField->show(); //Attriute 3 for a Betta.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysBuildField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();

    }
    else if(typeOfAnimal == "Goldfish"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Comet"<<"Fantail"<<"Lionhead" << "Oranda" <<"Ryukin" <<"Bubble Eye" << "Shubunkin" << "Black Moor");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysFinnSizeField->show(); //Attriute 1 for a Goldfish.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Goldfish.
        ui->animalPhysBodyPatternField->show(); //Attriute 3 for a Goldfish.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysBuildField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();

    }
    // End of fish.

    // Amphibians
    else if(typeOfAnimal == "Frog"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Tailed Frog"<<"Toads"<<"Tree Frogs" << "Western Toad" <<"American Toad" <<"Fowler's toad" << "Oophaga" << "Spring peeper");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysBodyPatternField->show(); //Attriute 1 for a Frog.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Frog.
        ui->animalPhysBuildField->show(); //Attriute 3 for a Frog.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();

    }
    else if(typeOfAnimal == "Salamander"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Fire Salamander"<<"Hellbender"<<"Tiger Salamander" << "Spotted Salamander" <<"Red Salamander" <<"Alpine Salamander" << "Spring Salamander" << "Marbled Salamander");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysBodyPatternField->show(); //Attriute 1 for a Salamander.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Salamander.
        ui->animalPhysBuildField->show(); //Attriute 3 for a Salamander.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysScaleTypeField->hide();
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();

    }
    // End of Amphibians

    // Reptiles
    else if(typeOfAnimal == "Snake"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Garter Snake"<<"Rattlesnakes"<<"Water Snakes" << "Kingsnakes" <<"Milk Snake" <<"Pythons" << "King Cobra" << "Boa constrictor" << "Ball Python");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysBodyPatternField->show(); //Attriute 1 for a Salamander.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Salamander.
        ui->animalPhysScaleTypeField->show(); //Attriute 3 for a Salamander.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();
        ui->animalPhysBuildField->hide();

    }
    else if(typeOfAnimal == "Lizard"){
        ui->animalSpeciesField->clear();
        QStringList list=(QStringList()<<"Select the type of species" <<"Gold Tegu"<<"Green Anole"<<"Gila Monster" << "Green Iguana" <<"Desert Iguana" <<"Brown Anole" << "Sand Lizard" << "Marine Iguana" << "Nile Monitor");
        ui->animalSpeciesField->addItems(list);
        ui->animalPhysBodyPatternField->show(); //Attriute 1 for a Salamander.
        ui->animalPhysBodyLengthField->show(); //Attriute 2 for a Salamander.
        ui->animalPhysScaleTypeField->show(); //Attriute 3 for a Salamander.
        //Hide other fields(physical attributes not related to this animal)
        ui->animalPhysFinnSizeField->hide();
        ui->animalPhysFurLengthField->hide();
        ui->animalPhysFurColourField->hide();
        ui->animalPhysWingSpanField->hide();
        ui->animalPhysBeakLengthField->hide();
        ui->animalPhysBeakColourField->hide();
        ui->animalPhysBuildField->hide();

    }
    //End of Reptiles



}


/*
 * This function even listener and handles the row for the table for matches list.
*/
void MainWindow::on_matchesList_cellPressed(int row, int column)
{
    ui->viewDetailedMatchBtn->show();
    rowTable = row;
    columnTable = column;
}

//==================================>  END OF EVENT LISTENERS <=====================================




//===================================> BEAUTIFCATION FOR THE UI <===================================

/*
 * The function below, is just to clear the fields once the user inputed the data for either adding animal or client fields.
*/
void MainWindow::clearFields(int typeOfAdding){

    //Clearing "Adding Animal" Fields
    if(typeOfAdding == 0){
        ui->animalNameField->setText("");
        ui->animalTypeField->setCurrentIndex(0);
        ui->animalAgeField->setCurrentIndex(0);
        ui->animalColourField->setCurrentIndex(0);
        ui->animalSpeciesField->setCurrentIndex(0);
        ui->animalHeightField->setText("");
        ui->animalWeightField->setText("");
        ui->animalGenderField->setCurrentIndex(0);

        //Clearing Attrubites(Animals)
        ui->animalIndividualismField->setCurrentIndex(0);
        ui->animalActivenessField->setCurrentIndex(0);
        ui->animalIntelligenceField->setCurrentIndex(0);
        ui->animalAffectionismField->setCurrentIndex(0);
        ui->animalDisciplineField->setCurrentIndex(0);
        ui->animalAssertivenessField->setCurrentIndex(0);
        ui->animalPlayfulnessField->setCurrentIndex(0);
        ui->animalEnergeticField->setCurrentIndex(0);
        ui->animalDiurnalField->setCurrentIndex(0);
        ui->animalHabitatField->setCurrentIndex(0);
        ui->animalSpaciousnessField->setCurrentIndex(0);
        ui->animalAppetiteField->setCurrentIndex(0);
    }
    //Clearing "Adding Client" Fields
    else if(typeOfAdding == 1){
         //Clearing basic info
         ui->clientFNameField->setText("");
         ui->clientLNameField->setText("");
         ui->clientAgeField->setText("");
         ui->clientEmailField->setText("");
         ui->clientPhoneField->setText("");
         ui->clientGenderFIeld->setCurrentIndex(0);

        //Clearing Attrubites(clients)

        ui->clientActivenessField->setCurrentIndex(0);
        ui->clientAffectionismField->setCurrentIndex(0);
        ui->clientHabitatPreferenceField->setCurrentIndex(0);
        ui->clientDiurnalField->setCurrentIndex(0);


    }
    //Clear fields for ranks.
    else if(typeOfAdding == 2){
        ui->preferenceBettaField->setText("");
        ui->preferenceCatField->setText("");
        ui->preferenceDogField->setText("");
        ui->preferenceFinchField->setText("");
        ui->preferenceFrogField->setText("");
        ui->preferenceGoldfisheField->setText("");
        ui->preferenceLizardField->setText("");
        ui->preferenceParrotField->setText("");
        ui->preferenceSalamanderField->setText("");
        ui->preferenceSnakeField->setText("");
    }

    else if(typeOfAdding == 3){
        //Mammal
        ui->dogFurBuildField->setCurrentIndex(0);
        ui->dogFurColourField->setCurrentIndex(0);
        ui->dogFurLengthField->setCurrentIndex(0);
        ui->catFurBuildField->setCurrentIndex(0);
        ui->catFurColourField->setCurrentIndex(0);
        ui->catFurLengthField->setCurrentIndex(0);

        //Bird
        ui->parrotBeakColourField->setCurrentIndex(0);
        ui->parrotBeakLengthField->setCurrentIndex(0);
        ui->parrotWingSpanField->setCurrentIndex(0);
        ui->finchBeakColourField->setCurrentIndex(0);
        ui->finchBeakLengthField->setCurrentIndex(0);
        ui->finchWingSpanField->setCurrentIndex(0);

        //Reptile
        ui->snakeBodyLengthField->setCurrentIndex(0);
        ui->snakeBodyPatternField->setCurrentIndex(0);
        ui->snakeScaleTypeField->setCurrentIndex(0);
        ui->lizardBodyLengthField->setCurrentIndex(0);
        ui->lizardBodyPatternField->setCurrentIndex(0);
        ui->lizardScaleTypeField->setCurrentIndex(0);

        //Fish
        ui->goldfishBodyLengthField->setCurrentIndex(0);
        ui->goldfishBodyPatternField->setCurrentIndex(0);
        ui->goldfishFinnSizeField->setCurrentIndex(0);

        ui->bettaBodyLengthField->setCurrentIndex(0);
        ui->bettaBodyPatternField->setCurrentIndex(0);
        ui->bettaFinnSizeField->setCurrentIndex(0);

        //Amphiban
        ui->salamanderBodyLengthField->setCurrentIndex(0);
        ui->salamanderBodyPatternField->setCurrentIndex(0);
        ui->salamanderBuildField->setCurrentIndex(0);

        ui->frogBodyLengthField->setCurrentIndex(0);
        ui->frogBodyPatternField->setCurrentIndex(0);
        ui->frogBuildField->setCurrentIndex(0);

    }

}


/*
    *This function takes an id from a menu button, in order to know which window to display
*/
void MainWindow::showTheCorrectWindow(int* id){

    //Views for Staff view.
    int viewAnimalsBtn = 0,addAnimalsBtn = 1, addClientBtn = 2, viewClientsBtn =3, launchAcmBtn = 4 ;


    //Views for Client view.
    int viewAnimalsFromClientViewBtn = 5, viewEditProfileFromClientViewBtn = 6, viewAcmPageFromStaffView = 7;

    //Show view for animals list
    if(*id == viewAnimalsBtn){
        clearFields(0);
        ui->addAnimalPopUp->hide();
        ui->addClientPopUp->hide();
        ui->viewClientsListPopUp->hide();
        ui->acmPage->hide();
        ui->viewAnimalsListPopUp->show();

    }
    //Show view for adding aniamls
    else if(*id == addAnimalsBtn){
        ui->viewAnimalsListPopUp->hide();
        ui->viewClientsListPopUp->hide();
        ui->addClientPopUp->hide();
        ui->acmPage->hide();
        ui->addAnimalPopUp->show();
    }
    //Show view for adding clients
    else if(*id == addClientBtn){
        ui->viewAnimalsListPopUp->hide();
        ui->viewClientsListPopUp->hide();
        ui->addAnimalPopUp->hide();
        ui->acmPage->hide();
        ui->addClientPopUp->show();
    }
    //Show view for viewing clients
    else if(*id == viewClientsBtn){
        ui->viewAnimalsListPopUp->hide();
        ui->addAnimalPopUp->hide();
        ui->addClientPopUp->hide();
        ui->acmPage->hide();
        ui->viewClientsListPopUp->show();
    }
    else if (*id == viewAcmPageFromStaffView){
        ui->viewAnimalsListPopUp->hide();
        ui->addAnimalPopUp->hide();
        ui->addClientPopUp->hide();
        ui->viewClientsListPopUp->hide();
        ui->acmPage->show();
    }
    //Show View for Launching ACM algorithim

    //Leave space for when the ACM actuall works.

    //CLIENT VIEW IDS

    else if(*id == viewAnimalsFromClientViewBtn){
        ui->viewAnimalsFromClientView->show();
        ui->viewClientProfilePage->hide();
    }

    else if(*id == viewEditProfileFromClientViewBtn){
        ui->viewClientProfilePage->show();
        ui->viewAnimalsFromClientView->hide();
    }


}
//===================================> END OF BEAUTIFCATION FOR THE UI <===================================





/*
 *  This function does authiecation for user login.
*/
void MainWindow::on_loginBtn_clicked()
{



    //Check Err Handling
    if(ui->userLoginEmail->text().isEmpty()){

        qDebug ("User left field empty.");
        QMessageBox::critical(this,"Login Client Error 315xcdXF1", "Invalid information! You left the login username field empty..");
        return;

    }

    //Check Err Handling
    for(int i=0; i< animalsClientsList.clients.size();i++){

        if(ui->userLoginEmail->text().trimmed().toLower().toUtf8().constData() == animalsClientsList.clients.get(i)->getEmail()){
            clientLoggedIn = i;
            break;
        }

        if(i == animalsClientsList.clients.size()-1 ){
            qDebug ("User isn't found..");
            QMessageBox::critical(this,"Login Error 001F13Y3Z", "Try Again! The user Isn't found or you could possibily made a typo.");
            return;
        }
    }

    //Passeed Err Handling

    ui->stackedWidget->setCurrentIndex(2);


    ui->userLoggedIn->setText(QString::fromStdString( animalsClientsList.clients.get(clientLoggedIn)->getFirstName() + " " + animalsClientsList.clients.get(clientLoggedIn)->getLastName()));


}



/*
 *
*/
void MainWindow::on_launchACM_clicked()
{
    //Steps to ACM.







    ui->animatePopUp->show();

    //1. Animate Loading screen(later).
    ui->animatePopUp->setMovie(movie);







    movie->start();



    //2. run algorithm
    animalsClientsList.runACM();


    qDebug("value is %d", movie->state());

   connect(movie, &QMovie::frameChanged, [=](int frameNumber){
        if(frameNumber == movie->frameCount()-1){
            movie->stop();

            qDebug("true?");
            ui->viewDetailedMatchBtn->hide();
            int VIEW_ANIMALS_LIST = 7;
            showTheCorrectWindow(&VIEW_ANIMALS_LIST);
            ui->acmPage->setCurrentIndex(0);

            ui->animatePopUp->hide();
        }
    });



    //3. Update UI
    updateAcmMatchesUI();
}


/*
 * This function Updates the detailed matches List (STAFF VIEW)
*/
void MainWindow::updateAcmMatchesDetailedUI(){

    //Info between client and animal
    ui->clientMatchNameField->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[rowTable].getClient()->getFirstName()));
    ui->animalMatchNameField->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[rowTable].getAnimal()->getName()));
    ui->animalMatchSpeciesField->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[rowTable].getAnimal()->getSpecies()));
    ui->animalMatchTypeField->setText(QString::fromStdString(animalsClientsList.optimalSetMatches[rowTable].getAnimal()->getType()));



    //Non-Phsyical stats.
    ui->nonPhysMatchTotalField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getNonPhysicalTotal()));
    ui->nonPhysAverageMatchField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getNonPhysicalAverage()));

    //Phsyical stats.
    ui->physTotalMatchField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getPhysicalTotal()));
    ui->physAverageMatchField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getPhysicalAverage()));


    //Overall stats.
    ui->overallMatchTotalField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getMatchTotal()));
    ui->overallAverageMatchField->setText(QString::number(animalsClientsList.optimalSetMatches[rowTable].getMatchAverage()));

}



