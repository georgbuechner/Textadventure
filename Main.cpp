//Main function
// @Author = Jan van Dick


#include <iostream>
#include "CPlayer.h"
#include "CGame.h"
#include "CFunctions.h"

using namespace std;


int main()
{
    cout << "Welcome to \"The communist reununion\"!" << endl;

    //Variables
    CFunctions F;
    char chWahl[128];
    
    do
    {
        cout << "1. play game" << endl;
        cout << "2. exit"      << endl;
        cout << ">";
        cin.getline(chWahl, 127);
        
        switch(chWahl[0])
        {
            //Play "The communist reununion"
            case('1'):
            {
                CGame lGame;
                lGame.play();
                cout << endl;
                cout << endl;

            }break;

            //Exit game
            case('2'):
            {
                cout << "Gooodbye..." << endl;
            }break;

            //Wrong input
            default:
            {
                F.error("Sorry, wrong input\n\n");
            }
                
        }
    }while(chWahl[0] != '2');

    return 0;
} 
