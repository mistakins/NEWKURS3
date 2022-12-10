#include "struct.h"

class ListNewspaper {

private:

    // ������� ������
	class Node
	{
	public:
		Newspaper* data; // �������� ������ �������� ������
		Node* next;      // ��������� �� ��������� ������� ������
		Node* prev;      // ��������� �� ���������� ������� ������


		// �����������
		Node(Newspaper* data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}


		// ����������
		~Node() {
			delete data;
		}
	};

	// ********************************************************************************************

    // �������� ������
	Node* head; // "������" (������) ������
	Node* tail; // "�����" (�����) ������

public:

	// �����������
	ListNewspaper() { // intialize the first object
		head = nullptr;
		tail = nullptr;
	}


    // ����������
	~ListNewspaper() { // clear all elements
		clearList();
	}


	// ���������� ���������� ��������� � ������
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


    // ��������� �� ������� ������
	bool isEmpty() {
		return (getSize() == 0);
	}
	
	
	// �������� ������� � ������ ������
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
		cout << endl << "������� ��� �������� � ������ ������." << endl;
	}
	
	
	// �������� ������� � ����� ������
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
		cout << endl << "������� ��� �������� � ����� ������." << endl;
	}
	
	
	// �������� ������� � ������ (�� ����������� ������)
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
				cout << endl << "������� ��� �������� � ������." << endl;
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
			cout << endl << "������� ��� �������� � ������." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	
	
	// ������� ������ �� �����
	void showList() {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << ": " << endl; // ����� �� ����� ��� ������������ ��������� ������ �������� ��� 0
				cur->data->showNewspaper();
				cout << endl; // �������� �������� ����������� ����� ���������� ������
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}


	// �������� ������� ������ �� ����������� ������
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

	// ��������������� ������� ������ (�� ����������� ������)
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

	// ������� ������� �� ������ ������
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
			cout << endl << "������� ��� ����� �� ������ ������." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}


	// ������� ������� �� ����� ������
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
			cout << endl << "������� ��� ����� �� ����� ������." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	

	// ������� ������� �� ������ (�� ����������� ������)
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
			cout << endl << "������� ��� ����� �� ������." << endl;
		}
		else
		{
			cout << endl << "Index is out of range" << endl;
		}
	}
	

	// �������� ������
	void clearList() { // deleting all list items
		size_t size = getSize();
		while (size > 0)
		{
			popFront();
			size--;
		}
		cout << endl << "������ ������." << endl;
	}


	// ********************************************************************************************

	// ����� ������ ��� ������ �� ��������
	void findByName(string name) {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				if (cur->data->name == name)
				{ // ����� �������� ��������� �� ������� ������ ��������� � string - �������, ��� ������� substring()
					cur->data->showNewspaper();
					cout << endl; // �������� ����������� ����� ���������� ������
					break; // �������� ��� ������� � ������ ���� ��������� ����� ������� (==)
				}
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// ����� ������ ��� ������ �� ������������
	void findByPublisher(string publisher) {
		size_t size = getSize();
		if (size > 0)
		{
			Node* cur = head;
			for (int i = 0; i < size; i++)
			{
				if (cur->data->publisher == publisher)
				{ // ����� �������� ��������� �� ������� ������ ��������� � string - �������, ��� ������� substring()
					cur->data->showNewspaper();
					cout << endl; // �������� ����������� ����� ���������� ������
					break; // �������� ��� ������� � ������ ���� ��������� ����� ������� (==)
				}
				cur = cur->next;
			}
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// ����������� ������ � ������� � ������� ����������� �� ���������� �������
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
				//������ ������� ���� ������� ����� ����� data
				Newspaper* tmp = left->data;
				left->data = right->data;
				right->data = tmp;
			}
		}
*/
        // ���������� �������� "������������ ���������� �� ������� ������ - �������������� ����� "��������" ������
		size_t size = getSize();
		if (size > 0)
		{
			for (int i = 0; i < size; i++) // ��������, ����� ���������� ��������� � �������� �������
			{
				// int flag = 0;
				Node* cur = head;
				for (int j = 0; j < (size - 1); j++) // ��������, ����� ���������� ��������� � �������� �������
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
			cout << endl << "������ ��� ������������." << endl;
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}
	
	
	// ����������� ������ � ������� � ������� ����������� �� ��������
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
        // ���������� �������� "������������ ���������� �� ������� ������ - �������������� ����� "��������" ������
		size_t size = getSize();
		if (size > 0)
		{
			for (int i = 0; i < size; i++) // ��������, ����� ���������� ��������� � �������� �������
			{
				// int flag = 0;
				Node* cur = head;
				for (int j = 0; j < (size - 1); j++) // ��������, ����� ���������� ��������� � �������� �������
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
			cout << endl << "������ ��� ������������." << endl;
		}
		else
		{
			cout << endl << "The list is empty" << endl;
		}
	}


	// ********************************************************************************************

	
	// ��������� ������ � ����
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
				fout << endl; // �������� ����������� ����� ���������� ������
				cur = cur->next;
			}

			fout.close();

			cout << endl << "������ ��� ������� � ����." << endl;
		}
		else
		{
			cout << endl << "������ ������!" << endl;
		}
	}
	
	
	// ������� ������ �� �����
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

		cout << endl << "������ ��� ������ �� �����." << endl;
	}

	// ********************************************************************************************

