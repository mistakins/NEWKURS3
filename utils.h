#include <iostream>
//#include <cstdio>
#include <fstream>
#include <string>
//#include <string.h>
//#include <cstring>
#include <windows.h>
#include <conio.h>
//#include <ConIO.h>
#include <wincon.h>
#include <stdexcept>

using namespace std;

// ********************************************************************

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(hStdOut, { x, y });
}


void ConsoleCursorVisible(bool show, short size) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

// ********************************************************************

int inputInt(string prompt) {
	int value = 0;
	cout << prompt;
	if (!(cin >> value))
	{
		cout << "Incorrect number!\n";
		cin.clear();
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin.ignore(BUFSIZ, '\n');
		inputInt(prompt);
	}
	else
	{
		cin.clear();
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin.ignore(BUFSIZ, '\n');
		return value;
	}
}


int inputInt(ifstream &fin) {
	string word = "";
	int value = 0;
	if (!fin.eof())
	{
		getline(fin, word);
	}
	if (!(value = stoi(word)))
	{
		value = 0;
	}
	return value;
}


int inputInt(string prompt, int min)
{
	int value = 0;
	cout << prompt;
	if ((!(cin >> value)) || (value < min))
	{
		cout << "Incorrect number!\n";
		cin.clear();
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin.ignore(BUFSIZ, '\n');
		inputInt(prompt);
	}
	else
	{
		cin.clear();
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin.ignore(BUFSIZ, '\n');
		return value;
	}
}


int inputInt(ifstream& fin, int min) {
	string word = "";
	int value = 0;
	if (!fin.eof())
	{
		getline(fin, word);
	}
	if ((!(value = stoi(word))) || (value < min))
	{
		value = min;
	}
	return value;
}


size_t inputIndex(string prompt) {
	size_t index = inputInt(prompt);
	return index;
}


string inputString(string prompt) {
	string word = "";
	cout << prompt << endl;
	getline(cin, word);
	return word;
}


string inputString(ifstream &fin) {
	string word = "";
	if (!fin.eof())
	{
		getline(fin, word);
	}
	return word;
}

// ********************************************************************

string inputFilename(string prompt) {
	string filename = inputString(prompt);
	if (filename == "") {
		cout << "Incorrect file name!" << endl;
		inputFilename(prompt);
	}
	else {
		return filename;
	}
}


string checkOpenFile() {
	string path = inputFilename("Введите имя файла: ");
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		fin.open(path);
		fin.close();
		return path;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Не удалось открыть файл для чтения!" << endl;
		checkOpenFile();
	}
}


string checkOutputFile() {
	string path = inputFilename("Введите имя файла: ");
	ofstream fout;
	fout.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		fout.open(path);
		fout.close();
		return path;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Не удалось открыть файл для записи!" << endl;
		checkOutputFile();
	}
}
