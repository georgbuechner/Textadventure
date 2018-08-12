//Game Events - Header

#ifndef CGAMEEVENTS_H
#define CGAMEEVENTS_H

class CGame;

#include "CGame.h"

class CGameEvents
{
private:
    int fuckYou;
public:
    CGameEvents() {
        fuckYou = 5;
    }
    void echo_item(CGame* game);
    void echo_person(CGame* game);
};

#endif 
