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
        int Available;
    public:
        Book();
        Book(string BN, string A, double P, int Av);
};

#endif