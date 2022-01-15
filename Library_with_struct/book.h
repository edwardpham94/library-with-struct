// Ho va ten : Pham Hong Gia Bao
// MSSV : 21127014
#pragma once
#include<string.h>
using namespace std;

struct book
{
	int isbn;
	string namebook;
	string author;
	string publisher;
	string year;
	string kind;
	int price, amount;
};

void ListOfBook(int& NumberOfBook, book a[]);

void AddBook(int& NumberOfBook, book a[]);

void EditBook(int& NumberOfBook, book a[]);

void RemoveBook(int& NumberOfBook, book a[]);

void SearchByISBN(int& NumberOfBook, book a[]);

void SearchByNamebook(int& NumberOfBook, book a[]);

void function2(int& NumberOfBook, book a[]);