/*
	void saveList() {
	� ��������� ������� ������������� ��� ����� ���� ����� ��������� ������,
	��� ��� ����� ������ ������ �������
	��� ����� ����� ����� ��������� ������������� ���� (����� ������� ������� �� ������� ��������)
	��� ������� ���������� showList - ������ � ���� �� ����� �������� ������ ��������
	}

	void saveList() {
		size_t size = getSize();
		if (size > 0) {
			Node* cur = head;
			for (int i = 0; i < size; i++) {
				cout << i + 1; // ����� �� ����� ��� ������������ ��������� ������ �������� ��� 0
				cur->data->showNewspaper();
				cout << endl; // �������� ����������� ����� ���������� ������
				cur = cur->next;
			}
		}
		else throw std::invalid_argument("The list is empty");
	}

	void readList() {
	� ��������� ������� ������������� ��� ����� ������ ����� ������� ������,
	��� ��� ����� ������ ������ �������
	��� ����� ����� ����� ��������� ������������� ���� (����� ������� ������� �� ������� ��������)
	��� ������� ������� ���������� showList - ������ �� ����� �� ����� ��������� ������ ��������
	����� ������ ��� ������������� ���������� ������, ��� ����� ����������� ����� ���������:
	��� �������������� ������� ��� ������� ����� �� ��� ����� - �, �� ��������� �����, �������� ������ ������ (����� ��������� ����� �� getline �� eof() ������ �� 7 - ��� ���-�� ��������� ������)
	��� ������� � ������ ������ ����� ������ ������, � ����� ����� ���� for � ������� getline ��������� �� ������� ��� �������� ������ (�� ��������� �����)
	��� ����� �� ������� ���� ���������� ����� ����� �� eof() - �, ��� ����, ����� �� ��������� ����� ������� � ����� ������ ����� ���������� ��������� 6 �����
	��� ���������� �������� ���������� �� �����, �������������� ��� �������� ������� ������ ����� ������� (�������� ������)
	}


	// ******************************************************************************************************************************************************************************************


	void sortBySubscriptionIndex() {
	� �������� ��������� ���������� ����� ������������ ����������� ���������� (������� ���� �� ������ ������),
	��� ������� ���������� (��������� ������ ������� �� size, � ������ ��� ����� �� ������ � ������ ������ ���� � �����)
	��� ��������� ���� ��������� ������ (�������������� ����������� cur1 � cur2) ������� ��������� ������������ ���:
		if (cur1->data->subscriptionIndex > cur2->data->subscriptionIndex) {
			������ ������� ���� ������� ����� ����� data
			Newspaper* tmp = cur1->data;
			cur1->data = cur2->data;
			cur2->data = tmp;
		}
	}

	void sortByName() {
	��� ������� ����� �� ��� ���� - ������ ������ ������� ��������� ���������� ���� name
	}
*/

};
