#pragma once
#include <iostream>
using namespace std;

struct monom
{
public:
	int power;
	double coeff;
	monom(int power_a = 0, double coef_f = 0);
	monom(const string& A);
	bool  operator ==(const monom& A) const;
	monom& operator = (const monom& A);
	bool  operator !=(const monom& A) const;
	bool  operator <(const monom& A) const;
	bool  operator >(const monom& A) const;
private:
	bool determinatechar(char s);
	bool determinatecharonly(char s);
};
