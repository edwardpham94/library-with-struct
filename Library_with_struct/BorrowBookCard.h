#pragma once
#include"reader.h"
#include"book.h"

struct Predicted
{
	int d, m, y;
};

struct Borrow
{
	int d, m, y;
};

int DaysInMonth(int month, int year);

void BorrowBookCard(int isbnBorrow[10][10], int BorrowBook[], int NumberOfReader, int NumberOfBook, int& TotalBorrowBook, reader a[], book b[], Predicted c[], Borrow d[]);