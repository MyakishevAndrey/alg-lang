// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
//

// очередь

#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int ss = 0;
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
		ss++;
	}
};

spisok* phead = 0;
spisok* prosmotr = 0;



void add(int a, spisok* b)
{
	if ((a == 0) && (phead == 0))
	{
		phead = b;
		return;
	}
	prosmotr = phead;
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
	prosmotr = phead;
	while (prosmotr->n != a)
	{
		prosmotr = prosmotr->next;
	}
	cout << prosmotr->data << endl;
}

void del(int a)
{
	prosmotr = phead;
	if (a == 0)
	{
		phead = prosmotr->next;
		prosmotr = phead;
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
	ss--;
}

int main()
{
	int kol;
	cin >> kol;
	string dev;
	int l, h;
	for (int i = 0; i < kol; i++)
	{
		cin >> dev;
		if (dev == "add")
		{
			cin >> h;
			spisok* sad;
			sad = new spisok(h, ss);
			add(ss - 1, sad);
		}
		if (dev == "get")
		{
			get(0);
		}
		if (dev == "del")
		{
			del(0);
		}
	}
	return 0;
}


