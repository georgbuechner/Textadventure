//CDialog.h
//Elemnts of a dialog

#ifndef CDIALOG_H
#define CDIALOG_H

class CGame;

#include <iostream>
#include "CGame.h"
#include "CGraph.h"
#include "CState.h"
#include "CFunctions.h"


//Class managing dialogs
class CDialog
{
private:
    char m_chName[128];                  //Name of the dialog
    CGame* m_game;                       //Instance of the game
    CGraph<CState>* m_dialogGraph;       //Graph containing states of the dialog
    void(CDialog::*m_createDialog)();    //Function pointer, containg function to create 
                                         //a concrete dialog

public:
    //Constructor
    CDialog(char* chName, void(CDialog::*createDialog)(), CGame* game);

    //Getter

    //get Graph
    CGraph<CState>* getGraph() {
        return m_dialogGraph;
    }

    //startDialog: dialog will be started    
    void startDialog(CGraph<CState>* node);

    //Dialog creaters:
    void createDialogMath();
    void createDialogMarx();
    void createDialogEngels();
    void createDialogDog();
};

#endif
