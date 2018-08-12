//Header CDoor
// @Author = Jan van Dick

#ifndef CDOOR_H
#define CDOOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Forward declarations:
class CRoom;

class CDoor
{
private:
    char* m_chName;         //Name of the Door (can be changed during the game)
    int m_localID;          //(local ID of the Door (existing in the door-list of a room)
    int m_ID;               //ID clearly identifing this room
    CRoom* m_linkedRoom;    //Room the door is leading to

    int m_curDescription;                       //Marks current discription 
    std::vector<std::string> m_sDescriptions;   //String array of all descriptions
                                                //of the room this door is leading to

    void(CDoor::*m_callDescription)();      //Points on a function to call description of the next
                                            //room and gives various other possibilities
public:
    //Constructor
    CDoor(char* chName, CRoom* linkedRoom, int localID, int ID,
             std::vector<std::string> sDescription, void(CDoor::*callDescription)());

    //Getter
    
    //Get name of the door
    char* getName()
    {
        return m_chName;
    }

    //Get DoorID (local ID) of the door
    int getDoorID()
    {
        return m_localID;
    }

    //Get ID of the door
    int getID()
    {
        return m_ID;
    }
    
    //Get the room the door is leading to
    CRoom* getLinkedRoom()
    {
        return m_linkedRoom;
    }

    
    //Setter

    //Set door-name
    void setName(char* chName)
    {   
        m_chName = chName;
    }

    //Set currentDiscription 
    void setCurrentDescription(int Index)
    {
        m_curDescription = Index;
    }

    //Set callDescription
    void setCallDescription(void(CDoor::*callDescription)())
    {
        m_callDescription = callDescription;
    }

    //Print Description
    void printDescription();

    //Call "m_callDescription
    void callDesc();

    //Descriptions
    void DescCall_Standard();
    void DescCall_Increase1CurDesc();
    void DescCallLeninsTomb();
};

#endif   
