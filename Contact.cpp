#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"
using namespace std;

// Define the static const regex pattern
const regex Contact::pattern("(\\w+(\\.|_)?\\w*)@(\\w+(\\.\\w+)+)");

// Constructor
Contact::Contact() :
  lastname("empty"),
  firstname("empty"), 
  phone("empty"),
  email("empty")
{
    address = Address();
}

//accessors:
string Contact::getFirstName() const{ return firstname; }
string Contact::getLastName() const{ return lastname; }

string Contact::getAddress() const{ //creates an output of the address as a single string
    string output = address.getHome() + " " + address.getStreet() + ", ";
    if (address.getApt().compare("none") != 0) output = output + address.getApt() + ", ";
    output = output + address.getCity() + ", " + address.getState() + " " + address.getZip();
    return output;
}

string Contact::getPhone() const{ return phone; }
string Contact::getEmail() const{ return email; }
Address Contact::returnAddress() const{ return address; }

//mutators:
void Contact::setFirstName(string x){ firstname = x; }
void Contact::setLastName(string x){ lastname = x; }
void Contact::setAddress(){ cin >> address; }


void Contact::setPhone(string x) {
    while (true) {
        if (x.size() == 10) {
            phone = x;
            break;  // Exit the loop if the phone number is valid
        } else {
            cout << "Invalid phone number input. Phone number must be 10 digits only - no dashes or parentheses. Please try again: ";
            cin >> x;  // Read new input from the user
        }
    }
}


    /*while (true){
        if (regex_match(x, checkPhone)){
            phone = x;
            break;
        }
        else {
            //prints an error message and asks to enter number again
            cout << "Error: Invalid phone number format entered for " << firstname << " " << lastname << ". Phone number must be 10 digits only - no dashes or parentheses. Please try again.:" << endl;
            cin >> x;
        }
        cout << endl << endl;
    }
}

*/


void Contact::setEmail(string x){
    while (true){
        if (regex_match(x, pattern)) {
            email = x;
            break;
        }
        else {
        //prints an error message and asks again to enter email adress in right format
            cout << "Error: Invalid E-mail address format entered for " << firstname << " " << lastname << ". Please try again.:" << endl;
            cin >> x;
        }
        cout << endl << endl;
    }
}

void Contact::input(){
    string fn, ln,*add, ph, em;
    //prompt user to enter contact first name
    cout << "Enter the first name of the new contact.: ";
    cin >> fn;
    setFirstName(fn);

    //prompt user to enter contact last name
    cout << "Enter the last name of the new contact.: ";
    cin >> ln;
    setLastName(ln);

    cout << "Enter the address in format mentioned below." << endl;
    cin >> address;
      //prompt user to enter contact phone number
    cout << "Enter the phone number of the new contact.: ";
    cin >> ph;
    setPhone(ph);

    //prompt user to enter contact address
    cout << "Enter the email address of the new contact.: ";
    cin >> em;
    setEmail(em);

    cout << endl << "Contact created successfully." << endl << endl;
}

void Contact::output() const{
    cout << "First Name: " << firstname << endl
         << "Last Name: " << lastname << endl
         << "Address: " << endl;
    address.output();
    cout << "Phone Number: " << phone << endl
         << "Email Address: " << email << endl << endl;
}

//member operator overloads:
const bool Contact::operator < (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) < 0) return true;
    else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return true;
    return false;
}

const bool Contact::operator > (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) > 0) return true;
    else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return true;
    return false;
}

const bool Contact::operator == (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return true;
    return false;
}

const bool Contact::operator != (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return false;
    return true;
}

const bool Contact::operator <= (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) > 0) return false;
    else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return false;
    return true;
}

const bool Contact::operator >= (const Contact& contact){
    if (getLastName().compare(contact.getLastName()) < 0) return false;
    else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return false;
    return true;
}


//non-member operator overloads:
istream& operator >> (istream& in, Contact& contact){
    string fn, ln, ph, em;
    cout << "Enter the first name of the new contact.: ";
    in >> contact.firstname;

    cout << "Enter the last name of the new contact.: ";
    in >> ln; contact.setLastName(ln);

    cout << "Enter the contact information in right format.:" << endl;
    contact.setAddress();
    cout << endl;

    //prompt user to enter contact phone number
    cout << "Enter the phone number of the new contact.: ";
    in >> ph; contact.setPhone(ph);

    //prompt user to enter contact email address
    cout << "Enter the email of the new contact.: ";
    in >> em; contact.setEmail(em);

    cout << "Contact updated successfully." << endl;

    return in;
}

ostream& operator << (ostream& out, const Contact& contact){
    out << "First Name: " << contact.getFirstName() << endl
        << "Last Name: " << contact.getLastName() << endl
        << "Address:" << endl;
    out << contact.returnAddress();
    out << "Phone number: " << contact.getPhone() << endl
        << "Email Address: " << contact.getEmail() << endl;

    return out;
}
