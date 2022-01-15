#include<iostream>
#include<string>
#include "BorrowBookCard.h"
#include"book.h"
#include"Reader.h"
using namespace std;


int DaysInMonth(int month, int year)
{
	int k;
	if (year % 100 == 0)
	{
		if (year % 400 == 0) k = 1;
		else k = 0;
	}
	else if (year % 4 == 0) k = 1;
	else k = 0;
	if (k == 1 && month == 2) return 29;
	if (k == 0 && month == 2) return 28;
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		}
	}
}



// chuc nang 3 phieu muon sach
void BorrowBookCard(int isbnBorrow[10][10], int BorrowBook[], int NumberOfReader, int NumberOfBook, int& TotalBorrowBook, reader a[], book b[], Predicted c[], Borrow d[])
{
	string madocgia;
	cout << "Moi ban nhap vao ma doc gia : ";
	cin.ignore();
	getline(cin, madocgia);
	for (int i = 0; i < NumberOfReader; i++)
	{
		if (madocgia == a[i].ma)
		{
			cout << endl << "*** MA ISBN SACH TRONG THU VIEN ***\n";
			for (int h = 0; h < NumberOfBook; h++)
			{
				cout << "Ma ISBN : " << b[h].isbn << "\t\t Ten sach : \t" << b[h].namebook << endl;
			}

			cout << endl << "Moi ban nhap so luong sach muon muon : ";
			cin >> BorrowBook[i];
			TotalBorrowBook = TotalBorrowBook + BorrowBook[i];

			cout << "\n--- THONG TIN SACH MUON ---";
			for (int k = 0; k < BorrowBook[i]; k++)
			{
				cout << "\nMoi ban nhap ma ISBN : ";
				cin >> isbnBorrow[i][k];
				for (int j = 0; j < NumberOfBook; j++)
				{
					if (isbnBorrow[i][k] == b[j].isbn)
					{
						cout << "Ten sach		:  " << b[j].namebook << endl;
						b[j].amount = b[j].amount - 1;
						//tongsosachmuon++;
						if (b[i].amount < 0)
						{
							cout << "Sach nay da het!";
						}
					}
				}
			}

			cout << endl;

			cout << "\nNGAY MUON\n";
			cout << "Nhap ngay muon	            :";
			cin >> d[i].d;
			cout << "Nhap thang muon             :";
			cin >> d[i].m;
			cout << "Nhap nam muon               :";
			cin >> d[i].y;


			c[i].d = d[i].d;
			c[i].m = d[i].m;
			c[i].y = d[i].y;

			int MaxDay = 7;
			while (MaxDay != 0)
			{
				c[i].d = c[i].d + 1;
				c[i].m = c[i].m;
				c[i].y = c[i].m;
				if (c[i].d > DaysInMonth(c[i].m, c[i].y))
				{
					c[i].d = 1;
					c[i].m = c[i].m + 1;
					if (c[i].m > 12)
					{
						c[i].m = 1;
						c[i].y = c[i].y + 1;
					}
				}
				MaxDay = MaxDay - 1;
			}

			// ngay tra du kien la ngay muon sach + 7 ngay

			cout << "\nTRA SACH DU KIEN" << endl;
			cout << "Ngay tra		: " << c[i].d << endl;
			cout << "Thang tra		: " << c[i].m << endl;
			cout << "Nam tra			: " << c[i].y << endl;

			cout << endl;
		}
	}
}


