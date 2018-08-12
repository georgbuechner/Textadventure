//Header CItem
// @Author = Jan van Dick

#ifndef CITEM_H
#define CITEM_H

class CPlayer;
class CGame;

#include <iostream>
#include "CFunctions.h"
#include "CPlayer.h"
#include "CGame.h"

class CItem
{
private:
    char m_chName[128];         //Name of the item
    int m_ID;                   //ID of the item 
    CGame* m_game;              //Instaz of the game to gain access to all classes
    unsigned int m_price;       //Price of the item
    unsigned int m_quantity;    //Quantity of this item

    void(CItem::*m_ItemFunction)();   //Function of the Item

public:
    //Constructor
    CItem(char chName[128], CGame* game, unsigned int price, unsigned int quantity, 
                void(CItem::*itemFunction)(), int ID);

    //Getter
    
    //get name of item
    char* getName() {
        return m_chName;
    }

    //get Id of item
    int getNum() {
        return m_ID;
    }

    //get price of item
    unsigned int getPrice() {
        return m_price;
    }

    //Get quatity of item
    unsigned int getQuantity() {
        return m_quantity;
    }

    
    //Setter

    //set price of item
    void setPrice(unsigned int price) {
        m_price = price;
    }

    //Set quantity of item
    void setQuantity(unsigned int quantity) {
        m_quantity = quantity;
    }

    
    //use item
    void use_Item();

    //functions of items
    void use_Healingpotion();     //Healing Potion: increase life by 20
    void use_Strengthpotion();    //Strength Potion: increase strenght by 1
    void use_Skillpotion();       //Skill potion: increase skill by 1
};

#endif
