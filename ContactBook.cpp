#include "ContactBook.h"
using namespace std;

const int ContactBook::numberOfContacts() const{
    return nextIndex;
}

void ContactBook::add(Contact input){
    if (nextIndex < 10){
        book[nextIndex] = input;
        nextIndex++;
    }
    else cerr << "Error: Contact book is full!" << endl;
}

void ContactBook::remove(int index){
    if (index > -1 && index < 10){
        Contact temp[10];
        int i = 0;

        while (i != index){
            temp[i] = book[i];
            i++;
        }

        while (i < 9){
            temp[i] = book[i + 1];
            i++;
        }
        for (int j = 0; j < 10; j++){
            book[j] = temp[j];
        }

        nextIndex--;

        cout << "Contact successfully deleted from the contact book!" << endl << endl;
    }
    else cerr << "Error: Index out of bound." << endl << endl;
}

void ContactBook::update(int index, Contact input){
    if (index > -1 && index < 10){
        book[index] = input;
        cout << "Contact successfully updated!" << endl << endl;
    }
    else cerr << "Error: Index is out of bounds." << endl << endl;
}

int ContactBook::search(string name){
    for (int i = 0; i < nextIndex; i++){
        string fullName = book[i].getFirstName() + ' ' + book[i].getLastName();

        if (name.compare(book[i].getFirstName()) == 0) return i;
        else if (name.compare(book[i].getLastName()) == 0) return i;
        else if (name.compare(fullName) == 0) return i;
    }

    return -1;
}

Contact ContactBook::contactAtIndex(int index) const {
    if (index >= 0 && index < nextIndex) {
        return book[index];
    } else {
        // Handle out-of-bounds index
        cerr << "Error: Index out of bounds." << endl;
        return Contact(); // Return a default Contact object
    }
}

void ContactBook::displayAll() const{
    for (int i = 0; i < nextIndex; i++){
        book[i].output();
    }
}

ostream& operator << (ostream& out, const ContactBook& list){
    for (int i = 0; i < list.numberOfContacts(); i++){
        out << list.book[i] << endl;
    }
    return out;
}
