#pragma once
#include "iostream"
#include "string"
#include "fstream"
using namespace std;
class Station {
private:
	string name;
	int line = 0;
	int number = 0;
public:
	friend ifstream& operator >> (ifstream& InputFile, Station& stations) {
		InputFile >> stations.name >> stations.line >> stations.number;
		return InputFile;
	}
	void ReadFile(Station* stations) {
		ifstream inputFile("dbase.txt");

		if (!inputFile.is_open()) {
			cout << "(1) Не открывается файл, брат( Проверь название, там накосячил" << endl;
			cout << "------------------------------------------------------------------" << endl;
			exit;
		}

		//inputFile.ignore(numeric_limits<streamsize>::max(), '\n'); // игнор первой строки

		for (int i = 0; !inputFile.eof(); i++) {
			inputFile >> stations[i]/*.Read(inputFile)*/;
		}
		cout << "(1) Добро брат, прочиталось)" << endl;
		cout << "------------------------------------------------------------------" << endl;

		inputFile.close();
	}
	void GetLineData(int line1, Station* stations, int count) {
		for (int i = 0; i < count; i++) {
			if (stations[i].line == line1) {
				cout << endl << stations[i].name << ' ' << stations[i].number;
			}
		}
	}
	
	void OneLineStationsRoad(Station* arr, int count) {
		string name1;
		string name2;
		cout << "Write your st.: ";
		cin >> name1;
		cout << "Write wich st. you need: ";
		cin >> name2;
		int id1 = 0, id2 = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i].name == name1) {
				id1 = arr[i].number - 1;
			}
		}
		for (int i = 0; i < count; i++) {
			if (arr[i].name == name2) {
				id2 = arr[i].number - 1;
			}
		}

		if (id1 < id2) {
			cout << "Your St. is: " << arr[id1].name << endl;
			cout << "Your rail is: ";
			while (id1 != id2) {
				cout << arr[id1 + 1].name;
				id1++;
				if (id1 != id2) {
					cout << ", ";
				}
			}
		}
		if (id2 < id1) {
			cout << "Your St. is: " << arr[id1].name << endl;
			cout << "Your rail is: ";
			while (id2 != id1) {
				cout << arr[id1 - 1].name;
				id1--;
				if (id2 != id1) {
					cout << ", ";
				}
			}
		}
	}
};