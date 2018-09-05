/** \file BPT.h
    \brief Function prototypes and implementation for the BPT class

            This contains the header file for BPT class.
            It also contains constructors, mutators, accessors, and helper functions.

  

*/


#ifndef BplusTournamentSort_BPT_h
#define BplusTournamentSort_BPT_h
#include <iostream>
#include <vector>
#include <limits>
#include <assert.h>
#include <math.h>
#include "SequenceSet.h"

using namespace std;

template <class Type>
class BPT
{
	private:
    	SequenceSet<Type>* root;
    	SequenceSet<Type>* head;    // head of sequence set doubly linked list
    	SequenceSet<Type>* tail;    // tail of sequence set doubly linked list
        int ORDER;
        string file_prefix;
        string file_postfix;
        int file_count;
    
        // helper
	/** \fn void rec_put(Type, SequenceSet<Type>*)
	*    \brief inserts the item into appropriate node
	*    \param item is an int or string
	*    \param p is a pointer to a node of type int or string
	*    \pre the parameter item should be an int or string
	*    \pre p should not be full
	*    \post the item is put into the correct node 
	*/
    
		void rec_put(Type, SequenceSet<Type>*);
    
	/** \fn bool rec_remove(Type, SequenceSet<Type>*)
	*    \brief removes the item from appropriate node
	*    \param item is an int or string
	*    \param p is a pointer to a node of type int or string
	*    \pre the parameter item should be an int or string
	*    \pre p should not be empty
	*    \post the item is removed from its location 
	*	 \post a boolean value is returned to indicate success or failure
	*/    

	       bool rec_remove(Type, SequenceSet<Type>*);
    
	/** \fn Type getSmallest(SequenceSet<Type>*)
	*    \brief gets the appropriate leaf with the smallest item 
	*    \param p is a pointer to a node of type int or string
	*    \pre the parameter p should not be empty
	*    \post The smallest item is returned 
	*/        
	      
	      Type getSmallest(SequenceSet<Type>*);
    
	/** \fn push_key_up_from(SequenceSet<Type>*, Type)
	*    \brief connects newly created node to its parent
	*    \param p is a pointer to a node of type int or string
	*    \param item is an int or string
	*    \pre assumes that there is a newly created node
	*    \post the node is connected to its parent
	*/            
    
	      void push_key_up_from(SequenceSet<Type>*, Type);

	/** \fn bool rebuild(SequenceSet<Type>*)
	*    \brief rebuilds the tree
	*    \param p is a pointer to a node of type int or string
	*    \pre the node should not be empty 
	*    \pre the node should not be a leaf 
	*    \post the tree is rebuilt 
	*/
	
	     bool rebuild(SequenceSet<Type>*);
	
public:

    /**Default Constructor */
    
            BPT();
    
    /**Copy Constructor*/
   
           BPT(int);
    
    	// Setter
	/** \fn void put(Type)
	*    \brief This method just calls the private method void rec_put(Type, SequenceSet<Type>*)
	*    \param item is an int or string
	*    \pre 
	*    \post the item is placed at the correct location 
	*/    
    	
          void put(Type);

	/** \fn void remove(Type)
	*    \brief This method just calls the private method void rec_remove(Type, SequenceSet<Type>*)
	*    \param item is an int or string
	*    \pre 
	*    \post the item is removed from the location 
	*/ 

		  bool remove(Type);
    
  		  // Getter
		/** \fn void print()
		*    \brief This method prints all the items in the B+tree
		*    \pre The tree has items in it
		*    \post prints all the items 
		*/     
    
		void print();
    
};


