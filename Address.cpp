#include "Address.h"
#include <string>
#include <iostream>

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

void Address::output() const
{
    cout << home << " " << street;
    if (apt != "none")
        cout << ", Apt# " << apt;
    cout << endl;
    cout << city << ", " << state << " " << zip << endl;
}

void Address::input()
{
    char userChoice;
    //prompt user to enter apartment or House
    cout << "Apartment or House (a/h):> ";
    cin >> userChoice;
    cout << endl;

    cin.ignore(10, '\n');
    //prompt user to enter home number
    cout << "Enter home number (EX: 132-12): ";
    getline(cin, home);
    //prompt user to enter street number
    cout << "Enter street number (EX: 11th RD): ";
    getline(cin, street);

    if (userChoice == 'a')
    {
        //prompt user to enter apartment number
        cout << "Enter Apartment Number: (EX: 1A): ";
        getline(cin, apt);
    }
    else
        apt = "none";

    //prompt user to enter contact city
    cout << "Enter city (Ex. NewYork): ";
    getline(cin, city);

    //prompt user to enter contact state
    cout << "Enter state (EX: NY): ";
    getline(cin, state);

    //prompt user to enter contact state
    cout << "Enter zip code (EX: 12345): ";
    getline(cin, zip);
}

istream& operator >> (istream& in, Address& add){
    char choice;
    cout << "Apartment or House (a/h):> ";
    in >> choice;
    cout << endl;

    in.ignore(10, '\n');
    cout << "Enter home number (EX: EX: 132-12): ";
    getline(in, add.home);
    cout << "Enter street number (EX: 12th RD): ";
    getline(in, add.street);

    if (choice == 'a')
    {
        cout << "Enter Apartment Number: (EX: 1A): ";
        getline(in, add.apt);
    }
    else
        add.apt = "none";

    cout << "Enter city (Ex: New York): ";
    getline(in, add.city);

    cout << "Enter state (EX: NY): ";
    getline(in, add.state);

    cout << "Enter zip code (EX: 12345): ";
    getline(in, add.zip);

    return in;
}

ostream& operator << (ostream& out, const Address& add){
    out << add.home << " " << add.street;
    if (add.apt != "none")
        out << ", Apt# " << add.apt;
    out << endl;
    out << add.city << ", " << add.state << " " << add.zip << endl;

    return out;
}
