// Ho va ten : Pham Hong Gia Bao
// MSSV : 21127014

#include<iostream>
#include<string>
#include<fstream>
#include"reader.h"

using namespace std;


void ReadFromFile(reader a[])
{
	int n = 3;
	ifstream newfile;
	newfile.open("doc_gia.txt", ios::in);
	
	for (int i = 0; i < n; i++)
	{
		getline(newfile, a[i].ma);
		getline(newfile, a[i].name);
		newfile >> a[i].cmnd;
		getline(newfile, a[i].date);
		getline(newfile, a[i].email);
		getline(newfile, a[i].address);
		newfile >> a[i].d;
		newfile >> a[i].m;
		newfile >> a[i].y;
	}
	newfile.close();
}


// cau 1.a xem danh sach doc gia

void ListOfReader(int& soluongdocgia, reader a[100])
{
	cout << "-----------------------------------------\n";
	cout << "|      ***   Ket qua tim kiem   ***     |\n";
	cout << "-----------------------------------------";
	cout << "\n=== Danh sach doc gia ===";
	if (soluongdocgia == 0)
	{
		cout << "\nKHONG CO doc gia nao ca! Moi ban them doc gia!\n";
		return;
	}

	for (int i = 0; i < soluongdocgia; i++)
	{
		cout << "\n*** Doc gia thu " << i + 1 << " : \n";
		cout << "Ma doc gia	     : " << a[i].ma << endl;
		cout << "Ho va ten            : " << a[i].name << endl;
		cout << "CMND                 : " << a[i].cmnd << endl;
		cout << "Ngay thang nam sinh  : " << a[i].date << endl;
		cout << "Email                : " << a[i].email << endl;
		cout << "Dia chi              : " << a[i].address << endl;
		cout << "Ngay lap the         : " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
		cout << "Ngay het han         : " << a[i].d + 1 << "/" << a[i].m << "/" << a[i].y + 4 << endl;

	}
}


//cau 1.b them doc gia
void AddReader(int& soluongdocgia, reader a[])
{
	int soluong;
	cout << "Nhap so luong doc gia ban muon them vao : ";
	cin >> soluong;
	for (int i = soluongdocgia; i < soluongdocgia + soluong; i++)
	{
		cout << "*** Doc gia thu " << i + 1 << endl;
		cout << "Ma doc gia           : ";
		cin.ignore();
		getline(cin, a[i].ma);
		cout << "Ho va ten            : ";
		getline(cin, a[i].name);
		cout << "So CMND              : ";
		cin >> a[i].cmnd;
		cout << "Ngay thang nam sinh  : ";
		cin.ignore();
		getline(cin, a[i].date);
		cout << "Gioi tinh            : ";
		getline(cin, a[i].gender);
		cout << "Email                : ";
		getline(cin, a[i].email);
		cout << "Dia chi              : ";
		getline(cin, a[i].address);
		cout << "Ngay lap the         : ";
		cin >> a[i].d;
		cout << "Thang lap the        : ";
		cin.ignore();
		cin >> a[i].m;
		cout << "Nam lap the          : ";
		cin >> a[i].y;
	}
	soluongdocgia += soluong;
}

// cau 1.c chinh sua thong tin doc gia
void EditReader(int soluongdocgia, reader a[])
{
	int cmnd1;
	cout << "Moi ban nhap CMND doc gia can chinh sua thong tin : ";
	cin >> cmnd1;
	for (int i = 0; i < soluongdocgia; i++)
	{
		if (cmnd1 == a[i].cmnd)
		{
			int chon = 1;

			while (chon != 0)
			{
				cout << endl;
				cout << "-----------------------------------------------------------------------------\n";
				cout << "|                   *** CHON THONG TIN CAN CHINH SUA ***                    |\n";
				cout << "| Chon 1: Ma doc gia                                                        |" << endl;
				cout << "| Chon 2: Ho va ten                                                         |" << endl;
				cout << "| Chon 3: CMND                                                              |" << endl;
				cout << "| Chon 4: Ngay thang nam sinh                                               |" << endl;
				cout << "| Chon 5: Email                                                             |" << endl;
				cout << "| Chon 6: Dia chi                                                           |" << endl;
				cout << "| Chon 7: Ngay lap the                                                      |" << endl;
				cout << "| Chon 8: Ngay het han the (ban chi can chinh sua 'Ngay lap the')           |" << endl;
				cout << "| Chon 0: Quay lai                                                          |" << endl;
				cout << "-----------------------------------------------------------------------------\n";

				cout << "Moi ban chon thong tin : ";
				cin >> chon;

				switch (chon)
				{
				case 1:
				{
					cout << "Ma doc gia           : ";
					cin.ignore();
					getline(std::cin, a[i].ma);
					break;
				}
				case 2:
				{
					cout << "Ho va ten            : ";
					cin.ignore();
					getline(cin, a[i].name);
					break;
				}
				case 3:
				{
					cout << "So CMND              : ";
					cin.ignore();
					cin >> a[i].cmnd;
					break;
				}
				case 4:
				{
					cout << "Ngay thang nam sinh  : ";
					cin.ignore();
					getline(cin, a[i].date);
					break;
				}
				case 5:
				{
					cout << "Email                : ";
					cin.ignore();
					getline(cin, a[i].email);
					break;
				}
				case 6:
				{
					cout << "Dia chi              : ";
					cin.ignore();
					getline(cin, a[i].address);
					break;
				}
				case 7:
				{
					cout << "Ngay lap the         : ";
					cin.ignore();
					cin >> a[i].d;
					cout << "Thang lap the        : ";
					cin.ignore();
					cin >> a[i].m;
					cout << "Nam lap the          : ";
					cin.ignore();
					cin >> a[i].y;
					break;
				}
				}
			}



		}
	}
}



