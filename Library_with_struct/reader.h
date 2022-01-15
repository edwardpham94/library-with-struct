#pragma once

#include<string>
using namespace std;

//#define sie 100

struct reader
{
	string ma;
	string name;
	long cmnd;
	string date;
	string gender;
	string address;
	string email;
	int d, m, y;
};

void ReadFromFile(reader a[]);

void ListOfReader(int& soluongdocgia, reader a[]);

void AddReader(int& soluongdocgia, reader a[]);

void EditReader(int soluongdocgia, reader a[]);

void RemoveReader(int& soluongdocgia, reader a[]);

void SearchByCMND(int soluongdocgia, reader a[]);

void SearchByName(int soluongdocgia, reader a[]);

void function1(int& soluongdocgia, reader a[]);