// Definition of BPT Class

	template <class Type>
	BPT<Type>::BPT()
	{ 
    		cout << "NOT USE BPT()\n";
    		// default order is 3
    		BPT(3);
		/** endcode */
	}

		template <class Type>
		BPT<Type>::BPT(int order)
	{
	
    		ORDER = order;
    		file_count = 0;
		    file_prefix = "nodefile_";
    			file_postfix = ".txt";

  		  // horizontal link
  			  head = new SequenceSet<Type>(ORDER);
    			tail = new SequenceSet<Type>(ORDER);
    
    		// initial node(=leaf)
    		SequenceSet<Type>* node;
    		node = new SequenceSet<Type>(ORDER);
    		node->setLeaf(true);
    		node->setParent(NULL);
    		stringstream ss;
    		ss << ++file_count;

    		node->setFilename(file_prefix + ss.str() + file_postfix);
    		root = node;
    		ofstream outfile;
    		outfile.open(node->getFilename().c_str(), ios_base::trunc);
    
    		head->setBack(NULL);
    		head->setNext(node);
    		node->setBack(head);
    		node->setNext(tail);
    		tail->setBack(node);
    		tail->setNext(NULL);
	
	}

	// find appropriate leaf and insert the item.
	// p can be leaf and middle node
	template <class Type>
	void BPT<Type>::rec_put(Type item, SequenceSet<Type>* p)
	{
		
   	 if (p->isLeaf())
		{        
        	if (p->isDataFull())
                  { 
            
            		p->putData(item);
            		// Create new leaf
            		SequenceSet<Type>* newp = new SequenceSet<Type>(ORDER);
            		newp->setLeaf(true);
            		newp->setParent(p->getParent());                          // same parent as p
            		stringstream ss;
            		ss << ++file_count;
            		newp->setFilename(file_prefix + ss.str() + file_postfix);
            
           		 // horizontal link
           		 SequenceSet<Type>* temp;
         		   temp = p->getNext();
         		   p->setNext(newp); // p => new node
         		   newp->setBack(temp->getBack()); // p <= new node
         		   newp->setNext(temp); // new node => p.next
            
         		   // copy contents ( data)
         		
				   int middle = (ORDER + 1) / 2;                     // when order size=3, middle is 2; when order=4, middle is 2
          			   copy(p->getDataBegin()+middle, p->getDataBegin() + p->getSize(), newp->getDataBegin());
            
          			  newp->setSize(p->getSize() - middle);
        			    p->setSize(middle);
            
            
            
            
           			 // push up new key
        			    push_key_up_from(newp, getSmallest(newp));
            
            
            			ofstream outfile1;
            			outfile1.open(p->getFilename().c_str(), ios_base::trunc);
           			 
					for (int i=0; i < p->getSize(); i++)
	   				{
        					        outfile1 << p->getDataAt(i) << '|';
      				        }
            
				ofstream outfile2;
            			outfile2.open(newp->getFilename().c_str(), ios_base::trunc);
            			for (int i=0; i < newp->getSize(); i++){
                		outfile2 << newp->getDataAt(i) << '|';
            		}
            
        	}
				
					else
					{ 
           					 p->putData(item);
      					         ofstream outfile;
     					         outfile.open(p->getFilename().c_str(), ios_base::app);
         				         outfile << item << '|';
            
                }
   
	 }
		
			else
			  { 
       				 int pos=0;
	
				for (int i=0; i < p->getSize(); i++)
                                  {
          				  if (i == 0)
                                           {
                			if (item < p->getDataAt(0))
                  			      {
            					        pos = 0;
              				      }
			
				else
				   {
                    			pos = 1;
             			   }
                         }

				else            if (item >= p->getDataAt(i))
						  {
               						 pos++;
        
           		                          }
        	}
      					  rec_put(item, p->getChildAt(pos));
    }
	
}


template <class Type>
bool BPT<Type>::rebuild(SequenceSet<Type>* p)
{
	
    if (p == NULL || p->isLeaf() || p->getSize() == 0)
       {
        return false;
    }else
       {
        SequenceSet<Type> tempNode = SequenceSet<Type>(ORDER);
        int tempSize =0;
        int tempCsize = 0;

        for (int i=0; i<p->getCsize(); i++)
            {
              if (p->getChildAt(i)->getSize() == 0)
              {
                if (p->getChildAt(i)->isLeaf())
                  {
                    // relink horizontal connection
                    p->getChildAt(i)->getBack()->setNext(p->getChildAt(i)->getNext());
                    p->getChildAt(i)->getNext()->setBack(p->getChildAt(i)->getBack());
                  }
                
                // child is empty node
                p->getChildAt(i)->setParent(NULL);
                delete p->getChildAt(i);
                continue;
             }

            if (tempCsize == 0)
                {
                
                tempNode.writeChildAt(tempCsize++, p->getChildAt(i));
                }
             else
             {
                tempNode.writeDataAt(tempSize++, getSmallest(p->getChildAt(i)));
                tempNode.writeChildAt(tempCsize++, p->getChildAt(i));
             }
        }

        copy(tempNode.getDataBegin(), tempNode.getDataBegin() + tempSize, p->getDataBegin());
        copy(tempNode.getChildrenBegin(), tempNode.getChildrenBegin() + tempCsize, p->getChildrenBegin());
        p->setSize(tempSize);
        p->setCsize(tempCsize);
        rebuild(p->getParent());
        return true;
    }
	
}