// cau 1.d xoa doc gia 
void RemoveReader(int& soluongdocgia, reader a[])
{
	int cmnd1;
	cout << "Moi ban nhap CMND doc gia can xoa thong tin : ";
	cin >> cmnd1;
	int vitrixoa = 0;
	for (int i = 0; i < soluongdocgia; i++)
	{
		if (cmnd1 == a[i].cmnd)
		{
			vitrixoa = i;
		}
	}
	for (int i = vitrixoa; i < soluongdocgia - 1; i++)
	{
		a[i].ma = a[i + 1].ma;
		a[i].name = a[i + 1].name;
		a[i].cmnd = a[i + 1].cmnd;
		a[i].date = a[i + 1].date;
		a[i].gender = a[i + 1].gender;
		a[i].email = a[i + 1].email;
		a[i].address = a[i + 1].address;
		a[i].d = a[i + 1].d;
		a[i].m = a[i + 1].m;
		a[i].y = a[i + 1].y;
	}
	soluongdocgia--;
}

// cau 1.e tim kiem doc gia theo cmnd
void SearchByCMND(int soluongdocgia, reader a[])
{
	int cmnd1;
	cout << "Moi ban nhap CMND cua doc gia can tim : ";
	cin >> cmnd1;
	for (int i = 0; i < soluongdocgia; i++)
	{
		if (a[i].cmnd == cmnd1)
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------";
			cout << endl;
			cout << "Ma doc gia	     : " << a[i].ma << endl;
			cout << "Ho va ten            : " << a[i].name << endl;
			cout << "CMND                 : " << a[i].cmnd << endl;
			cout << "Ngay thang nam sinh  : " << a[i].date << endl;
			cout << "Email                : " << a[i].email << endl;
			cout << "Dia chi              : " << a[i].address << endl;
			cout << "Ngay lap the         : " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
			cout << "Ngay het han         : " << a[i].d + 1 << "/" << a[i].m << "/" << a[i].y + 4 << endl;
		}
	}
}

// cau 1.f tim kiem doc gia theo ho ten
void SearchByName( int soluongdocgia, reader a[])
{
	string name1;
	cout << "Nhap Ho Ten doc gia ban can tim kiem : ";
	cin.ignore();
	getline(cin, name1);

	for (int i = 0; i < soluongdocgia; i++)
	{
		string name2 = a[i].name;
		int n = 0;
		short flag = 1;


		// so sanh chuoi s1 voi s2P
		while (name1[n] != '\0')
		{
			if (name1[n] != name2[n])
			{
				flag = 0;
				break;
			}
			n++;
		}

		if (flag == 1)
		{
			cout << endl;
			cout << "-----------------------------------------\n";
			cout << "|      ***   Ket qua tim kiem   ***     |\n";
			cout << "-----------------------------------------";
			cout << endl;
			cout << "Ma doc gia	     : " << a[i].ma << endl;
			cout << "Ho va ten            : " << a[i].name << endl;
			cout << "CMND                 : " << a[i].cmnd << endl;
			cout << "Ngay thang nam sinh  : " << a[i].date << endl;
			cout << "Email                : " << a[i].email << endl;
			cout << "Dia chi              : " << a[i].address << endl;
			cout << "Ngay lap the         : " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
			cout << "Ngay het han         : " << a[i].d + 1 << "/" << a[i].m << "/" << a[i].y + 4 << endl;

		}
	}
}

// chuc nang 1 quan ly doc gia
void function1(int& soluongdocgia, reader a[])
{
	char chucnang1 = 'a';

	while (chucnang1 != 'g')
	{

		cout << "\n------------------------------------------";
		cout << endl << "|   ---CHUC NANG 1: Quan ly doc gia---    |\n";
		cout << "|a. Xem danh sach doc gia trong thu vien  |\n";
		cout << "|b. Them doc gia                          |\n";
		cout << "|c. Chinh thong tin mot doc gia           |\n";
		cout << "|d. Xoa thong tin doc gia                 |\n";
		cout << "|e. Tim kiem doc gia theo CMND            |\n";
		cout << "|f. Tim kiem doc gia theo Ho Ten          | \n";
		cout << "|g. Quay lai                              | \n";
		cout << "------------------------------------------\n";

		cout << "Moi ban nhap chuc nang :  ";
		cin >> chucnang1;

		switch (chucnang1)
		{
		case 'a':
		{
			ListOfReader(soluongdocgia, a);
			break;
		}
		case 'b':
		{
			AddReader(soluongdocgia, a);
			break;
		}
		case 'c':
		{
			EditReader(soluongdocgia, a);
			break;
		}
		case 'd':
		{
			RemoveReader(soluongdocgia, a);
			break;
		}
		case 'e':
		{
			SearchByCMND(soluongdocgia,a);
			break;
		}
		case 'f':
		{
			SearchByName(soluongdocgia, a);
			break;
		}
		}
	}
}