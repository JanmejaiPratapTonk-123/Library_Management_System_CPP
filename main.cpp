#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;

int main()
{
    cout << "Library Management System" << endl;
    cout << "Choose an option:" << endl;
    while(true)
    {
        cout << "1. Load Books from File" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        Library library;

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
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
