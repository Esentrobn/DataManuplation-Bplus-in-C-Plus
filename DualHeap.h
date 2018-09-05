/** \file DualHeap.h
    \brief Function prototypes and implementations for the DualHeap class
            This contains the header file and implementation for methods of DualHeap class.
            The following methods are implemented in this file: constructors, mutators, accessors, and helper functions.

*/

#ifndef BplusTournamentSort_DualHeap_h
#define BplusTournamentSort_DualHeap_h

#include <iostream>
#include <vector>
#include <limits>
#include <assert.h>
using namespace std;

// maxmum number of items that heap can hold
//#define HEAPSIZE 3

// ------------------------------
// Declaration of DualHeap Class
// ------------------------------

template <class Type>
class DualHeap
{
private:

    //-- Attributes --//
    // flag:
    //  True => active heap's head be left, pending's be right
    //  False => active heap's head be right, pending's be left

    bool direction;
    int HEAPSIZE;

    //bool setmaxmin;

    Type maxmin;     // will be compared to new item

    //string maxminstr;

    vector<Type> data;  		// array structure used for heap
    vector<Type> run;      	       // output run
    vector<vector<Type> > buffer;     // buffer = list of lists
    
    int current_size; 	// size of active heap
    int pending_size; 	// size of pending heap
    
        //-- Supporting methods --//
/**  \fn int l_child(int)
*    \brief gets the index of the left child
*    \param  n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child is returned
*/
   
	 int l_child(int); // index of left child: general version

/**  \fn int r_child(int)
*    \brief gets the index of the right child
*    \param  n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the right child is returned
*/	
   	
	 int r_child(int); // index of right child: general version

/**  \fn int parent(int)
*    \brief gets the index of the parent node
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node is returned
*/	
  	
	  int parent(int); // index of parent node: general version
	
/**  \fn int current_l_child(int)
*    \brief gets the index of the left child for the active heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child for the active heap is returned
*/	
   
	 int current_l_child(int); // l_child for active heap

/**  \fn int current_r_child(int)
*    \brief gets the index of the right child for the active heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the right child for the active heap is returned
*/	
	
	    int current_r_child(int); // r_child for active heap
	
/**  \fn int current_parent(int)
*    \brief gets the index of the parent node for the active heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node for the active heap is returned
*/	
    	
	int current_parent(int);

/**  \fn int pending_l_child(int)
*    \brief gets the index of the left child for the pending heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child for the pending heap is returned
*/	    

	    int pending_l_child(int);
	
/**  \fn int pending_r_child(int)
*    \brief gets the index of the right child for the pending heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the right child for the pending heap is returned
*/	   

	    int pending_r_child(int);
	
/**  \fn int pending_parent(int)
*    \brief gets the index of the parent node for the pending heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node for the pending heap is returned
*/	   

	    int pending_parent(int);

/**  \fn bool exist_current_l_child(int)
*    \brief verifies whether the active heap has a left child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child for the active heap is returned
*/    

	  bool exist_current_l_child(int);
	

/**  \fn bool exist_current_r_child(int)
*    \brief verifies whether the active heap has a right child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*	 \pre the direction should be checked 
*    \post the index of the right child for the active heap is returned
*/    

	    bool exist_current_r_child(int);
	
/**  \fn bool exist_current_parent(int)
*    \brief verifies whether the active heap has a parent node
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node for the active heap is returned
*/ 

	    bool exist_current_parent(int);
	
/**  \fn bool exist_pending_l_child(int)
*    \brief verifies whether the pending heap has a left child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*	 \pre the direction should be checked
*    \post the index of the left child for the pending heap is returned
*/
  
	  bool exist_pending_l_child(int);
	
/**  \fn bool exist_pending_r_child(int)
*    \brief verifies whether the pending heap has a right child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*	 \pre the direction should be checked
*    \post the index of the right child for the pending heap is returned
*/
  
	  bool exist_pending_r_child(int);
	
/**  \fn bool exist_pending_parent(int)
*    \brief verifies whether the pending heap has a parent node
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*	 \pre the direction should be checked
*    \post the index of the parent node for the pending heap is returned
*/
	
	 bool exist_pending_parent(int);

/**	 \fn bool current_heap_push(Type)
*    \brief pushes the new item into the active heap
*    \param item is Type for the new item to be pushed
*    \pre the parameter should be a Type
*	 \pre the active heap should not be full
*    \post the new item is inserted into the active heap and the size of active heap incremented
*/   

