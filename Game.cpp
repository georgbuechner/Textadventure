//Game.cpp
// @Author = Jan van Dick

#include "CGame.h"

using namespace std;

//play
//Play game
void CGame::play()
{
    //Variables
    bool gameEnd = false;
    char chPlayerCommand[128];
    m_EM = new CEventManager;
    CFunctions F;

    /*/Enter player's name
    cout << "Enter your player's name:" << endl;
    cout << ">";
    cin.getline(chPlayerCommand, 127);

    //Create player, all rooms, doors, people and items
    gameCreate(chPlayerCommand); */

    worldFactory();


    //Manage Events

    //Create basic player-functions
    m_EM->add_listener((char*)"func_showDoors", &CEventManager::echo_funcShowDoors);
    m_EM->add_listener((char*)"func_showPeople", &CEventManager::echo_funcShowPeople);
    m_EM->add_listener((char*)"func_showAttributes", &CEventManager::echo_funcShowAttributes);
    m_EM->add_listener((char*)"func_showInventory", &CEventManager::echo_funcShowInventory);
    m_EM->add_listener((char*)"func_goTo", &CEventManager::echo_funcGoTo);
    m_EM->add_listener((char*)"func_TalkTo", &CEventManager::echo_funcTalkTo);
    m_EM->add_listener((char*)"func_UseItem", &CEventManager::echo_funcUseItem);
    m_EM->add_listener((char*)"func_ShowActiveQuests", &CEventManager::echo_funcShowActiveQuests);
    m_EM->add_listener((char*)"func_help", &CEventManager::echo_funcHelp);

    //Create basic events
    m_EM->add_listener((char*)"item_taken", &CEventManager::echo_item);
    m_EM->add_listener((char*)"person_interact", &CEventManager::echo_person);
    m_EM->add_listener((char*)"room_entered", &CEventManager::echo_room);
    m_EM->add_listener((char*)"door_aproached", &CEventManager::echo_door);



    //Introduction
    cout << endl;
    cout << m_Player->getName() << " woke up in " << m_Player->getCurRoom()->getName() << endl;


    //Game started
    do
    {
        //Type command ('help', 'show doors', 'show people', 'go to', "talk to"
        cout << ">";
        cin.getline(chPlayerCommand, 127);

        cout << "\n";     //empty lines

        //->'quit'
        if(F.compare(chPlayerCommand, (char*)"quit") == true)
        {
            cout << "Goodbye... \n";
            break;
        }

        if(F.contains(chPlayerCommand, (char*)"show doors") == true)
            m_EM->throw_event((char*)"func_showDoors", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"show people") == true)
            m_EM->throw_event((char*)"func_showPeople", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"show attributes") == true)
            m_EM->throw_event((char*)"func_showAttributes", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"show inventory") == true)
            m_EM->throw_event((char*)"func_showInventory", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"use") == true)
            m_EM->throw_event((char*)"func_UseItem", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"go to") == true)
            m_EM->throw_event((char*)"func_goTo", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"talk to") == true)
            m_EM->throw_event((char*)"func_TalkTo", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"show active quests") == true)
            m_EM->throw_event((char*)"func_ShowActiveQuests", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"show active quests") == true)
            m_EM->throw_event((char*)"func_ShowActiveQuests", this, chPlayerCommand);
        else if(F.contains(chPlayerCommand, (char*)"help") == true)
            m_EM->throw_event((char*)"func_help", this, chPlayerCommand);


        //--- Programmer's specials ---//
        //Show all people in game
        if(F.compare(chPlayerCommand, (char*)"showAll people") == true)
            m_listAllPeople->out();
        //Show all rooms in game
        else if(F.compare(chPlayerCommand, (char*)"showAll rooms") == true)
            m_listAllRooms->out();
        //Show all doors in game
        else if(F.compare(chPlayerCommand, (char*)"showAll doors") == true)
            m_listAllDoors->out();
        

    }while(gameEnd == false);
}
