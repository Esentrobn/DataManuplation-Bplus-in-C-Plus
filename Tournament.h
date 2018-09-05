/** \file Tournament.h
    \brief Function prototypes and implementations for the Tournament class

            This contains the header file and implementation for methods of Tournament class.
            The following methods are implemented in this file: constructors, mutators, accessors, and helper functions.

 

#ifndef BplusTournamentSort_Tournament_h
#define BplusTournamentSort_Tournament_h

#include <iostream>
#include <vector>
#include <limits>
#include <assert.h>
#include <math.h>
using namespace std;


template <class Type>
class Tournament
{
private:

    int HEAPSIZE;
    vector<vector<Type> > master_data;				 // copied the input vector of vectors to be able to access data
    
    typedef typename vector<Type>::iterator It;
    vector<It> its;   						  // iterators for each vector
    vector<int> data; 						  // Heap, containing indexes for iterators and master_data
    vector<Type> run; 						  // a vector to be used for output
    
    int size; 							  // size of heap
    

    //-- Support methods --//
/**  \fn int l_child(int)
*    \brief gets the index of the left child
*    \param  n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child is returned
*/

    int l_child(int); 			// index of left child: general version

	
/**  \fn int r_child(int)
*    \brief gets the index of the right child
*    \param  n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the right child is returned
*/	
  
  int r_child(int);			 // index of right child: general version
 
	
/**  \fn int parent(int)
*    \brief gets the index of the parent node
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node is returned
*/

    int parent(int); 			// index of parent node: general version


/**  \fn bool exist_l_child(int)
*    \brief verifies whether there is a left child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the left child is returned
*/ 



    bool exist_l_child(int);


/**  \fn bool exist_r_child(int)
*    \brief verifies whether there is a right child
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the right child is returned
*/ 



    bool exist_r_child(int);


/**  \fn bool exist_parent(int)
*    \brief verifies whether there is a parent node
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the index of the parent node is returned
*/


    bool exist_parent(int);

    
/**	 \fn void push(int)
*    \brief pushes the new item onto the heap
*    \param index is int for the index of the item pushed
*    \pre there should be items to push
*    \post the new item is inserted into the heap and the size of heap incremented
*/  



    void push(int);		 // will increments size


/**	 \fn Type pop()
*    \brief pops an item from the heap
*	 \pre there should be items to pop
*    \post the item is popped from the heap and the size of heap decremented
*/



    Type pop(); 		   // pop from heap. If the vector pointed by the popped item reaches at the end of the vector, 
                   		// pop the itm from the heap. otherwise, don't remove it, just increment the iterator of vector and do heapify_down



/**	 \fn int next(int)
*    \brief gets the next index from heap
*    \param n is an int for the index
*    \pre the parameter should be entered as an int
*    \post the next index for heap is returned
*/	


    int next(int);		     // next index for  heap

	
/**	 \fn int head()
*    \brief gets the head of heap
*    \pre there should be a head
*    \post the head of heap is returned
*/ 

    int head();   		 // head of heap



/**	 \fn int tail()
*    \brief gets the tail of heap
*    \pre there should be a tail
*    \post the tail of heap is returned
*/ 


    int tail(); 		   // tail of heap

    
/**	 \fn void heapify_up(int)
*    \brief heapifies up a node in heap  
*	 \param  n is an int for the index
*    \pre checks whether the item in heap's head is the root
*    \post a node is heapified up in heap
*/	 


    void heapify_up(int);  			    // heapify up a node in heap


/**	 \fn void heapify_down(int)
*    \brief heapifies down a node in heap  
*	 \param  n is an int for the index
*    \pre checks whether the root has children
*    \post a node is heapified down in heap
*/	





    void heapify_down(int);   				 // heapify down a node in heap
    
public:
/** Default constructor */
    Tournament();
/** Copy constructor */
    Tournament(vector<vector<Type> >);

/**	 \fn void init(vector<vector<Type> >)
*    \brief initialize a vector of items  
*	 \param  items is a vector of vectors to hold items
*    \pre the elements of the vector items should be vectors
*    \post a vector of vectors containing items is returned
*/





    void init(vector<vector<Type> >);

/**	 \fn void sort()
*    \brief sorts each list 
*    \pre the list to be sorted should not be empty
*    \post each list is sorted
*/




    void sort();

/**	 \fn vector<Type> retrieve()
*    \brief returns list of sorted items
*    \pre there should some items in the list
*    \post the sorted list is returned
*/




    vector<Type> retrieve();   // returns list of sorted items

/**	 \fn void logFile(ofstream& )
*    \brief generates logfile
*	 \param logfile is of type ofstream for a pointer
*    \pre the argument should be a pointer 
*    \post the logfile is returned
*/	





    void logFile(ofstream& );

};

// ------------------------------
// Definition of Tournament Class
// ------------------------------

//-- Public Methods --//

// Default Constructor

template <class Type>
Tournament<Type>::Tournament()
{
}


template <class Type>
Tournament<Type>::Tournament(vector<vector<Type> > items)
{

    init(items);

}

