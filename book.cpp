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