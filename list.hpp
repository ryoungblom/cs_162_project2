/*********************************************************************
 ** Program name: list.hpp
 ** Author: reuben youngblom
 ** Date: 2/5/16
 ** Description: list header file for project 2
 *********************************************************************/

#include "item.hpp"

class List
{
private:
    Item ** listArray = new Item*[3];  //array that will hold everything
    double total;  //for the list total
    
public:
    
    void addItem(Item X);  //adds item
    void printList();  //prints list
    void removeItem(Item R);  //removes items
    void printTotal ();  //prints the cost total
    int counter=0;  //and tracks iterations through, which I use as number of items
};