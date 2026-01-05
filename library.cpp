#include "library.h"

#include <fstream>
#include <sstream>
#include <iostream>

void Library::loadFromFile()
{
    ifstream file("books.txt");
    if(!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }
    string line;
    while(getline(file, line))
    {
        stringstream ss(line);
        string bookName;
        string author;
        string priceStr;
        string availStr;
        getline(ss, bookName, '|');
        cout << bookName << endl;
        getline(ss, author, '|');
        cout << author << endl;
        getline(ss, priceStr, '|');
        double price = stod(priceStr);
        cout << price << endl;
        getline(ss, availStr, '|');
        int avail = stoi(availStr);
        if(avail == 1)
            cout << "Available" << endl;
        else
            cout << "Not Available" << endl;
    }
}