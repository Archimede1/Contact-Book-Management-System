#include <iostream>
#include <fstream>
#include "Contact.h"
#include "ContactBook.h"
#include "ContactSystem.h"
using namespace std;



int main() {
    ContactSystem contactSystem;
    int systemIndex;
    int systemIndex2;
    int systemOption;
    int systemOption2;
    int option;
    int option2;
    int index;
    int choice;
    string a,b,c,d;
  
    do {
      cout << "Welcome to your Contact Book Management System. \nPlease choose one of the options: \n";
      cout << "Enter '1' to Create a New Contact Book.\n";
      cout << "Enter '2' to Select an Existing Contact Book.\n";
      cout << "Enter '3' to Search for an Existing Contact Book\n";
      cout << "Enter '4' to Display All Contact Books\n"; 
      cout << "Enter '5' to View Contact Book System Storage \n";
      cout << "Enter '6' to Exit \n";
      cin >> systemOption;

      if(systemOption == 1){
        contactSystem.add();
        continue;
      }

      if(systemOption == 2){
        cout << "Select a ContactBook \nPlease choose one of the options: \n";
        cout << "* If name is blank, Contact Book has not been used, Therefore it cannot be selected. \n";
        cout << "Enter 1 for " << contactSystem.getContactSystem()[0].getoFirst() << "'s Contact Book\n";
        cout << "Enter 2 for " << contactSystem.getContactSystem()[1].getoFirst() << "'s Contact Book\n";
        cout << "Enter 3 for " << contactSystem.getContactSystem()[2].getoFirst() << "'s Contact Book\n";
        cout << "Enter 4 for " << contactSystem.getContactSystem()[3].getoFirst() << "'s Contact Book\n";
        cout << "Enter 5 for " << contactSystem.getContactSystem()[4].getoFirst() << "'s Contact Book\n";
        cin >> systemIndex2;
        if(contactSystem.getContactSystem()[systemIndex2 - 1].getoFirst() == ""){
          cout << "Contact Book Has Not Been Added Yet, Please Go To Main Menu To Create One With a Owner First and Last Name! \n";
          continue;
        }
        do {
            cout << "Welcome to your Contact Book " << contactSystem.getContactSystem()[systemIndex2 - 1].getoFirst() <<"\nPlease choose one of the options:\n";
            cout << "Enter '1' to Create a New Contact.\n";
            cout << "Enter '2' to Search for an Existing Contact\n";
            cout << "Enter '3' to Display All Contacts\n"; 
            cout << "Enter '4' to View Contact Book Storage \n"; 
            cout << "Enter '5' to Exit to System Menu\n"; 
            cin >> option;

            if (option == 1) {
                contactSystem.getContactSystem()[systemIndex2 - 1].addContact();
                continue;
              }
        

            if (option == 2) {
                index = contactSystem.getContactSystem()[systemIndex2 - 1].searchContact();
                if (index < 0) {
                  cout << "Cannot find the contact that you are looking for in the database.\n";
                  continue;
                }
                else contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                do{
                  cout << "What Would You Like to Do Next? \nPlease choose one of the options: \n";
                  cout << "Enter '1' to Edit the Contact \n";
                  cout << "Enter '2' to Delete the Contact \n";
                  cout << "Enter '3' to Return to Main Menu \n";
                  cin >> option2;
                  if(option2 == 1){
                    cout << "What Would You Like to Edit \nPlease choose one of the options:\n";
                    cout << "Enter '1' for First Name \n";
                    cout << "Enter '2' for Last Name \n";
                    cout << "Enter '3' for Address \n";
                    cout << "Enter '4' for Phone Number \n";
                    cout << "Enter '5' for Email \n";
                    cout << "Enter '6' for Entire Contact \n";
                    cout << "Enter '7' to Go Back to Main Menu \n";
                    cin >> choice;
                    switch(choice) {
                      case 1: cout << "Enter First Name: ";
                              cin >> a;
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).setFirst(a);
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                      case 2: cout << "Enter Last Name: ";
                              cin >> b;
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).setLast(b);
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                      case 3: cout << "Enter Address: ";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).setAddress();
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                      case 4: cout << "Enter Phone Number: ";
                              cin >> c;
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).setNumb(c);
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                      case 5: cout << "Enter Email: ";
                              cin >> d;
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).setEmail(d);
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                      case 6: contactSystem.getContactSystem()[systemIndex2 - 1].editContact(index);
                              cout <<"Your New Contact !: \n";
                              contactSystem.getContactSystem()[systemIndex2 - 1].getContact(index).output();
                              break;
                    }
                    if(choice == 7) break;
                    else continue;
                  }
                  if(option2 == 2){
                    contactSystem.getContactSystem()[systemIndex2 - 1].removeContact(index);
                    cout <<"Contact Removed \n";
                    break;
                  }
                }while(option2 != 3);
                continue;
            }
            else if (option == 3){contactSystem.getContactSystem()[systemIndex2 - 1].displayAll();}
            if (option == 4){
              cout << "Amount of Contact Spaces Used: " << contactSystem.getContactSystem()[systemIndex2 - 1].getContactAmount() << endl;
              cout << "Amount of Contact Spaces Available: "; 
              cout << contactSystem.getContactSystem()[systemIndex2 - 1].getCapacity()/*capacity*/ - contactSystem.getContactSystem()[systemIndex2 - 1].getContactAmount(); 
              cout << endl; 
              cout << "Capacity: " << contactSystem.getContactSystem()[systemIndex2 - 1].getCapacity() << endl;
              continue;
            }
            else if (option > 5 && option != 6231) cout << "Please enter 1, 2, 3, 4, or 5.\n";        
            cout << "\n";

            if(option == 6231){ //for quick testing, enter 6231  to add nine contacts to the contactBook, for quicker test of the growable feature.
              contactSystem.getContactSystem()[systemIndex2 - 1].fillArray();
            } 

        } while(option != 5);
        continue;
      }

      if(systemOption == 3){
        systemIndex = contactSystem.search();
        if(systemIndex < 0){
          cout << "Cannot find the Contact Book that you are looking for in the database.\n";
          continue;
        }
        do{
            cout << "What Would You Like to Do Next? \nPlease choose one of the options: \n";
            cout << "Enter '1' to Merge this Contact Book with Another\n";
            cout << "Enter '2' to Delete this Contact Book \n";
            cout << "Enter '3' to Return to Main Menu \n";
            cin >> systemOption2;
            if(systemOption2 == 1){
              cout << "Choose other Contact Book to Merge With \nPlease choose one of the options: \n";
              cout << "Enter 1 for " << contactSystem.getContactSystem()[0].getoFirst() << "'s Contact Book\n";
              cout << "Enter 2 for " << contactSystem.getContactSystem()[1].getoFirst() << "'s Contact Book\n";
              cout << "Enter 3 for " << contactSystem.getContactSystem()[2].getoFirst() << "'s Contact Book\n";
              cout << "Enter 4 for " << contactSystem.getContactSystem()[3].getoFirst() << "'s Contact Book\n";
              cout << "Enter 5 for " << contactSystem.getContactSystem()[4].getoFirst() << "'s Contact Book\n";
              cin >> systemIndex2;
              switch(systemIndex2){
                case 1: contactSystem.getContactSystem()[systemIndex].merge(contactSystem.getContactSystem()[systemIndex2 - 1]);
                        cout << "Contacts have been merged! \n";
                        contactSystem.remove(systemIndex2 - 1);
                        break;
                case 2: contactSystem.getContactSystem()[systemIndex].merge(contactSystem.getContactSystem()[systemIndex2 - 1]);
                        cout << "Contacts have been merged! \n";
                        contactSystem.remove(systemIndex2 - 1);
                        break;
                case 3: contactSystem.getContactSystem()[systemIndex].merge(contactSystem.getContactSystem()[systemIndex2 - 1]);
                        cout << "Contacts have been merged! \n";
                        contactSystem.remove(systemIndex2 - 1);
                        break;
                case 4: contactSystem.getContactSystem()[systemIndex].merge(contactSystem.getContactSystem()[systemIndex2 - 1]);
                        cout << "Contacts have been merged! \n";
                        contactSystem.remove(systemIndex2 - 1);
                        break;
                case 5: contactSystem.getContactSystem()[systemIndex].merge(contactSystem.getContactSystem()[systemIndex2 - 1]);
                        cout << "Contacts have been merged! \n";
                        contactSystem.remove(systemIndex2 - 1);
                        break;
              }
            }
            if(systemOption2 == 2){
              contactSystem.remove(systemIndex);
              cout << "Contact Book Removed !\n";
              continue;
            }
        }while(systemOption2 != 3);
        continue; 
      }

      if(systemOption == 4){
        contactSystem.display();
        continue;
      }

      if(systemOption == 5){
        cout << "Amount of Contact Book Spaces Used: " << contactSystem.getBooksUsed() << endl;
        cout << "Amount of Contact Book Spaces Available: " << contactSystem.getCapacity()/*capacity*/ - contactSystem.getBooksUsed() << endl; 
        cout << "Capacity: " << contactSystem.getCapacity() << endl;
        continue;

      }

      if (systemOption > 6) cout << "Please enter 1, 2, 3, 4, 5, or 6\n";        
      cout << "\n";

    }while(systemOption !=  6);
    cout << "Goodbye! \n";
    return 0;
}