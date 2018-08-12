//Person.cpp
// @Author Jan van Dick

#include "CPerson.h"
#include <iostream>

using namespace std;

//Constructor
//chName (Name of this person), ID (ID clearly identifing this person out of all people)
CPerson::CPerson(char* chName, int ID, CGame* game, void(CDialog::*dialog)(), void (CQuest::*createQuest)())
{
    //Assign attribute
    m_chName = chName;
    m_ID = ID;

    //Set game instance to grant person access to various thing, like other people or item
    m_game=game;

    //Set dialog of this person
    m_Dialog = new CDialog(chName, dialog, game);


    //Create 

    //Create quests of this person 
    m_createQuest = createQuest;  //Assign matching function
    m_Quests = new CList<CQuest>;   //Assign new (empty) list of quests
    CQuest* newQuest = new CQuest(m_game, createQuest);  //Create quest
    m_Quests->add(newQuest);        //Add quest to list of quests
}


//Dialogs and quests

//call dialog:
void CPerson::callDialog() {
    m_Dialog->startDialog(m_Dialog->getGraph());
}


//Default dialog
void CPerson::dialog_Standard() {
    cout << "Never heard anything like that..." << endl;
}


//--- Karl Marx ---//
   
//Dialogs

//Dialog 1
void CPerson::dialog1_KarlMarx()
{
    //Variables
    CColor C;
    CFunctions F;
    char chPlayerCommand[128];
    bool dialogEnd = false;

    cout << C.red() << "Marx: Hallo jung proletarian!" << endl;
    cout << C.blue();
    cout << "1. So pleased to meet you, did you read \"the manifest of the communist party?" << endl;
    cout << "2. Love your book, you got swag man, I'm dying for your insane sence of " << endl;
    cout << "   rythem!" << endl;
    cout << "3. Got something to do for me?" << endl;
    cout << "4. I gotta go" << endl;

    do
    {
        cout << ">";

        //Player command
        cin.getline(chPlayerCommand, 127);
        cout << C.resetAll() << "\n";

         
        if(F.compare(chPlayerCommand, (char*)"1") == true)
        {
            //Print player's choice
            cout << "You: So pleased to meet you, di you read \"the manifest of";
            cout << "the communist party\"?" << endl;

            cout << C.red() << "Marx: Dude, course, I wrote them..." << endl;
            cout << C.resetAll() << "Karl Marx shakes his head." << endl;
            cout << C.red() << "Marx: You won't become a good revolutionary." << endl;
            dialogEnd = true;
        }

        else if(F.compare(chPlayerCommand, (char*)"2") == true)
        {
            cout << C.red() << "Your cool man! Here's a signed copy of \"The economical and" << endl;
            cout << "philosophical manuscripts\"" << endl;
            cout << C.resetAll() << "Marx hands you a signed copy of \"The economical and" << endl;
            cout << "philosophical mauniscripts\"" << endl;
            dialogEnd = true;
        }
        
        else if(F.compare(chPlayerCommand, (char*)"3")==true)
        {
            cout << C.red() << "Jo, Marx! You got something to do for me?" << endl;
            cout << C.resetAll() << "Talk to the dog walking around here!" << endl;

            //Add quest to players quests and start quest
            //Check whether quest could be found
            if (m_Quests->getElement(11) == NULL)
                F.error("Fatal error: Quest not found!\n");
            else
            {
                cout << "Quest found, added to player and started" << endl;
                m_game->getPlayer()->addQuest(m_Quests->getElement(11));
                setDialog(&CPerson::dialog2_KarlMarx);
            }

            dialogEnd = true;
        }

        else if(F.compare(chPlayerCommand, (char*)"4") == true)
        {
            cout << C.red() << "Goodbye commrad" << endl;
            dialogEnd = true;
        }

    }while(dialogEnd != true); 

}

