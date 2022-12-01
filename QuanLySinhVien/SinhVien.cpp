#include "SinhVien.h"
#include<conio.h>

int main()
{
	MS* root;
	Init(root);
	int n = Count();
	int op;
	bool isInput = false;
	do
	{
		system("cls");
		MENU();
		cin >> op;
		cin.ignore();
		Tilte(op);
		switch (op)
		{
		case 1: // Đọc dữ liệu từ file.
			#pragma region Đọc dữ liệu từ file
			ReadFile(root, n);
			cout << "\nDoc File du lieu thanh cong.!!!";
			isInput = true;
			break;
			#pragma endregion
		case 2: // tìm kiếm sinh viên.
			#pragma region Tìm kiếm sinh viên
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					MS* p;
					int id;
					cout << "\n\nNhap id can tim : ";
					cin >> id;
					p = SearchStudent(root, id);
					if (p != NULL)
					{
						DrawHeader();
						OutputStudent(p->st);
						DrawFooter();
					}
					else {
						cout << "\nKhong co sinh vien trong danh sach.!!";
					}
				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 3: // Xóa sinh viên.
			#pragma region Xóa sinh viên
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					MS* p;
					int id;
					cout << "\nNhap ma sinh vien can xoa : ";
					cin >> id;
					p = SearchStudent(root, id);
					if (p != NULL)
					{
						DrawHeader();
						OutputStudent(p->st);
						DrawFooter();
					}
					else
						cout << "\nKhong co sinh vien nay trong danh sach.!!";
					if (Delete(root, id) == 1)
					{
						cout << "\nXoa sinh vien thanh cong.!!!";
						WriteFile(root);
					}
					else
						cout << "\nXoa sinh vien that bai.!!!";

				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 4: // Thêm một sinh viên.
			#pragma region Thêm sinh viên
			if (isInput)
			{
				if (Add(root) == 1)
				{
					cout << "\nThem sinh vien thanh cong.!!";
					WriteFile(root);
				}
				else
					cout << "\nThem sinh vien that bai.!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 5: // in danh sách tên sinh viên tăng dần.
			#pragma region Tên tăng dần
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					MS* head;
					Init(head);
					LNR(root, head);
					SortNameAESC(head);
					DrawHeader();
					OutputDESC(head);
					DrawFooter();
					delete head;
				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 6: // in danh sách điểm trung bình giảm dần.
			#pragma region điểm trung bình giảm dần
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					MS* head;
					Init(head);
					LNR(root, head);
					SortAverageDESC(head);

					DrawHeader();
					OutputDESC(head);
					DrawFooter();
					delete head;
				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 7: // in danh sách sinh viên đậu.
			#pragma region Sinh viên đậu
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					DrawHeader();
					SearchPass(root);
					DrawFooter();
				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 8: // in danh sách sinh viên rớt.
			#pragma region Sinh viên rớt
			if (isInput)
			{
				if (checkEmpty(root) == 1)
				{
					DrawHeader();
					if (SearchFail(root) == 0)
						cout << "\nKhong co sinh vien rot.!!";
					DrawFooter();
				}
				else
					cout << "\nDanh sach sinh vien dang trong.!!!";
			}
			else
				cout << "\nVui long nhap sinh vien tu file.!!!";
			break;
			#pragma endregion
		case 9:
			break;
		}
		_getch();
	} while (op > 0 && op <= 8);
	return 0;
}