	bool current_heap_push(Type); // will increments size, need manual heapify
	
/**	 \fn bool pending_heap_push(Type)
*    \brief pushes the new item into the pending heap
*    \param item is Type for the new item to be pushed
*    \pre the parameter should be a Type
*	 \pre the pending heap should not be full
*    \post the new item is inserted into the pending heap and the size of pending heap incremented
*/   

	bool pending_heap_push(Type); // will increments size, need manual heapify
	
/**	 \fn Type current_heap_pop()
*    \brief pops an item from the active heap
*	 \pre the active heap should not be empty
*    \post the new item is returned at the root of heap and the size of active heap decremented
*/

	    Type current_heap_pop();    // pop from active // need manually decrement size,  heapify // => will decrements
	

/**	 \fn int current_next(int)
*    \brief gets the next index for the active heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the next index for the active heap is returned
*/    

    int current_next(int);     // next index for active heap

	
/**	 \fn int pending_next(int)
*    \brief gets the next index for the pending heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the next index for the pending heap is returned
*/  

    int pending_next(int);     // next index for pending heap

	
/**	 \fn int current_head()
*    \brief gets the head for the active heap
*    \pre the direction should be verified
*    \post the head for the active heap is returned
*/  

    int current_head();    // head of active heap

	
/**	 \fn int pending_head()
*    \brief gets the head for the pending heap
*    \pre the direction should be verified
*    \post the head for the pending heap is returned
*/   

    int pending_head();    // head of pending heap


/**	 \fn int current_tail()
*    \brief gets the tail for the active heap
*    \pre the direction should be verified
*    \post the tail for the active heap is returned
*/ 

    int current_tail();    // tail of active heap

	
/**	 \fn int pending_tail()
*    \brief gets the tail for the pending heap
*    \pre the direction should be verified
*    \post the tail for the pending heap is returned
*/

    int pending_tail();    // tail of pending heap

	
/**	 \fn bool full()
*    \brief verifies whether the heap has any available spot
*    \pre the heap is filled with items from the active and pending heaps 
*    \post returns whether there is space in the heap
*/

    bool full();    // no available spot?
	
	
/**	 \fn bool fullwith_pending()
*    \brief verifies whether the heap is filled with pending items
*    \pre the heap is filled with items from the pending heap
*    \post returns whether there is space in the heap
*/

    bool fullwith_pending(); // heap totally filled with pending items

	
/**	 \fn void finalize()
*    \brief gets items from active heap to obtain the runs  
*    \pre the items are retrieved from the active heap
*    \post there are no items left in the active heap
*/

    void finalize();    // used by retrieve(), signaling there's no new item
      	
/**	 \fn void current_heapify_up(int)
*    \brief heapifies up a node in active heap  
*	 \param  n is an int for the index
*    \pre checks whether the item in active heap's head is the root
*    \post a node is heapified up in active heap
*/	
    
	void current_heapify_up(int);      // heapify up a node in active heap
	

/**	 \fn void current_heapify_down(int)
*    \brief heapifies down a node in active heap  
*	 \param  n is an int for the index
*    \pre checks whether the root has children
*    \post a node is heapified down in active heap
*/

    void current_heapify_down(int);    // heapify down a node in active heap

	
/**	 \fn void pending_heapify_up(int)
*    \brief heapifies up a node in pending heap  
*	 \param  n is an int for the index
*    \pre checks whether the item in active heap's head is the root
*    \post a node is heapified up in pending heap
*/

    void pending_heapify_up(int);      // heapify up a node in pending heap

    
public:

/** Default constructor */
    DualHeap();

/** Copy constructor */
    DualHeap(int);
	
/**	 \fn void put(Type)
*    \brief puts item into heap 
*	 \param item is a Type for the item
*    \pre checks whether heap is full with pending items
*    \post the item is inserted in the heap
*/

    void put(Type);     	// put items into heap
	
/**	 \fn vector<vector<Type> > retrieve()
*    \brief returns list of lists 
*    \pre there should some lists to put in the buffer
*    \post the buffer holding the lists is returned
*/
 
 	  vector<vector<Type> > retrieve();	   // returns list of lists
	
};

// ------------------------------
// Definition of DualHeap Class
// ------------------------------

//-- Public Methods --//

template <class Type>
DualHeap<Type>::DualHeap()
{

    // heapsize is 3
    
     HEAPSIZE = 3;
     data.reserve(HEAPSIZE);
     data.resize(HEAPSIZE);
     direction = true;
     current_size = 0;
     pending_size = 0;
	
}

template <class Type>
DualHeap<Type>::DualHeap(int heapsize)
{
	
    HEAPSIZE = heapsize;
    data.reserve(HEAPSIZE);
    data.resize(HEAPSIZE);
    direction = true;
    current_size = 0;
    pending_size = 0;
	
}


