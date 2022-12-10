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

	ListNewspaper* list = new ListNewspaper(); // Основной список в программе
	Newspaper* data = nullptr; // Добавляемый элемент списка
	size_t index = 0; // Порядковый номер выбираемого элемента в списке

	string name;
	string publisher;

	string Menu[] = { // Меню орпеаций
	" 1 - Очистить список",
	" 2 - Добавить элемент в начало списка",
	" 3 - Добавить элемент в конец списка",
	" 4 - Добавить элемент в список (по порядковому номеру)",
	" 5 - Вывести список на экран",
	" 6 - Вывести элемент списка по порядковому номеру",
	" 7 - Отредактировать элемент списка (по порядковому номеру)",
	" 8 - Удалить элемент из начала списка",
	" 9 - Удалить элемент из конца списка",
	"10 - Удалить элемент из списка (по порядковому номеру)",
	"11 - Найти газету или журнал по названию",
	"12 - Найти газету или журнал по издательству",
	"13 - Сортировать газеты и журналы в порядке возрастания по подписному индексу",
	"14 - Сортировать газеты и журналы в порядке возрастания по названию",
	"15 - Сохранить список в файл",
	"16 - Считать список из файла",
	" 0 - Выход из программы"
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
		active_menu = inputInt("Введите нужный номер пункта меню: ");

		switch (active_menu)
			{
				// Выход из программы
				case 0:
					delete list;
					exit(0);
					break;

				// Очистить список
				case 1:
					//system("CLS");
					list->clearList();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;

				// Добавить элемент в начало списка
				case 2:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					list->pushFront(data);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Добавить элемент в конец списка
				case 3:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					list->pushBack(data);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Добавить элемент в список (по порядковому номеру)
				case 4:
					//system("CLS");
					data = new Newspaper();
					data->inputNewspaper();
					index = inputIndex("Введите порядковый номер элемента списка: ");
					list->insert(data, index);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Вывести список на экран
				case 5:
					//system("CLS");
					list->showList();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Вывести элемент списка по порядковому номеру
				case 6:
					//system("CLS");
					index = inputIndex("Введите порядковый номер элемента списка: ");
					data = list->get(index);
					data->showNewspaper();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Отредактировать элемент списка (по порядковому номеру)
				case 7:
					//system("CLS");
					index = inputIndex("Введите порядковый номер элемента списка: ");
					list->set(index);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Удалить элемент из начала списка
				case 8:
					//system("CLS");
					list->popFront();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Удалить элемент из конца списка
				case 9:
					//system("CLS");
					list->popBack();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Удалить элемент из списка (по порядковому номеру)
				case 10:
					//system("CLS");
					index = inputIndex("Введите порядковый номер элемента списка: ");
					list->remove(index);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Найти газету или журнал по названию
				case 11:
					//system("CLS");
					name = inputString("Введите название газеты или журнала для поиска в списке: ");
					list->findByName(name);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Найти газету или журнал по издательству
				case 12:
					//system("CLS");
					publisher = inputString("Введите название издательства для поиска газет и журналов в списке: ");
					list->findByPublisher(publisher);
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Сортировать газеты и журналы в порядке возрастания по подписному индексу
				case 13:
					//system("CLS");
					list->sortBySubscriptionIndex();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Сортировать газеты и журналы в порядке возрастания по названию
				case 14:
					//system("CLS");
					list->sortByName();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				// Сохранить список в файл
				case 15:
					//system("CLS");
					list->saveList();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
				
				
				// Считать список из файла
				case 16:
					//system("CLS");
					list->clearList();
					list->readList();
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;

		        // Ошика выбора пункта меню
				default:
					//system("CLS");
					cout << "Неверный пункт меню!" << endl;
					cout << endl << "Для продолжения работы, нажмите на любую клавишу ... ";
					_getch();
					break;
			}
/*
			break;
		}
*/
	}
}
