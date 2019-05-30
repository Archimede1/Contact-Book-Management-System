#include <iostream>
#include <string>
#include "Contact.h"

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

class ContactBook : public Contact{
  private:
    string ownerFirst, ownerLast;
    int capacity;
    int contactAmount;
    Contact *contactBook;
    void grow();
    void sort();
  
  public:
    ContactBook();
    ContactBook(int capacity, int index, string first, string last);
    ContactBook(const ContactBook &b);
    ~ContactBook();
    Contact getContact(int index);
    Contact* getContactBook();
    int index;
    int searchContact();
    int getContactAmount();
    int getCapacity();
    void merge(ContactBook otherBook);
    void inputName();
    void fillArray();
    void addContact(); 
    void editContact(int index); 
    void removeContact(int index); 
    void displayAll();  
    string getoFirst();
    string getoLast();
};
#endif