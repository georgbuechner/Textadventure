//Item.cpp
// @Author = Jan van Dick

#include "CItem.h"

using namespace std;

//Constructor
CItem::CItem(char* chName, CGame* game, unsigned int price, unsigned int quantity, 
        void(CItem::*itemFunction)(), int ID)
{
    //Variables
    CFunctions F;   //CFunction "allocate"-function 

    F.allocate(m_chName, chName);
    m_game = game;
    m_ID = ID;
    m_price = price;
    m_quantity = quantity;

    //Assigned function of the Item:
    m_ItemFunction = itemFunction;
}

//useItem
//Call the function to use item
void CItem::use_Item()
{
    (this->*m_ItemFunction)();
}


//Items

//Healingpotion
//add 20 life 
void CItem::use_Healingpotion()
{
    //Increase players life:
    unsigned int life = m_game->getPlayer()->getLife() + 20;
    unsigned int increasedBy = 20;
    if (life > m_game->getPlayer()->getMaxLife())
    {
        increasedBy -= life-m_game->getPlayer()->getMaxLife();
        life = m_game->getPlayer()->getMaxLife();
    }

    m_game->getPlayer()->setLife(life);  //set life to new value*/
    
    cout << "Healingpotion has been used!" << endl;
    cout << "Life increased by " << increasedBy << "." << endl;
}

//Strengthpotion
void CItem::use_Strengthpotion()
{
    //Increase players strength by 1:
    m_game->getPlayer()->setStrength(m_game->getPlayer()->getStrength()+1);

    cout << "Strengthpotion has been used!" << endl;
}

//Skillpotion
void CItem::use_Skillpotion()
{
    //Increase players skill by 1:
    m_game->getPlayer()->setSkill(m_game->getPlayer()->getSkill()+1);

    cout << "Skillpotion has been used!" << endl;
}
