// TIMPlab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int A;
	int B;
	cin >> A;
	cin >> B;
	int N;
	cin >> N;
	bool* visited;
	visited = new bool[A];

	int* distanc;
	distanc = new int[A];

	int** graf;
	graf = new int*[A];
	for (int i = 0; i < A; i++)
	{
		graf[i] = new int[A];
	}
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++)
		{
			graf[i][j] = 0;

		}
	}
	for (int i = 0; i < B; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		cin >> graf[v1][v2];
	}
	for (int i = 0; i<A; i++)
	{
		distanc[i] = INT_MAX; visited[i] = false;
	}

	distanc[N] = 0;

	int u = 0;
	for (int i = 0; i<A - 1; i++)
	{

		int min = INT_MAX;
		for (int i = 0; i < A; i++)
		{
			if (!visited[i] && distanc[i] <= min)
			{
				min = distanc[i]; u = i;
			}
		}

		visited[u] = true;
		for (int i = 0; i < A; i++)
		{
			if (!visited[i] && graf[u][i] && (distanc[u] != INT_MAX) && distanc[u] + graf[u][i] < distanc[i])
			{
				distanc[i] = distanc[u] + graf[u][i];
			}
		}
	}

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++)
			cout << graf[i][j] << "  ";
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < A; i++)
		cout << distanc[i] << "  ";
	system("pause");
	return 0;
}
