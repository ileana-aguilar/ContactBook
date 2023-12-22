#ifndef CONTACT_H
#define CONTACT_H
#include "Address.h"
#include <regex>
using namespace std;

class Contact{
private:
    string firstname;
    string lastname;
    Address address;
    string phone;
    string email;

    static const regex pattern;

public:
    Contact();
    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    string getPhone() const;
    string getEmail() const;
    Address returnAddress() const;
    void setFirstName(string x);
    void setLastName(string x);
    void setAddress();
    void setPhone(string x);
    void setEmail(string x);

    void input();

    void output() const;

    const bool operator < (const Contact& contact);
    const bool operator > (const Contact& contact);
    const bool operator == (const Contact& contact);
    const bool operator != (const Contact& contact);
    const bool operator <= (const Contact& contact);
    const bool operator >= (const Contact& contact);

    friend istream& operator >> (istream& in, Contact& contact);
    friend ostream& operator << (ostream& out, const Contact& contact);
};

#endif
