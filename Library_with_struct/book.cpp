// Ho va ten : Pham Hong Gia Bao
// MSSV : 21127014
#include<iostream>
#include<string>
#include<fstream>
#include"book.h"

using namespace std;

// cau 2.a xem danh sach cac sach trong thu vien
void ListOfBook(int& NumberOfBook, book a[])
{
	if (NumberOfBook == 0)
	{
		cout << endl;
		cout << "-----------------------------------------\n";
		cout << "|      ***   Ket qua tim kiem   ***     |\n";
		cout << "-----------------------------------------";
		cout << "\nKHONG CO sach nao ca! Moi ban them sach!\n";
		return;
	}
	cout << endl;
	cout << "-----------------------------------------\n";
	cout << "|      ***   Ket qua tim kiem   ***     |\n";
	cout << "-----------------------------------------";
	cout << "\n=== Danh sach cac sach trong thu vien ===";
	for (int i = 0; i < NumberOfBook; i++)
	{
		cout << "\n***Sach thu " << i + 1 << " : \n";
		cout << "ISBN (ma sach)		     :  " << a[i].isbn << endl;
		cout << "Ten sach                     :  " << a[i].namebook << endl;
		cout << "Tan tac gia                  :  " << a[i].author << endl;
		cout << "Nha san xuat                 :  " << a[i].publisher << endl;
		cout << "Nam xuat ban                 :  " << a[i].year << endl;
		cout << "The loai                     :  " << a[i].kind << endl;
		cout << "Gia sach                     :  " << a[i].price << endl;
		cout << "So quyen sach                :  " << a[i].amount << endl;
	}

}

// cau 2.b them sach
void AddBook(int& NumberOfBook, book a[])
{
	int number;
	cout << "Nhap so luong sach ban muon them vao : ";
	cin >> number;
	for (int i = NumberOfBook; i < NumberOfBook + number; i++)
	{
		cout << "*** Sach thu " << i + 1 << endl;
		cout << "ISBN (ma sach)           : ";
		cin >> a[i].isbn;
		cout << "Ten sach                 : ";
		cin.ignore();
		getline(cin, a[i].namebook);
		cout << "Ten tac gia              : ";
		getline(cin, a[i].author);
		cout << "Nha xuat ban             : ";
		getline(cin, a[i].publisher);
		cout << "Nam san xuat             : ";
		getline(cin, a[i].year);
		cout << "The loai                 : ";
		getline(cin, a[i].kind);
		cout << "Gia sach                 : ";
		cin >> a[i].price;
		cout << "So quyen sach            : ";
		cin >> a[i].amount;

	}
	NumberOfBook += number;
}

// cau 2.c chinh sua thong tin sach
void EditBook(int& NumberOfBook, book a[])
{
	int isbn1;
	cout << "Moi ban nhap ma sach ISBN cua sach can chinh sua thong tin : ";
	cin >> isbn1;
	for (int i = 0; i < NumberOfBook; i++)
	{
		if (isbn1 == a[i].isbn)
		{
			int chon = 1;


			while (chon != 0)
			{

				cout << "---------------------------------------------------------\n";
				cout << "|          *** CHON THONG TIN CAN CHINH SUA ***          |\n";
				cout << "| Chon 1: ISBN (ma sach)                                 |" << endl;
				cout << "| Chon 2: Ten sach                                       |" << endl;
				cout << "| Chon 3: Ten tac gia                                    |" << endl;
				cout << "| Chon 4: Nha san xuat                                   |" << endl;
				cout << "| Chon 5: Nam xuat ban                                   |" << endl;
				cout << "| Chon 6: The loai                                       |" << endl;
				cout << "| Chon 7: Gia sach                                       |" << endl;
				cout << "| Chon 8: So quyen sach                                  |" << endl;
				cout << "| Chon 0: Quay lai                                       |" << endl;
				cout << "----------------------------------------------------------\n";

				cout << "Moi ban chon thong tin : ";
				cin >> chon;

				switch (chon)
				{
				case 1:
				{
					cout << "ISBN (ma sach)           : ";
					cin >> a[i].isbn;
					break;
				}
				case 2:
				{
					cout << "Ten sach                 : ";
					cin.ignore();
					getline(cin, a[i].namebook);
					break;
				}
				case 3:
				{
					cout << "Ten tac gia              : ";
					cin.ignore();
					getline(cin, a[i].author);
					break;
				}
				case 4:
				{
					cout << "Nha xuat ban             : ";
					cin.ignore();
					getline(cin, a[i].publisher);
					break;
				}
				case 5:
				{
					cout << "Nam san xuat             : ";
					cin.ignore();
					getline(cin, a[i].year);
					break;
				}
				case 6:
				{
					cout << "The loai                 : ";
					cin.ignore();
					getline(cin, a[i].kind);
					break;
				}
				case 7:
				{
					cout << "Gia sach                 : ";
					cin >> a[i].price;
					break;
				}
				case 8:
				{
					cout << "So quyen sach             : ";
					cin >> a[i].amount;
					break;
				}
				}
			}
		}
	}
}

