/** \file SequenceSet.h
    \brief Function prototypes and implementation for the SequeneceSet class

            This contains the header file for SequeneceSet class.
            It also contains constructors, mutators, accessors, and helper functions.

    

*/

#ifndef BplusTournamentSort_SequenceSet_h
#define BplusTournamentSort_SequenceSet_h

#include <iostream>
#include <vector>
#include <limits>
#include <assert.h>
#include <math.h>
#include <algorithm>

using namespace std;

template <class Type>
class SequenceSet
{

private:
    SequenceSet<Type>* next;
    SequenceSet<Type>* back;
    SequenceSet<Type>* parent;
    
    vector<SequenceSet<Type>* > children;
    vector<Type> data;
    int MAXSIZE;
    int size;		 	// number of elements in data
    int csize;			 // number of elements in children
    bool leaf;
    string filename;
    
    // helper
/** \fn void sortData()
*    \brief sorts the items
*    \pre the items should be of type int or string
*    \post the items have been sorted
*/
    
	void sortData();

/** \fn static bool compChildren(SequenceSet<Type>*, SequenceSet<Type>*)
*    \brief compares children
*    \param i and j are pointers to children of type int or string
*    \pre the children should be of type int or string
*    \post returns which child is greater than the other
*/

    static bool compChildren(SequenceSet<Type>*, SequenceSet<Type>*);

/** \fn void sortChildren()
*    \brief sorts the children
*    \pre the children should be of type int or string
*    \pre there should be children to sort otherwise it is a leaf and there is no children
*    \post the children have been sorted
*/

    void sortChildren();    

public:
    // constructors
/** Default constructor */
    SequenceSet();
/** Copy constructor */
   
   SequenceSet(int);
    
    // setter
/** \fn void setNext(SequenceSet<Type>*)
*    \brief sets the pointer that points to the next block
*    \param next is a pointer for the next block
*    \pre the parameter should be a pointer of type int or string
*    \post the member variable next of class SequenceSet is set with the parameter's value
*/
  
      void setNext(SequenceSet<Type>*);

/** \fn void setBack(SequenceSet<Type>*)
*    \brief sets the pointer that points to the back of a block
*    \param back is a pointer for the back of a block 
*    \pre the parameter should be a pointer of type int or string
*    \post the member variable block of class SequenceSet is set with the parameter's value
*/

    void setBack(SequenceSet<Type>*);

/** \fn void setParent(SequenceSet<Type>*)
*    \brief sets the pointer that points to the parent of a block
*    \param parent is a pointer for the parent of a block 
*    \pre the parameter should be a pointer of type int or string
*    \post the member variable parent of class SequenceSet is set with the parameter's value
*/

    void setParent(SequenceSet<Type>*);

/** \fn void writeDataAt(int, Type)
*    \brief writes an item at a given position
*    \param pos is an int for the position at which writing is done 
*    \param item is an int or string for the item to be written
*    \pre the parameter pos should be an int 
*    \pre the parameter item should be either an int or string
*    \post the item is written at the position specified 
*	 \post the size of the vector of items is increased
*/

    void writeDataAt(int, Type);

/** \fn void writeChildAt(int, SequenceSet<Type>*)
*    \brief writes a child at a given position
*    \param pos is an int for the position at which writing is done 
*    \param child is an int or string for the child to be written
*    \pre the parameter pos should be an int 
*    \pre the parameter child should be either an int or string
*    \post the child is written at the position specified 
*	 \post the size of the vector of children is increased
*/

    void writeChildAt(int, SequenceSet<Type>*);

/** \fn void removeChildAt(int)
*    \brief removes a child at a given position
*    \param pos is an int for the position at which removal is done 
*    \pre the parameter pos should be an int 
*    \post the child is removed at the position specified 
*	 \post the size of the vector of children is decreased
*/

    void removeChildAt(int);

/** \fn void removeDataAt(int)
*    \brief removes an item at a given position
*    \param pos is an int for the position at which removal is done 
*    \pre the parameter pos should be an int 
*    \post the item is removed at the position specified 
*	 \post the size of the vector of items is decreased
*/

    void removeDataAt(int);

/** \fn void setSize(int)
*    \brief sets the size of the vector of items
*    \param size is an int for the size of the vector of items
*    \pre the parameter size should be an int 
*    \post the member variable size of the SequenceSet class is set with the parameter's value
*/

    void setSize(int);

/** \fn void setCsize(int)
*    \brief sets the size of the vector of children
*    \param size is an int for the size of the vector of children
*    \pre the parameter size should be an int 
*    \post the member variable csize of the SequenceSet class is set with the parameter's value
*/

