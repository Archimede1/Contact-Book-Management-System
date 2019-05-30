#include <iostream>
#include <string>
#include "Address.h"
using namespace std;

#ifndef CONTACT_H
#define CONTACT_H


class Contact{
  protected:
    string firstname, lastname, phonenum, email;
    Address address;

  public:
    Contact(string a, string b, string c, string d);
    Contact();
    Address getAddressClass();
    string getFirst();
    string getLast();
    string getNumb();
    string getEmail();
    void getAddress();
    void setFirst(string a);
    void setLast(string a);
    void setAddress();
    void setNumb(string a);
    void setEmail(string a);
    void input();
    void output();
    bool operator== (Contact &c2);
    bool operator!= (Contact &c2);
    bool operator> (Contact &c2);
    bool operator>= (Contact &c2);
    bool operator< (Contact &c2);
    bool operator<= (Contact &c2);
    friend ostream& operator <<(ostream &out, Contact &contact);
    friend istream& operator >>(istream &ins, Contact &contact);

};
#endif