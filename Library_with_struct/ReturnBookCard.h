#pragma once
#include"reader.h"
#include"book.h"
#include"BorrowBookCard.h"

bool LeapYear(int year);

int spanBetween2date(int day1, int month1, int year1, int day2, int month2, int year2);

void ReturnBookCard(int& TotalBorrowBook, int& NumberOfReader, reader a[], book b[], int BorrowBook[], int NumberOfBook, int isbnBorrow[10][10], Borrow d[], Predicted c[]);