    void setCsize(int);

/** \fn void setLeaf(bool)
*    \brief sets the leaf
*    \param leaf is of type bool for the leaf 
*    \pre the parameter leaf should be a bool
*    \post the member variable leaf of the SequenceSet class is set with the parameter's value
*/

    void setLeaf(bool);

/** \fn void setFilename(string)
*    \brief sets the file name
*    \param filename is of type string for the file name
*    \pre the parameter filename should be a string
*    \post the member variable filename of the SequenceSet class is set with the parameter's value
*/

    void setFilename(string);

/** \fn bool putData(Type)
*    \brief puts the item at the correct index in the vector of items
*    \param item is an int or string
*    \pre the parameter item should be an int or string
*    \pre the vector of items should not be full
*    \post the item is put at the correct index 
*	 \post the size of the vector of items is increased
*/

    bool putData(Type);

/** \fn bool putChild(SequenceSet<Type>*)
*    \brief puts the child at the correct index in the vector of children 
*    \param child is an int or string
*    \pre the parameter child should be an int or string
*    \pre the vector of children should not be full
*    \post the child is put at the correct index 
*	 \post the size of the vector of children is increased
*/

    bool putChild(SequenceSet<Type>*);

    // getter
/** \fn SequenceSet<Type>* getNext()
*    \brief gets the pointer to the next block
*    \pre the object using the function should be an object of SequenceSet class
*    \post the index to the next block is returned
*/

    SequenceSet<Type>* getNext();
	
/** \fn SequenceSet<Type>* getBack()
*    \brief gets the pointer to the back of a block
*    \pre the object using the function should be an object of SequenceSet class
*    \post the index to the back of a block is returned
*/

    SequenceSet<Type>* getBack();
	
/** \fn SequenceSet<Type>* getParent()
*    \brief gets the pointer to the parent of a block
*    \pre the object using the function should be an object of SequenceSet class
*    \post the index to the parent of a block is returned
*/

    SequenceSet<Type>* getParent();	
	
/** \fn typename vector<SequenceSet<Type>* >::iterator getChildrenBegin()
*    \brief gets the beginning of the vector of items
*    \pre the vector using the function should be of type int or string
*    \post the index to the beginning of the vector of children is returned 
*/

    typename vector<SequenceSet<Type>* >::iterator getChildrenBegin();
	
/** \fn typename vector<Type>::iterator getDataBegin()
*    \brief gets the beginning of the vector of children
*    \pre the vector using the function should be of type int or string
*    \post the index to the beginning of the vector of items is returned 
*/

    typename vector<Type>::iterator getDataBegin();
	
/** \fn SequenceSet<Type>* getChildAt(int)
*    \brief gets the child at the specified position
*    \param pos is an int for the position at which retrieval is done
*    \pre the parameter pos should be of type int
*    \post the child is returned 
*/

    SequenceSet<Type>* getChildAt(int);
	
/** \fn Type getDataAt(int)
*    \brief gets the item at the specified position
*    \param pos is an int for the position at which retrieval is done
*    \pre the parameter pos should be of type int
*    \post the item is returned 
*/

    Type getDataAt(int);
	
/** \fn int getSize()
*    \brief gets the size of the vector of items
*    \pre the vector using the function should be of type int or string
*    \post the vector's size is returned 
*/

    int getSize();
	
/** \fn int getSize()
*    \brief gets the size of the vector of children
*    \pre the vector using the function should be of type int or string 
*    \post the vector's size is returned 
*/

    int getCsize();

/** \fn bool isLeaf()
*    \brief verifies if node is a leaf
*    \pre the variable using the function should be of type bool
*    \post returns whether the node is a leaf
*/

    bool isLeaf();
	
/** \fn bool isChildrenFull()
*    \brief verifies if vector of children is full
*    \pre the vector of children should be of type bool
*    \post returns whether the vector of children is full
*/

    bool isChildrenFull();
	
/** \fn bool isDataFull()
*    \brief verifies if vector of items is full
*    \pre the vector of items should be of type bool
*    \post returns whether the vector of items is full
*/

    bool isDataFull();

/** \fn string getFilename()
*    \brief gets the file name
*    \pre the file name to get should be a string 
*    \post returns the file name 
*/

    string getFilename();
       
};



// ------------------------------
// Definition of SequenceSet Class
// ------------------------------
//-- Public Methods --//
// Default Constructor


template <class Type>

SequenceSet<Type>::SequenceSet()
{

    //  ORDER of 3;
    SequenceSet(3);
	

}

template <class Type>
SequenceSet<Type>::SequenceSet(int MAXSIZE)
{

    next = NULL;
    back = NULL;
    this->MAXSIZE = MAXSIZE;
    this->size = 0;
    this->csize = 0;
    leaf = false;
    filename = "";
    data.reserve(MAXSIZE + 1); 			// data capacity = size +1, for separation
    data.resize(MAXSIZE + 1);
    children.reserve(MAXSIZE + 2);		 // then children cap = size + 2
    children.resize(MAXSIZE + 2);


}



