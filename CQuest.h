//Quests

#ifndef CQUEST_H
#define CQUEST_H

class CQuestStep; 

#include "CGame.h"
#include "CQuestStep.h"
#include "CList.h"
#include "CFunctions.h"


class CQuest
{
private:
    char m_chName[128]; //Name of the quest
    int m_questNum;     //Number, as identifier for the quest
    bool m_questStatus; //Status, whether quest is fullfilled or not
    
    CGame* m_game;              //Game instance granting excess to eventmanager and other game-objects
    void (CQuest::*m_func)();   //Function-pointer to function setting up quest

    CList<CQuestStep>* m_questSteps;    //List with all steps to solve quest

public:
    //Constructor
    CQuest(CGame* game, void (CQuest::*func)());


    //Getter
    
    //Get Name
    char* getName() {
        return m_chName;
    }

    //Get quest status (bool = true: quest solved, bool = false: quest yet to solve
    bool getQuestStatus() {
        return m_questStatus;
    }

    //getNum: return quest-number
    int getNum() {
        return m_questNum;
    }

    //getSteps: return list of steps
    CList<CQuestStep>* getSteps() {
        return m_questSteps;
    }

    //getStep: return a step
    CQuestStep* getStep(int stepNum) {
        return m_questSteps->getElement(stepNum);
    }

    
    //Setter
    
    //setStatus
    void setStatus(bool newStatus) {
        m_questStatus = newStatus;
    }

    
    //buildQuest: set up quest steps
    void buildQuest();

    //startQuest: prints a status that the quest has started
    void startQuest();

    //Quests
    void quest_Standard();
    void quest_Marx();
};

#endif
    
     


