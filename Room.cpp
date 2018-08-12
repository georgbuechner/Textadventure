//Room.cpp
// @Author = Georg Buechner

#include "CRoom.h"
#include <iostream>

using namespace std;


CRoom::CRoom(char* chName, CList<CDoor> *Doors, CList<CPerson> *People, int ID)
{
    m_chName = chName;
    m_ID = ID;
    m_Doors = Doors;
    m_People = People;
}
