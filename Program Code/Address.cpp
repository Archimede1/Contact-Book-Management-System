#include <string>
#include <iostream>
#include "Address.h"
using namespace std;

Address::Address() : home(""),
                     street(""),
                     apt("none"),
                     city(""),
                     state(""),
                     zip("")
{
   // empty
}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

void Address::setHome(string a){
   home = a;
}

void Address::setStreet(string a){
   street = a;
}

void Address::setApt(string a){
   apt = a;
}

void Address::setCity(string a){
   city = a;
}

void Address::setState(string a){
   state = a;
}

void Address::setZip(string a){
   zip = a;
}

void Address::output(Address &address) const
{
  cout << address;
}

void Address::input(Address &address)
{
  cin >> address;
}

ostream& operator <<(ostream &out, Address &address){
  return(out << "Home: " << address.getHome() << endl << "Street: " << address.getState() << endl << "Apartment: " << address.getState() << endl << "City: " << address.getCity() << endl << "State: " << address.getState() << endl << "Zip Code: " << address.getZip() << endl);

}

istream& operator >>(istream &ins, Address &address){
   string a,b,c,d,e,f;
   int choice;
   cout << "Enter Home: ";
   ins >> a;
   address.setHome(a);
   cout << "Enter Street:  (Name Only) ";
   ins >> b;
   address.setStreet(b);
   cout << "Do You Live in an Apartment? (1 : Yes / 2 : No)";
   cin >> choice;
   if (choice == 1){
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      ins >> c;
      address.setApt(c);
   }
   else{
      c = "none";
      address.setApt(c);
   }
   cout << "Enter City: ";
   ins >> d;
   address.setCity(d);
   cout << "Enter State: ";
   ins >> e;
   address.setState(e);
   cout << "Enter Zip Code: ";
   ins >> f;
   address.setZip(f);
  return ins;
}