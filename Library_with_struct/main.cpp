// Ho va ten : Pham Hong Gia Bao
// MSSV : 21127014

#include<iostream>
#include"reader.h"
#include"book.h"
#include"BorrowBookCard.h"
#include"ReturnBookCard.h"
#include"Statistic.h"

using namespace std;

#define size 100

int main()
{
	// Reader
	reader a[size];
	int n = 3;
	int NumberOfReader=0;
	NumberOfReader = NumberOfReader + n;
	

	// book
	int NumberOfBook = 0;
	book b[size];

	// borrow book
	Predicted c[size];
	int TotalBorrowBook = 0;
	int BorrowBook[size];
	int isbnBorrow[10][10];
	Borrow d[size];

	// read date from file
	ReadFromFile(a);



	int chucnang = 1;
	while (chucnang != 0)
	{
		cout << "\n*************************************************\n";
		cout << "*     === CHUONG TRINH QUAN LY THU VIEN ===     *\n";
		cout << "*            *** CAC CHUC NANG ***              *\n";
		cout << "*  1. Quan ly doc gia                           *\n";
		cout << "*  2. Quan ly sach                              *\n";
		cout << "*  3. Lap phieu muon sach                       *\n";
		cout << "*  4. Lap phieu tra sach                        *\n";
		cout << "*  5. Cac thong ke co ban                       *\n";
		cout << "*  0. Thoat khoi chuong trinh                   *\n";
		cout << "*************************************************\n";
		cout << "Moi ban chon chuc nang : ";
		cin >> chucnang;
		while (chucnang >= 6 || chucnang < 0)
		{
			cout << "\nKHONG co chuc nang ban yeu cau. Moi ban nhap lai!\n";
			cout << "\nMoi ban chon chuc nang : ";
			cin >> chucnang;
		}
		if (chucnang == 0)
		{
			cout << endl;
			cout << "=== CAM ON BAN DA SU DUNG CHUONG TRINH ===\n";
		}
		switch (chucnang)
		{
			case 1:
			{
				function1(NumberOfReader, a);
				break;
			}
			case 2:
			{
				function2(NumberOfBook, b);
				break;
			}
			case 3:
			{
				BorrowBookCard( isbnBorrow, BorrowBook, NumberOfReader, NumberOfBook, TotalBorrowBook, a, b, c, d);
				break;
			}
			case 4:
			{
				ReturnBookCard(TotalBorrowBook, NumberOfReader, a, b, BorrowBook, NumberOfBook, isbnBorrow, d, c);
				break;
			}
			case 5:
			{
				BasicStatistics(BorrowBook, c, a, b, NumberOfReader, NumberOfBook, TotalBorrowBook);
				break;
			}
		}
	}
	return 0;
}
