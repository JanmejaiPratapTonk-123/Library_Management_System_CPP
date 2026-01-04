#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
    private:
        string BookName;
        string Author;
        double Price;
        bool Available;
    public:
        Book();
        Book(string BN, string A, double P, bool Av);
};

#endif