template <class Type>
void Tournament<Type>::init(vector<vector<Type> > items)
{

    HEAPSIZE = (int)items.size();
    master_data = items;
    size = 0;
    data.reserve(HEAPSIZE);
    
   for (int i=0; i < HEAPSIZE; i++)
    {
        its.push_back(master_data[i].begin());
    }
    
    for (int i=0; i < HEAPSIZE; i++)
    {
        push(i);
    }

}


template <class Type>
void Tournament<Type>::sort()
{

    while (size != 0)
    {
        run.push_back(pop());
    }

}

template <class Type>
vector<Type> Tournament<Type>::retrieve()
{

    return run;

}

template <class Type>
void Tournament<Type>::logFile(ofstream& outFile2)
{

    
    outFile2 << "The number of records that can fit in memory are "  << HEAPSIZE << endl;
    
    int counter = 0;
    
    for (typename vector<vector<Type> >::iterator outit = master_data.begin(); outit != master_data.end(); ++outit)
    {
        for (typename vector<Type>::iterator init = (*outit).begin(); init != (*outit).end(); ++init)
        {
            counter++; 				//keeps track of how many elements are in the vector of vectors i.e. the number of records
        }
    }
    
    outFile2 << "The number of records are " << counter << endl;
    
    outFile2 << "The number of runs are " << HEAPSIZE << endl;
    
    int max = (int)master_data[0].size();
    int min = (int)master_data[0].size();
    
    for(int i = 0; i < HEAPSIZE; i++)
    {
        
        if(master_data[i].size() > max)
        {
            max = (int)master_data[i].size();
        }
        
        if(master_data[i+1].size() < min)
        {
            min = (int)master_data[i+1].size();
        }
        
    }
    
    
    outFile2 << "The smallest number of records in all of the runs is " << min << endl;
    outFile2 << "The largest number of records in all of the runs is " << max << endl;
    outFile2 << "The arithmetic mean number of records in all of the runs is " << counter / HEAPSIZE << endl;
    
    int height = ceil(log2(counter)); 
    outFile2 << "The height of the tournament tree for the merge is " << height << endl;

    
}


//---- Supporter Methods ----//
//-- Private Methods --//

//-- Index Getter --//


template <class Type>
int Tournament<Type>::l_child(int n)
{

    return 2 * n + 1;

}


template <class Type>
int Tournament<Type>::r_child(int n)
{

    return 2 * (n + 1);

}


template <class Type>
int Tournament<Type>::parent(int n)
{

    return (n-1)/2;

}

template <class Type>
int Tournament<Type>::next(int n)
{

    return n+1;

}


template <class Type>
int Tournament<Type>::head()
{

    return 0;

}


template <class Type>
int Tournament<Type>::tail()
{

    return size - 1;

}


//-- Existence Checker --//


template <class Type>
bool Tournament<Type>::exist_parent(int n)
{

    return parent(n) >= 0;

}


template <class Type>
bool Tournament<Type>::exist_l_child(int n)
{

    return l_child(n) < size;

}


template <class Type>
bool Tournament<Type>::exist_r_child(int n)
{

    return r_child(n) < size;

}


template <class Type>
void Tournament<Type>::push(int index)
{

    data[next(tail())] = index;
    size++;
    heapify_up(tail());
    return;

}



template <class Type>
Type Tournament<Type>::pop()
{

    Type returndata = *(its[data[head()]]);
    its[data[head()]] = ++ its[data[head()]];

    if (its[data[head()]] == master_data[data[head()]].end())
     {
        // run out the item from the vector
        data[head()] = data[tail()];
        size--;
    }

    heapify_down(head());
    return returndata;

}



template <class Type>
void Tournament<Type>::heapify_up(int n)
{
    if (n == head()) 
        return;

    if (*(its[data[parent(n)]]) > *(its[data[n]]))
    { 
        int tempdata = data[parent(n)];
        data[parent(n)] = data[n];
        data[n] = tempdata;
        heapify_up(parent(n)); // recursive call to parent node
    }

}


template <class Type>
void Tournament<Type>::heapify_down(int n)
{

    
    if (!exist_l_child(n))
      { // both children not exist
        // stop heapifying
        
          return;
      }

        else if (!exist_r_child(n))
        {                        

        if (*(its[data[l_child(n)]]) < *(its[data[n]]))
        { 
            int tempdata = data[l_child(n)];
            data[l_child(n)] = data[n];
            data[n] = tempdata;
            heapify_down(l_child(n));
        }
        return;
    }
  
      else // both exist
                 // if left child is smaller than right

        if (*(its[data[l_child(n)]]) < *(its[data[r_child(n)]]))
         {

            if (*(its[data[l_child(n)]]) < *(its[data[n]]))
            { 
                int tempdata = data[l_child(n)];
                data[l_child(n)] = data[n];
                data[n] = tempdata;
                heapify_down(l_child(n));
            }
        }
    // if right child is smaller
       
       else
         {

            if (*(its[data[r_child(n)]]) < *(its[data[n]]))
             { 
                int tempdata = data[r_child(n)];
                data[r_child(n)] = data[n];
                data[n] = tempdata;
                heapify_down(r_child(n));
            }
        }
    return;

}




#endif
