// Spisok.cpp: определяет точку входа для консольного приложения.
//

#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class spisok
{
public:
	int data;
	int n;
	spisok* next;
	spisok(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
	}
};

spisok* ph = 0;
spisok* prosmotr = 0;


void add(int a, spisok* b)
{
	if ((a == 0) && (ph == 0))
	{
		ph = b;
		return;
	}

	if ((a != 0) && (ph == 0))
	{
		ph = new spisok(0, 0);
	}

	if ((a == 0) && (ph != 0))
	{
		prosmotr = ph;
		ph = b;
		ph->next = prosmotr;
		prosmotr->n++;
		while (prosmotr->next != 0)
		{
			prosmotr = prosmotr->next;
			prosmotr->n++;
		}
		return;
	}

	prosmotr = ph;
	while (prosmotr->n != (a - 1))
	{
		if (prosmotr->next == 0) prosmotr->next = new spisok(0, prosmotr->n + 1);
		else prosmotr = prosmotr->next;
	}
	b->next = prosmotr->next;
	prosmotr->next = b;
	//b->n = prosmotr->n+1 ;
	prosmotr = prosmotr->next;
	while (prosmotr->next != 0)
	{
		prosmotr = prosmotr->next;
		prosmotr->n++;
	}

}

void get(int a)
{
	prosmotr = ph;
	while (prosmotr->n != a)
	{
		prosmotr = prosmotr->next;
	}
	cout << prosmotr->data << endl;
}

void del(int a)
{
	prosmotr = ph;
	if (a == 0)
	{
		ph = prosmotr->next;
		prosmotr = ph;
		prosmotr->n--;
	}
	else
	{
		while (prosmotr->n != a - 1)
		{
			prosmotr = prosmotr->next;
		}
		spisok* q;
		q = prosmotr->next;
		prosmotr->next = q->next;
	}
	while (prosmotr->next != 0)
	{
		prosmotr = prosmotr->next;
		prosmotr->n--;
	}
}

int main()
{
	int count;
	cin >> count;
	string dev;
	int l, h;
	for (int i = 0; i < count; i++)
	{
		cin >> dev;
		if (dev == "add")
		{
			cin >> l;
			cin >> h;
			spisok* sad;
			sad = new spisok(h, l);
			add(l, sad);
		}
		if (dev == "get")
		{
			cin >> l;
			get(l);
		}
		if (dev == "del")
		{
			cin >> l;
			del(l);
		}
	}
	return 0;
}


