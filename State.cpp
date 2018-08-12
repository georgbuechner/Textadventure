#include "CState.h"


//Constructor - standard
CState::CState(unsigned int stateNum, char* chName, bool choose)
{
    CFunctions F;   //Provides various functions (here: allocate)

    //Assign attributes
    m_stateNum = stateNum;          //State number
    F.allocate(m_chName, chName);   //State content
    m_choose = choose;              //Player choise yes/ no
    m_func = &CState::func_default; //Function indicating what happens, when the state is called
}

//Constructor - pass function
CState::CState(unsigned int stateNum, char* chName, bool choose, void(CState::*func)(CGame* game))
{
    CFunctions F;   //Provides various functions (here: allocate)

    //Assign attributes
    m_stateNum = stateNum;          //State number
    F.allocate(m_chName, chName);   //State content
    m_choose = choose;              //Player choise yes/ no
    m_func = func;                  //Function indicating what happens, when the state is called
}

//Constructor - pass function, pass content
CState::CState(unsigned int stateNum, char* chName, char* chContent, bool choose, void(CState::*func)(CGame* game))
{
    CFunctions F;   //Provides various functions (here: allocate)

    //Assign attributes
    m_stateNum = stateNum;              //State number
    F.allocate(m_chName, chName);       //State name 
    F.allocate(m_chContent, chContent); //State content
    m_choose = choose;                  //Player choise yes/ no
    m_func = func;                      //Function indicating what happens, when the state is called
}


//Standard state function printing just the content/ name
void CState::func_default(CGame* game) {
    cout << m_chName << endl;
}


//Function for state of Karl Marx
void CState::func_KarlMarx23(CGame* game) 
{
    cout << m_chName << endl;

    //Add quest to players quests and start quest
    CQuest* quest = game->getPerson((char*)"Karl Marx")->getQuests()->getElement(11);
    cout << "Quest " << quest->getName() << " added to player and started." << endl;
    game->getPlayer()->addQuest(quest);
}


