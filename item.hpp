/*********************************************************************
 ** Program name: item.hpp
 ** Author: reuben youngblom
 ** Date: 2/5/17
 ** Description: item header file for project s
 *********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


class Item
{
private:
    string itemName;  //holds item name
    string itemUnit;  //holds item units
    int itemQuantity;  //holds item quantity
    double itemPrice; //holds item price
    
public:
    Item (string name, string unit, int quantity, double price);  //object prototype
    
    string getName ();  //function to return name
    string getUnit();  //to return unit
    int getQuantity();  //to return quantity
    double getPrice();  //to return price
    void addItemI (Item X);  //to add an item
    void printItem(Item x);  //to print an item (testing)
    friend bool operator== (Item &c1, Item &c2);  //overloads == operator
    int itemCount=0;  //tracks number of items
};

