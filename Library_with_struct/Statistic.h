#pragma once
#include<iostream>
#include<string>
#include "BorrowBookCard.h"
#include"book.h"
#include"Reader.h"
#include"BorrowBookCard.h"

int BookStatistics(int NumberOfBook, book b[]);

void KindBookStatistics(int NumberOfBook, book b[]);

void GenderStatistics(int soluongdocgia, reader a[]);

void DocGiaTreHanStatistics(int BorrowBook[], int NumberOfReader, reader a[], Predicted c[], int& TotalBorrowBook);

void BasicStatistics(int BorrowBook[], Predicted c[], reader a[], book b[], int NumberOfReader, int NumberOfBook, int& TotalBorrowBook);