//Dialog 2
void CPerson::dialog2_KarlMarx()
{
    //Variables
    CColor C;
    CFunctions F;
    char chPlayerCommand[128];
    bool dialogEnd = false;

    cout << C.red() << "Marx: Hallo jung proletarian!" << endl;
    cout << C.blue();
    cout << "1. So pleased to meet you, did you read \"the manifest of the communist party?" << endl;
    cout << "2. Love your book, you got swag man, I'm dying for your insane sence of " << endl;
    cout << "   rythem!" << endl;
    cout << "3. About talking to the dog..." << endl;
    cout << "4. I gotta go" << endl;

    do
    {
        cout << ">";

        //Player command
        cin.getline(chPlayerCommand, 127);
        cout << C.resetAll() << "\n";

         
        if(F.compare(chPlayerCommand, (char*)"1") == true)
        {
            //Print player's choice
            cout << "You: So pleased to meet you, di you read \"the manifest of";
            cout << "the communist party\"?" << endl;

            cout << C.red() << "Marx: Dude, course, I wrote them..." << endl;
            cout << C.resetAll() << "Karl Marx shakes his head." << endl;
            cout << C.red() << "Marx: You won't become a good revolutionary." << endl;
            dialogEnd = true;
        }

        else if(F.compare(chPlayerCommand, (char*)"2") == true)
        {
            cout << C.red() << "Your cool man! Here's a signed copy of \"The economical and" << endl;
            cout << "philosophical manuscripts\"" << endl;
            cout << C.resetAll() << "Marx hands you a signed copy of \"The economical and" << endl;
            cout << "philosophical mauniscripts\"" << endl;
            dialogEnd = true;
        }
        
        else if(F.compare(chPlayerCommand, (char*)"3")==true)
        {
            if(m_Quests->getElement(11)->getStep(1)->getStepStatus() == true)
            {
                cout << C.red() << "Hi, I did as you told me and talked to the dog!" << endl;
                cout << C.resetAll() << "Good job! Here's 5 bucks!" << endl;
                m_Quests->getElement(11)->getStep(2)->setStatus(true);
                m_Quests->getElement(11)->setStatus(true);
                setDialog(&CPerson::dialog3_KarlMarx);
            }

            else
            {
                cout << C.red() << "I didn't speek to him yet." << endl;
                cout << C.resetAll() << "Then hop of a do so. The revolution won't wait forever!" << endl;
                cout << C.red() << "Of course! I will do it right away!" << endl;
                cout << C.resetAll() << endl;
            }

            dialogEnd = true;
        }

        else if(F.compare(chPlayerCommand, (char*)"4") == true)
        {
            cout << C.red() << "Goodbye commrad" << endl;
            dialogEnd = true;
        }

    }while(dialogEnd != true); 

}

//Dialog 3
void CPerson::dialog3_KarlMarx()
{
    //Variables
    CColor C;
    CFunctions F;
    char chPlayerCommand[128];
    bool dialogEnd = false;

    cout << C.red() << "Marx: Hallo jung proletarian!" << endl;
    cout << C.blue();
    cout << "1. So pleased to meet you, did you read \"the manifest of the communist party?" << endl;
    cout << "2. Love your book, you got swag man, I'm dying for your insane sence of " << endl;
    cout << "   rythem!" << endl;
    cout << "3. I gotta go" << endl;

    do
    {
        cout << ">";

        //Player command
        cin.getline(chPlayerCommand, 127);
        cout << C.resetAll() << "\n";

         
        if(F.compare(chPlayerCommand, (char*)"1") == true)
        {
            //Print player's choice
            cout << "You: So pleased to meet you, di you read \"the manifest of";
            cout << "the communist party\"?" << endl;

            cout << C.red() << "Marx: Dude, course, I wrote them..." << endl;
            cout << C.resetAll() << "Karl Marx shakes his head." << endl;
            cout << C.red() << "Marx: You won't become a good revolutionary." << endl;
            dialogEnd = true;
        }

        else if(F.compare(chPlayerCommand, (char*)"2") == true)
        {
            cout << C.red() << "Your cool man! Here's a signed copy of \"The economical and" << endl;
            cout << "philosophical manuscripts\"" << endl;
            cout << C.resetAll() << "Marx hands you a signed copy of \"The economical and" << endl;
            cout << "philosophical mauniscripts\"" << endl;
            dialogEnd = true;
        }
        
        else if(F.compare(chPlayerCommand, (char*)"3") == true)
        {
            cout << C.red() << "Goodbye commrad" << endl;
            dialogEnd = true;
        }

    }while(dialogEnd != true); 

}



//Friedrich Engels
void CPerson::dialog_FriedrichEngels()
{
    CColor C;

    cout << C.red() << "Engels: Karl Marx is the biggest materialist thinker of our time" << endl;
    cout << C.blue() << "You: As in \"he eats a lot\"?" << endl;
    cout << C.red() << "Engels: No! As in \"the greates\"! I meant to say \"The greatest\"!" << endl;
}
    
//Ein Hund
void CPerson::dialog_Dog()
{
    //Variables
    CColor C;
    CFunctions F;
    char chPlayerCommand[128];
    bool dialogEnd = false;
    
    cout << "The dog barks" << endl;
    cout << C.blue();
    cout << "1. Can't you do or say anything else?" << endl;
    cout << "2. Would you let me stroke you?" << endl;
    cout << "3. I gotta go." << endl;

    do
    {
        cout << C.resetAll() <<  ">";
        
        //Player command
        cin.getline(chPlayerCommand, 127);
        cout << "\n";

        if (F.compare(chPlayerCommand, (char*)"1") == true)
        {
            cout << C.red() << "Dog: Check your priveliges dude! You suck! " << endl;
            dialogEnd = true;
        }
        
        else if(F.compare(chPlayerCommand, (char*)"2") == true)
        {
            cout << C.red() << "Yes, of course you can, I thought that was, what ";
            cout << "humans are made for." << endl;
            cout << C.resetAll() << "You stroke the dog, he barks happyly." << endl;
            cout << C.red() << "And now piss of you filthy human!" << endl;
            dialogEnd = true;
        }
            

        else if(F.compare(chPlayerCommand, (char*)"3") == true)
        {
            cout << "The dog barks..." << endl;
            dialogEnd = true;
        }

    }while(dialogEnd != true);
}    


