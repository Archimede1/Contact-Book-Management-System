#include <iostream>
#include "ContactBook.h"
#include <string>

#ifndef CONTACTSYSTEM_H
#define CONTACTSYSTEM_H


class ContactSystem {
  private:
    int capacity, booksUsed;
    ContactBook *contactSystem;
  
  public:
    ContactSystem();
    ContactSystem(int capacity, int used);
    ContactSystem(const ContactSystem &b);
    ~ContactSystem();
    ContactBook getBook(int index);
    ContactBook* getContactSystem();
    int search();
    int getCapacity();
    int getBooksUsed();
    void add();
    void display();
    void remove(int index);
    void inputBook(int index);
    void outputBook();
    void findAndReplace(string toReplace, string replacer);

};

#endif