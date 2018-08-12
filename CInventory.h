//Header for Inventory
// @Author = Jan van Dick

#ifndef CINVENTORY_H
#define CINVENTORY_H


#include <iostream>
#include "CItem.h"
#include "CFunctions.h"
#include "CPlayer.h"
#include "CList.h"

//Forward declarations:
class CItem;

class CInventory
{
private:
    CList<CItem>* m_itemList;   //List of all items in inventory 
public:
    //Constructor
    CInventory();

    //add: add next item to inventory
    void add(CItem* item);

    //Getter 
    
    //Setter
    
        
    //printInventory: print inventory (all items & amount of each item)
    void printInventory();

    //useItem: find item, then call "use_Item" 
    void useItem(char* chName);

    //delteItem: delete selected item
    bool deleteItem(char* chName);

    //getItemByName
    CItem* getItemByName(char* chName);

};

#endif
    
    
