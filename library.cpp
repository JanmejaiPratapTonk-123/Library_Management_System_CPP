#include "library.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void Library::loadFromFile()
{
    books.clear();
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
        cout << "-------------------" << endl;
        cout << "Book Name : " << book.getBookName() << endl;
        cout << "Author : " << book.getAuthor() << endl; 
        cout << "Price : " << book.getPrice() << endl;
        cout << "Status : " << (book.isAvailable() ? "Available" : "Not Available") << endl;
        cout << "-------------------" << endl;
    }
}

void Library::searchBookByName(string name)
{
    for(auto& book : books)
    {
        if(book.getBookName() == name)
        {
            cout << "Book Found:" << endl;
            cout << "-------------------" << endl;
            cout << "Book Name : " << book.getBookName() << endl;
            cout << "Author : " << book.getAuthor() << endl; 
            cout << "Price : " << book.getPrice() << endl;
            cout << "Status : " << (book.isAvailable() ? "Available" : "Not Available") << endl;
            cout << "-------------------" << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Library::saveToFile()
{
    ofstream file("books.txt");
    if(!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }
    for(auto& book : books)
    {
        file << book.getBookName() << "|" << book.getAuthor() << "|" << book.getPrice() << "|" << book.isAvailable() << endl;
    }
    cout << "Books saved to file successfully." << endl;
    file.close();
}

void Library::addBook()
{
    string bookName;
    string author;
    double price;
    int avail;

    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, bookName);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Is the book available? (1 for Yes, 0 for No): ";
    cin >> avail;

    Book newBook(bookName, author, price, avail);
    books.push_back(newBook);
    saveToFile();
    cout << "Book added successfully." << endl;
}


void Library::deleteBook()
{
    string name;
    cout << "Enter Book's Name to Delete: ";
    cin.ignore();
    getline(cin, name);
    for(auto it = books.begin(); it != books.end(); it++)
    {
        if(it->getBookName() == name)
        {
            books.erase(it);
            saveToFile();
            cout << "Book Deleted Successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Library::issueBook()
{
    string name;
    cout << "Enter Book's Name to Issue: ";
    cin.ignore();
    getline(cin, name);
    for(auto &book : books)
    {
        if(book.getBookName() == name)
        {
            if(book.isAvailable())
            {
                book.setAvailable(0);
                saveToFile();
                cout << "Book Issued Successfully." << endl;
            }
            else
            {
                cout << "Book already issued." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

// void Library::issueBook()
// {
//     string name;
//     cout << "Enter Book's Name to Issue: ";
//     cin.ignore();
//     getline(cin, name);
//     for(auto &book : books)
//     {
//         if(book.getBookName() == name)
//         {
//             if(book.isAvailable())
//             {
//                 book.setAvailable(0);
//                 saveToFile();
//                 cout << "Book Issued Successfully." << endl;
//             }
//             else
//             {
//                 cout << "Book already issued." << endl;
//             }
//             return;
//         }
//     }
//     cout << "Book not found." << endl;
// }

void Library::returnBook()
{
    string name;
    cout << "Enter Book's Name to Return: ";
    cin.ignore();
    getline(cin, name);
    for(auto &book : books)
    {
        if(book.getBookName() == name)
        {
            if(book.isAvailable() == 1)
            {
                cout << "Book Already Available." << endl;
                return;
            }
            book.setAvailable(1);
            cout << "Book Returned." << endl;
            saveToFile();
            return;
        }
    }
    cout << "Book not found." << endl;
}