#include<iostream>
#include<string>
#include "BorrowBookCard.h"
#include"book.h"
#include"Reader.h"
#include"BorrowBookCard.h"


using namespace std;

// cau 5.a thong ke tat ca sach co trong thu vien
int BookStatistics(int NumberOfBook, book b[])
{
	int AllBook = 0;
	for (int i = 0; i < NumberOfBook; i++)
	{
		AllBook = AllBook + b[i].amount;
	}
	return AllBook;
}

// cau 5.b thong ke sach theo the loai
void KindBookStatistics(int NumberOfBook, book b[])
{
	int totalnumber[100];
	int tam[100];

	for (int i = 0; i < NumberOfBook; i++)
	{
		tam[i] = 1;
	}
	for (int i = 0; i < NumberOfBook; i++)
	{
		totalnumber[i] = 0;
		if (tam[i] == 1)
		{
			totalnumber[i] = b[i].amount;
			tam[i] = 0;
			for (int j = i + 1; j < NumberOfBook; j++)
			{
				if (b[i].kind == b[j].kind)
				{
					tam[j] = 0;
					totalnumber[i] = totalnumber[i] + b[j].amount;
				}
			}
		}
		// cout << "Thu vien co tat ca " << soluongtheloai << " the loai\n";
		if (totalnumber[i] != 0)
		{
			cout << i + 1 << ". So luong sach co the loai ' " << b[i].kind << " ' la : " << totalnumber[i] << endl;
		}

	}
}


// cau 5.d thong ke doc gia theo gioi tinh
void GenderStatistics(int NumberOfReader, reader a[])
{
	int male = 0, female = 0;
	string nam = { "Nam" }, nu = { "Nu" };
	for (int i = 0; i < NumberOfReader; i++)
	{
		if (a[i].gender == nam)
		{
			male = male + 1;
		}
		else if (a[i].gender == nu)
		{
			female = female + 1;
		}
	}
	if (male == 0 && female == 0)
	{
		cout << "Khong co doc gia nao trong thu vien";
	}
	else
	{
		cout << "So luong doc gia nam : " << male << endl;
		cout << "So luong doc gia nu  : " << female << endl;
	}


}

// cau 5.f thong ke doc gia bi tre han
void DocGiaTreHanStatistics(int BorrowBook[], int NumberOfReader, reader a[], Predicted c[], int& TotalBorrowBook)
{
	int dem = 0;
	int ngay, thang, nam;
	if (TotalBorrowBook == 0)
	{
		cout << endl;
		cout << "-----------------------------------------\n";
		cout << "|      ***   Ket qua tim kiem   ***     |\n";
		cout << "-----------------------------------------\n";
		cout << "KHONG co doc gia nao dang tre han" << endl;
	}

	else
	{
		cout << "Moi ban nhap ngay hien tai  : ";
		cin >> ngay;
		cout << "Moi ban nhap thang hien tai : ";
		cin >> thang;
		cout << "Moi ban nhap nam hien tai   : ";
		cin >> nam;

		cout << endl;
		cout << "-----------------------------------------\n";
		cout << "|      ***   Ket qua tim kiem   ***     |\n";
		cout << "-----------------------------------------";
		cout << endl << "=== DANH SACH DOC GIA DANG BI TRE HAN : \n";

		for (int i = 0; i < NumberOfReader; i++)
		{
			if (BorrowBook[i] != 0)
			{
				if (nam > c[i].y)
				{
					cout << "\nMa doc gia :  " << a[i].ma << "\t Ho va ten : " << a[i].name;
					dem++;
				}
				else if (nam == c[i].y)
				{
					if (thang > c[i].m)
					{
						cout << "\nMa doc gia :  " << a[i].ma << "\t Ho va ten : " << a[i].name;
						dem++;
					}
					else if (thang == c[i].m)
					{
						if (ngay > c[i].d)
						{
							cout << "\nMa doc gia :  " << a[i].ma << "\t Ho va ten : " << a[i].name;
							dem++;
						}
					}
				}
			}
			cout << endl;

		}
		if (dem == 0)
		{
			cout << "\nKhong co doc gia nao bi tre han ";
		}
	}

}

// chuc nang 5 thong ke co ban
void BasicStatistics(int BorrowBook[], Predicted c[], reader a[], book b[], int NumberOfReader, int NumberOfBook, int& TotalBorrowBook)
{
	char chucnang5 = 'a';

	while (chucnang5 != 'g')
	{
		cout << "\n--------------------------------------------------";
		cout << endl << "|       ---CHUC NANG 5: Thong ke co ban---        |\n";
		cout << "|a. Thong ke so luong sach trong thu vien         |\n";
		cout << "|b. Thong ke so luong sach theo the loai          |\n";
		cout << "|c. Thong ke so luong doc gia                     |\n";
		cout << "|d. Thong ke so luong doc gia theo gioi tinh      |\n";
		cout << "|e. Thong ke so sach dang duoc muon               |\n";
		cout << "|f. Thong ke danh sach doc gia bi tre han         | \n";
		cout << "|g. Quay lai                                      | \n";
		cout << "--------------------------------------------------\n";

		cout << "Moi ban nhap chuc nang :  ";
		cin >> chucnang5;

		switch (chucnang5)
		{
		case 'a':
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------\n";
			cout << "So luong sach trong thu vien la : " << BookStatistics(NumberOfBook, b) << " quyen" << endl;
			break;
		}
		case 'b':
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------\n";
			KindBookStatistics(NumberOfBook, b);
			break;
		}
		case 'c':
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------\n";
			cout << "So luong doc gia la : " << NumberOfReader << " nguoi" << endl;
			break;
		}
		case 'd':
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------\n";
			GenderStatistics(NumberOfReader, a);
			break;
		}
		case 'e':
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------\n";
			cout << "So luong sach dang muon la : " << TotalBorrowBook << endl;
			break;
		}
		case 'f':
		{
			DocGiaTreHanStatistics(BorrowBook, NumberOfReader, a, c, TotalBorrowBook);
			break;
		}

		}
	}


}