template <class Type>
bool BPT<Type>::rec_remove(Type item, SequenceSet<Type>* p)
  {
	
    if (p->isLeaf())
      {
        
        bool found = false;
        int indexWhenFound = 0;
        for (int i=0; i < p->getSize(); i++)
            {
                if (p->getDataAt(i) == item)
                {
                found = true;
                indexWhenFound = i;
            }
        }
        if (found)
         {
            
           if (indexWhenFound != 0)
           { 
                
                p->removeDataAt(indexWhenFound);
            }
            else
               { 
                p->removeDataAt(0);
				rebuild(p->getParent());
	       }
			

            ofstream outfile;
            outfile.open(p->getFilename().c_str(), ios_base::trunc);
            
            for (int i=0; i < p->getSize(); i++)
            {
                outfile << p->getDataAt(i) << '|';
            }

          return true;
        }
            else
            {
                 return false;
            }
    } 
         else  
           {
                        int pos=0;
		
		for (int i=0; i < p->getSize(); i++)
                   {
           		 if (i == 0)
                  	   {
                if (item < p->getDataAt(0))
			{
                  		pos = 0;
                }
		else
		 {
                    pos = 1;
                 }

            }else
                if (item >= p->getDataAt(i))
                {
                    pos++;
                }
        }
        
        return rec_remove(item, p->getChildAt(pos));
    }
	
}

template <class Type>
void BPT<Type>::put(Type item)
{
	
    rec_put(item, root);
	
}

template <class Type>
bool BPT<Type>::remove(Type item)
{
	
    return rec_remove(item, root);
	
}

template <class Type>
void BPT<Type>::print()
{
	
    SequenceSet<Type>* traveler;
    traveler = head->getNext();
    while (traveler != NULL)
     {
        for (int i=0; i < traveler->getSize(); i++)
        {
            cout << traveler->getDataAt(i) << "|";
        }

        traveler = traveler->getNext();
		cout << " |";
     }
	
}

template <class Type>
Type BPT<Type>::getSmallest(SequenceSet<Type>* p)
{
	
    if (p->isLeaf())
      {
        return p->getDataAt(0);
      }
      else
      {
        return getSmallest(p->getChildAt(0));
      }
	
}


// this method is called for newly created node to connect (=set key & pointer) it to parent
// called by rec_put

template <class Type>
void BPT<Type>::push_key_up_from(SequenceSet<Type>* p, Type key)
{
	
    SequenceSet<Type>* pp;
    pp = p->getParent();
    
    if (pp == NULL)                   // reached at root
      { 
        // create new root node
        // then same as separation case
        
        
        // Creating new root
        
        SequenceSet<Type>* newpp = new SequenceSet<Type>(ORDER);
        newpp->setParent(NULL);
        
        // set value and connections

        newpp->putData(key);
        newpp->putChild(root);
		root->setParent(newpp);
        newpp->putChild(p);
		p->setParent(newpp);
        root = newpp;
        
    }
      else
        { 			// has parent
        
        if (pp->isDataFull())     // full => need separate
         { 
            // store it first
            pp->putData(key);
            pp->putChild(p);

            // then separate by creating new parent

                 SequenceSet<Type>* newpp = new SequenceSet<Type>(ORDER);
                 newpp->setParent(pp->getParent());
            
           	 // copy contents (data & children) except middle key
           
		 int middle = (ORDER + 1) / 2;
            	 Type middleValue = pp->getDataAt(middle);
            	 copy(pp->getDataBegin() + middle + 1, pp->getDataBegin() + pp->getSize(), newpp->getDataBegin());
                 copy(pp->getChildrenBegin() + middle + 1, pp->getChildrenBegin() + pp->getCsize(), newpp->getChildrenBegin());
                 newpp->setSize(pp->getSize() - middle - 1);
                 newpp->setCsize(pp->getCsize() - middle - 1);
		
                	for (int i=0; i<newpp->getCsize(); i++)
                          {
                		newpp->getChildAt(i)->setParent(newpp);
            		  }
            			
					pp->setSize(middle);
            				pp->setCsize(middle + 1);
  
 			           push_key_up_from(newpp, middleValue);
                    
        		}
		else
            	   { 
               		pp->putData(key);
               		pp->putChild(p);
           	   }

    }
	
}

#endif