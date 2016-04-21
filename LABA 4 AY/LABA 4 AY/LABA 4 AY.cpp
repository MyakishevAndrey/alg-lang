// LABA 4 AY.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
// Совпадает с кургановым
#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

class Complex // êëàññ êîìïëåêñíûõ ÷èñåë  
{
	double re, im; // öåëàÿ è ìíèìàÿ ÷àñòè  

				   // ñîçäàåì êîíñòðóêòîðû   
public:

	double get_re()
	{
		return re;
	}

	double get_im()
	{
		return im;
	}

	Complex() {};

	Complex(double r) // êîíñòðóêòîð ïî óìîë÷àíèþ  
	{
		re = r;
		im = 0;
	}

	Complex(double r, double i) // êîíñòðóêòîð ïî óìîë÷àíèþ  
	{
		re = r;
		im = i;
	}

	Complex(Complex &c) // êîíñòðóêòîð êîïèðîâàíèÿ  
	{
		re = c.re;
		im = c.im;
	}

	~Complex() {}

	float abs() // Ìîäóëü êîìïëåêñíîãî ÷èñëà  
	{
		return sqrt(re * re - im * im);
	}

	Complex & operator = (Complex &c) // ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ  
	{
		re = c.re;
		im = c.im;

		return (*this);
	}

	Complex Complex::operator + (Complex &c) // ïåðåãðóçêà îïåðàòîðà ñëîæåíèÿ  
	{
		Complex temp;

		temp.re = re + c.re;
		temp.im = im + c.im;

		return temp;
	}


	Complex Complex::operator * (Complex &c) // ïåðåãðóçêà îïåðàòîðà óìíîæåíèÿ
	{
		Complex temp;

		temp.re = re*c.re;
		temp.im = im*c.im;

		return temp;
	}

};

class matrix {
	Complex** T;
	int M;
	int N;
public:
	matrix(int m, int n) : T(NULL), M(m), N(n)
	{
		T = new Complex*[M]; //ñòðîêè â ìàññèâå
		for (int i = 0; i < M; i++)
		{
			T[i] = new Complex[N]; //  ñòîëáöû
			for (int j = 0; j < N; j++)
				T[i][j] = Complex(0, 0);
		}
	}
	Complex& operator () (int i, int j)
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


	~matrix()
	{

	}

};

matrix operator+(matrix& s1, matrix& s2)//ïåðåãðóçêà ñëîæåíèÿ ìàòðèö
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

matrix operator*(matrix& s1, matrix& s2)//ïåðåãðóçêà ïåðåìíîæåíèÿ ìàòðèö
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
				g(i, j) = g(i,j) + (s1(i,t) * s2(t, j));
			}
		}
	}
	return g;
}

matrix operator~(matrix& s1)//ïåðåãðóçêà òðàíñïîíèðîâàíèÿ ìàòðèöû
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
	Complex value1(5, 2);
	Complex value2(3, -3);

	matrix A(3, 2);        // Äî çàïÿòîé èäåò öåëàé ÷àñòü ïîòîì ìíèìàÿ
	A(0, 0) = Complex(1, 0);
	A(0, 1) = Complex(2, 1);
	A(1, 0) = Complex(0, 0);
	A(1, 1) = Complex(3, 4);
	A(2, 0) = Complex(2, 0);
	A(2, 1) = Complex(1, 1);

	matrix B(2, 2);
	B(0, 0) = Complex(1, 0);
	B(0, 1) = Complex(3, 2);
	B(1, 0) = Complex(1, 2);
	B(1, 1) = Complex(0, 0);

	matrix F(3, 2);
	F(0, 0) = Complex(1, 0);
	F(0, 1) = Complex(3, 2);
	F(1, 0) = Complex(1, 2);
	F(1, 1) = Complex(0, 0);
	F(2, 0) = Complex(4, 1);
	F(2, 1) = Complex(0, 3);

	cout << "Matrica A: " << endl;
	A.print();
	cout << "Matrica B: " << endl;
	B.print();
	cout << "Matrica F: " << endl;
	F.print();
	matrix C(2, 2);
	C = A + F;//ñëîæåíèå ìàòðèö
	cout << "Matrica A+F: " << endl;
	C.print();
	matrix D(2, 2);
	D = A * B;//ïåðåìíîæåíèå ìàòðèö
	cout << "Matrica A*B: " << endl;
	D.print();
	matrix E(2, 2);
	E = ~A;//òðàíñïîíèðîâàíèå ìàòðèöû
	cout << "Matrica A transponirovannay: " << endl;
	E.print();
	try
	{
		D = A * F;
		D.print();
	}
	catch (char*& k)
	{
		cout << "iskluchenie for * " << k << endl;
	}
	cout << endl;
			
	cout <<" re " << value1.get_re() << " im ";
	cout << value1.get_im() << endl;
	cout << " re " << value2.get_re() << " im ";
	cout << value2.get_im() << endl;

	system("pause");
	return 0;
}