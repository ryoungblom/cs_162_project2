/*********************************************************************
 ** Program name: list.cpp
 ** Author: reuben youngblom
 ** Date: 2/5/17
 ** Description: list implementation file for project 2
 *********************************************************************/

#include "list.hpp"

/*
 this function adds an item.  It does one first, because there's nothing to check against.  Then it adds enough to fill the array, because the array has up to 4 slots.
 Then, it moves to the expanded array beyond those 4 slots.  It keeps a counter to see how many items have been added.
 */

void List::addItem(Item X)

{
    
    if (counter == 0)  // if counter is zero, this is the first item.
    {
        listArray [counter] = &X;  //so it just adds it
    }
    
    
    else if (counter > 0 && counter <= 3)  //but if the counter is 1-3, it's in the original predetermined array.
        
    {
        bool doubleBool = false;  //created  a bool to test for duplicates
        
        for (int i=0; i<counter; i++)  //so it runs through the array
        {
            if (X == *listArray[i])  //and checks current item against all elements
            {
                cout<< "This item is already on your list" << endl;  //if match is found, alerts user
                doubleBool = true;  //and switches bool to true
                
                if (doubleBool == true)  //so if it's true, item isn't added.
                {cout << "Item not added" << endl;}
            }
            
            else  //but, if nothing is found
            {
                if (doubleBool == false)  //i.e. if the bool stays false
                    
                {listArray [counter] = &X;}  //it just adds the item
                
                else {counter--;}  //and if not (i.e. if bool is true), preemtively deletes one from the counter to make up for the one that will be added
            }
        }
    }
    
    else  //This is where things start if the array isn't large enough.  Code adapted from a post on Piazza.
    {
        
       //the below overloaded operator test is the same as above.
        
        bool doubleBool = false;  //created  a bool to test for duplicates
        
        for (int i=0; i<counter; i++)  //so it runs through the array
        {
            if (X == *listArray[i])  //and checks current item against all elements
            {
                cout<< "This item is already on your list" << endl;  //if match is found, alerts user
                doubleBool = true;  //and switches bool to true
                
                if (doubleBool == true)  //so if it's true, item isn't added.
                {cout << "Item not added" << endl;}
            }
            
            else  //but, if nothing is found
            {
                if (doubleBool == false)  //i.e. if the bool stays false
        
            {
        
        Item ** tempPtr = new Item*[counter];  //creates new array
        
        for(int index = 0; index < counter+1; index++)  //and copies it exactly from the original array (listArray)
        {
            tempPtr[index] = listArray[index];  //by setting them equal
        }
        
        for(int index = (counter); index < counter; index++)  //and then deletes the elements in listArray
        {
            delete[] listArray[index];
        }
        
        listArray = new Item* [counter+1];  //and re-creates listArray with an extra space
        
        for (int index = 0; index < counter+1; index++)  //and then copies the "old" listArray, which was stored in tempPtr, into this new listArray
        {
            listArray[index] = tempPtr[index];
        }
        
        listArray [counter] = &X;  //and then adds the new element.
               
            }
            
            else {counter--;}  //and if not (i.e. if bool is true), preemtively deletes one from the counter to make up for the one that will be added
            }
        }
    }
    
            
    cout << "Item Added!" << endl;  //and tells the user that the item was added
    counter ++; //and tracks the loop through on the counter
}


void List::removeItem(Item R)  //this function is to delete items
{
    
    string Cstr = R.getName();  //I adapted this code from a cs161 project.  Kept the caps error checking
    int toDelete;  //tracks what to delete
    
    
    bool testBool = false;  //created a test bool just like above. Helps me easily create conditionals at the end of each code segment
    
    
    Cstr[0] = toupper(Cstr[0]);  //i used an auxillary string so I could manipulate it. Here, I turn the first letter into uppercase and run the search that way:
    
    for(int i=0; i < counter; i++)  //iterate through the inventory
    {
        if ((listArray[i]->getName()).find (Cstr) != std::string::npos)  //I check for a match by seeing if the Cstr is found in the descriptions and checking against npos.  if something is found...
        {
            
            cout << "Item Deleted!" << endl;  //alert user that something is deleted
            
            toDelete = i;  //then delete it
            
            testBool = true;  //sets bool equal to true
            
            counter --;  //and subtracts one from the counter
            
        }
    }
    
    //and then does it again for lowercase
    
    Cstr[0] = tolower(Cstr[0]);  //i used an auxillary string so I could manipulate it. Here, I turn the first letter into uppercase and run the search that way:
    
    for(int i=0; i < counter; i++)  //iterate through the inventory
    {
        if ((listArray[i]->getName()).find (Cstr) != std::string::npos)  //I check for a match by seeing if the Cstr is found in the descriptions and checking against npos.  if something is found...
        {
            
            toDelete = i; //sets toDelete to i
            
            testBool = true;  //sets bool equal to true
            
            counter --; //and deletes on from counter
            
            //cout << counter;
        }
        
    }

    
    if (testBool == false) //so.  If no match is found,
    {cout << "sorry, item not found" << endl;} //tell user item wasn't found.  But if it was...
    
    else
    {
       listArray[toDelete] = NULL;  //free that space up by setting it to NULL
        
        
        if (true)  //so if this is true (it will be)
        {
            Item ** tempPtr = new Item*[counter];  //redo the array as above, but minus a space
            
            
            for(int index = 0; index < toDelete; index++)
            {
                tempPtr[index] = listArray[index];  //so copy the array up to delete
            }
            
            for(int index = toDelete+1; index < counter+1; index++)
            {
                tempPtr[index-1] = listArray[index];  //and then copy after delete
            }
            
            //delete [] &listArray[0];
            
           /*
            for (int index = (counter); index < counter; index++)
            {
                delete[] listArray[0];  //and then clear the old array
            
            }
            */
            delete [] listArray;
            
            
            std::cout << "Item Removed!" << std::endl;  //alerts the user
            listArray = new Item* [counter];  //makes a NEW array, with one less space
            
            for (int index = 0; index < counter; index++)
            {
                listArray[index] = tempPtr[index];  //and assigns tempPtr slots to that array
            }
        }
    }
}



void List::printList()
{
    cout << endl;  //just a space for aesthetics
    
    cout << "Your List:" << endl;  //tells user what they're looking at
    
    cout << endl;  //another space
    
    for (int i=0; i<counter; i++)  //runs through the array
        
    {  //and outputs the elements of the list objects via ->
        cout << "Item name:  " << listArray[i]->getName() << endl;
        cout << "Unit:  " << listArray[i]->getUnit() << endl;
        cout << "Quantity:  " << listArray[i]->getQuantity() << endl;
        cout << "Price:  " << listArray[i]->getPrice() << endl;
        
        cout << endl;  //space for looks
    }
}


void List::printTotal()  //prints the total
{
    
    total = 0;  //sets equal to zero every time
    
    for (int i=0; i<counter; i++)  //runs through array
        
    {
        double totalRound = (listArray[i]->getQuantity()) * (listArray[i]->getPrice()); //gets price and quantity, and multiplies them
        
        total += totalRound;  //and keeps a running total
    }
    
    cout << "Total: " << total << endl;  //before outputting total
    
}



