//Header CRoom.h
// @Author = Georg Buechner 

#ifndef CROOM_H
#define CROOM_H

#include "CList.h"
#include "CDoor.h"
#include "CPerson.h"

//Forward declarations:
class CPerson;

//Class for object: room
class CRoom 
{
private:
    char* m_chName;   //Name of the room
    int m_ID;               //ID clearly identifing this room
    CList<CDoor>* m_Doors;     //List of doors leading out of this room 
    CList<CPerson>* m_People;  //List of all People in this room

public:
    //Constructor
    CRoom(char* chName, CList<CDoor> *Doors, CList<CPerson> *People, int ID);

    //Getter
    
    //Get the rooms name
    char* getName()
    {
        return m_chName;
    }

    //Get ID
    int getID()
    {
        return m_ID;
    }

    //Get list of all doors leading out off this room
    CList<CDoor>* getDoors()
    {
        return m_Doors;
    }
    
    //Get list of all people in this room
    CList<CPerson>* getPeople()
    {
        return m_People;
    }
    
};

#endif

