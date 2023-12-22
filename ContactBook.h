#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include <iostream>
#include "Contact.h"

using namespace std;

class ContactBook{
private:
    Contact book[10];
    int nextIndex;


public:
    ContactBook() : nextIndex(0) {}
    //retunr numberof contact ini the book
    const int numberOfContacts() const;
    //add contact
    void add(Contact input);
    //remove contact from the list
    void remove(int index);
    //update the contact
    void update(int index, Contact input);
    //search in contact list
    int search(string name);
    Contact contactAtIndex(int index) const;
    //displays all the contacts in the list
    void displayAll() const;

    friend ostream& operator << (ostream& out, const ContactBook& list);
};

#endif
