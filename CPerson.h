//Header CPerson
// @Author = Jan van Dick

#ifndef CPERSON_H
#define CPERSON_H

class CGame;
class CInventory;
class CDialog;

#include "CColor.h"
#include "CFunctions.h"
#include "CInventory.h"
#include "CGame.h"
#include "CQuest.h"
#include "CDialog.h"


class CPerson
{
private:
    char* m_chName;     //Name of the person (might change during he game
    int m_ID;           //Id clearly identifing this person

    //Game instance
    CGame* m_game;

    //Attributes:
    unsigned int m_maxLife;     //maximun of life 
    unsigned int m_Life;        //Lifepoints

    //Money and items
    int m_Gold;                 //Gold 
    CInventory* m_Inventory;    //Person's inventory
    
    //Dialog
    CDialog* m_Dialog;          //Dialog of a person (represented through a graph)
    
    //Quest handeling
    CList<CQuest>* m_Quests;            //All quests a person sets during the game
    void(CQuest::*m_createQuest)();   //create all of a persons quests
    

public:
    //Constructor
    CPerson(char* chName, int ID, CGame* game,  void(CDialog::*dialog)(), void (CQuest::*createQuest)());


    //Getter
    
    //Get person's name
    char* getName() {
        return m_chName;
    }

    //Get ID
    int getID() {
        return m_ID;
    }

    //getQuests
    CList<CQuest>* getQuests() {
        return m_Quests;
    }

    //getQuest: return a quest (search by name)
    CQuest* getQuest(char* chQuestName) {
        return m_Quests->getElement(chQuestName);
    }

    //getQuest: return a quest (search by number)
    CQuest* getQuest(int questNumber) {
        return m_Quests->getElement(questNumber);
    }

    void setDialog(void (CPerson::*dialog)()) {}


    //Dialogs and quests:

    //call dialog
    void callDialog();

    void dialog_Standard();
    

    //--- Karl Marx ---//
    //Dialogs
    void dialog1_KarlMarx();
    void dialog2_KarlMarx();
    void dialog3_KarlMarx();
    
    //--- Dog --- //
    //Dialogs
    void dialog_Dog();

    //--- Friedirch Engels ---//
    //Dialogs
    void dialog_FriedrichEngels();
};

#endif
