#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cmath>

using namespace std;


template <typename Z >
class matrix {
	Z** T;
	int M;
	int N;
public:
	matrix(int m, int n) : T(NULL), M(m), N(n)
	{
		T = new Z*[M]; //строки в массиве
		for (int i = 0; i < M; i++)
		{
			T[i] = new Z[N]; //  столбцы
			for (int j = 0; j < N; j++)
				T[i][j] = Z();
		}
	}
	Z& operator () (int i, int j)
	{
		return T[i][j];
	}

	friend matrix operator+(matrix& s1, matrix& s2);
	friend matrix operator*(matrix& s1, matrix& s2);
	friend matrix operator~(matrix& s1);

	void print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				cout << T[i][j].get_re() << ", " << T[i][j].get_im() << " | ";
			cout << endl;
		}
		cout << endl;
	}
	~matrix<Z>()
	{

	}

};

template<typename Z>
matrix<Z> operator+(matrix<Z>& s1, matrix<Z>& s2)//перегрузка сложени€ матриц
{
	matrix q(s1.M, s1.N);
	for (int i = 0; i < s1.M; i++)
	{
		for (int j = 0; j < s1.N; j++)
		{
			q(i, j) = s2(i, j) + s1(i, j);
		}
	}
	return q;
}

template<typename Z>
matrix<Z> operator*(matrix<Z>& s1, matrix<Z>& s2)//перегрузка перемножени€ матриц
{
	if (s1.N != s2.M)
		throw "ne pravilnie razmeri";
	matrix g(s1.M, s1.N);

	for (int i = 0; i < s1.M; i++)
	{
		for (int j = 0; j < s1.N; j++)
		{
			for (int t = 0; t < s1.N; t++)
			{
				g(i, j) = g(i, j) + (s1(i, t) * s2(t, j));
			}
		}
	}
	return g;
}

template<typename Z>
matrix<Z> operator~(matrix<Z>& s1)//перегрузка транспонировани€ матрицы
{
	matrix q(s1.N, s1.M);
	for (int i = 0; i < s1.M; i++)
	{
		for (int j = 0; j < s1.N; j++)
		{
			q(j, i) = s1(i, j);
		}
	}
	return q;
}


int main()
{

	matrix <int> A(3, 2);        // ƒо зап€той целай часть числа , а потом мнима€
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 0;
	A(1, 1) = 1;
	A(2, 0) = 2;
	A(2, 1) = 4;

	matrix <int> B(2, 2);
	B(0, 0) = 5;
	B(0, 1) = 1;
	B(1, 0) = 2;
	B(1, 1) = 4;

	matrix <int> C(3, 2);
	C(0, 0) = 0;
	C(1, 0) = 3;
	C(1, 1) = 5;
	C(2, 0) = 2;
	C(2, 1) = 1;

	cout << "Matrica A: " << endl;
	A.print();
	cout << "Matrica B: " << endl;
	B.print();
	cout << "Matrica —: " << endl;
	C.print();


	system("pause");
	return 0;
}

	
