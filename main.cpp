#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;

int main()
{
    cout << "Library Management System" << endl;
    Library library;
    while(true)
    {
        cout << "\nChoose an option:" << endl;
        cout << "1. Load Books from File" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Books by Name" << endl;
        cout << "4. Add Book" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Issue Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;


        switch(choice)
        {
            case 1:
                library.loadFromFile();
                cout << "Books loaded successfully." << endl;
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
            {
                cout << "Enter book name to search: ";
                string name;
                cin.ignore();
                getline(cin, name);
                library.searchBookByName(name);
                break;
            }
            case 4:
                library.addBook();
                break;
            case 5:
                library.deleteBook();
                break;
            case 6:
                library.issueBook();
                break;
            case 7:
                library.returnBook();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}