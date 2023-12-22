#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"
using namespace std;


int main() {
    //contact book menu
   int menu = 1;
   ContactBook contactBookList;

   cout << "Welcome to contact book! ";

   while (menu > 0 && menu < 7){
       //print the menu to user
      cout << endl << "Please make a selection from the menu.\n\n";

      //menu
      cout << "1. Add a new contact" << endl
         << "2. Delete an old contact" << endl
         << "3. Display a contact's info" << endl
         << "4. Update a contact's info" << endl
         << "5. Display the entire contact list" << endl
         << "6. Exit" << endl << endl << "Your Menu Choice: ";

      cin >> menu;
      cout << endl;

      if (menu == 6) break;

      else if (menu == 1){
          //creates a new contact that will be input by the user
          Contact newContact;
         cin >> newContact;
         contactBookList.add(newContact);
         continue;
      }

      else if (menu == 2){
         int index;
         char answer;

      deleteIndex:
         cout << "Do you know the index of the contact you'd like to delete? (Y/N): ";
         cin.ignore();
         cin >> answer;

         if (answer == 'Y' || answer == 'y'){
            cout << "Please enter the index you'd like to delete.: ";
            cin >> index;
            contactBookList.remove(index);
            continue;
         }

         else if (answer == 'N' || answer == 'n'){
            string name;
            cout << "Please enter the name of the contact you'd like to delete.: ";
            cin.ignore();
            getline(cin, name);
            contactBookList.remove(contactBookList.search(name));
            continue;
         }

         else {
            cerr << "Error: Invalid answer. Please try again." << endl << endl;
            goto deleteIndex;
         }
      }

      else if (menu == 3){
         string display;
         cout << "Please enter the name of the contact you'd like to have displayed.: ";
         cin.ignore();
         getline(cin, display);

         cout << contactBookList.contactAtIndex(contactBookList.search(display));
         continue;
      }

      else if (menu == 4){
         string mod;
         cout << "Please enter the full name of the contact you'd like to modify.: ";
         cin.ignore();
         getline(cin, mod);

         int index = contactBookList.search(mod);

         cout << "Please enter the new data for the contact " << contactBookList.contactAtIndex(contactBookList.search(mod)).getFirstName()
              << ' ' << contactBookList.contactAtIndex(contactBookList.search(mod)).getLastName() << '.' << endl << endl;

         Contact input;
         cin >> input;
         contactBookList.update(index, input);

         cout << "Contact updated successfully!" << endl << endl;
         continue;
      }

      else if (menu == 5){
         cout << contactBookList;
         cout << endl << endl;
         continue;
      }
   }

   cout << "Thank You for using Contact Book." << endl;

   return 0;
}