template <class Type>
void SequenceSet<Type>::setNext(SequenceSet<Type>* next)
{

           this->next = next;
	
}

template <class Type>
void SequenceSet<Type>::setBack(SequenceSet<Type>* back)
{

    this->back = back;

}

template <class Type>
void SequenceSet<Type>::setParent(SequenceSet<Type>* parent)
{
	
     this->parent = parent;
	

}


template <class Type>
void SequenceSet<Type>::writeDataAt(int pos, Type item)
{
	
    assert(size <= MAXSIZE); 
   
    data.at(pos) = item;
    size++;
	
}

template <class Type>
void SequenceSet<Type>::writeChildAt(int pos, SequenceSet<Type>* child)
{
  
	
    children.at(pos) = child;
    csize++;
	
}

template <class Type>
void SequenceSet<Type>::removeChildAt(int pos)
{
	
    typename vector<SequenceSet<Type>* >::iterator it;
    it = children.begin();

    for (int i=0; i < pos; i++)
    {
        ++it;
    }

    children.erase(it);
    csize--;
	
}

template <class Type>
void SequenceSet<Type>::removeDataAt(int pos)
{
 
    data.at(pos) = data.at(--size);
    sortData();

}

template <class Type>
void SequenceSet<Type>::setSize(int size)
{
	
    this->size = size;
	

}

template <class Type>
void SequenceSet<Type>::setCsize(int csize)
{
	
    this->csize = csize;
	

}

template <class Type>
void SequenceSet<Type>::setLeaf(bool leaf)
{
	
    this->leaf = leaf;
	

}

template <class Type>
void SequenceSet<Type>::setFilename(string filename)
{
	
    this->filename = filename;
	

}

template <class Type>
bool SequenceSet<Type>::putData(Type item)
{
	
    if (size == MAXSIZE + 1)
       {
        return false;
      } 
        else
         {
             data.at(size++) = item;

            sortData();
  
            return true;
    }
	
}

template <class Type>
bool SequenceSet<Type>::putChild(SequenceSet<Type>* child)
{
	
    if (csize == MAXSIZE+2)
    {
        return false;
    }

    else
     {
        children.at(csize++) = child;

        sortChildren();
        return true;
    }
	

}


template <class Type>
SequenceSet<Type>* SequenceSet<Type>::getNext()
{
	
    return next;
	

}

template <class Type>
SequenceSet<Type>* SequenceSet<Type>::getBack()
{
	
    return back;
	

}

template <class Type>
SequenceSet<Type>* SequenceSet<Type>::getParent()
{
	
    return parent;
	

}

template <class Type>
typename vector<SequenceSet<Type>*  >::iterator SequenceSet<Type>::getChildrenBegin()
{
	
    return children.begin();
	

}

template <class Type>
typename vector<Type>::iterator SequenceSet<Type>::getDataBegin()
{
	
    return data.begin();
	

}

template <class Type>
SequenceSet<Type>* SequenceSet<Type>::getChildAt(int pos)
{
	
    assert(pos < csize);
    return children.at(pos);
	

}

template <class Type>
Type SequenceSet<Type>::getDataAt(int pos)
{
	
    assert(pos < size);
    return data.at(pos);


}

template <class Type>
int SequenceSet<Type>::getSize()
{
	
    return size;
	

}

template <class Type>
int SequenceSet<Type>::getCsize()
{
	
    return csize;
	

}

template <class Type>
bool SequenceSet<Type>::isLeaf()
{
	
    return leaf;
	

}

template <class Type>
bool SequenceSet<Type>::isChildrenFull()
{
	
    return csize == MAXSIZE + 1;
	

}

template <class Type>
bool SequenceSet<Type>::isDataFull()
{
	
    return size == MAXSIZE;
	

}

template <class Type>
string SequenceSet<Type>::getFilename()
{
	
    return filename;
	

}

/*
 *  Private: Helper
 */

template <class Type>

void SequenceSet<Type>::sortData()
{
	
    sort(data.begin(), data.begin()+size);
	

}

template <class Type>
bool SequenceSet<Type>::compChildren(SequenceSet<Type>* i, SequenceSet<Type>* j)
{
     
	
    return (i->getDataAt(0) < j->getDataAt(0));
	
}

template <class Type>
void SequenceSet<Type>::sortChildren()
{
	
    if (leaf)
          { 			// if this is leaf, there's no children
                    return;
    }
      else
     {
        sort(children.begin(), children.begin() + csize, compChildren);
       
     }
	
}

#endif