template <class Type>
void DualHeap<Type>::put(Type item)
{
	
    if (fullwith_pending())
	{
      		  buffer.push_back(run);
  	      run = vector<Type>(); // empty output run       
  	      direction = not direction;
       	      assert(current_size == 0);
              current_size = pending_size;
	      pending_size = 0;
    }   

    if (!full())
	{ 
        	current_heap_push(item);
    }
	else
	    { 
        	maxmin = current_heap_pop();    
       		 if (maxmin > item)
                 { 
            
                   run.push_back(maxmin);          
                   pending_heap_push(item);        
                 }

	else
	  { 
            run.push_back(maxmin);          
            current_heap_push(item);        
          }
    }
	 
}


template <class Type>
vector<vector<Type> > DualHeap<Type>::retrieve()
{
	
    finalize();
    return buffer;
	
}


template <class Type>
void DualHeap<Type>::finalize()
{
	
    Type tempitem;
    int heapsize = current_size;

    for (int i = 0; i < heapsize; i++)
    {
        tempitem = current_heap_pop();
        run.push_back(tempitem);
    }
    
   if (run.size() > 0)
    {
        buffer.push_back(run);
        run = vector<Type>();
        direction = not direction;
        current_size = pending_size;
        pending_size = 0;
    }
    
    heapsize = current_size;
    
    for (int i = 0; i < heapsize; i++)
    {
        run.push_back(current_heap_pop());
    }

    if (run.size() > 0)
    {
        buffer.push_back(run);
        run = vector<Type>();
        direction = not direction;
        current_size = 0;
        
    }
	
}


//---- Support Methods ----//
//-- Private Methods --//

//-- Index Getter --//

template <class Type>
int DualHeap<Type>::l_child(int n)
{
	
    return 2 * n + 1;
	 
}


template <class Type>
int DualHeap<Type>::r_child(int n)
{
	
    return 2 * (n + 1);
	 
}


template <class Type>
int DualHeap<Type>::parent(int n)
{
	
    return (n-1)/2;
	 
}


template <class Type>
int DualHeap<Type>::current_l_child(int n)
{
	
    if (direction)
    {
        return l_child(n);
    }
    
    else
    {
        return (HEAPSIZE - 1) - l_child((HEAPSIZE - 1) - n);
    }
	 
}


template <class Type>
int DualHeap<Type>::current_r_child(int n)
{
	
    if (direction)
    {
        return r_child(n);
    }

    else
    {
        return (HEAPSIZE - 1) - r_child((HEAPSIZE - 1) - n);
    }
	 
}

template <class Type>
int DualHeap<Type>::current_parent(int n)
{
	
    if (direction)
    {
        return parent(n);
    }

    else
    {
        return (HEAPSIZE - 1) - parent((HEAPSIZE - 1) - n);
    }
	 
}


template <class Type>
int DualHeap<Type>::pending_l_child(int n)
{

    if (!direction)
    {
        return l_child(n);
    }

    else
    {
        return (HEAPSIZE - 1) - l_child((HEAPSIZE - 1) - n);
    }
	 
}


template <class Type>
int DualHeap<Type>::pending_r_child(int n)
{
	
    if (!direction)
    {
        return r_child(n);
    }

    else
     {
        return (HEAPSIZE - 1) - r_child((HEAPSIZE - 1) - n);
    }
	 
}


template <class Type>
int DualHeap<Type>::pending_parent(int n)
{
	
    if (!direction)
    {
        return parent(n);
    }
   
    else
    {
        return (HEAPSIZE - 1) - parent((HEAPSIZE - 1) - n);
    }
	 
}


template <class Type>
int DualHeap<Type>::current_next(int n)
{
	
    return (direction)? n+1 : n-1;
	 
}


template <class Type>
int DualHeap<Type>::pending_next(int n)
{
	
    return (direction)? n-1 : n+1;
	 
}


template <class Type>
int DualHeap<Type>::current_head()
{
	
    return (direction)? 0 : (HEAPSIZE - 1);
	 
}

template <class Type>
int DualHeap<Type>::pending_head()
{
	
    return (!direction)? 0 : (HEAPSIZE - 1);
	 
}


template <class Type>
int DualHeap<Type>::current_tail()
{
	
    return (direction)? (current_size - 1) : (HEAPSIZE - current_size);
	 
}


template <class Type>
int DualHeap<Type>::pending_tail()
{
	
    return (!direction)? (pending_size - 1) : (HEAPSIZE - pending_size);
	 
}


