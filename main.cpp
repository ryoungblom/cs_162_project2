/*********************************************************************
 ** Program name: main.cpp
 ** Author: reuben youngblom
 ** Date: 2/5/17
 ** Description: Main implementation file for project 2
 *********************************************************************/

#include "list.hpp"

int main ()
{
    
    List testList;  //create list
    
    Item bread ("bread", "loaf", 5, 5.99);  //these all create items.  bread, soup, etc.
    Item soup ("soup", "can", 3, 2.99);
    Item apple ("apple", "bag", 7, 8.00);
    Item froyo ("froyo", "gallon", 2, 11.00);
    Item cod ("cod", "fish", 3, 4.99);
    Item eggs ("eggs", "carton", 1, 2.50);
    Item cheese ("cheese", "slice", 12, 2.99);


   // froyo.printItem(froyo);  //tested this to make sure items were working, but commented out
    
    
    testList.addItem (bread);   //this adds items to the list.
    testList.addItem (soup);
    testList.addItem(bread);  //I put this one to make sure my program would catch it
    testList.addItem(apple);
    testList.addItem(froyo);  //went beyond the four to make sure array would expand
    testList.addItem(cod);  //and another test
    testList.addItem(eggs);
    testList.addItem(cod);
    testList.addItem(cheese);
    
    
    
    testList.printList();  //printed list as-is
    
    testList.printTotal();  //printed total
    
    testList.removeItem(cheese);  //removed the cod item, as a test
    
    testList.printList();  //reprinted list to make sure it was gone
    
    testList.printTotal();  //and reprinted updated total

    
    
    return 0;
}



