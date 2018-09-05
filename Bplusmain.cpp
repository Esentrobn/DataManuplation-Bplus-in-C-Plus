
// Bplusmain.cpp
   /** Bplusmain used to run the program. It will be executed
           This is the file where all the classes are tested.
           It holds the main () function. */


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "DualHeap.h"
#include "Tournament.h"
#include "SequenceSet.h"
#include "BPT.h"

using namespace std;

/** \fn void show_menu()
*    \ displays the menu to user
*/

void show_menu() 
{
	
    cout<< "> Please type in one of the following options: \n";
    cout<< "  1 to open and read a file \n";
    cout<< "  2 to print record information \n";
    cout<< "  3 to modify a record\n";
    cout<< "  4 to insert a record \n";
    cout<< "  5 to delete a record \n";
    cout<< "  0 to exit \n";
	
}

/** \fn void select_menu()
*    \brief user can selects the actions to perform by the program based on choices offered
*/

void select_menu()
{
	
    char select;

    show_menu();
    cout << "> Please indicate your choice of operation: ";
    cin >> select;
    cin.ignore(200, '\n');
    cin.clear();            //clear out all input
    int menu_counter = 0;
    BPT<int> T(6);
    
    while (true)
      {
        if (select == '1')
          { // open file
          }

          else if (select == '2')
           { // disp records
           }

           else if (select == '3')
           { // modify a record
           }
           
           else if (select == '4')
           { // insert a record
           }

           else if (select == '5')
           { // delete a record
           }

           else if (select == '0')
           {
                 break;
           }
           
            else
            {
                 cout << "Invalid selection.\n";
            }
      
                menu_counter++;
        
          if (menu_counter % 4 == 0)
           {
              show_menu();
           }
        
        cout << "Please indicate your choice of operation: ";
        cin >> select;
        cin.ignore(200, '\n'); 
        cin.clear();              //clear out all input
    }
    
         cout << "Thank you! Good-bye!!\n";
	
}



/** \fn void demoStr()
*    \brief demonstrates the execution of the program using s file of strings
*/
void demoStr()
{
	
    ifstream inFile;
    string inFileName;
    string flag;
    string strValue;
    char select;
    BPT<string> T(6);
    show_menu();
    cout << "> Please indicate your choice of operation: ";
    cin >> select;
    cin.ignore(200, '\n'); 
    cin.clear(); 		//clear out all input
    int menu_counter = 0;
    
	while (true)
	{
        	if (select == '1')
		    { 		// open file
            		cout << "> Please enter input file name: ";
           		 cin >> inFileName;
          		  inFile.open(inFileName.c_str());
          		  if (! inFile)
			  {
                		cout << "> Invalid file name.";
               			 break;
        		  }
         	    getline(inFile, flag ,'|');
        	    while (getline(inFile, strValue, '|'))
			{
                		T.put(strValue);
            		}
            cout << "> Successfully read.\n";
            inFile.close();
         }
          
             else if (select == '2')
                {        // disp records
            
                   T.print();
            	   cout << endl;
        }
               else if (select == '3')
                    {      // modify a record
         		 
			  cout << "> Please enter a record to be modified.\n";
         		   cin >> strValue;
         	          
                       if (T.remove(strValue))
                           {
                	          cout << "> Please enter a new value.\n";
                	          cin >> strValue;
                                  T.put(strValue);
                	          cout << "> Successfully modified.\n";
                   }
         
            else
             {
                 cout << "> Not found in records.\n";
             }
        }
          
             else if (select == '4')
                 {                // insert a record
                   
                    cout << "> Please enter a new record.\n";
                    cin >> strValue;
                    T.put(strValue);
                    cout << "> Successfully inserted.\n";
               }
      
              else if (select == '5')
               {                // delete a record
                        cout << "> Please enter a record to be deleted.\n";
            		cin >> strValue;
            		if (T.remove(strValue)){
                	cout << "> Successfully deleted.\n";
            }
		else 
		{
                	cout << "> Not found in records.\n";
            	}
        }
		else if (select == '0')
			{
            			break;
        		}
		
		else	
		{
            		cout << "Invalid selection.\n";
        	}
        
			menu_counter++;
       			
 		if (menu_counter % 4 == 0)
			{
            			show_menu();
        		}
       
		 cout << "Please indicate your choice of operation: ";
        	 cin >> select;
        	 cin.ignore(200, '\n'); 
                 cin.clear();                        //clear out all input
        }

}


/** \fn void demoInt()
*    \brief demonstrates the execution of the program using s file of integers
*/


