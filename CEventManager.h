//EventManager 
//It is possible to add and call events to certain times and occasions

#ifndef CEventManager_H
#define CEventManager_H

class CGame;


#include "CGame.h"
#include "CFunctions.h"
#include <iostream>

class CEventManager
{
private:

    //Function-pointer: funcion calling event 
    void(CEventManager::*m_func)(CGame* game, char* chIdentify);     
   
    char m_chEventType[128];       //Character idicating type of the event
    CEventManager *m_next;          //points to next knot of the event

    int m_numEvents;

public:
    //Constructer
    CEventManager();

    //Set a new knot
    void set(char* chEventType, void(CEventManager::*func)(CGame* game, char* chIdentify));

    //Add new listener
    void add_listener(char* chEventType, void(CEventManager::*func)(CGame* game, char* chIdentify));

    //Call event
    void throw_event(char* chEventType, CGame* game, char* chIdentify);
    
    //Delete event
    void delete_event(int eventNum);


    //Getter
    int getNumEvents() {
        return m_numEvents;
    }

    int getEventNum() {
        return m_numEvents;
    }

    //Setter
    void setNumEvents(int numEvents) {
        m_numEvents = numEvents;
    }

    //*******Events******//

    //Basic functions 
    void echo_funcShowDoors         (CGame* game, char* chIdentify);
    void echo_funcShowPeople        (CGame* game, char* chIdentify);
    void echo_funcShowAttributes    (CGame* game, char* chIdentify);
    void echo_funcShowInventory     (CGame* game, char* chIdentify);
    void echo_funcGoTo              (CGame* game, char* chIdentify);
    void echo_funcTalkTo            (CGame* game, char* chIdentify);
    void echo_funcUseItem           (CGame* game, char* chIdentify);
    void echo_funcShowActiveQuests  (CGame* game, char* chIdentify);
    void echo_funcHelp              (CGame* game, char* chIdentify);

    //Basic events
    void echo_item   (CGame* game, char* chIdentify);
    void echo_person (CGame* game, char* chIdentify);
    void echo_room   (CGame* game, char* chIdentify);
    void echo_door   (CGame* game, char* chIdentify);

    //Sepecial events
    void echo_qMarx_TalkToDog (CGame* game, char* chIdentify);
     
};

#endif
