#include "book.h"

Book::Book()
{
    BookName = "";
    Author = "";
    Price = 0;
    Available = true;
}

Book::Book(string BN, string A, double P, bool Av)
{
    BookName = BN;
    Author = A;
    Price = P;
    Available = Av;
}