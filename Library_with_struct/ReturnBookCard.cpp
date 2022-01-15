// Ho va ten : Pham Hong Gia Bao
// MSSV : 21127014

#include<iostream>
#include<string>
#include "BorrowBookCard.h"
#include"book.h"
#include"Reader.h"
#include"BorrowBookCard.h"


using namespace std;

bool LeapYear(int year)
{
	if (year % 400 == 0) return true;
	else if (year % 100 != 0 && year % 4 == 0) return true;
	return false;
}

int spanBetween2date(int day1, int month1, int year1, int day2, int month2, int year2)
{
	int distance = 0, daymuon1, daymuon2;
	if (year1 == year2)
	{
		for (int i = 1; i < month1; i++)
		{
			daymuon1 = day1 + DaysInMonth(i, year1);
		}
		for (int i = 1; i < month2; i++)
		{
			daymuon2 = day2 + DaysInMonth(i, year2);
		}
		distance = daymuon2 - daymuon1;
	}
	if (year2 > year1)
	{
		for (int i = 1; i < month1; i++)
		{
			daymuon1 = day1 + DaysInMonth(i, year1);
		}
		for (int i = year1; i < year2; i++)
		{
			if (LeapYear(i) == true)
				daymuon2 = daymuon2 + 366;
			else if (LeapYear(i) == false)
				daymuon2 = daymuon2 + 365;
		}
		for (int i = 1; i < month2; i++)
		{
			daymuon2 = day2 + DaysInMonth(i, year2);
		}
		distance = daymuon2 - daymuon1;
	}
	return distance;
}

// chuc nang 4 phieu tra sach

void ReturnBookCard(int& TotalBorrowBook, int& NumberOfReader, reader a[], book b[], int BorrowBook[], int NumberOfBook, int isbnBorrow[10][10], Borrow d[], Predicted c[])
{
	int ngaytra, thangtra, namtra;
	int soluongsachmat, isbnmat[100];
	string madocgia;
	cout << "Moi ban nhap vao ma doc gia : ";
	cin.ignore();
	getline(cin, madocgia);

	cout << "-----------------------------------------\n";
	cout << "|      ***   Ket qua tim kiem   ***     |\n";
	cout << "-----------------------------------------";

	for (int i = 0; i < NumberOfReader; i++)
	{
		TotalBorrowBook = TotalBorrowBook - BorrowBook[i];

		int tien = 0;
		if (madocgia == a[i].ma)
		{

			cout << endl;
			cout << "=== Thong tin doc gia muon sach ===\n";
			cout << "Ma doc gia	     : " << a[i].ma << endl;
			cout << "Ho va ten            : " << a[i].name << endl;
			cout << "CMND                 : " << a[i].cmnd << endl;
			cout << "Ngay thang nam sinh  : " << a[i].date << endl;
			cout << "Email                : " << a[i].email << endl;
			cout << "Dia chi              : " << a[i].address << endl;
			cout << "Ngay lap the         : " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
			cout << "Ngay het han         : " << a[i].d + 1 << "/" << a[i].m << "/" << a[i].y + 4 << endl;

			cout << "\n=== DANH SACH CAC SACH DA MUON ===\n";
			for (int k = 0; k < BorrowBook[i]; k++)
			{
				for (int j = 0; j < NumberOfBook; j++)
				{
					if (isbnBorrow[i][k] == b[j].isbn)
					{
						cout << "Ma ISBN : " << isbnBorrow[i][k] << "\t" << "Ten sach : " << b[j].namebook << endl;
					}
				}
			}

			BorrowBook[i] = 0;

			cout << endl << "\nNGAY TRA DU KIEN \n";
			cout << "Nhap ngay tra du kien        : " << c[i].d << endl;
			cout << "Nhap thang tra du kien       : " << c[i].m << endl;
			cout << "Nhap nam tra du kien         : " << c[i].y << endl;

			cout << "\nNGAY TRA SACH THUC TE\n";
			cout << "Nhap ngay tra thuc te	      : ";
			cin >> ngaytra;
			cout << "Nhap thang tra thuc te       : ";
			cin >> thangtra;
			cout << "Nhap nam tra thuc te         : ";
			cin >> namtra;

			cout << "Nhap so luong sach mat : ";
			cin >> soluongsachmat;

			if (soluongsachmat != 0)
			{
				for (int j = 0; j < soluongsachmat; j++)
				{
					cout << "Nhap ma ISBN sach mat      : ";
					cin >> isbnmat[j];
					for (int k = 0; k < NumberOfBook; k++)
					{
						if (isbnmat[j] == b[k].isbn)
						{
							b[k].isbn = b[k].isbn - 1;
							tien = tien + b[k].price * 2;
						}
					}
				}

			}

			// tinh so ngay muon sach thuc te
			int daycount = spanBetween2date(c[i].d, c[i].m, c[i].y, ngaytra, thangtra, namtra);
			if (daycount > 0)
			{
				tien = tien + daycount * 7000;
			}

			cout << endl;
			cout << "Tong so tien ban can tra la : " << tien << "VND";
			cout << endl;


		}
	}
}