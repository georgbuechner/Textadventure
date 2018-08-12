//EventManager (.cpp)
//It is possible to add and call events to a certain time and occasion

#include "CEventManager.h"

using namespace std;


//Constructor
CEventManager::CEventManager() 
{
    m_next = NULL;  //Set next not to NULL
    m_numEvents = 0;
}


//Set a kew knot/ a new Event
void CEventManager::set(char* chEventType, void(CEventManager::*func)(CGame* game, char* chIdentify))
{
    CFunctions F;   //Provides various functions (here: allocate)

    F.allocate(m_chEventType, chEventType); //Assigne eventtype 
    m_func = func;                          //Assign function of the event
}


//Add a new event to the eventmanager
void CEventManager::add_listener(char* chEventType, void(CEventManager::*func)(CGame* game, char* chIdentify))
{
    m_numEvents++;
    
    //If there is a next node, call "add_listener" with next node
    if(m_next)
        m_next->add_listener(chEventType, func);

    //If there is no next node, create new node and call "set" from this node
    else
    {
        m_next = new CEventManager;
        m_next->set(chEventType, func);
    }

    return;
}
        


//Call event
void CEventManager::throw_event(char* chEventType, CGame* game, char* chIdentify)
{
    //Check for empty list
    if(!m_next)
        return;

    CFunctions F;                       //Provides various functions (here: compare)
    CEventManager* temp = this->m_next; //Create temp
    
    //Check whether given event matches the current knot
    if(F.compare(temp->m_chEventType, chEventType) == true)
        (this->*m_next->m_func)(game, chIdentify);  //Call function
    
    //Check, whether there is a next knot
    if(temp->m_next)
        temp->throw_event(chEventType, game, chIdentify);  //Call function via next knot
}


//delete event
void CEventManager::delete_event(int eventNum)
{
    //Check for empty list
    if(!m_next)
        return;

    CEventManager* temp = this->m_next; //temp node
    m_numEvents--;                      //Reduse number of elements in the list

    //Check whether number of current node matches given number
    if(temp->m_numEvents == eventNum)
    {
        m_next = temp->m_next;  //Relink
        delete temp;            //Delete
    }

    //if not, then check, whether there is a next node and call delete via next node
    else if (temp->m_next)
        m_next->delete_event(eventNum);
}



//*********Events***************//


//---Basic functions---//
//Basic function to show all Doors in the current room
void CEventManager::echo_funcShowDoors(CGame* game, char* chIdentify)
{
    //Output
    cout << game->getPlayer()->getName() << " looks around for futher ways to go. \n";
    cout << "He finds following exits: \n";

    //Print list of all doors
    game->getPlayer()->getCurRoom()->getDoors()->out();
}

//Basic function to show all people in the current room
void CEventManager::echo_funcShowPeople(CGame* game, char* chIdentify)
{
    //Output
    cout << game->getPlayer()->getName() << " sees the following people: \n";

    //Print list of all people
    game->getPlayer()->getCurRoom()->getPeople()->out();
}

//Basic function to show all attributes of the player
void CEventManager::echo_funcShowAttributes(CGame* game, char* chIdentify)
{
    //Call matching Player function
    game->getPlayer()->showAttributes();
} 

//Basic function to show all items in the player's inventory
void CEventManager::echo_funcShowInventory(CGame* game, char* chIdentify)
{
    //Output
    cout << game->getPlayer()->getName() << "'s inventory: \n";

    //Print inventory
    game->getPlayer()->getInventory()->printInventory(); 
}

//Basic function to leave a door to a next room
void CEventManager::echo_funcGoTo(CGame* game, char* chIdentify)
{
    CFunctions F;   //Provides various function. Here: "error"-function
    
    //Create selected door
    CDoor *selectedDoor = game->getPlayer()->getCurRoom()->getDoors()->getElementByNameContains(chIdentify);

    //Door found: the change current room of player and call description of new room
    if(selectedDoor != NULL)
    {
        game->getPlayer()->setCurRoom(selectedDoor->getLinkedRoom());
        game->getPlayer()->printMainAtts();
        selectedDoor->callDesc();
    }

    //Door not found: print error and jump back to input
    else
        F.error("Room not found!\n");
}

//Basic function to talk to a selected person
void CEventManager::echo_funcTalkTo(CGame* game, char* chIdentify)
{
    CFunctions F;   //Provides various function. Here: "error"-function

    //Create selected person
    CPerson* selectedPerson = game->getPlayer()->getCurRoom()->getPeople()->getElementByNameContains(chIdentify);

    //Person found: start dialog
    if(selectedPerson != NULL)
    {
        game->getEventManager()->throw_event((char*)"person_interact", game, 
                selectedPerson->getName());
        selectedPerson->callDialog();
    }

    //Person not found: print eroor and jump back to input 
    else
        F.error("Person not found!\n");
}

//Basic function to use an item from players inventory
void CEventManager::echo_funcUseItem(CGame* game, char* chIdentify)
{
    //Call "useItem"-function from class "Inventory
    game->getPlayer()->getInventory()->useItem(chIdentify);
}

//basic function to show all of the players active quests
void CEventManager::echo_funcShowActiveQuests(CGame* game, char* chIdentify)
{
    //Call "showActiveQuests" from CPlayer
    game->getPlayer()->showActiveQuests();
}

//Basic functions showing possible user commands
void CEventManager::echo_funcHelp(CGame* game, char* chIdentify)
{
    cout << "\"show doors\", \"show people\", \"show attributes\", \"inventory\"\n";
    cout << "\"show inventory\", \"use\", \"go to\", \"talk to\", \"help\"\n";
    cout << endl;
}



//---Basic Events---//

//Basic event for picked up items
void CEventManager::echo_item(CGame* game, char* chIdentify)
{
    cout << "Hallo boy, you picked up ";
    cout << game->getItemList()->getElement(chIdentify)->getName() << ".\n";
}

//Basic event for interacting with a person
void CEventManager::echo_person(CGame* game, char* chIdentify)
{
    cout << "You aproach ";
    cout << game->getPeopleList()->getElement(chIdentify)->getName() << ".\n";
}

//Basic event for entering a room or place
void CEventManager::echo_room(CGame* game, char* chIdentify)
{
    cout << "You enter ";
    cout << game->getRoomList()->getElement(chIdentify)->getName() << ".\n";
    
}

//Basic event for approaching a door
void CEventManager::echo_door(CGame* game, char* chIdentify)
{
}


   
//---Special events---//

//Quest: Karl Marx nr.1 -> talk to the dog
void CEventManager::echo_qMarx_TalkToDog(CGame* game, char* chIdentify)
{
    CFunctions F;   //provides various functions (here: compare)

    //Create selected person
    CPerson* selP = game->getPlayer()->getCurRoom()->getPeople()->getElement(chIdentify);

    if (F.compare(selP->getName(), (char*)"a dog") == true)
    {
        cout << "Quest successful\n";

        game->getPerson((char*)"Karl Marx")->getQuest(11)->getStep(1)->setStatus(true);
        game->getPerson((char*)"Karl Marx")->getQuest(11)->getStep(2)->startQueststep();
        //Delete Event
        game->getEventManager()->delete_event(m_numEvents);
    }
}

