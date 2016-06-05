// TIMPlab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class BinaryTree
{
private:
	vector<int> tree;
public:
	void add(int value);
	void orderTree(int i);
	void del();
	int get() const { return tree[0]; }
	void show() const;
};

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

int main(int argc, char* argv[])
{
	BinaryTree tree;
	string command;
	vector<string> commands;
	int N;
	int i = 0;
	int size;
	cout << "N = ";
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (i < N && i >= 0)
	{
		cout << i + 1 << ">>";
		getline(cin, command);
		commands = split(command, ' ');
		size = commands.size();
		if (size == 0)
		{
			cout << "Wrong command.\n";
			i--;
		}
		else if (size == 2)
		{
			if (commands[0] == "add")
				tree.add(stoi(commands[1]));
			else
			{
				cout << "Wrong command.\n";
				i--;
			}
		}
		else if (size == 1)
		{
			try
			{
				if (commands[0] == "del")
					tree.del();
				else if (commands[0] == "get")
					cout << tree.get() << endl;
				else if (commands[0] == "show")
				{
					tree.show();
					cout << endl;
				}
				else
				{
					cout << "Wrong command.\n";
					i--;
				}
			}
			catch (char* message)
			{
				cout << message << endl;
			}
		}
		else
		{
			cout << "Wrong command.\n";
			i--;
		}
		i++;
	}
	system("pause");
	return 0;
}

void BinaryTree::add(int value)
{
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
}

void BinaryTree::orderTree(int i)
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

		int temp = tree[i];
		tree[i] = tree[leastChild];
		tree[leastChild] = temp;
		i = leastChild;
	}
}

void BinaryTree::del()
{
	if (tree.size() == 0)
		throw "Tree is empty";

	int result = tree[0];
	tree[0] = tree[tree.size() - 1];
	tree.erase(tree.begin() + tree.size() - 1);

	for (int i = tree.size() / 2; i >= 0; i--)
		orderTree(i);
}

void BinaryTree::show() const
{
	for (int i = 0; i < tree.size(); i++)
		cout << tree[i] << "  ";
}