// cau 2.d xoa thong tin sach
void RemoveBook(int& NumberOfBook , book a[])
{
	int isbn1;
	int remove = 0;
	cout << "Moi ban nhap ma sach ISBN cua sach can xoa thong tin : ";
	cin >> isbn1;
	for (int i = 0; i < NumberOfBook; i++)
	{
		if (isbn1 == a[i].isbn)
		{
			remove = i;
		}
	}
	for (int i = remove; i < NumberOfBook - 1; i++)
	{
		a[i].isbn = a[i + 1].isbn;
		a[i].namebook = a[i + 1].namebook;
		a[i].publisher = a[i + 1].publisher;
		a[i].year = a[i + 1].year;
		a[i].kind = a[i + 1].kind;
		a[i].price = a[i + 1].price;
		a[i].amount = a[i + 1].amount;
	}
	NumberOfBook--;
}

// cau 2.e tim kiem sach theo ma ISBN
void SearchByISBN(int& NumberOfBook, book a[])
{
	int isbn1;
	cout << "Moi ban nhap ma sach ISBN cua sach can tim kiem thong tin : ";
	cin >> isbn1;
	for (int i = 0; i < NumberOfBook; i++)
	{
		if (isbn1 == a[i].isbn)
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------";
			cout << endl;
			cout << "ISBN (ma sach)		     :  " << a[i].isbn << endl;
			cout << "Ten sach                     :  " << a[i].namebook << endl;
			cout << "Tan tac gia                  :  " << a[i].author << endl;
			cout << "Nha san xuat                 :  " << a[i].publisher << endl;
			cout << "Nam xuat ban                 :  " << a[i].year << endl;
			cout << "The loai                     :  " << a[i].kind << endl;
			cout << "Gia sach                     :  " << a[i].price << endl;
			cout << "So quyen sach                :  " << a[i].amount << endl;
		}
	}
}

// cau 2.f tim kiem sach theo ho ten
void SearchByNamebook(int& NumberOfBook, book a[])
{
	string namebook1;
	cout << "Moi ban nhap Ten cua sach can tim kiem thong tin : ";
	cin.ignore();
	getline(std::cin, namebook1);
	for (int i = 0; i < NumberOfBook; i++)
	{
		if (a[i].namebook == namebook1)
		{
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------";
			cout << endl;
			cout << "ISBN (ma sach)		     :  " << a[i].isbn << endl;
			cout << "Ten sach                     :  " << a[i].namebook << endl;
			cout << "Tan tac gia                  :  " << a[i].author << endl;
			cout << "Nha san xuat                 :  " << a[i].publisher << endl;
			cout << "Nam xuat ban                 :  " << a[i].year << endl;
			cout << "The loai                     :  " << a[i].kind << endl;
			cout << "Gia sach                     :  " << a[i].price << endl;
			cout << "So quyen sach                :  " << a[i].amount << endl;
		}
	}
}

// chuc nang 2 quan ly sach
void function2(int& NumberOfBook, book a[])
{
	char chucnang2 = 'a';
	while (chucnang2 != 'g')
	{

		cout << "\n---------------------------------------------\n";
		cout << "|     ---CHUC NANG 2: Quan ly sach---       |\n";
		cout << "|a. Xem danh sach cac sach trong thu vien   |\n";
		cout << "|b. Them sach                               |\n";
		cout << "|c. Chinh thong tin mot quyen sach          |\n";
		cout << "|d. Xoa thong tin sach                      |\n";
		cout << "|e. Tim kiem sach theo ISBN                 |\n";
		cout << "|f. Tim kiem sach theo ten sach             | \n";
		cout << "|g. Quay lai                                | \n";
		cout << "---------------------------------------------\n";

		cout << "Moi ban nhap chuc nang :  ";
		cin >> chucnang2;

		switch (chucnang2)
		{
			case 'a':
			{
				ListOfBook(NumberOfBook, a);
				break;
			}
			case 'b':
			{
				AddBook(NumberOfBook, a);
				break;
			}
			case 'c':
			{
				EditBook(NumberOfBook, a);
				break;
			}
			case 'd':
			{
				RemoveBook(NumberOfBook, a);
				break;
			}
			case 'e':
			{
				SearchByISBN(NumberOfBook, a);
				break;
			}
			case 'f':
			{
				SearchByNamebook(NumberOfBook, a);
				break;
			}
		}
	}

}
