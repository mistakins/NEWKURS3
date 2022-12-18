#include "utils.h"

struct Newspaper {

	int subscriptionIndex; // Подписной индекс
	string name;           // Название издания
	string publisher;      // Издательство
	int circulation;       // Тираж
	int period;            // Периодичность выхода
	int price;             // Цена


	Newspaper() {
	}


	void inputNewspaper() {
		cout << "Подписной индекс: " << this->subscriptionIndex << endl;
		cout << "Название издания: " << this->name << endl;
		cout << "Издательство: " << this->publisher << endl;
		cout << "Тираж: " << this->circulation << endl;
		cout << "Периодичность выхода: " << this->period << endl;
		cout << "Цена: " << this->price << endl;
	}


	void showNewspaper() {
		cout << "Подписной индекс: : " << this->subscriptionIndex << endl;
		cout << "Название издания: " << this->name << endl;
		cout << "Издательство: " << this->publisher << endl;
		cout << "Тираж: " << this->circulation << endl;
		cout << "Периодичность выхода: " << this->period << endl;
		cout << "Цена: " << this->price << endl;
	}


	void editNewspaper() {
		cout << "Подписной индекс: " << this->subscriptionIndex << endl;
		this->subscriptionIndex = inputInt("Введите подписной индекс: ");

		cout << "Название издания: " << this->name << endl;
		this->name = inputString("Введите название газеты или журнала: ");

		cout << "Издательство: " << this->publisher << endl;
		this->publisher = inputString("Введите издательство: ");

		cout << "Тираж: " << this->circulation << endl;
		this->circulation = inputInt("Введите тираж: ");

		cout << "Периодичность выхода: " << this->period << endl;
		this->period = inputInt("Введите периодичность выхода: ");

		cout << "Цена: " << this->price << endl;
		this->price = inputInt("Введите цену: ");
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