void demoInt()
{
	
    ifstream inFile;
    string inFileName;
    string flag;
    int inValue;
    char delimiter;
    char select;
    BPT<int> T(6);
    show_menu();
    
     cout << "> Please indicate your choice of operation: ";
     cin >> select;
     cin.ignore(200, '\n');
     cin.clear();                    //clear out all input
     int menu_counter = 0;
     
         while (true)
          {
        		if (select == '1')          
                          {
				 // open file
            
                                 cout << "> Please enter input file name: ";
                                 cin >> inFileName;
            			 inFile.open(inFileName.c_str());
                                
                                 if (! inFile)
                                   {
                			cout << "> Invalid file name.";
               				 break;
                           }
            
                    getline(inFile, flag ,'|');
                    
                    while (inFile >> inValue)
                       {
               
                              T.put(inValue);
                              inFile >> delimiter;
                
                       }
            
                   cout << "> Successfully read.\n";
                   inFile.close();
          }
            
               else if (select == '2')
                   {        // disp records
            
                        T.print();
                        cout << endl;
                   }            
              
                   else if (select == '3')
                    {
                                // modify a record
           
                        cout << "> Please enter a record to be modified.\n";
                        cin >> inValue;
            
                        if (T.remove(inValue))
                            {
                                        cout << "> Please enter a new value.\n";
                                        cin >> inValue;
                                        T.put(inValue);
                                        cout << "> Successfully modified.\n";
                             }
                          
                              else 
				{
                			cout << "> Not found in records.\n";
            			}
        	     }
          	 
                         else if (select == '4')
                            {
                                     // insert a record
                            
                                cout << "> Please enter a new record.\n";
                                cin >> inValue;
            			T.put(inValue);
            			cout << "> Successfully inserted.\n";
        }

 			else if (select == '5')
                            { // delete a record
            
                               cout << "> Please enter a record to be deleted.\n";
            		       cin >> inValue;
                                 
                                  if (T.remove(inValue))
                                     {
                			cout << "> Successfully deleted.\n";
            			     }
                          else
                            {
                		cout << "> Not found in records.\n";
            		    }
       		 }

                         else if (select == '0')
                          {
            			break;
        	   }
                        else
                         {
            			cout << "Invalid selection.\n";
        		 }
       				
                                 menu_counter++;
        		
                        if (menu_counter % 4 == 0)
                         {
            			show_menu();
        		 }
        			
                             cout << "Please indicate your choice of operation: ";
        		     cin >> select;
        		     cin.ignore(200, '\n'); 
                             cin.clear();                   //clear out all input
        }
	
   }

// ------------------------------------------------
// --------------------- SORT ---------------------
// ------------------------------------------------

/** \fn void demoSort()
*    \brief demonstrates the sorting of records
*/
void demoSort()
{
	
    ifstream inFile;
    ofstream outFile, runFile;
    string inFileName, outFileName, runFileName;
    string flag;
    char delimiter;
    int inValue;
    string strValue;
    
    // File Operations
     
    cout << "> Please enter input file name: ";
   
    cin >> inFileName;
    inFile.open(inFileName.c_str());
    
   if (! inFile)
    {
        cout << "> Invalid file name.";
        return;
    }
   
    cout << "> Please enter output file name: ";
    cin >> outFileName;
    outFile.open(outFileName.c_str());
    
    
     // Retrieving records from input file
     
    getline(inFile, flag ,'|');
    if (flag == "str")
      {
        
        // instantiate algorithm class with type <string>
       
         DualHeap<string> h(10);
        
        // read and insert all values into algorithm
        
        while (getline(inFile, strValue, '|'))
        {
            h.put(strValue);
        }
        
        // retrieve the vector of vectors
        // each vector is a sorted list of items

        vector<vector<string> > v = h.retrieve();
                
        // Generating run files.
        
        stringstream ss;
        
      for (int i=0; i < v.size(); i++)
        {
            ss.str("");
            ss.clear();
            ss << inFileName << "_run" << i+1 << ".txt";
            runFileName = ss.str();
            runFile.open(runFileName.c_str());
            
           for (int j=0; j < v[i].size(); j++)
           {
                runFile << v[i][j] << "|";
           }
           
                    runFile.close();
        }
        
        //Tornament Sorting.
         
        
        Tournament<string> t(v);
        t.sort();
        vector<string> r = t.retrieve();    
        
         // Saving sorted string records to output file.
        
        outFile << "string|";
        for (int i=0; i < r.size(); i++)
        {
            outFile << r[i] << "|";
        }
        
        outFile << endl;
        
        ofstream outFile2;
        outFile2.open("logFile.txt");
        
        
        outFile2 << "The unsorted records are from the data file: " << inFileName <<endl;
        
        outFile2 << "The sorted records are placed in the data file called: " << outFileName << endl;
        
        t.logFile(outFile2);
        
        cout << "Sorting records and saving into a file succeeded.\n";
        
    }

    else if (flag == "int")
      {
        
        // instantiate algorithm class with type <int>
    
    DualHeap<int> h(10);
        
        // read and insert all values into algorithm
        
     while (inFile >> inValue)
         {
            h.put(inValue);
            inFile >> delimiter;
         }
     
       // retrieve the vector of vectors
        // each vector is a sorted list of items
        
		vector<vector<int> > v = h.retrieve();
        
        // Generating run files.
         
        
         stringstream ss;
        
      for (int i=0; i < v.size(); i++)
        {
            ss.str("");
            ss.clear();
            ss << inFileName << "_run" << i+1 << ".txt";
            
            runFileName = ss.str();
            runFile.open(runFileName.c_str());

            for (int j=0; j < v[i].size(); j++)
            {
                runFile << v[i][j] << "|";
            }

            runFile.close();
        }
        
        // Sorting.
        
        
        Tournament<int> t(v);
        t.sort();
        vector<int> r = t.retrieve();
        
        /*
         * Saving sorted integer records to output file
         */
        
        outFile << "int|";
        for (int i=0; i < r.size(); i++)
        {
            outFile << r[i] << "|";
        }
        
        outFile << endl;
        
        ofstream outFile2;
        outFile2.open("logFile.txt");
        
        
        outFile2 << "The unsorted records are from the data file: " << inFileName <<endl;
        
        outFile2 << "The sorted records are placed in the data file called: " << outFileName << endl;
        
        t.logFile(outFile2);
        
        cout << "Sorting records and saving into a file succeeded.\n";
        
    }

  else 
    {
        cout << "The data file is not valid: the first field should specify if data is string or integer by using these flags: \"str\", \"int\".\n";
    }
    inFile.close();
    outFile.close();
	
}


