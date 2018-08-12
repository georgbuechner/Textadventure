//Door
// @Author = Jan van Dick

#include "CDoor.h"

using namespace std;

//Constructor: 
//chName (name of he door), linkedRoom (Room this door is leading to), 
//localID (ID to clearly identify all doors in a room), ID (ID to clearly identify this door out of all doors)
CDoor::CDoor(char* chName, CRoom* linkedRoom, int localID, int ID, 
                std::vector<std::string> sDescriptions, void(CDoor::*callDescription)())
{
    m_chName = chName;
    m_localID = localID;
    m_ID = ID;
    m_linkedRoom = linkedRoom;
    
    m_curDescription = 0;
    for(unsigned int i=0; i<sDescriptions.size(); i++)
        m_sDescriptions.push_back(sDescriptions[i]); 
    
    m_callDescription = callDescription;
        
}


//PrintDescription:
//Load current description, then print current description
void CDoor::printDescription()
{
    //Vaiables
    string sDescription;    //String containing description
    string sDescName = "/home/leonce/Documents/C++ Projects/Textadventure/DoorDescriptions/";
    sDescName.append(m_sDescriptions[m_curDescription]);

    //Read description-file
    ifstream ifs(sDescName);
    
    //Check, whether file has been open
    if (!ifs)
        cout << "File: \"" << sDescName << "\"  could not be opended! \n\n";

    //Load description form file "into sDescription"
    else
        sDescription.assign((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

    //close file
    ifs.close();

    //Print description
    cout << sDescription << endl;
}

//callDesc
//Calls m_callDescription which is a pointer to the wanted function
void CDoor::callDesc()
{
   (this->*m_callDescription)();
}


//****************Description Calls *******************//

//DescCall_Standard: 
//Simply calls the current description
void CDoor::DescCall_Standard()
{
    //Print description
    this->printDescription();
}

//DescCall_IncreaseCurDesc()
//Prints current description and increases current description
void CDoor::DescCall_Increase1CurDesc()
{
    this->printDescription();   //Print description
    this->m_curDescription++;   //Increase curDescription by 1
    this->setCallDescription(&CDoor::DescCall_Standard); //Change DescCall to standard
}

//DescCall_d_LeninsTomb3
//Prints current description, increases current description and changes door_name
void CDoor::DescCallLeninsTomb()
{
    this->printDescription();   //Print description
    this->m_curDescription++;   //Change to next description
    this->setCallDescription(&CDoor::DescCall_Standard);    //Change DescCall to standard
    this->setName((char*)"Stalins tomb");                   //Change door name to "Stalins tomb"
}
