#include "utils.h"

struct Newspaper {

	int subscriptionIndex; // ��������� ������
	string name;           // �������� �������
	string publisher;      // ������������
	int circulation;       // �����
	int period;            // ������������� ������
	int price;             // ����


	Newspaper() {
	}


	void inputNewspaper() {
		cout << "��������� ������: " << this->subscriptionIndex << endl;
		cout << "�������� �������: " << this->name << endl;
		cout << "������������: " << this->publisher << endl;
		cout << "�����: " << this->circulation << endl;
		cout << "������������� ������: " << this->period << endl;
		cout << "����: " << this->price << endl;
	}


	void showNewspaper() {
		cout << "��������� ������: " << this->subscriptionIndex << endl;
		cout << "�������� �������: " << this->name << endl;
		cout << "������������: " << this->publisher << endl;
		cout << "�����: " << this->circulation << endl;
		cout << "������������� ������: " << this->period << endl;
		cout << "����: " << this->price << endl;
	}


	void editNewspaper() {
		cout << "��������� ������: " << this->subscriptionIndex << endl;
		this->subscriptionIndex = inputInt("������� ��������� ������: ");

		cout << "�������� �������: " << this->name << endl;
		this->name = inputString("������� �������� ������ ��� �������: ");

		cout << "������������: " << this->publisher << endl;
		this->publisher = inputString("������� ������������: ");

		cout << "�����: " << this->circulation << endl;
		this->circulation = inputInt("������� �����: ");

		cout << "������������� ������: " << this->period << endl;
		this->period = inputInt("������� ������������� ������: ");

		cout << "����: " << this->price << endl;
		this->price = inputInt("������� ����: ");
	}


	void saveNewspaper(ofstream &fout) {
		fout << this->subscriptionIndex << endl;
		fout << this->name << endl;
		fout << this->publisher << endl;
		fout << this->circulation << endl;
		fout << this->period << endl;
		fout << this->price << endl;
	}


	void readNewspaper(ifstream &fin) {
		this->subscriptionIndex = inputInt(fin);
		this->name = inputString(fin);
		this->publisher = inputString(fin);
		this->circulation = inputInt(fin);
		this->period = inputInt(fin);
		this->price = inputInt(fin);
	}


	int getSubscriptionIndex() {
		return this->subscriptionIndex;
	}


	string getName() {
		return this->name;
	}


	string getPublisher() {
		return this->publisher;
	}


	bool compareName(string name) {
		return (this->name == name);
	}


	bool comparePublisher(string publisher) {
		return (this->publisher == publisher);
	}


	bool lessSubscriptionIndex(Newspaper* data) {
		return (this->subscriptionIndex < data->getSubscriptionIndex());
	}


	bool lessName(Newspaper* data) {
		return (this->name < data->getName());
	}

};
