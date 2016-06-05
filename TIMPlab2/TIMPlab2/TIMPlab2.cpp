// TIMPlab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	char a[255];
	string s;
	int i = 1;
	string rezult;
	bool ch = false;
	int pos, k;

	cin >> a;
	ifstream F(a);

	while (getline(F, s)) {
		if (s.find("/**") != string::npos) {
			ch = true;
		}
		pos = s.find("\\func");
		k = s.find("*/");
		if (ch & (pos != string::npos)) {
			if (k != string::npos) {
				cout << i << ". " << s.substr(s.find("\\func") + 6, s.find("*/") - s.find("\\func") - 6) << endl;
				i++;
			}
			string temp = s.substr(s.find("\\func") + 6);
			if (k == string::npos)
			{
				getline(F, s);
				if (s.find("*/") != string::npos) {
					cout << i << ". " << temp << endl;
					i++;
				}
			}
			ch = false;
		}
	}
	system("pause");
	return 0;
}

