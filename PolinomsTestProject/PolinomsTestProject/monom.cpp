#include "monom.h"
#include <cstdlib>
monom::monom(int power_a, double coef_f)
{
	power = power_a;
	coeff = coef_f;
}

monom::monom(const string& A)
{

	int i = 0;
	power = 0;
	if (!determinatechar(A[0]))
	{
		string Coeff = "";
		Coeff.push_back('1');
		coeff = atof(&Coeff[0]);
	}

	while (i < A.length())
	{
		if (determinatechar(A[i]))
		{
			string Coeff = "";
			if (determinatechar(A[i]) && (!determinatechar(A[i + 1])) && (i + 1 < A.length()) && (A[i + 1] != '.'))
			{
				Coeff.push_back(A[i]);
				Coeff.push_back('1');
				coeff = atof(&Coeff[0]);
				i += 1;
			}
			else
			{
				while ((determinatechar(A[i]) || A[i] == '.'))
				{
					Coeff.push_back(A[i]);
					i++;
				}
				coeff = atof(&Coeff[0]);
			}

		}
		else if ((A[i] == 'x') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				power = power + 100 * (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_x";
		}
		else if ((A[i] == 'y') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				power = power + 10 * (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_y";
		}
		else if ((A[i] == 'z') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				power = power + (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_z";
		}
		else if ((A[i] == 'x') && (A[i + 1] != '^'))
		{
			power = power + 100;
			i += 1;
		}
		else if ((A[i] == 'y') && (A[i + 1] != '^'))
		{
			power = power + 10;
			i += 1;
		}
		else if ((A[i] == 'z') && (A[i + 1] != '^'))
		{
			power = power + 1;
			i += 1;
		}
		else i++;

	}
}
bool monom::determinatechar(char s) 
{
	int k = s;
	if ((k > 47) && (k < 58))
		return true;
	else if ((s == '+') || (s == '-'))
		return true;
	else return false;
}
bool monom::determinatecharonly(char s)
{
	int k = s;
	if ((k > 47) && (k < 58))
		return true;
	else return false;
}
bool monom:: operator ==(const monom& A) const
{
	if ((this->power == A.power) && (coeff == A.coeff)) return 1; else return 0;
}




bool monom:: operator !=(const monom& A) const
{
	if ((this->power == A.power) && (coeff == A.coeff)) return 0; else return 1;
}

bool monom:: operator <(const monom& A) const
{
	if (this->power < A.power) return 1; else return 0;
}

bool monom:: operator >(const monom& A) const
{
	if (this->power > A.power) return 1; else return 0;
}


monom& monom :: operator = (const monom& A)
{
	power = A.power;
	coeff = A.coeff;
	return *this;
}