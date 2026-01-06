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
        getline(ss, author, '|');
        getline(ss, priceStr, '|');
        double price = stod(priceStr);
        getline(ss, availStr, '|');
        int avail = stoi(availStr);
        Book book(bookName, author, price, avail);
        books.push_back(book);
    }
    file.close();
}

void Library::displayBooks()
{
    for(auto& book : books)
    {
        cout << "--------------------" << endl;
        cout << "Book Name : " << book.getBookName() << endl;
        cout << "Author : " << book.getAuthor() << endl; 
        cout << "Price : " << book.getPrice() << endl;
        cout << "Status : " << (book.isAvailable() ? "Available" : "Not Available") << endl;
        cout << "--------------------" << endl;
    }
}