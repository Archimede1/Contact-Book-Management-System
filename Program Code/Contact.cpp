#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.h"
using namespace std;


Contact::Contact(string a, string b, string c, string d){
  firstname = a;
  lastname = b;
  Address address;
  phonenum = c;
  email = d;
}

Contact::Contact(){
  firstname = "";
  lastname = "";
  Address address;
  phonenum = "";
  email = "";
}

string Contact::getFirst(){
  return firstname;
}

string Contact::getLast(){
  return lastname;
}

Address Contact::getAddressClass(){
  return address;
}

void Contact::getAddress(){
  return address.output(address);
}

string Contact::getNumb(){
  return phonenum;
}

string Contact::getEmail(){
  return email;
}

void Contact::setFirst(string a){
  (*this).firstname = a;
}

void Contact::setLast(string a){
  (*this).lastname = a;
}

void Contact::setAddress(){
  address.input(address);
}

void Contact::setNumb(string a){
     if(a.length()!= 10){
      cout << "invalid number length \n";
      exit(1);

    }
    else{
      for(int i = 0; i < a.length(); i++){
        if(!isdigit(a[i])){
          cout << "This number is not all digits \n";
          exit(1);
        }

      }
    }
    (*this).phonenum = a;
}

void Contact::setEmail(string a){
  int atsign = (int) a.find("@");
    int dotsign = (int) a.rfind(".");
    if (atsign == -1 || dotsign == -1 || dotsign < atsign){
        cout << "Incorrect e-mail.\n";
        exit(1);
    }
    (*this).email = a;
}

void Contact::input(){
    cin >> (*this);
    
}

void Contact::output(){
    cout << (*this);
}

bool Contact::operator== (Contact &c2){
    return (getFirst() == c2.getFirst() &&
            getLast() == c2.getLast());
}

bool Contact::operator!= (Contact &c2){
    return !(getFirst() == c2.getFirst() &&
            getLast() == c2.getLast());
}

bool Contact::operator> (Contact &c2){
    return (getFirst() > c2.getFirst() && getLast() > c2.getLast());
}
 
bool Contact::operator>= (Contact &c2){
    return (getFirst() >= c2.getFirst() && getLast() >= c2.getLast());
}
 
bool Contact::operator< (Contact &c2){
    return (getFirst() > c2.getFirst() && getLast() > c2.getLast());
}
 
bool Contact::operator<= (Contact &c2){
    return (getFirst() > c2.getFirst() && getLast() > c2.getLast());
}

ostream& operator <<(ostream &out, Contact &contact){
  out << "Firstname: " << contact.getFirst() << endl << "Lastname: " << contact.getLast() << endl;
  contact.getAddress();
  out << "Phone Number: " << contact.getNumb() << endl << "Email: " << contact.getEmail() << endl;
return out;
}

istream& operator >>(istream &ins, Contact &contact){
   string a,b,c,d;
   cout << "Enter First Name: ";
   ins >> a;
   contact.setFirst(a);
   cout << "Enter Last Name: ";
   ins >> b;
   contact.setLast(b);
   cout << "Enter Info for Address: ";
   contact.setAddress();
   cout << "Enter Phone Number: ";
   ins >> c;
   contact.setNumb(c);
   cout << "Enter E-mail: ";
   ins >> d;
   contact.setEmail(d);
   return ins;
} 