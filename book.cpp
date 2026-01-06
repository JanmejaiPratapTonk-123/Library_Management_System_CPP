#include "book.h"

Book::Book()
{
    BookName = "";
    Author = "";
    Price = 0;
    Available = 1;
}

Book::Book(string BN, string A, double P, int Av)
{
    BookName = BN;
    Author = A;
    Price = P;
    Available = Av;
}

string Book::getBookName()
{
    return BookName;
}

string Book::getAuthor()
{
    return Author;
}

double Book::getPrice()
{
    return Price;
}

int Book::isAvailable()
{
    return Available;
}