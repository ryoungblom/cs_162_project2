/*********************************************************************
 ** Program name: item.cpp
 ** Author: reuben youngblom
 ** Date: 2/5/17
 ** Description: item implementation file for project 2
 *********************************************************************/

#include "item.hpp"

Item::Item (string name, string unit, int quantity, double price)  //item constructor
{
    itemName = name;  //sets object elements equal to holding variables
    itemUnit = unit;
    itemQuantity = quantity;
    itemPrice = price;
}


void Item::printItem(Item x)  //prints items.  Mostly used for testing, but could be useful for some users
{
    cout << x.itemName << endl;
    cout << x.itemUnit << endl;
    cout<< x.itemQuantity << endl;
    cout << x.itemPrice << endl;
    cout << endl;
    cout << endl;
}



bool operator== (Item &c1, Item &c2)  //operator overload parameters.  Sets them equal (used in list::addItem function)
{
    return (c1.getName()== c2.getName());  //checks them and returns bool
}



string Item::getName ()  //returns item name
{
    return itemName;
}

string Item::getUnit ()  //returns item unit
{
    return itemUnit;
}

int Item::getQuantity()  //returns item quantity
{
    return itemQuantity;
}

double Item::getPrice () //returns item price
{
    return itemPrice;
}

