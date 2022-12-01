#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include<cctype>

using namespace std;

// student
struct Student {
	int id;
	string fName;
	string lName;
	string fullname;
	float subScore1;
	float subScore2;
	float average = 0;
}typedef ST;


// sum average
float Average(ST& st)
{
	return	st.average = (st.subScore1 + st.subScore2) / 2;
}


// cấu trúc cơ bản
#pragma region Cấu trúc cơ bản của cây
struct ManagementStudent{
	ST st;
	ManagementStudent* left;
	ManagementStudent* right;
}typedef MS;

// initialize
void Init(MS*&root)
{
	root = NULL;
}

// create node
MS* CreateStudent(ST &st)
{
	MS* p = new MS;
	p->st = st;
	p->left = NULL;
	p->right = NULL;

	return p;
}	

// insert node
void insertStudent(MS*& root, ST &st)
{
	if (root == NULL)
		root = CreateStudent(st);
	else 
	{
		MS* p = root;
		MS* prev = NULL;
		while (p != NULL && p->st.id != st.id)
		{
			prev = p;
			if (p->st.id > st.id)
				p = p->left;
			else
				p = p->right; 
		}
		if (p == NULL)
		{
			p = CreateStudent(st);
			if (prev->st.id < st.id)
				prev->right = p;
			else
			{
				prev->left = p;
			}
		}
	}
}
#pragma endregion


// menu
void MENU()
{
	cout << "	CHUONG TRINH QUAN LY SINH VIEN C++\n";
    cout <<	"*************************MENU**************************\n";
    cout << "**  1. Doc du lieu tu File.                          **\n";
    cout << "**  2. Tim kiem sinh vien.                           **\n";
    cout << "**  3. Xoa sinh vien boi ID.                         **\n";
    cout << "**  4. Them vao sinh vien.                           **\n";
    cout << "**  5. In danh sach ten tang dan.                    **\n";
    cout << "**  6. In danh sach dtb giam dan.                    **\n";
	cout << "**  7. In danh sach sinh vien Dau.                   **\n";
	cout << "**  8. In danh sach sinh vien Rot.                   **\n";
    cout << "**  0. Thoat                                         **\n";
    cout << "*******************************************************\n";
	cout << "Chon (0-8) : ";
}

// Check tree empty
int checkEmpty(MS* root)
{
	if (root == NULL)
		return 0;
	else
		return 1;
}

// Chức năng 2 : tìm kiếm sinh viên
#pragma region Tìm kiếm sinh viên
// search student by id
MS* SearchStudent(MS* root, int id)
{
	while (root != NULL)
	{
		if (root->st.id == id)
			return root;
		else
			if (root->st.id > id)
				root = root->left;
			else
				root = root->right;
	}
	return NULL;
}
#pragma endregion

// Nhập và in danh sách sinh viên
#pragma region Nhập và in danh sách sinh viên
// input student
int InputStudent(MS* root, ST& st)
{
	float sub;
	do
	{
		cout << "\nMa sinh vien : ";
		cin >> st.id;
		if (SearchStudent(root, st.id) != NULL)
			cout << "Ma so sinh vien da ton tai. Vui long nhap lai.!!!";
	} while (SearchStudent(root, st.id) != NULL);
	cin.ignore();
	cout << "\nHo : ";
	getline(cin, st.fName);
	cout << "\nTen: ";
	getline(cin, st.lName);
	do
	{
		cout << "\nDiem mon 1 : ";
		cin >> sub;
		st.subScore1 = sub;
		if (sub < 0 || sub >= 11)
		{
			cout << "\nDiem khong duoc nho hon 0 va lon hon 10. Vui long nhap lai.!!!";
		}
	} while (sub < 0 || sub >= 11);
	cin.ignore();
	do
	{
		cout << "\nDiem mon 2 : ";
		cin >> sub;
		st.subScore2 = sub;
		if (sub < 0 || sub >= 11)
			cout << "\nDiem khong duoc nho hon 0 va lon hon 10. Vui long nhap lai.!!!";
	} while (sub < 0 || sub >= 11);
	cin.ignore();
	st.fullname = st.fName +" "+ st.lName;
	st.average = Average(st);
	return 1;
}

// output the screen
void OutputStudent(ST st)
{
	cout << setfill(' ');
	if (st.id < 10)
	{
		cout << "\n| sv0" << setw(7) << left << st.id;
		cout << "| " << setw(20) << left << st.fullname;
		cout << setw(10) << right << "| " << setw(6) << st.subScore1;
		cout << setw(8) << right << "| " << setw(6) << st.subScore2;
		cout << setw(8) << right << "| " << setw(10) << st.average << setw(7) << "|";
	}
	else if(st.id >= 10 && st.id <= 99)
	{
		cout << "\n| sv" << setw(8) << left << st.id;
		cout << "| " << setw(20) << left << st.fullname;
		cout << setw(10) << right << "| " << setw(6) << st.subScore1;
		cout << setw(8) << right << "| " << setw(6) << st.subScore2;
		cout << setw(8) << right << "| " << setw(10) << st.average << setw(7) <<"|";
	}
	else 
	{ 
		cout << "\n| sv" << setw(8) << left << st.id;
		cout << "| " << setw(20) << left << st.fullname;
		cout << setw(10) << right << "| " << setw(6) << st.subScore1;
		cout << setw(8) << right << "| " << setw(6) << st.subScore2;
		cout << setw(8) << right << "| " << setw(10) << st.average << setw(7) << "|";
	}
}
#pragma endregion

