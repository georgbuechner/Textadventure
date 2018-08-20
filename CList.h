//Header for Lists with various functions
// @Author = Jan van Dick

#ifndef CLIST_H
#define CLIST_H


#include "CFunctions.h"

//Class for lists with various function
template < typename T1>
class CList
{
private:
    T1 *m_cur;      //current element
    CList *m_next;  //current node

    unsigned int m_numElements;   //Number of elemnts in the list

public:
    //Constructor
    CList()
    {
        m_cur = NULL;
        m_next = NULL;
        m_numElements = 0;
    }

    void set(T1* element) {
        m_cur = element;    //Set cur element
    }

    //Add: add new element to list
    void add(T1* element)
    {
        m_numElements++;

        //if there is a next node, call "add" with next node
        if(m_next)
            m_next->add(element);

        //if there is no next node, create new node and call "set" from this node
        else
        {
            m_next = new CList;
            m_next->set(element);
        }
        
        return;
    }
    
    //Out: print element(Name) of each element in list
    void out()
    {
        //Check for empty list
        if(!m_next)
            return;

        CList* temp = this->m_next;   //Create temp

        //Print name of current element 
        cout << m_next->m_numElements << ": " <<  temp->m_cur->getName() << endl;
        
        //if there is a next node, call "out" with next node
        if(temp->m_next)
            temp->out();

        return;
    }

    //Out: print element(Name) of each element in list
    void outNum()
    {
        //Check for empty list
        if(!m_next)
            return;

        CList* temp = this->m_next;   //Create temp

        //Print name of current element 
        cout << m_next->m_numElements << endl; 
        
        //if there is a next node, call "out" with next node
        if(temp->m_next)
            temp->outNum();

        return;
    }

    //Out2: print element(name) of each element in list, without free lines
    void out2()
    {

        //Check for empty list
        if(!m_next)
            return;

        CList* temp = this->m_next;   //Create temp


        //Print name of current element
        cout << temp->m_cur->getName();

        //if there is a next node, call "out2" with next node
        if(temp->m_next)
        {
            cout << ", ";
            temp->out2();
        }

        else
            cout << endl;
    
        return;
    }

    //CheckElementByName: check if the given name matches the name of an
    //element in the list
    bool checkElementByName(char* chElementName)
    {
        //Check for empty list
        if(!m_next)
            return false;

        CList* temp = this->m_next;   //Create temp

        //Variables
        CFunctions F;   //Suplies various functions
        
        //Name of the current element matches given name: return true
        if(F.compare(chElementName, temp->m_cur->getName()) == true)
            return true;

        //Name doesn't match, but next node exists: return function-value with via node
        else if(temp->m_next)
            return temp->checkElementByName(chElementName);

        //Name doesn't matcha and no next node exists: return false
        else
            return false;
    }


    //GetElement (ByName): check if the given name matches the name of an 
    //element in the list, if yes, then return that element
    T1* getElement(char* chElementName)
    {
        //Check for empty list
        if(!m_next)
            return NULL;

        CList* temp = this->m_next;   //Create temp
        
        //Variables
        CFunctions F;   //Suplies various functions
        
        //Name of the current element matches given name: return the current element
        if(F.compare(chElementName, temp->m_cur->getName()) == true)
            return temp->m_cur;

        //Name doesn't match, but next node exists: return function-value via next node
        else if(temp->m_next)
            return temp->getElement(chElementName);

        //Name doesn't match and no next node exists: return "NULL"
        else
            return NULL;
    }

    //GetElementByName: check if the given name CONTAINS the name of an 
    //element in the list
    T1* getElementByNameContains(char* chElementName)
    {
        //Check for empty list
        if(!m_next)
            return NULL;

        CList* temp = this->m_next;   //Create temp

        //Variables
        CFunctions F;    //Suplies the "contains"-function"

        //given name contains name of current element: return current element
        if(F.contains(chElementName, temp->m_cur->getName()) == true)
            return temp->m_cur;

        //given name doesn't contain name of current element, but next node exists:
        //return function-value via next node
        else if(temp->m_next)
            return temp->getElementByNameContains(chElementName);

        //given name doesn't contain name of current element, and no next node exists:
        //return "NULL"
        else
            return NULL;
     }

    //GetElement (ByNum): check if the given number matches the number of the number 
    //of the element in the list 
    T1* getElement(int num)
    {
        //check for empty list
        if(!m_next)
            return NULL;

        CList* temp = this->m_next;   //Create temp

        //Given number matches the number of the current element: return current element
        if(num == temp->m_cur->getNum())
            return temp->m_cur;

        //Given number does not match the number of the current element,
        //a next node exists: return function-value via next node
        else if(temp->m_next)
            return temp->getElement(num);

        //Given number does not match the number of the current element,
        //and no next node exists: return "NULL"
        else
            return NULL;
    }
    
    //getElement by node number
    T1* iterateElements(unsigned int num)
    {
        //Given number matches m_numElements of current element: return current element
        if(num == m_numElements)
            return m_cur;
        
        //Given number does not match m_numElements of current element,
        //a next node exists: return function-value via next node
        else if(m_next)
            return m_next->iterateElements(num);

        //Given number does not match m_numElements of current element,
        //a next node does not exist: return NULL
        else
            return NULL;
    }
        
    //getFirstElement: simply retruns m_cur
    T1* getFirstElement() {
        return m_cur;
    }

    //getNumElements: return the number of elements
    unsigned int getNumElements() {
        return m_numElements; 
    }

        
    //deleteNode: delete a given node
    void deleteNode(int num)
    {
        //check for empty list
        if(!m_next)
            return;

        CList* temp = this->m_next; //Create temp
        m_numElements--;            //Reduse number of elements in the list

        //check whether number of current node matches given number
        if(temp->m_cur->getNum() == num)
        {
            m_next = temp->m_next;  //relink
            delete temp;            //delete  
        }
    
        //if not, then check, whether there is a next node and call delete via next node
        else if(temp->m_next)
            m_next->deleteNode(num);
    }
        
};
           
#endif

    
    
