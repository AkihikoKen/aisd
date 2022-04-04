#pragma once
#include "list.h"
#include "monom.h"
using namespace std;
class Polinom
{
public:
	Polinom(const string& A = "");
	Polinom(const Polinom& A);
	~Polinom();

	void plusPolinoms(const Polinom& Polinom2);

	bool operator==(const Polinom& Polinom2) const;
	Polinom& operator=(const Polinom& Polinom2);
	Polinom operator+(const Polinom& Polinom2);
	Polinom operator-(const Polinom& Polinom2);
	Polinom operator * (const Polinom& Polinom2);
	friend ostream& operator<<(ostream& os, const Polinom& P);
	
	friend  Polinom operator * (const Polinom& A, const double a);
	friend  Polinom operator * (const double a, const Polinom& A);

private:
	list<monom> List;
	void Insert(const monom A);
};
