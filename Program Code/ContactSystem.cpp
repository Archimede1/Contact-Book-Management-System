#include <iostream>
#include <string>
#include <fstream>
#include "ContactSystem.h"
#include "ContactBook.h"
#include "Address.h"
#include "Contact.h"

ContactSystem::ContactSystem(){ //default constructor
  (*this).capacity = 5;
  booksUsed = 0;
  contactSystem = new ContactBook[(*this).capacity];
}

ContactSystem::ContactSystem(int capacity, int used){ //assignment constructor
  (*this).capacity = capacity;
  (*this).booksUsed = used;
  contactSystem = new ContactBook[(*this).capacity];
}

ContactSystem::ContactSystem(const ContactSystem &b){ //copy constructor
  (*this).capacity = b.capacity;
  booksUsed = b.booksUsed;
  contactSystem = new ContactBook[b.capacity];
  copy(b.contactSystem, b.contactSystem + capacity, contactSystem);
}

ContactSystem::~ContactSystem(){ //destructor
  delete []contactSystem;

}

void ContactSystem::add(){ 
  int option;
  for(int i = 0; i <= capacity; i++){
    i = booksUsed;
    contactSystem[i].inputName();
    cout << endl;
    cout << "Contact Book Create For Owner: " << contactSystem[i].getoFirst() << " " << contactSystem[i].getoLast() << endl; 
    cout << "\nTo Modify Book, Please Go to Main Menu, Select, And Select Owner's Name!\n";
    booksUsed++; 
         if(booksUsed >= capacity){
            cout << "System is Full!" << endl;
            break;
         }
    cout <<"What Would You Like to Do \nPlease choose one of the options:\n";
    cout <<"Enter '1' to Create a Another ContactBook\n";
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
  int ContactSystem::search(){ 
  string fname, lname;
  cout << "Enter First Name: ";
  cin >> fname;
  cout << "Enter Last Name: ";
  cin >> lname;
  for(int i = 0; i < capacity; i++){
      if(contactSystem[i].getoFirst() == fname && contactSystem[i].getoLast() == lname){
        cout << "\nContactBook Number: " << i + 1 << endl;
        cout << "Contact Book Owner: " << contactSystem[i].getoFirst() << " " << contactSystem[i].getoLast() << endl; 
        return i;
      }  
    }
 return -1; 
}

void ContactSystem::remove(int index){
  ContactBook blankContactBook;
  contactSystem[index] = blankContactBook;
  if(booksUsed!= 0){
  booksUsed--;
    for(int i = 0; i < booksUsed; i++){
      contactSystem[index + i] = contactSystem[index + (i + 1)];
    }
  }
  else{
    cout << "System is Empty \n";
  }

}

void ContactSystem::display(){
  for(int i = 0; i < capacity; i++){
    inputBook(i);
  }
  outputBook();
  cout << endl;
}

void ContactSystem::outputBook(){
  ifstream input("contactbooks.txt");
  string output;
  if(input.is_open()){
    while(getline(input, output)){
      cout << output << "\n";
    }
  }
  else{
    cout << "Error: File Cannot Open \n";
    cin.get();
  }
}

void ContactSystem::inputBook(int index){
  findAndReplace("Ownerfname", contactSystem[index].getoFirst());
  findAndReplace("Ownerlname", contactSystem[index].getoLast());
  for(int i = 0; i < contactSystem[index].getContactAmount(); i++){
    findAndReplace("first-name", contactSystem[index].getFirst());
    findAndReplace("last-name", contactSystem[index].getLast());
    findAndReplace("phone", contactSystem[index].getNumb());
    findAndReplace("email", contactSystem[index].getEmail());
    findAndReplace("home", contactSystem[index].getAddressClass().getHome());
    findAndReplace("street", contactSystem[index].getAddressClass().getStreet());
    findAndReplace("apt", contactSystem[index].getAddressClass().getApt());
    findAndReplace("city", contactSystem[index].getAddressClass().getCity());
    findAndReplace("state", contactSystem[index].getAddressClass().getState());
    findAndReplace("zip", contactSystem[index].getAddressClass().getZip());
   }
}

void ContactSystem::findAndReplace(string toReplace, string replacer){
    ifstream in("contactbooks.txt");
    string wordToReplace(toReplace);
    string wordToReplaceWith(replacer);
    string line;
    size_t len = wordToReplace.length();
    while (getline(in, line))
    {
      size_t pos = line.find(wordToReplace);
      if (pos != string::npos)
          line.replace(pos, len, wordToReplaceWith);
      else 
          break;
      cout << line << '\n';
    }   
}


ContactBook* ContactSystem::getContactSystem(){
  return contactSystem;
}

ContactBook ContactSystem::getBook(int index){
  return (*this).contactSystem[index];
}

int ContactSystem::getCapacity(){
  return (*this).capacity;
}

int ContactSystem::getBooksUsed(){
  return (*this).booksUsed;
}



 


