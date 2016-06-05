// queuelib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#pragma once

#define EXPORT __declspec(dllexport)

__interface EXPORT IQueueLib
{
	void create(int size);
	bool add(int value);
	int get();
	bool del();
};

class QueueLib : public IQueueLib
{
private:
	int* array;
	int start;
	int tail;
	int size;
	int counter;
public:
	void create(int size);
	bool add(int value);
	int get();
	bool del();
};

extern "C"
{
	__declspec(dllexport) IQueueLib* GetIQueueLib();
}

void QueueLib::create(int size)
{
	size = size;
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = 0;
}

bool QueueLib::add(int data)
{
	if (counter == size)
		return false;
	if (tail >= size)
		tail = 0;
	array[tail] = data;
	counter++;
	tail++;
	return true;
}

int QueueLib::get()
{
	return array[start];
}

bool QueueLib::del()
{
	if (counter == 0)
		return false;
	array[start] = 0;
	start++;
	if (start >= size)
		start = 0;
	counter--;
	return true;
}

IQueueLib * GetIQueueLib()
{
	return new QueueLib();
}

