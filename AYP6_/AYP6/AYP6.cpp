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

	matrix(const matrix& src) {
		M = src.M;
		N = src.N;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				T[i][j] = src.T[i][j];
			}
		}
	}

	//friend matrix operator*(matrix& s1, matrix& s2);
	
	Z get(int m, int n) {
		return T[m][n];
	}

	void print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << get(i, j);
			    cout << " ";
		    }
			cout << endl;
		}
		cout << endl;
	}

	matrix operator + (const matrix& arg2) const {
				matrix result(M, N);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				result.T[i][j] = T[i][j] + arg2.T[i][j];
			}
		}
		return result;
	}

	~matrix()
	{
		delete[] T;
	}

};

template <class Z>
	class uniqPtr {
	private:
		Z* ptr;
	public:
		uniqPtr(Z* _ptr) {
			ptr = _ptr;
		}
		uniqPtr(uniqPtr&& src) {
			ptr = src.ptr;
			src.ptr = nullptr;
		}
		~uniqPtr(void) {
			delete ptr;
		}
	};

/*template<typename Z>
matrix<Z> operator*(matrix<Z>& s1, matrix<Z>& s2)//перегрузка перемножения матриц
{
	if (s1.N != s2.M)
		throw "ne pravilnie razmeri";
	matrix<Z> g(s1.M, s1.N);

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
}*/


int main()
{

	matrix <int> A(3, 2);      
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 0;
	A(1, 1) = 1;
	A(2, 0) = 2;
	A(2, 1) = 4;

	matrix <int> B(3, 2);
	B(0, 0) = 2;
	B(0, 1) = 3;
	B(1, 0) = 0;
	B(1, 1) = 1;
	B(2, 0) = 2;
	B(2, 1) = 4;

	cout << "Matrica A: " << endl;
	A.print();
	cout << "Matrica B: " << endl;
	B.print();

	system("pause");
	return 0;
}

	
