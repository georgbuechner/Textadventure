//CGraph.h
//Class for graphs

#ifndef CGRAPH_H
#define CGRAPH_H


#include <iostream>
#include "CList.h"
#include "CFunctions.h"
#include "CColor.h"


template < typename T1 >
class CGraph
{
private:
    T1 *m_cur;                      //Current element
    CList<CGraph>* m_outgoingNodes; //List of all outgoing node
    CList<CGraph>* m_incomingNodes; //List of all incoming nodes

    unsigned int m_numNodes;         //Number of Elements in List

public:
    //Constructor
    CGraph()
    {
        m_outgoingNodes = new CList<CGraph>;    //Declare list of outgoing nodes
        m_incomingNodes = new CList<CGraph>;    //Declare list of incoming nodes
        m_numNodes = 0;
    }

    //getCur: return current element
    T1* getCur() {
        return m_cur;
    } 

    //getOutgoing: return list of outgoing nodes
    CList<CGraph>* getOutgoing() {
        return m_outgoingNodes;
    }

    //getIncoming: return list of incoming nodes
    CList<CGraph>* getIncoming() {
        return m_incomingNodes;
    }

    //getNUm: return the number of nodes
    unsigned int getNum() {
        return m_numNodes;
    }

    //set: set first element in graph
    void set(T1* element) {
        m_cur = element;
    }

    //add: add ew element in graph
    void add(T1* element,  CList<T1>* incomingElements)
    {
        //Increase number of nodes
        m_numNodes++;
        
        //Create new node
        CGraph* node = new CGraph;

        //Assign element and list of incoming nodes to new node
        node->m_cur = element;                              //Assign element to new node
        node->m_incomingNodes = transfer(incomingElements); //Transfer list of elements to list of nodes
        node->m_numNodes = m_numNodes - 1;

        //Add new node to list of outcoming nodes in list of incoming nodes
        int numNodes = node->m_incomingNodes->getNumElements()-1;
        int nodeCounter = 0;   //Counter for number of incoming node (=0)
        //Loop running through all incoming nodes
        while(nodeCounter <= numNodes)
        {
            //Create foo node, representing the incoming node
            CGraph *before = node->m_incomingNodes->iterateElements(nodeCounter);
            before->m_outgoingNodes->add(node); //Call "add" for all coming elements

            nodeCounter++;  //Increase nodeCounter
        }
    }

    //transfer: transfers list of elements to list of nodes
    CList<CGraph>* transfer(CList<T1>* listElements)
    {
        //Create a foo list, representing the list for all list of nodes
        CList<CGraph>* listNodes = new CList<CGraph>;

        //Transfer list of elements to list of nodes
        int numElements = listElements->getNumElements()-1;
        int elementCounter = 0;    //Counter for number of elements in the list
        //Loop running through all nodes
        while (elementCounter <= numElements)
        {   
            //Create foo element, representing the current element
            T1* fooElement = listElements->iterateElements(elementCounter);

            listNodes->add(getNode(fooElement->getNum()));    //Call "add" for all coming nodes
           
            elementCounter++;   //Increase elementCounter
        }

        //Return list of incoming nodes
        return listNodes;
    }

     
    //Find a node by the name of its element
    CGraph* getNode(char* chName)
    {
        CFunctions F;   //Class containing various functions (here: compare-function)

        //Check whether given name matches name of current element
        if(F.compare(chName, m_cur->getName()) == true)
            return this;

        //If not, then go through all its outgoing nodes
        int numNodes = m_outgoingNodes->getNumElements()-1;
        int nodeCounter = 0;   //Counter for number of nodes in the list
        //Loop running through all outgoing nodes
        while(nodeCounter <= numNodes)
        {
            //foo node, representing the current outgoing node (search)
            CGraph* foo = m_outgoingNodes->iterateElements(nodeCounter)->getNode(chName);

            //Check, whether node was found 
            if(foo != NULL)
                return foo; //return node

            nodeCounter++;  //Increase nodeCounter
        }
            
        //If no node was found, then return NULL
        return NULL;
    }


    //Find a node by the number of its element
    CGraph* getNode(unsigned int num)
    {
        //Check whether given number matches number of current element
        if(num == m_cur->getNum())
            return this;

        //If not, then go through all its outgoing nodes
        int numNodes = m_outgoingNodes->getNumElements()-1;
        int nodeCounter = 0;   //Counter for number of nodes in the list
        //Loop running through all outgoing nodes
        while(nodeCounter <= numNodes)
        {
            //foo node, representing the current outgoing node (search)
            CGraph* foo = m_outgoingNodes->iterateElements(nodeCounter)->getNode(num);

            //Check, whether node was found 
            if(foo != NULL)
                return foo; //return node

            nodeCounter++;  //Increase nodeCounter
        }
            
        //If no node was found, then return NULL
        return NULL;
    }

    //replaceElement: replace on element by another
    void replaceElement(unsigned int numOldElement, T1* newElement)
    {
        CGraph* oldNode = getNode(numOldElement);
        if(oldNode)
            oldNode->set(newElement);
    }


    //deleteNode: deletes the given node
    void deleteNode(unsigned int numNode)
    {
        //Create foo node: use foo node as given node from now on
        CGraph* nodeDelete = getNode(numNode);

        //Check, whether given node exists
        if(nodeDelete)
        {
            int numNodes = nodeDelete->m_incomingNodes->getNumElements()-1;
            int nodeCounter = 0;   //node counter (=0)
            //Loop running through all incomming nodes (delete node out of list of outgoing nodes)
            while(nodeCounter <= numNodes)
            {
                //Create foo node: use foo as current incoming node
                CGraph* incomingNode = nodeDelete->m_incomingNodes->iterateElements(nodeCounter);

                //Delete given node from list of outgoing nodes
                if(incomingNode->m_outgoingNodes->getElement(nodeDelete->m_numNodes))
                    incomingNode->m_outgoingNodes->deleteNode(nodeDelete->m_numNodes);

                nodeCounter++;  //Increase counter
            }
    
            delete nodeDelete;
        }

        else
            cout << "Fatal Error" << endl;
    }

    //Print graph:
    void print()
    {
        //print name of element
        cout << m_cur->getName() << endl;
        
        int numNodes = m_outgoingNodes->getNumElements()-1;
        int nodeCounter = 0;
        //Loop running through all outgoing nodes
        while(nodeCounter <= numNodes)
        {
            m_outgoingNodes->iterateElements(nodeCounter)->print();
            nodeCounter++;
        }
    }

};

#endif
        
      

