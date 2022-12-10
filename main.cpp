#include "list.h"

#define UP 72
#define DOWN 80
#define ENTER 13

int main()
{
	system("CLS");
	SetConsoleTitle(L"Kursach");
	setlocale(LC_ALL, "Russian");
	ConsoleCursorVisible(false, 100);

	ListNewspaper* list = new ListNewspaper(); // �������� ������ � ���������
	Newspaper* data = nullptr; // ����������� ������� ������
	size_t index = 0; // ���������� ����� ����������� �������� � ������

	string name;
	string publisher;

	string Menu[] = { // ���� ��������
	" 1 - �������� ������",
	" 2 - �������� ������� � ������ ������",
	" 3 - �������� ������� � ����� ������",
	" 4 - �������� ������� � ������ (�� ����������� ������)",
	" 5 - ������� ������ �� �����",
	" 6 - ������� ������� ������ �� ����������� ������",
	" 7 - ��������������� ������� ������ (�� ����������� ������)",
	" 8 - ������� ������� �� ������ ������",
	" 9 - ������� ������� �� ����� ������",
	"10 - ������� ������� �� ������ (�� ����������� ������)",
	"11 - ����� ������ ��� ������ �� ��������",
	"12 - ����� ������ ��� ������ �� ������������",
	"13 - ����������� ������ � ������� � ������� ����������� �� ���������� �������",
	"14 - ����������� ������ � ������� � ������� ����������� �� ��������",
	"15 - ��������� ������ � ����",
	"16 - ������� ������ �� �����",
	" 0 - ����� �� ���������"
	};
	int active_menu = 0;

	while (true)
	{
		system("CLS");
/*
		int x = 0, y = 0;
		GoToXY(x, y);

		char ch;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch) {
		case UP:
			if (active_menu > 0)
				--active_menu;
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1)
				++active_menu;
			break;
		case ENTER:
*/
		for (int i = 0; i < size(Menu); i++)
		{
			cout << Menu[i] << endl;
		}
		active_menu = inputInt("������� ������ ����� ������ ����: ");

		switch (active_menu)
			{
				// ����� �� ���������
				case 0:
					delete list;
					exit(0);
					break;

				// �������� ������
				case 1:
					//system("CLS");
					list->clearList();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;

				// �������� ������� � ������ ������
				case 2:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					list->pushFront(data);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// �������� ������� � ����� ������
				case 3:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					list->pushBack(data);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// �������� ������� � ������ (�� ����������� ������)
				case 4:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					index = inputIndex("������� ���������� ����� �������� ������: ");
					list->insert(data, index);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ������� ������ �� �����
				case 5:
					//system("CLS");
					list->showList();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ������� ������� ������ �� ����������� ������
				case 6:
					//system("CLS");
					index = inputIndex("������� ���������� ����� �������� ������: ");
					data = list->get(index);
					data->showNewspaper();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ��������������� ������� ������ (�� ����������� ������)
				case 7:
					//system("CLS");
					index = inputIndex("������� ���������� ����� �������� ������: ");
					list->set(index);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ������� ������� �� ������ ������
				case 8:
					//system("CLS");
					list->popFront();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ������� ������� �� ����� ������
				case 9:
					//system("CLS");
					list->popBack();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ������� ������� �� ������ (�� ����������� ������)
				case 10:
					//system("CLS");
					index = inputIndex("������� ���������� ����� �������� ������: ");
					list->remove(index);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ����� ������ ��� ������ �� ��������
				case 11:
					//system("CLS");
					name = inputString("������� �������� ������ ��� ������� ��� ������ � ������: ");
					list->findByName(name);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ����� ������ ��� ������ �� ������������
				case 12:
					//system("CLS");
					publisher = inputString("������� �������� ������������ ��� ������ ����� � �������� � ������: ");
					list->findByPublisher(publisher);
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ����������� ������ � ������� � ������� ����������� �� ���������� �������
				case 13:
					//system("CLS");
					list->sortBySubscriptionIndex();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ����������� ������ � ������� � ������� ����������� �� ��������
				case 14:
					//system("CLS");
					list->sortByName();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				// ��������� ������ � ����
				case 15:
					//system("CLS");
					list->saveList();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
				
				
				// ������� ������ �� �����
				case 16:
					//system("CLS");
					list->clearList();
					list->readList();
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;

		        // ����� ������ ������ ����
				default:
					//system("CLS");
					cout << "�������� ����� ����!" << endl;
					cout << endl << "��� ����������� ������, ������� �� ����� ������� ... ";
					_getch();
					break;
			}
/*
			break;
		}
*/
	}
}
