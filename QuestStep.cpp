//QuestStep.cpp
//Class containing the steps of a quest

#include <iostream>
#include "CQuestStep.h"

using namespace std;


//Constructor
CQuestStep::CQuestStep(char* chName, int stepNum, CGame* game, void (CQuestStep::*func)())
{
    CFunctions F;   //Provides various functions (here: allocate)

    //Assign attributes
    F.allocate(m_chName, chName);
    m_stepNum = stepNum;
    m_stepStatus = false;

    //Assign game instance and function-pointer
    m_game = game;  //Game instance
    m_func = func;  //Pointer to function setting up queststep
}
    
//StartQueststep: acctivats a step
void CQuestStep::startQueststep() {
    (this->*m_func)();
}

//***** Steps *****//


//--- Karl Marx ---//

//Step1: Talk to the dog
void CQuestStep::questMarx_Step1()
{
    m_game->getEventManager()->add_listener((char*)"person_interact", 
            &CEventManager::echo_qMarx_TalkToDog);
}

void CQuestStep::questMarx_Step2()
{
}



