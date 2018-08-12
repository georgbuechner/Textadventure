//CQuestStep.h
//Class containing the steps of a quest

#ifndef CQUESTSTEP_H
#define CQUESTSTEP_H

#include "CGame.h"
#include "CList.h"
#include "CFunctions.h"


class CQuestStep
{
private:
    char m_chName[128]; //Name of the queststep
    int m_stepNum;      //Number as identifierr for the step
    bool m_stepStatus;  //Status, whether step is fullfilled or not
    
    CGame* m_game;      //Game instance granting excess to gameManager and other game-objects
    void (CQuestStep::*m_func)();   //Function-pointer to function setting up the quest

public:
    //Constructor
    CQuestStep(char* chName, int stepNum, CGame* game, void (CQuestStep::*func)());
    
    
    //Getter
    
    //getName: returns name of the step
    char* getName() {
        return m_chName;
    }

    //getNum: returns number of the step
    int getNum() {
        return m_stepNum;
    }

    //getStepStatus: return current  status of the step (true = step solved, false = step not yet solved)
    bool getStepStatus() {
        return m_stepStatus;
    }

    
    //Setter

    //setStatus: sets/ changes status of a step
    void setStatus(bool newStatus) {
        m_stepStatus = newStatus;
    }

    
    //startQueststep: acctivates a step
    void startQueststep();

    
    //Steps

    //--- Marx ---//

    //Quest: talk to the dog
    void questMarx_Step1();
    void questMarx_Step2();
};

#endif
