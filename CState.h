#ifndef CSTATE_H
#define CSTATE_H

class CGame;
class CQuest;

#include <iostream>
#include "CGame.h"
#include "CFunctions.h"

class CState
{
private:
    unsigned int m_stateNum;                //Number of the state
    char m_chName[128];                     //Name of the state
    char m_chContent[128];                  //Contant of the state
    bool m_choose;                          //State contains a player option (true = yes, false = no)
    void (CState::*m_func)(CGame* game);    //Function-pointer: what happens, when state is called?

public:
    //Constructor - standard
    CState(unsigned int stateNum, char* chName, bool choose); 
    
    //Constructor - pass function
    CState(unsigned int stateNum, char* chName, bool choose, void(CState::*func)(CGame* game));
    
    //Constructor - pass function, pass content
    CState(unsigned int stateNum, char* chName, char* chContent, bool choose, void(CState::*func)(CGame* game));
    

    //Getter
    unsigned int getNum() {
        return m_stateNum;
    }

    char* getName() {
        return m_chName;
    }

    char* getContent() {
        return m_chContent;
    }

    bool getChoose() {
        return m_choose;
    }

   
    //Functions
    void callStateFunction(CGame* game) {
        (this->*m_func)(game);
    }

    void func_default(CGame* game);

    void func_KarlMarx23(CGame* game);
};
#endif
