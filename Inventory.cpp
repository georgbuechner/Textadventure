//Inventory.cpp
// @Author = Jan van Dick

#include "CInventory.h"

//Constructor
CInventory::CInventory()
{
    m_itemList = new CList<CItem>;
}

//add: add next item to inventory
void CInventory::add(CItem* item)
{
    m_itemList->add(item);
}

//printInventory: print inventory (all items & amount of each item)
void CInventory::printInventory()
{
    
    int itemCounter = 0;
    int numItems = m_itemList->getNumElements()-1;
    //Loop running through all quests
    while(itemCounter <= numItems)
    {
        //Build foo items
        CItem* fooItem = m_itemList->iterateElements(numItems - itemCounter);

        //Print item stats
        cout << fooItem->getName() << " x " << fooItem->getQuantity() << endl;

        //Increase item counter
        itemCounter++;
    }
}

//useItem: find item, then call "useItem", check wether it was the last item, if yes: fixList
void CInventory::useItem(char* chName)
{

    //Search given item in list and safe in a foo item
    CItem* fooItem = m_itemList->getElement(chName);

    if(fooItem)
    {
        //Use item and decrease quantity
        fooItem->use_Item();                            //Use item
        fooItem->setQuantity(fooItem->getQuantity()-1); //Decrease quantity
    
        //Delte item from inventory if quantity == 0
        if (fooItem->getQuantity() == 0)
            m_itemList->deleteNode(fooItem->getNum());
    }
    
    else
    {
        cout << "Item not found" << endl;
        cout << endl;
    }
}



//getItemByName
CItem* CInventory::getItemByName(char* chName)
{
    //Search given item in list and safe in a foo item
    CItem* fooItem = m_itemList->getElement(chName);

    if(fooItem)
        return fooItem;
    else
        return NULL;
}
    
   
