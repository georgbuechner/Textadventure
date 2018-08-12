//Header CPlayer
// @Author = Jan van Dick

#ifndef CPLAYER_H
#define CPLAYER_H

class CQuest;
class CQuestStep;

#include <map>
#include "CRoom.h"
#include "CFunctions.h"
#include "CColor.h"
#include "CInventory.h"
#include "CQuest.h"
#include "CQuestStep.h"

using namespace std;

//Forward declarations:
class CInventory;

class CPlayer
{
private:

    //Attributes 
    char m_chName[128];    //Name of Player (can be chosen at the beginning of the game)
    unsigned int m_maxLife;         //maximum of life
    unsigned int m_Life;            //Lifepoints
    unsigned int m_Strength;        //Strength
    unsigned int m_Skill;           //Skill 
    int m_Morality;                 //Moralpoints

    //Money and items
    int m_Gold;              //Gold
    CInventory* m_Inventory; //Player's inventory

    CRoom* m_curRoom;       //The room the player is currently in

    //Players functions:
    typedef void(CPlayer::*m_PlayerFunction)(char*); //Function-pointer points to various player 
                                                    //functions
    map<char*, pair<m_PlayerFunction, const char*> > *m_FunctionMap;    //Map containing all player functions
    
    CList<CQuest>* m_quests;    //Quests
    
public:
    //Constructor
    CPlayer(char* chName, CRoom* curRoom, CInventory* Inventory);

    //Getter

    //Get player's name
    char* getName() {
        return m_chName;
    }

    //get maximum life
    unsigned int getMaxLife() {
        return m_maxLife;
    }

    //get life
    unsigned int getLife() {
        return m_Life;
    }
    
    //get strength
    unsigned int getStrength() {
        return m_Strength;
    }
    
    //get skill
    unsigned int getSkill() {
        return m_Skill;
    }
    
    //get moral
    int getMoral() {
        return m_Morality;
    }
    
    //get gold
    int getGold() {
        return m_Gold;
    }

    //get player's items
    CInventory* getInventory() {
        return m_Inventory;
    }

    //Get player's curren room
    CRoom* getCurRoom() {
        return m_curRoom;
    }

    //Setter

    //set life
    void setLife(unsigned int newLife) {
        m_Life = newLife;
    }

    //set strength
    void setStrength(unsigned int newStrength) {
        m_Strength = newStrength;
    }

    //set skill
    void setSkill(unsigned int newSkill) {
        m_Skill = newSkill;
    }

    //Set Room
    void setCurRoom(CRoom* newRoom)
    {
        m_curRoom = newRoom;
    }

    void addQuest(CQuest* quest);

    
    //Functions:

    //printMainAtts: print life, gold and moral
    void printMainAtts(); 

    //Prints all attributes of player
    void showAttributes();     

    //Quests
    void showActiveQuests();
    void showSolvedQuests();
    
};

#endif

