#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "book.h"

class Library
{
    private:
        vector<Book> books;
    public:
        void loadFromFile();
        void displayBooks();
};

#endif