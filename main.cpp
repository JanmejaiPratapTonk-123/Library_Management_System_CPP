#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;

int main()
{
    cout << "Library Management System started." << endl;
    Library l;
    l.loadFromFile();
    l.displayBooks();
    return 0;
}
