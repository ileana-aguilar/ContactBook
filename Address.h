#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>
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

    void output() const;

    void input();

    friend istream& operator >> (istream& in, Address& add);
    friend ostream& operator << (ostream& out, const Address& add);
};
#endif
