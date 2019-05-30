#include <iostream>
#include <string>
#include "ContactBook.h"
#include "Address.h"
#include "Contact.h"


ContactBook::ContactBook(){ //default constructor
  ownerFirst = "";
  ownerLast = "";
  (*this).capacity = 10;
  contactAmount = 0;
  contactBook = new Contact[capacity];
}

ContactBook::ContactBook(const ContactBook &b){ //copy constructor
  capacity = b.capacity;
  contactAmount = b.contactAmount;
  contactBook = new Contact[b.capacity];
  copy( b.contactBook, b.contactBook + capacity, contactBook );
}


ContactBook::ContactBook(int capacity, int index, string first, string last){ //assignment constructor
  ownerFirst = first;
  ownerLast = last;
  (*this).capacity = capacity;
  (*this).contactAmount = index;
  contactBook = new Contact[capacity];
}

  
ContactBook::~ContactBook(){ //destructor
   delete []contactBook;
 }

void ContactBook::grow(){ 
  if(contactAmount >= capacity){
    Contact* temp = new Contact[capacity * 2];
    copy(contactBook, contactBook + capacity, temp);
    capacity = capacity * 2; 
    delete []contactBook;
    contactBook = temp;
   }
 }

void ContactBook::addContact(){
  int option;
  for(int i = 0; i <= capacity; i++){
    i = contactAmount;
    contactBook[i].input();
    contactAmount++; 
    sort();
         if(contactAmount >= capacity){
            grow(); 
         }
    cout <<"What Would You Like to Do \nPlease choose one of the options:\n";
    cout <<"Enter '1' to Create a Another Contact \n";
    cout <<"Enter '2' to go to Main Menu \n";
    cin >> option;
    if(option == 1){
      continue;
    }
    if(option == 2){
      break;
    }
  }
 
}

void ContactBook::inputName(){
  cout << "Enter Owner First Name: \n";
  cin >> ownerFirst;
  cout << "Enter Owner Last Name: \n";
  cin >> ownerLast; 
}

void ContactBook::editContact(int index){
  (*this).index = index;
  contactBook[index].input(); 
}

void ContactBook::removeContact(int index){
  Contact blankContact;
  contactBook[index] = blankContact;
  if(contactAmount!= 0){
  contactAmount--;
    for(int i = 0; i < contactAmount; i++){
      contactBook[index + i] = contactBook[index + (i + 1)];
    }
  }
  else{
    cout << "ContactBook is Empty \n";
  }
  
}

int ContactBook::searchContact(){ 
  string fname, lname;
  cout << "Enter First Name: ";
  cin >> fname;
  cout << "Enter Last Name: ";
  cin >> lname;
  for(int i = 0; i < capacity; i++){
      if(contactBook[i].getFirst() == fname && contactBook[i].getLast() == lname){
        cout << "\n1Contact Number: " << i + 1 << endl;
        contactBook[i].output(); 
        return i;
      }  
    }
 return -1; 
}

void ContactBook::displayAll(){
  for(int i = 0; i < capacity; i++){
    cout << "Contact Number: " << i + 1 << endl;
    cout << contactBook[i];
    cout << endl;
    }
}

Contact ContactBook::getContact(int index){
  return (*this).contactBook[index];
}

Contact* ContactBook::getContactBook(){
  return contactBook;
  }

void ContactBook::fillArray(){ //test method
  Contact blankContact;
  blankContact.input();
  for(int i = 0; i < capacity - 1; i++){
    contactBook[i] = blankContact;
    contactAmount++;
  }
  sort();
}

void ContactBook::sort(){
  Contact temp;
  for(int i = 0; i < contactAmount; i++){
    if(contactBook[i + 1].getFirst() < contactBook[i].getFirst()){
      contactBook[i] = temp;
      contactBook[i] = contactBook[i + 1];
      contactBook[i + 1] = temp;
    }
  }
}

void ContactBook::merge(ContactBook otherBook){
  Contact* temp = new Contact[capacity + otherBook.capacity];
  copy(contactBook, contactBook + capacity, temp);
  capacity = capacity + otherBook.capacity;
  copy(contactBook + contactAmount, contactBook + capacity, temp);
  contactAmount = contactAmount + otherBook.contactAmount;
  delete []contactBook;
  contactBook = temp;
  sort();
}


int ContactBook::getContactAmount(){
  return contactAmount;
}

int ContactBook::getCapacity(){
  return capacity;
}

string ContactBook::getoFirst(){
  return ownerFirst;
}

string ContactBook::getoLast(){
  return ownerLast;
}