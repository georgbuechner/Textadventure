//Header CGame.h
// @Author = Jan van Dick

#ifndef CGAME_H
#define CGAME_H

class CItem;
class CPerson;
class CEventManager;
class CInventory;
class CState;

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include "CPlayer.h"
#include "CRoom.h"
#include "CDoor.h"
#include "CPerson.h"
#include "CInventory.h"
#include "CItem.h"
#include "CEventManager.h"
#include "CDialog.h"
#include "CQuest.h"
#include "CState.h"
#include "CList.h"
#include "CFunctions.h"


class CGame
{
private:
    CPlayer* m_Player;       //Player

    CList<CRoom>* m_listAllRooms;       //List containing all rooms in the game
    CList<CDoor>* m_listAllDoors;       //List containing all doors in the game
    CList<CPerson>* m_listAllPeople;    //List containing all people in the game
    CList<CItem>* m_listAllItems;       //List containing all items in the game
    CEventManager* m_EM;                //Eventmanager for Event: Item
    
public:
    CGame() {
        m_listAllRooms  = new CList<CRoom>;
        m_listAllDoors  = new CList<CDoor>;
        m_listAllPeople = new CList<CPerson>;
        m_listAllItems  = new CList<CItem>;
    } 


    void gameCreate(char chPlayerName[128]);  //create all rooms and door (return first room)
    void play();    //Matrix for game

    void worldFactory();
    CRoom* roomFactory  (char* chName, int num);
    void doorFactory    (char* chName, CRoom* myRoom, CRoom* linkedRoom, int localNum, int globalNum,
                        vector<string> sDescriptions, void(CDoor::*callDescription)());
    void personFactory  (char* chName, int num, CRoom* myRoom, void(CDialog::*func_dialog)(),
                        void(CQuest::*func_quest)());
    void itemFactory    (char* chName, int price, int quantity, void(CItem::*func_useItem)(), int num);
    void playerFactory  (char* chName, CRoom* startRoom, CInventory* playersInventory);
    char* playerInput();

    //Getter

    //getPlayer: get current player
    CPlayer* getPlayer() {
        return m_Player;
    }

    //getRoomList: return list of all rooms in the game
    CList<CRoom>* getRoomList() {
        return m_listAllRooms;
    }

    //getDoorList: return list of all doors in the game
    CList<CDoor>* getDoorList() {
        return m_listAllDoors;
    }

    //getPeopleList: return list of all doors in the game
    CList<CPerson>* getPeopleList() {
        return m_listAllPeople;
    }

    //getItemList: return list of all items in the game
    CList<CItem>* getItemList() {
        return m_listAllItems;
    }
    
    //getRoom: return a room
    CRoom* getRoom(char* chRoomName) {
        return m_listAllRooms->getElement(chRoomName);
    }

    //getDoor: return a door
    CDoor* getDoor(char* chDoorName) {
        return m_listAllDoors->getElement(chDoorName);
    }

    //getPerson: return a person
    CPerson* getPerson(char* chPersonName) {
        return m_listAllPeople->getElement(chPersonName);
    }

    //getItem: return a item
    CItem* getItem(char* chItemName) {
        return m_listAllItems->getElement(chItemName);
    }

    //getEventManager: return the event manager
    CEventManager* getEventManager() {
        return m_EM;
    }
};

#endif
