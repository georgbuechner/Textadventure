//Quests.cpp

#include <iostream>
#include "CQuest.h"


//Constructor
CQuest::CQuest(CGame* game, void (CQuest::*func)())
{
    //Assign attributes
    m_questStatus = false;

    //Assign game instance and function-pointer
    m_game = game;  //Game instance
    m_func = func;  //Pointer to function setting up quest

    //Create empty List for steps
    m_questSteps = new CList<CQuestStep>;   //New list of quest steps
    buildQuest();                           //Build quest
}

//buildQuest: builds the quests, i.a. sets up the steps etc.
void CQuest::buildQuest() {
    (this->*m_func)();
}

//StartQuest: sets quest on active
void CQuest::startQuest() {
    cout << "Quest \"" << m_chName << "\" started and is now active." << endl;
    m_questSteps->iterateElements(m_questSteps->getNumElements())->startQueststep();
}


//Quests
void CQuest::quest_Standard()
{
    CFunctions F;   //Provides various functions

    F.allocate(m_chName, (char*)"Standard");
    m_questNum = 0;
}

//KARL MARX
void CQuest::quest_Marx()
{
    CFunctions F;   //provides various functions

    F.allocate(m_chName, (char*)"Talk to the dog");
    m_questNum = 11;

    CQuestStep* step1 = new CQuestStep((char*)"Talk to Dog", 1, m_game, &CQuestStep::questMarx_Step1);
    m_questSteps->add(step1);

    CQuestStep* step2 = new CQuestStep((char*)"Talk to Marx", 2, m_game, &CQuestStep::questMarx_Step2);
    m_questSteps->add(step2);

    CQuestStep* step3 = new CQuestStep((char*)"Jump around", 3, m_game, &CQuestStep::questMarx_Step2);
    m_questSteps->add(step3);
}
    
