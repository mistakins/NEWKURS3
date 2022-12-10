#include "struct.h"

class ListNewspaper {

private:

    // Элемент списка
	class Node
	{
	public:
		Newspaper* data; // Полезные данные элемента списка
		Node* next;      // Указатель на следующий элемент списка
		Node* prev;      // Указатедь на предыдущий элемент списка


		// Конструктор
		Node(Newspaper* data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}


		// Деструктор
		~Node() {
			delete data;
		}
	};

	// ********************************************************************************************

    // Формуляр списка
	Node* head; // "Голова" (начало) списка
	Node* tail; // "Хвост" (конец) списка

public:

	// Конструктор
	ListNewspaper() { // intialize the first object
		head = nullptr;
		tail = nullptr;
	}


    // Деструктор
	~ListNewspaper() { // clear all elements
		clearList();
	}


	// Подсчитать количество элементов в списке
	size_t getSize() {
		Node* cur = head;
		size_t size = 0;
		while (cur != nullptr)
		{
			size++;
			cur = cur->next;
		}
		return size;
	}


    // Проверить на пустоту списка
	bool isEmpty() {
		return (getSize() == 0);
	}
	
	
	// Добавить элемент в начало списка
	void pushFront(Newspaper* data) {
		size_t size = getSize();
		if (size > 1)
		{
			Node* cur = head;
			head = new Node(data, head);
			cur->prev = head;
		}
		else if (size == 1)
		{
			head = new Node(data, head); // creating a new head element
			tail->prev = this->head; // at the tail, we put the previous on the new element
		}
		else
		{
			head = tail = new Node(data);
		}
		cout << endl << "Элемент был добавлен в начало списка." << endl;
	}
	
	
	// Добавить элемент в конец списка
	void pushBack(Newspaper* data) {
		size_t size = getSize();
		if (size > 1)
		{
			Node* cur = tail;
			tail = new Node(data, nullptr, tail);
			cur->next = tail;
		}
		else if (size == 1)
		{
			tail = new Node(data, nullptr, tail);
			head->next = this->tail;
		}
		else
		{
			head = tail = new Node(data);
		}
		cout << endl << "Элемент был добавлен в конец списка." << endl;
	}
	
	
	// Добавить элемент в список (по порядковому номеру)
	void insert(Newspaper* data, size_t index) {
		index--;
		size_t size = getSize();
		if ((index <= size) && (index >= 0))
		{
			if (index == 0) pushFront(data);
			else if (index == size) pushBack(data);
			else if (index <= size / 2)
			{ // if the head is closer
				Node* previous = this->head; //creating a node with the adress of the head
				for (int i = 0; i < index - 1; i++)
				{ // walk from the head to the node that point to the one we need
					previous = previous->next;
				}
				Node* newNode = new Node(data, previous->next, previous); // creating a new node
				previous->next = newNode;
				Node* pNext = newNode->next;
				pNext->prev = newNode;
				cout << endl << "Элемент был добавлен в список." << endl;
			}
		}
		else if (index > size / 2)
		{ // all the tail is closer
			Node* pNext = this->tail;
			for (int i = size - 1; i > index; i--)
			{
				pNext = pNext->prev;
			}
			Node* newNode = new Node(data, pNext, pNext->prev); // creating a new node
			pNext->prev = newNode;
			Node* previous = newNode->prev;
			previous->next = newNode;
			cout << endl << "Элемент был добавлен в список." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	
	
	// Вывести список на экран
	void showList() {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << ": " << endl; // вывод на экран для пользователя порядкого номера элемента без 0
				cur->data->showNewspaper();
				cout << endl; // добавить красивый разделитель между элементами списка
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}


	// Получить элемент списка по порядковому номеру
	Newspaper* get(size_t index) {
		index--;
		size_t size = getSize();
		if ((index < size) && (index >= 0))
		{
			Node* cur = head;
			for (int i = 0; i < index; i++)
			{
				cur = cur->next;
			}
			return cur->data;
		}
		else
		{
			// throw std::invalid_argument("Index is out of range");
			return nullptr;
		}
	}

	// ********************************************************************************************

	// Отредактировать элемент списка (по порядковому номеру)
	void set(size_t index) {
		index--;
		size_t size = getSize();
		if ((index < size) && (index >= 0))
		{
				Node* cur = this->head;
				for (int i = 0; i < index; i++)
				{
					cur = cur->next;
				}
				cur->data->editNewspaper();
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}

	// ********************************************************************************************

	// Удалить элемент из начала списка
	void popFront() {
		size_t size = getSize();
		if (!isEmpty())
		{
			if (size > 1)
			{
				Node* cur = head;
				head = head->next;
				delete cur;
			}
			else if (size == 1)
			{
				Node* cur = head;
				tail = head = head->next;
				delete cur;
			}
			cout << endl << "Элемент был удалён из начала списка." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}


	// Удалить элемент из конца списка
	void popBack() {
		size_t size = getSize();
		if (!isEmpty())
		{
			if (size > 1)
			{
				Node* item = tail->prev;
				delete tail;
				tail = item;
				tail->next = nullptr;
			}
			else if (size == 1)
			{
				delete head;
				head = tail = nullptr;
			}
			cout << endl << "Элемент был удалён из конца списка." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	

	// Удалить элемент из списка (по порядковому номеру)
	void remove(size_t index) {
		index--;
		size_t size = getSize();
		if ((index < size) && (index >= 0))
		{
			if (index == 0) popFront();
			else if (index == size - 1) popBack();
			else if (index <= size / 2)
			{ // if the head is closer
				Node* previous = this->head;
				for (int i = 0; i < index - 1; i++)
				{
					previous = previous->next;
				}
				Node* toDelete = previous->next;
				previous->next = toDelete->next;
				Node* pNext = toDelete->next;
				pNext->prev = previous;
				delete toDelete;
			}
			else if (index > size / 2)
			{ // if the tail is closer
				Node* pNext = this->tail;
				for (int i = size - 1; i > index - 1; i--)
				{
					pNext = pNext->prev;
				}
				Node* toDelete = pNext->prev;
				pNext->prev = toDelete->prev;
				Node* previous = toDelete->prev;
				previous->next = pNext;
				delete toDelete;
			}
			cout << endl << "Элемент был удалён из списка." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	

	// Очистить список
	void clearList() { // deleting all list items
		size_t size = getSize();
		while (size > 0)
		{
			popFront();
			size--;
		}
		cout << endl << "Список очищен." << endl;
	}


	// ********************************************************************************************

	// Найти газету или журнал по названию
	void findByName(string name) {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				if (cur->data->name == name)
				{ // можно заменить равенство на функцию поиска подстроки в string - кажется, это функция substring()
					cur->data->showNewspaper();
					cout << endl; // красивый разделитель между элементами списка
					break; // оставить эту команду в случае если равенство будет строгое (==)
				}
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// Найти газету или журнал по издательству
	void findByPublisher(string publisher) {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				if (cur->data->publisher == publisher)
				{ // можно заменить равенство на функцию поиска подстроки в string - кажется, это функция substring()
					cur->data->showNewspaper();
					cout << endl; // красивый разделитель между элементами списка
					break; // оставить эту команду в случае если равенство будет строгое (==)
				}
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// Сортировать газеты и журналы в порядке возрастания по подписному индексу
	void sortBySubscriptionIndex() {
/*
		size_t size = getSize();
		Node* left = head;
		Node* right = tail;
		size_t middle = size / 2;
		while (left <= right) {
			while (left < middle) left = left->next;
			while (right > middle) right = right->prev;
			if (left->data->subscriptionIndex > right->data->subscriptionIndex) {
				//внутри условия идет простой обмен ячеек data
				Newspaper* tmp = left->data;
				left->data = right->data;
				right->data = tmp;
			}
		}
*/
        // Реализован алгоритм "пузярькоковй сортировки по размеру списка - оптимизировать число "прогонов" списка
		size_t size = getSize();
		if (size > 0)
		{
			for (int i = 0; i < size; i++) // возможно, нужно подправить начальные и конечные условия
			{
				// int flag = 0;
				Node* cur = head;
				for (int j = 0; j < (size - 1); j++) // возможно, нужно подправить начальные и конечные условия
				{
					if (cur->data->subscriptionIndex > cur->next->data->subscriptionIndex)
					{
						Newspaper* temp = cur->data;
						cur->data = cur->next->data;
						cur->next->data = temp;
						// flag = 1;
					}
					cur = cur->next;
				}
				// if (flag == 0) break;
			}
			cout << endl << "Список был отсортирован." << endl;
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// Сортировать газеты и журналы в порядке возрастания по названию
	void sortByName() {
/*
		size_t size = getSize();
		Node* leftCur = head;
		Node* rightCur = tail;
		size_t middle = size / 2;
		while ()
		{
			leftCur = head; // ?
			for (size_t i = 0; i < middle; i++)
			{
			   leftCur = leftCur->next;
			   rightCur = tail; // ?
			   for (size_t j = size-1; j > middle; j--)
			   {
			     rightCur = rightCur->prev;
			     if (leftCur->data->name > rightCur->data->name)
				 {
				   Newspaper* tmp = leftCur->data;
				   leftCur->data = rightCur->data;
				   rightCur->data = tmp;
			     }
			  }
			}
		}
*/
        // Реализован алгоритм "пузярькоковй сортировки по размеру списка - оптимизировать число "прогонов" списка
		size_t size = getSize();
		if (size > 0)
		{
			for (int i = 0; i < size; i++) // возможно, нужно подправить начальные и конечные условия
			{
				// int flag = 0;
				Node* cur = head;
				for (int j = 0; j < (size - 1); j++) // возможно, нужно подправить начальные и конечные условия
				{
					if (cur->data->name > cur->next->data->name)
					{
						Newspaper* temp = cur->data;
						cur->data = cur->next->data;
						cur->next->data = temp;
						// flag = 1;
					}
					cur = cur->next;
				}
				// if (flag == 0) break;
			}
			cout << endl << "Список был отсортирован." << endl;
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}


	// ********************************************************************************************

	
	// Сохранить список в файл
	void saveList() {
		size_t size = getSize();
		if (size > 0)
		{
			string path = checkOutputFile();
			ofstream fout;
			fout.open(path);

			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				cur->data->saveNewspaper(fout);
				fout << endl; // красивый разделитель между элементами списка
				cur = cur->next;
			}

			fout.close();

			cout << endl << "Список был сохранён в файл." << endl;
		}
		else
		{
			cout << endl << "Список пустой!" << endl;
		}
	}
	
	
	// Считать список из файла
	void readList() {
		string path = checkOpenFile();
		ifstream fin;
		fin.open(path);

		Node* cur = head;
		while (!fin.eof())
		{
			Newspaper* data = new Newspaper();
			data->readNewspaper(fin);
			pushBack(data);
			string line;
			if (!fin.eof())
			{
				getline(fin, line);
			}
		}

		fin.close();

		cout << endl << "Список был считан из файла." << endl;
	}

	// ********************************************************************************************

/*
	void saveList() {
	в аргументе функции предусмотреть имя файла куда нужно сохранить список,
	или его можно ввести внутри функции
	при вводе имени файла проверять существования пути (взять готовую функцию из второго семестра)
	код функции аналогичен showList - только в файл не нужно выводить индекс элемента
	}

	void saveList() {
		size_t size = getSize();
		if (size > 0) {
			Node* cur = head;
			for (int i = 0; i < size; i++) {
				cout << i + 1; // вывод на экран для пользователя порядкого номера элемента без 0
				cur->data->showNewspaper();
				cout << endl; // красивый разделитель между элементами списка
				cur = cur->next;
			}
		}
		else throw std::invalid_argument("The list is empty");
	}

	void readList() {
	в аргументе функции предусмотреть имя файла откуда нужно считать список,
	или его можно ввести внутри функции
	при вводе имени файла проверять существования пути (взять готовую функцию из второго семестра)
	код функции немного аналогичен showList - только из файла не нужно считывать индекс элемента
	чтобы понять где заканчивается считывание списка, это можно реализовать тремя способами:
	или предварительно считать все строчки файла до его конца - и, на основании этого, опредить размер списка (число считанных строк по getline до eof() делить на 7 - это кол-во элементов списка)
	или считать с первой строки файла размер списка, а затем через цикл for с помощью getline считывать по очереди все элементы списка (по отдельным полям)
	или сразу же ставить цикл считывания строк файла до eof() - и, при этом, сразу же добавлять новый элемент в конец списка после считывания очередных 6 строк
	при выполнении операции считывания из файла, предварительно все элементы старого списка нужно удалить (очистить список)
	}


	// ******************************************************************************************************************************************************************************************


	void sortBySubscriptionIndex() {
	в качестве алгоритма сортировки можно использовать пузырьковую сортировку (двойной цикл от головы списка),
	или быструю сортировку (разбиение списка пополам по size, а дальше два цикла от головы и хвоста списка друг к другу)
	при сравнении двух элементов списка (представленных указателями cur1 и cur2) условия сравнения записываются так:
		if (cur1->data->subscriptionIndex > cur2->data->subscriptionIndex) {
			внутри условия идет простой обмен ячеек data
			Newspaper* tmp = cur1->data;
			cur1->data = cur2->data;
			cur2->data = tmp;
		}
	}

	void sortByName() {
	код функции такой же как выше - только внутри условия сравнения выбирается поле name
	}
*/

};
