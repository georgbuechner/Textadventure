//Player
// @Author = Jan van Dick

#include "CPlayer.h"
#include <iostream>


CPlayer::CPlayer(char chName[128], CRoom* curRoom, CInventory *Inventory)
{
    //Variables
    CFunctions F;   //Provide "allocate"-function

    //Name
    F.allocate(m_chName, chName);

    //Attributes
    m_maxLife   = 100;
    m_Life      = 30;
    m_Strength  = 50;
    m_Skill     = 50;
    m_Morality  = 0;

    //Money and items
    m_Gold      = 89;
    m_Inventory = Inventory;

    //Current room
    m_curRoom   = curRoom;

    m_quests = new CList<CQuest>();
}

//Add quest to list of players quests and start the given quest
void CPlayer::addQuest(CQuest* quest) 
{
    m_quests->add(quest);
    quest->startQuest();
}


//printMainAtts: print life, gold and moral
void CPlayer::printMainAtts()
{
    CColor C;    //Provied colors etc.: <object>.<wanted color>

    cout << C.blue() << "Life: " << m_maxLife << "/" << m_Life << " - Gold: " << m_Gold 
                << " - Morality: " << m_Morality << endl;
    cout << C.resetAll();
}

//showAttributes: print all attributes of the player
void CPlayer::showAttributes()
{
    CColor C;   //Provides various colors

    cout << "--- attributes ---" << endl;

    if(m_Life < m_maxLife)
        C.red();

    cout << "Life: "     << m_Life << "/" << m_maxLife << C.resetAll(); 
    cout << "Strength: " << m_Strength << endl;
    cout << "Skill:    " << m_Skill    << endl;
    cout << "Morality: " << m_Morality << endl;
    cout << "Gold:     " << m_Gold     << endl;
} 

   
//Quests

//showActiveQuests: prints all currently active quests
void CPlayer::showActiveQuests()
{
    //Variables 
    cout << "Active Quests: " << endl;
    
    int questCounter = 0;                              //Counter for quests (= 0)
    int numQuests = m_quests->getNumElements()-1;      //Number of quests in list
    //Loop running through all quests
    while(questCounter <= numQuests)
    {
        //Build foo quest
        CQuest* quest = m_quests->iterateElements(numQuests - questCounter);

        //Check whether quest is still active or solved
        if (!quest->getQuestStatus())
        {
            cout << quest->getName() << endl;   //Print name of the quest
        
            
            int stepCounter = 0;                                   //Set stepCounter on zero
            int numSteps = quest->getSteps()->getNumElements()-1;  //Number of steps for this quest
            //loop running through all steps of current quest
            while (stepCounter <= numSteps)
            {
                //Build foo step
                CQuestStep* step = quest->getSteps()->iterateElements(numSteps- stepCounter);

                cout << "--- " << stepCounter+1 << ": " << step->getName(); //Print name of the step

                //Check whether step is solved or still active
                if (!step->getStepStatus())
                    cout << " - currently active" << endl;  //Print information
                else
                    cout << " - solved" << endl;            //Print Information
            
                stepCounter++;  //Increase counter for steps
            }
        }
        questCounter++; //Increase counter for quests
    }
}