// Chức năng 1 : Đọc dữ liệu.
#pragma region Đọc file text và in file text 
// count the number of lines in text
int Count()
{
	ifstream inF;
	inF.open("SinhVien.txt");
	string s;
	int count = 0;
	if (inF.is_open())
	{
		while (!inF.eof())
		{
			getline(inF, s);
			if (s == "...") break;
			count++;
		}
		inF.close();
		return count;
	}
	else 
		return -1;
}
// read file text 
void ReadFile(MS*& root, int &n)
{
	ST st;
	ifstream inF;
	inF.open("SinhVien.txt");
	if (inF.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			if (i >= 1) inF.ignore();
			inF.ignore(2);
			inF >> st.id;
			inF.ignore(1);
			getline(inF, st.fName, '-');
			getline(inF, st.lName, '-');
			st.fullname = st.fName +" "+ st.lName;
			inF >> st.subScore1;
			inF.ignore(1);
			inF >> st.subScore2;
			st.average = Average(st);
			insertStudent(root, st);
		}
		inF.close();
	}
	else
		cout << "Khong mo duoc file de doc du lieu.!!!" << endl;
}
#pragma endregion

//Cập nhật dữ liệu mõi khi thêm sửa xóa.
#pragma region Cập nhật dữ liệu vào file text
// write file txt
void WriteFile(MS* root)
{
	ofstream outF;
	outF.open("SinhVien.txt");
	if (outF.is_open())
	{
		MS* p;
		while (root)
		{
			if (root->left == NULL)
			{
				if (root->st.id < 10)
				{
					outF << "sv0" << root->st.id << '-';
				}
				else
				{
					outF << "sv" << root->st.id << '-';

				}
				outF << root->st.fName << '-';
				outF << root->st.lName << '-';
				outF << root->st.subScore1 << '-';
				outF << root->st.subScore2 << endl;
				root = root->right;
			}
			else
			{
				p = root->left;
				while (p->right && p->right != root)
				{
					p = p->right;
				}
				if (p->right == NULL)
				{
					p->right = root;
					root = root->left;
				}
				else
				{
					p->right = NULL;
					if (root->st.id < 10)
					{
						outF << "sv0" << root->st.id << '-';
					}
					else
					{
						outF << "sv" << root->st.id << '-';

					}
					outF << root->st.fName << '-';
					outF << root->st.lName << '-';
					outF << root->st.subScore1 << '-';
					outF << root->st.subScore2 << endl;
					root = root->right;
				}
			}
		}
		outF << "...";
		outF.close();
	}
	else
		cout << "\nKhong mo duoc file.";
} 
#pragma endregion

// Chức năng 3 : Xóa sinh viên.
#pragma region Xóa sinh viên
// search lastleft
void SearchLastLeft(MS*&root, MS*& q)
{
	if (q->left == NULL)
	{
		root->st.id = q->st.id;
		root = q;
		q = q->right;
	}
	else
		SearchLastLeft(root, q->left);
}


// delete student
int Delete(MS*&root, int id) {
	if (root == NULL) return 0;
	if (root->st.id == id) {
		MS* p = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else 
			SearchLastLeft(p, root->right);
		delete p;
		return 1;
	}
	if (root->st.id < id) return Delete(root->right, id);
	if (root->st.id > id) return Delete(root->left, id);
}
#pragma endregion

// Chức năng 4 : thêm sinh viên.
#pragma region Thêm sinh viên vào danh sách
// add a student to list
int Add(MS*& root)
{
	ST add;
	if (InputStudent(root, add) == 1)
	{
		insertStudent(root, add);
		return 1;
	}
}
#pragma endregion

// Chức năng 5 : In danh sách sinh viên tăng dần.
#pragma region Sắp xếp tên tăng dần
void SortNameAESC(MS* head)
{
	for (MS* i = head; i != NULL; i = i->right)
	{
		for (MS* j = i->right; j != NULL; j = j->right)
		{
			char* str1 = (char*)i->st.lName.c_str();
			char* str2 = (char*)j->st.lName.c_str();
			if (strcmp(str1, str2) > 0)
			{
				ST temp;
				temp = i->st;
				i->st = j->st;
				j->st = temp;
			}
		}
	}
}
#pragma endregion

// Chức năng 6 : In danh sách sinh viên dtb giảm dần.
#pragma region sắp xếp theo điểm trung bình giảm dần

