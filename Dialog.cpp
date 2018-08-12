//CDialog.cpp

#include "CDialog.h"

using namespace std;


//constructor
CDialog::CDialog(char* chName, void(CDialog::*createDialog)(), CGame* game)
{
    CFunctions F;   //Provides various functions (here: allocate)

    //Assign attributes 
    F.allocate(m_chName, chName);       //Name of the dialog
    m_game = game;                      //Instance of the game
    m_dialogGraph = new CGraph<CState>; //Graph containing states of the dialog

    //Assign createDialog-function, call create dialog
    m_createDialog = createDialog;  //Assign function to create dialog
    (this->*m_createDialog)();      //Call "createDialog" to create the dialog
}

void CDialog::createDialogMarx()
{
    //Node 1
    CState* state1 = new CState(1, (char*)"Hello jung proletarian!", true);
    m_dialogGraph->set(state1);
    
    //Node 2.1
    CState* state21 = new CState(21, (char*)"So pleased to meet you, did you read \"the manifest of the communist party?", false);
    CList<CState>* list = new CList<CState>;
    list->add(state1);
    m_dialogGraph->add(state21, list);

    //Node 2.2
    CState* state22 = new CState(22, (char*)"Love your book, you got swag man, I'm dying for your insance sence of rythem!", false);
    m_dialogGraph->add(state22, list);

    //Node 2.3
    CState* state23 = new CState(23, (char*)"Got something to do for me?", false);
    m_dialogGraph->add(state23, list);

    //Node 2.3
    CState* state24 = new CState(24, (char*)"I got to go.", false);
    m_dialogGraph->add(state24, list);

    
    //Node 3.1
    CState* state31 = new CState(31, (char*)"Marx: Dud, of course, I wrote it...\nKarl Marx shakes his head.\nMarx: You won't become a good revolutionary.", false);
    list = new CList<CState>;
    list->add(state21);
    m_dialogGraph->add(state31, list);

    //Node 3.2
    CState* state32 = new CState(32, (char*)"Marx: You're so cool man! Here's a signed copf of \"The economical and philosophical manuscripts\"\n Marx handy you a signed copf of \"The economical and philosophical manuscripts!", false);
    list = new CList<CState>;
    list->add(state22);
    m_dialogGraph->add(state32, list);

    //Node 3.3
    CState* state33 = new CState(33, (char*)"Jo, Marx, You got something to do for me?\nMarx: Talk to the dog running around here!", false, &CState::func_KarlMarx23);
    list = new CList<CState>;
    list->add(state23);
    m_dialogGraph->add(state33, list);
    
    //Node 3.3
    CState* state34 = new CState(34, (char*)"Marx: Goodby comrad!", false);
    list = new CList<CState>;
    list->add(state24);
    m_dialogGraph->add(state34, list);
}

void CDialog::createDialogEngels()
{
    //Node 1
    CState* state1 = new CState(1, (char*)"Karl Marx is the biggest materialist thinker of our time!", false);
    m_dialogGraph->set(state1);
    
    //Node 2
    CState* state2 = new CState(2, (char*)"You: As in \"he eats a lot\"?", false);
    CList<CState>* list = new CList<CState>;
    list->add(state1);
    m_dialogGraph->add(state2, list);

    //Node 3
    CState* state3 = new CState(3, (char*)"No! As in \"the greatest\"! I meant to say \"the greatest\"!", false);
    list = new CList<CState>;
    list->add(state2);
    m_dialogGraph->add(state3, list);
}

void CDialog::createDialogDog()
{
    //Node 1
    CState* state1 = new CState(1, (char*)"The dog barks.", true);
    m_dialogGraph->set(state1);

    //Node 2.1
    CState* state21 = new CState(21, (char*)"can't you do or say anything else?", false);
    CList<CState>* list = new CList<CState>;
    list->add(state1);
    m_dialogGraph->add(state21, list);

    //Node 2.2
    CState* state22 = new CState(22, (char*)"Would you let me pet you?", false);
    m_dialogGraph->add(state22, list);

    //Node 2.3
    CState* state23 = new CState(23, (char*)"I gotta go.", false);
    m_dialogGraph->add(state23, list);

    
    //Node 3.1
    CState* state31 = new CState(31, (char*)"Check your priveliges dude! You suck!", false);
    list = new CList<CState>;
    list->add(state21);
    m_dialogGraph->add(state31, list);

    //Node 3.2
    CState* state32 = new CState(32, (char*)"Yes, of course you can, I thought that was what humans are made for.\nYou stroke the dog, he barks happyly.\nAnd now piss of you filthy human!", false);
    list = new CList<CState>;
    list->add(state22);
    m_dialogGraph->add(state32, list);

    //Node 3.3
    CState* state33 = new CState(33, (char*)"The dog barks...", false);
    list = new CList<CState>;
    list->add(state23);
    m_dialogGraph->add(state33, list);
}

