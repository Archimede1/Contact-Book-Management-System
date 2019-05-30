#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
   private:
      string home;
      string street;
      string apt;
      string city;
      string state;
      string zip;
  public:
      Address();
      string getHome() const;
      string getStreet() const;
      string getApt() const;
      string getCity() const;
      string getState() const;
      string getZip() const;
      void output(Address &address) const;
      void setHome(string a);
      void setStreet(string a);
      void setApt(string a);
      void setCity(string a);
      void setState(string a);
      void setZip(string a);
      void input(Address &address);
      friend ostream& operator <<(ostream &out, Address &address);
      friend istream& operator >>(istream &ins, Address &address);
};
#endif