void InsertFirst(MS*& head, ST st)
{
	MS* p = CreateStudent(st);
	p->right = head;
	head = p;
}

// output the screen list desc
void LNR(MS* root, MS*& head)
{
	MS* p;
	while (root)
	{
		if (root->left == NULL)
		{
			InsertFirst(head, root->st);
			root = root->right;
		}
		else
		{
			p = root->left;
			while (p->right && p->right != root)
			{
				p = p->right;
			}
			if (p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				InsertFirst(head, root->st);
				root = root->right;
			}
		}
	}
}

void SortAverageDESC(MS* head)
{
	for (MS* i = head; i != NULL; i = i->right)
	{
		for (MS* j = i->right; j != NULL; j = j->right)
		{
			if (i->st.average < j->st.average)
			{
				ST temp;
				temp = i->st;
				i->st = j->st;
				j->st = temp;
			}
		}
	}
}

void OutputDESC(MS* head)
{
	MS* p = head;
	while (p != NULL)
	{
	
		OutputStudent(p->st);
		p = p->right;
	}
}

#pragma endregion

// Chức năng 7 : In danh sách sinh viên đậu.
#pragma region In danh sách sinh viên đậu
// search a student have avarage >= 5
void SearchPass(MS* root)
{
	MS* p;
	while (root)
	{
		if (root->left == NULL)
		{
			if (Average(root->st) >= 5)
			{
				OutputStudent(root->st);
			}
			root = root->right;
		}
		else
		{
			p = root->left;
			while (p->right && (p->right != root))
			{
				p = p->right;
			}
			if (p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				if (Average(root->st) >= 5)
				{
					OutputStudent(root->st);
				}
				root = root->right;
			}
		}
	}
}
#pragma endregion

//Chức năng 8 : In danh sách xin viên rớt.
#pragma region In danh sách xin viên rớt
// output the screen list student fail.
int SearchFail(MS* root)
{
	int check = 0;
	MS* p;
	while (root)
	{
		if (root->left == NULL)
		{
			if (Average(root->st) < 5)
			{
				OutputStudent(root->st);
				check = 1;
			}
			root = root->right;
		}
		else
		{
			p = root->left;
			while (p->right && (p->right != root))
			{
				p = p->right;
			}
			if (p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				if (Average(root->st) < 5)
				{
					OutputStudent(root->st);
					check = 1;
				}
				root = root->right;
			}
		}
	}
	return check;
}
#pragma endregion


// Vẽ bảng
#pragma region Dùng để vẽ bảng và tiêu đề

void DrawHeader()
{
	cout << setfill('-');
	cout << "\n\n\n+" << setw(12) << "+" << setw(30) << "+" << setw(14) << "+" << setw(14) << "+" << setw(18) << "+";
	cout << setfill(' ');
	cout << "\n| MSSV" << setw(6) << " " << "| Ho Ten" << setw(22) << " " << "| Diem mon 1" << setw(2) << " " << "| Diem mon 2" << setw(2) << " " << "| Diem trung binh |";
	cout << setfill('-');
	cout << "\n+" << setw(12) << "+" << setw(30) << "+" << setw(14) << "+" << setw(14) << "+" << setw(18) << "+";
	cout << setfill(' ');
	cout << "\n|" << setw(12) << "|" << setw(30) << "|" << setw(14) << "|" << setw(14) << "|" << setw(18) << "|";
}

void DrawFooter()
{
	cout << "\n|" << setw(12) << "|" << setw(30) << "|" << setw(14) << "|" << setw(14) << "|" << setw(18) << "|";
	cout << setfill('-');
	cout << "\n+" << setw(12) << "+" << setw(30) << "+" << setw(14) << "+" << setw(14) << "+" << setw(18) << "+";
}

void Tilte(int op)
{
	switch (op)
	{
	case 2:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|   TIM KIEM SINH VIEN   |------>||<";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";
		break;
	case 3:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|      XOA SINH VIEN     |------>||<";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";

		break;
	case 4:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|     THEM SINH VIEN     |------>||<";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";

		break;
	case 5:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|    SAP XEP DANH SACH   |------>||<";
		cout << "\n            ||       |	       THEO TEN       |       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";

		break;
	case 6:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       |    SAP XEP DANH SACH   |       ||";
		cout << "\n           >||<------|	         THEO         |------>||<";
		cout << "\n            ||       |     DIEM TRUNG BINH    |       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";
		break;
	case 7:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|        SINH VIEN       |------>||<";
		cout << "\n            ||       |           DAU          |       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";
		break;
	case 8:
		system("cls");
		cout << "\n";
		cout << "\n            ||                                        ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n           >||<------|        SINH VIEN       |------>||<";
		cout << "\n            ||       |           ROT          |       ||";
		cout << "\n            ||       |                        |       ||";
		cout << "\n            ||       +------------------------+       ||";
		cout << "\n            ||                                        ||";
		cout << "\n          ======                                    ======";

		break;
	}
}
#pragma endregion