void CDialog::createDialogMath()
{
    //Tree node 1
    CState* state1 = new CState(1, (char*)"Choose your math task: ", true);
    m_dialogGraph->set(state1);
    
    //Tree node 2.1
    CState* state21 = new CState(21, (char*)"10+10", false);
    CList<CState>* list = new CList<CState>;
    list->add(state1);
    m_dialogGraph->add(state21, list);
    
    //Tree node 2.2
    CState* state22= new CState(22, (char*)"20+20", false);
    m_dialogGraph->add(state22, list);

    //Tree node 3.1.1
    CState* state311= new CState(311, (char*)"Deine Frage lautet: Was ist 10 + 10.", true);
    list = new CList<CState>;
    list->add(state21);
    m_dialogGraph->add(state311, list);
    
    //Tree node 3.2.1
    CState* state321 = new CState(321, (char*)"Deine Frage lautet: Was ist 20 + 20", true);
    list = new CList<CState>;
    list->add(state22);
    m_dialogGraph->add(state321, list);


    //Tree node 4.1.1
    CState* state411 = new CState(411, (char*)"15", false);
    list = new CList<CState>;
    list->add(state311);
    m_dialogGraph->add(state411, list);

    //Tree node 4.1.2
    CState* state412 = new CState(412, (char*)"20", false);
    m_dialogGraph->add(state412, list);
    
    //Tree node 4.1.3
    CState* state413 = new CState(413, (char*)"30", false);
    list->add(state321);
    m_dialogGraph->add(state413, list);

    
    //Tree node 4.2.1
    //->same as 4.1.3

    //Tree node 4.2.2
    CState* state422 = new CState(422, (char*)"40", false);
    list = new CList<CState>;
    list->add(state321);
    m_dialogGraph->add(state422, list);

    //Tree node 4.2.3
    CState* state423 = new CState(423, (char*)"50", false);
    m_dialogGraph->add(state423, list);

    //Tree node 5.1 
    CState* state51 = new CState(51, (char*)"Das ist richtig!", false);
    list = new CList<CState>;
    list->add(state412);
    list->add(state422);
    m_dialogGraph->add(state51, list);

    //Tree node 5.2
    CState* state52 = new CState(52, (char*)"Das ist falsch!", false);
    list = new CList<CState>;
    list->add(state411);
    list->add(state413);
    list->add(state423);
    m_dialogGraph->add(state52, list);
}

//startDialog: starts the dialog
void CDialog::startDialog(CGraph<CState>* node)
{
    //Print name 
    node->getCur()->callStateFunction(m_game);

    //Check whether there is the option two choose the next state of the dialog
    if(node->getCur()->getChoose() == true)
    {
        //Variables for choosing dialog
        char chChoice[128];         //Player choice
        bool input = false;         //Checks, whether player input is correct (assuming false = incorrect)
        unsigned int choice = 0;    //Players choice as integer
        
        //Print all possibles states between wich the player can choose
        int nodeCounter = 0;   //Counter for nodes (= 0)
        int numNodes = node->getOutgoing()->getNumElements()-1;  //Number of outgoing nodes
        //Loop running through all outgoing nodes 
        while(nodeCounter <= numNodes)
        {
            //Create foo node for the current node
            CGraph<CState>* foo = node->getOutgoing()->iterateElements(numNodes - nodeCounter);
            
            //Print option
            cout << nodeCounter+1 << ": " << foo->getCur()->getName() << endl;

            //Increase counter
            nodeCounter++;
        }

        //Player input
        do
        {
            cout << ">"; 
            cin.getline(chChoice, 127);
    
            choice = (int)chChoice[0]- 49;    //Convert int to string

            CGraph<CState>* foo = node->getOutgoing()->iterateElements(numNodes - choice);
            if(foo)
            {
                //Call start dialog with chosen state (pass appropriate node)
                startDialog(foo);
                input = true;
            }

            else
                cout << "Wrong input! Please try again! \n" << endl;

        }while(input == false);
        
    }

    //If there is no player choice, then, check whether there are further nodes
    else if(node->getOutgoing()->getNumElements() != 0)
    {
        //Call startDialog with chosen state
        startDialog(node->getOutgoing()->iterateElements(node->getOutgoing()->getNumElements()-1));    
    }

    //Dialog ended
    else 
        cout << "Dialog ended..." << endl;

}
