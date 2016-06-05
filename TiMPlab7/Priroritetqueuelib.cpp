// Priroritetqueuelib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#pragma once
#include <vector>

#define EXPORT __declspec(dllexport)

using namespace std;

__interface EXPORT IQueue
{
	void create(int size);
	bool add(int value);
	int get();
	bool del();
};

class PrioritetQueue : public IQueue
{
private:
	vector<int> tree;
	int size;
public:
	void create(int size) { size = size; }
	bool add(int value);
	void orderTree(int i);
	bool del();
	int get() { return tree[0]; }
};

extern "C"
{
	__declspec(dllexport) IQueue* GetIQueue();
}

IQueue * GetIQueue()
{
	return new PrioritetQueue();
}

bool PrioritetQueue::add(int value)
{
	if (tree.size() == size)
		return false;

	tree.push_back(value);
	int i = tree.size() - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && tree[parent] > tree[i])
	{
		int temp = tree[i];
		tree[i] = tree[parent];
		tree[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
	return true;
}

void PrioritetQueue::orderTree(int i)
{
	int leftChild;
	int rightChild;
	int leastChild;

	while (true)
	{
		leftChild = 2 * i + 1;
		rightChild = 2 * i + 2;
		leastChild = i;

		if (leftChild < tree.size() && tree[leftChild] < tree[leastChild])
			leastChild = leftChild;

		if (rightChild < tree.size() && tree[rightChild] < tree[leastChild])
			leastChild = rightChild;

		if (leastChild == i)
			break;

		int temp =tree[i];
		tree[i] = tree[leastChild];
		tree[leastChild] = temp;
		i = leastChild;
	}
}

bool PrioritetQueue::del()
{
	if (tree.size() == 0)
		return false;

	int result = tree[0];
	tree[0] = tree[tree.size() - 1];
	tree.erase(tree.begin() + tree.size() - 1);

	for (int i = tree.size() / 2; i >= 0; i--)
		orderTree(i);
	return true;
}

