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
class ochered
{
public:
	int data;
	int n;
	ochered* next;
	ochered(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
		ss++;
	}
};

ochered* ph = 0;
ochered* prosmotr = 0;



void add(int a, ochered* b)
{
	if ((a == 0) && (ph == 0))
	{
		ph = b;
		return;
	}
	prosmotr = ph;
	while (prosmotr->n != (a - 1))
	{
		if (prosmotr->next == 0) prosmotr->next = new ochered(0, prosmotr->n + 1);
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
		ochered* q;
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
	int count;
	cin >> count;
	string dev;
	int l, h;
	for (int i = 0; i < count; i++)
	{
		cin >> dev;
		if (dev == "add")
		{
			cin >> h;
			ochered* sad;
			sad = new ochered(h, ss);
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