template <class Type>
bool DualHeap<Type>::exist_current_parent(int n)
{
	
    if (direction)
    {
        return current_parent(n) >= 0;
    }
    else
    {
        return (HEAPSIZE - 1) >= current_parent(n);
    }
	
}


template <class Type>
bool DualHeap<Type>::exist_current_l_child(int n)
{
	
    if (direction)
    {
        return current_l_child(n) < current_size;
    }
   
    else
    {
        return (HEAPSIZE - current_size) <= current_l_child(n);
    }
	 
}


template <class Type>
bool DualHeap<Type>::exist_current_r_child(int n)
{
	
    if (direction)
    {
        return current_r_child(n) < current_size;
    }
   
   else
    {
        return (HEAPSIZE - current_size) <= current_r_child(n);
    }
	 
}



template <class Type>
bool DualHeap<Type>::exist_pending_parent(int n)
{
	
    if (!direction)
    {
        return pending_parent(n) >= 0;
    }
    else
    {
        return (HEAPSIZE - 1) >= pending_parent(n);
    }
	 
}


template <class Type>
bool DualHeap<Type>::exist_pending_l_child(int n)
{
	
    if (!direction)
    {
        return pending_l_child(n) < current_size;
    }
    else
    {
        return (HEAPSIZE - current_size) <= pending_l_child(n);
    }
	
}


template <class Type>
bool DualHeap<Type>::exist_pending_r_child(int n)
{
	
    if (!direction)
     {
        return pending_r_child(n) < current_size;
    }
      else
       {
        return (HEAPSIZE - current_size) <= pending_r_child(n);
    }
	
}


template <class Type>
bool DualHeap<Type>::current_heap_push(Type item)
{
	
    if (full())
    {
        return false;
    }
    data[current_next(current_tail())] = item;
    current_size++;
    current_heapify_up(current_tail());
    return true;
	 
}


template <class Type>
bool DualHeap<Type>::pending_heap_push(Type item)
{
	
    if (full())
    {
        return false;
    } 

    data[pending_next(pending_tail())] = item;
    pending_size++;
    pending_heapify_up(pending_tail());
    return true;
	 
}


template <class Type>
Type DualHeap<Type>::current_heap_pop()
{
	
    Type returndata = data[current_head()];
    data[current_head()] = data[current_tail()];
    current_size--;
    current_heapify_down(current_head());
    return returndata;
	 
}


template <class Type>
bool DualHeap<Type>::full()
{
	
    return (current_size + pending_size) == HEAPSIZE;
	 
}


template <class Type>
bool DualHeap<Type>::fullwith_pending()
{
	
    return (pending_size) == HEAPSIZE;
	 
}


template <class Type>
void DualHeap<Type>::current_heapify_up(int n)
{
	
    if (n == current_head()) 				// at root
        return;
    if (data[current_parent(n)] > data[n])
    { 
        Type tempdata = data[current_parent(n)];
        data[current_parent(n)] = data[n];
        data[n] = tempdata;
        current_heapify_up(current_parent(n)); 		// recursive call to parent node
    }
	 
}

template <class Type>
void DualHeap<Type>::current_heapify_down(int n)
{
	
    // check if child exists
    if (!exist_current_l_child(n))
     { 				// both children not exist
       
        return;
    }

	else if (!exist_current_r_child(n))	
		{ 		// only left exist
        		if (data[current_l_child(n)] < data[n])
			{
            			Type tempdata = data[current_l_child(n)];
            			data[current_l_child(n)] = data[n];
            			data[n] = tempdata;
            			current_heapify_down(current_l_child(n));
        }
        return;
    }

else 		// both exist
   		 // if left child is smaller than right
    if (data[current_l_child(n)] < data[current_r_child(n)])
     {
        if (data[current_l_child(n)] < data[n])
         { 
            Type tempdata = data[current_l_child(n)];
            data[current_l_child(n)] = data[n];
            data[n] = tempdata;
            current_heapify_down(current_l_child(n));
        }
    }

    // if right child is smaller
   
  else
   {
       
	 if (data[current_r_child(n)] < data[n])
        { 
            Type tempdata = data[current_r_child(n)];
            data[current_r_child(n)] = data[n];
            data[n] = tempdata;
            current_heapify_down(current_r_child(n));
        }
    }
    return;
	 
}

template <class Type>
void DualHeap<Type>::pending_heapify_up(int n)
{
	
    if (n == pending_head()) 
        return;
    if (data[pending_parent(n)] > data[n])
    { 
        Type tempdata = data[pending_parent(n)];
        data[pending_parent(n)] = data[n];
        data[n] = tempdata;
        pending_heapify_up(pending_parent(n)); // recursive call to parent node
    }
	 
}

#endif