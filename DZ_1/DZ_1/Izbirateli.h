#pragma once

#include "resource.h"
#include "stdafx.h"
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Izbiratel {
private:
	string name;
	bool voited;
	int choice;
	int ID;
public:
	Izbiratel() {
		name = "";
		voited = false;
		choice = 0;
		ID = rand();
	}
	Izbiratel(const Izbiratel& c) {
		name = c.name;
		voited = false;
		choice = c.choice;
		ID = c.ID;
	}
	Izbiratel(string n, int v) {
		name = n;
		voited = false;
		choice = v;
		ID = rand();
	}

	void setName(string n) {
		name = n;
	}
	void setChoice(int ch) {
		choice = ch;
		voited = true;
	}

	string getName() {
		return name;
	}

	int getChoice() {
		return choice;
	}

	int getID() {
		return ID;
	}

	friend ostream& operator << (ostream& os, const Izbiratel& izb) {
		os << "Избиратель № " << izb.ID << endl;
		os << "Имя: " << izb.name << endl;
		os << "Выбор: ";
		if (izb.choice) {
			cout << izb.choice << endl;
		}
		else {
			cout << "выбор не сделан" << endl;
		}
		return os;
	}
	friend istream& operator >> (istream& is, Izbiratel& izb) {
		cout << "Введите имя избирателя: ";
		cin >> izb.name;
		cout << "Введите номер выбора избирателя (0, если избиратель не голосовал): ";
		cin >> izb.choice;
		srand(time(0));
		izb.ID = rand();
	}

	friend ofstream& operator << (ofstream& ofs, const Izbiratel& izb) {
		ofs << izb.ID << endl;
		ofs << izb.name << endl;
		ofs << izb.choice;
		return ofs;
	}

	friend ifstream& operator >> (ifstream& ifs, Izbiratel& izb) {
		ifs >> izb.ID;
		ifs >> izb.name;
		ifs >> izb.choice;
		return ifs;
	}

};

class Uchastok : public vector<Izbiratel>
{
	int num;
	string name;
	long int max;
	long int cur;

public:
	Uchastok() {
		num = 0;
		name = "";
		max = 0;
		cur = 0;
	}

	Uchastok(int n, string nam, long int m, long int c) {
		num = n;
		nam = name;
		max = m;
		cur = c;
	}

	//Ввести набор избирателей
	void Add(vector<Izbiratel>& v) {
		clear();
		reserve(v.size);
		for (int i = 0; i < v.size(); i++) {
			at(i) = v[i];
		}
	}

	void Add(Izbiratel izb) {
		push_back(izb);
	}

	void Remove(int ID) {
		for (int i = 0; i < size(); i++) {
			if (at(i).getID() == ID) {
				erase(begin() + i);
			}
		}
	}

	int FindByName(string name) {
		for (int i = 0; i < size(); i++) {
			if (at(i).getName() == name) {
				return at(i).getID();
			}
		}
	}

	void Join(Uchastok& uch2) {
		for (int i = 0; i < uch2.size(); i++) {
			at(size() + i) = uch2[i];
		}
		uch2.clear();
	}
};