//gameFactory
//Creates the game, e.a. calls the different factorys to create the world

#include "CGame.h"
using namespace std;


void CGame::worldFactory()
{
    //***** Create Rooms **********************************************************************

    //-- default room
    CRoom* defaultRoom = roomFactory((char*)"default room", 0);

    //-- Lenins tomb
    CRoom* leninsTomb   = roomFactory((char*)"Lenins tomb", 1);

    //-- Stalins tomb
    CRoom* stalinsTomb  = roomFactory((char*)"Stalins tomb", 2);



    //***** Create doors **********************************************************************

    //-- defaut room
    vector<string> sDescriptions = {"Desc1", "Desc2"};
    doorFactory((char*)"default door", defaultRoom, defaultRoom, 0, 0, sDescriptions, 
        &CDoor::DescCall_Standard);
    
    //-- Lenins tomb
    sDescriptions = {"Desc1", "Desc2"};
    doorFactory((char*)"exit lenins tomb", leninsTomb, defaultRoom, 0, 1, sDescriptions, 
        &CDoor::DescCall_Standard);
    sDescriptions = {"Desc1", "Desc2"};
    doorFactory((char*)"further into the cave", leninsTomb, defaultRoom, 1, 2, sDescriptions, 
        &CDoor::DescCall_Standard);
    sDescriptions = {"LeninsTomb-StalinsTomb1.txt", "LeninsTomb-StalinsTomb2"};
    doorFactory((char*)"old stone door", leninsTomb, stalinsTomb, 2, 3, sDescriptions, 
        &CDoor::DescCallLeninsTomb);

    //-- Stalins tomb
    sDescriptions = {"StalinsTomb-LeninsTomb1.txt"};
    doorFactory((char*)"Lenins tomb", stalinsTomb, leninsTomb, 0, 4, sDescriptions,
        &CDoor::DescCall_Standard);



    //***** Create people *********************************************************************

    //-- Default
    personFactory((char*)"Default", 0, defaultRoom, &CDialog::createDialogMath, 
        &CQuest::quest_Standard);

    //-- Karl Marx
    personFactory((char*)"Karl Marx", 1, leninsTomb, &CDialog::createDialogMarx,
        &CQuest::quest_Marx);

    //-- a dog
    personFactory((char*)"a dog", 2, leninsTomb, &CDialog::createDialogDog, 
        &CQuest::quest_Standard);

    //-- Friedrich Engels
    personFactory((char*)"Friedrich Engels", 3, stalinsTomb, &CDialog::createDialogEngels,
        &CQuest::quest_Standard);


    //***** Items ****************************************************************************
    
    //-- Healing potion: restore 20 life
    itemFactory((char*)"healing potion", 10, 2, &CItem::use_Healingpotion, 0);
    
    //-- Strength potion: adds +1 strength
    itemFactory((char*)"strength potion", 20, 2, &CItem::use_Strengthpotion, 1);

    //--Skill potion: adds +1 skill
    itemFactory((char*)"skill potion", 20, 2, &CItem::use_Skillpotion, 2);


    //***** Player ***************************************************************************
    char* chPlayerName = playerInput();
    CInventory* playersInventory = new CInventory;
    playersInventory->add(m_listAllItems->getElement((char*)"healing potion"));
    playersInventory->add(m_listAllItems->getElement((char*)"strength potion"));
    playersInventory->add(m_listAllItems->getElement((char*)"skill potion"));
    playerFactory(chPlayerName, leninsTomb, playersInventory); 
}


//Room factory
CRoom* CGame::roomFactory(char* chName, int num)
{

    CList<CDoor> *doors = new CList<CDoor>;         //list with all doors in this room
    CList<CPerson> *people = new CList<CPerson>;     //list of all people in this room
    //Create room
    CRoom *room = new CRoom(chName, doors, people, num);

    m_listAllRooms->add(room);   //Add room to list of all rooms

    return room;    //Return room
}


//Door factory
void CGame::doorFactory(char* chName, CRoom* myRoom, CRoom* linkedRoom, int localNum, int globalNum, 
                        vector<string> sDescriptions, void(CDoor::*callDescription)())
{
    //Create new door
    CDoor* door = new CDoor(chName, linkedRoom, localNum, globalNum, sDescriptions, callDescription);

    //add door to list of the room owning the door (myRoom)
    myRoom->getDoors()->add(door);
    //Add door to list of all doors
    m_listAllDoors->add(door);
} 

//Person factory
void CGame::personFactory(char* chName, int num, CRoom* myRoom, void(CDialog::*func_dialog)(), 
                            void(CQuest::*func_quest)())
{
    CPerson* person = new CPerson(chName, num, this, func_dialog, func_quest);
    myRoom->getPeople()->add(person);
    m_listAllPeople->add(person);
}

//Item factory
void CGame::itemFactory(char* chName, int price, int quantity, void(CItem::*func_useItem)(), int num)
{
    CItem* item = new CItem(chName, this, price, quantity, func_useItem, num);
    m_listAllItems->add(item);
}

//Player factory
void CGame::playerFactory(char* chName, CRoom* startRoom, CInventory* playersInventory) {
    m_Player = new CPlayer(chName, startRoom, playersInventory);
}

//Player input 
char* CGame::playerInput()
{
    //Variables 
    char* chPlayerCommand = new char[128];

    cout << "Enter you player's name: " << endl;
    cout << ">"; 
    cin.getline(chPlayerCommand, 127);
 
    return chPlayerCommand;
}
    
     