// ------------------------------------------------
// --------------------- MAIN METHOD---------------------
// ------------------------------------------------

int main(int argc, const char* argv[])
{
	
    char select;
    cout<< "---------------- RECORD SORTING \n";
    cout<< "> Do you want to sort records in a file?: \n";
    cout<< "  1 Yes \n";
    cout<< "  2 No \n";
    cout<< "> ";
    cin >> select;
    cin.ignore(200, '\n'); 
    cin.clear(); 			//clear out all input
    while (true)
	{
        	if (select == '1')
			{		 // sort
            			demoSort();
            			break;
        }
	
		else if (select == '2')
		   {			 // break
            			break;
        	   }

		else
		  {
            		cout << "Invalid selection.\n";
        	  }
        
                  cout<< "> Do you want to sort a file first?: \n";
        	  cout<< "  1 Yes \n";
        	  cout<< "  2 No \n";
                  cout<< "> ";
        	  cin >> select;
        	  cin.ignore(200, '\n');
                  cin.clear(); 			//clear out all input
    }
    
    
    // RECORD DATA TYPE
    
		cout<< "-------------- RECORD ORGANIZATION \n";
    		cout<< "> Do you want to manage records in a file?: \n";
    		cout<< "  1 Yes \n";
    		cout<< "  2 No \n";
    		cout<< "> ";
    		cin >> select;
    		cin.ignore(200, '\n'); 
		cin.clear(); 			//clear out all input
    
		while (true)
		  {
       			 if (select == '1')
				{		 // manage
            				break;
        	  }	
 
		 else if (select == '2')
			{			 // break
            
				cout << "Thank you! Good-bye!!\n";
          			return 0;
        }

		  else
		   {
           			 cout << "Invalid selection.\n";
        	   }
        
			cout<< "> Do you want to manage records in a file?: \n";
        		cout<< "  1 Yes \n";
        		cout<< "  2 No \n";
        		cout<< "> ";
        		cin >> select;
        		cin.ignore(200, '\n');
			cin.clear();		 //clear out all input
    }
    
    		cout<< "> Please select a record data type: \n";
    		cout<< "  1 integer(int) \n";
    
    cout<< "  2 string(str) \n";
    cout<< "> ";
    cin >> select;
    cin.ignore(200, '\n');
    cin.clear(); 		//clear out all input
    
  while (true)
    {
        if (select == '1')
         { 			// integer Sorting and Manuplation
            demoInt();
            break;
         }

	else if (select == '2')
          {			 // string Sorting and Manuplation
               demoStr();
               break;
          }

	else
	 {
            cout << "Invalid selection.\n";
         }
        		cout<< "> Please select a record data type: \n";
      			cout<< "  1 integer(int) \n";
        		cout<< "  2 string(str) \n";
      			cout<< "> ";
      		        cin >> select;
        		cin.ignore(200, '\n');
			cin.clear();			 //clear out all input
    	}
    		cout << "Thank you! Good-bye!!\n";
		    return 0;

}
