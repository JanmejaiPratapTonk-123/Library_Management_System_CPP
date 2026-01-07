#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;

int main()
{
    cout << "Library Management System started." << endl;
    cout << "Test" << endl;
    Library l;
    l.loadFromFile();
    l.displayBooks();
    return 0;
}
