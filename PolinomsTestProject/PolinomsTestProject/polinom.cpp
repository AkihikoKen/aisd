#include "polinom.h"
#include <iostream>
#include <string>

using namespace std;

Polinom::Polinom(const string& S)
{
	int i = 0;
	List.Insert_to_tail();
	string MonomStr = "";
	while (i + 1 <= S.length())
	{
		if ((S[i + 1] != '+') && (S[i + 1] != '-') && (S[i + 1] != '\0'))
		{
			MonomStr.push_back(S[i]);
			i += 1;
		}
		else
		{
			MonomStr.push_back(S[i]);
			monom A(MonomStr);
			if (A.coeff != 0)
				Insert(A);
			MonomStr = "";
			i++;
		}
	}
	if (List.IsEmpty())
		List.Insert_to_tail();
}

void Polinom::Insert(const monom N)
{
	int i = 0;
	int flag = 0;
	List.reset(); 
	while ((!List.IsEnd()) && (flag == 0))
	{
		monom M = List.getcurrentdate();
		if (M.power == N.power)
		{
			monom res(M.power, M.coeff + N.coeff);
			if (res.coeff != 0)
			{
				List.ChangeCurrent(res);
				flag = 1;
			}
			else
			{
				if (N.coeff != 0)
				{
					List.Dellcurrent();
					flag = 1;
				}
			}
		}
		else if ((M.power < N.power) && (N.power < List.getcurrentnextdata().power) && (flag == 0))
		{
			if (N.coeff != 0)
				List.InsertAfterCurrent(N);
			flag = 1;
		}
		List.getnext();
	}

	if ((List.IsEnd()) && (flag == 0))
	{
		monom M = List.getcurrentdate();
		if (M.power == N.power)
		{
			monom res(M.power, M.coeff + N.coeff);
			if (res.coeff != 0)
			{
				List.ChangeCurrent(res);
				flag = 1;
			}
			else
			{
				if (N.coeff != 0)
				{
					List.Dellcurrent();
					flag = 1;
				}
			}
		}
		else
			if (N.coeff != 0)
			{
				List.InsertAfterCurrent(N);
				flag = 1;
			}
		if (!List.IsEmpty())
			List.getnext();
	}
}

Polinom::~Polinom()
{
	List.clear();
}

Polinom::Polinom(const Polinom& A)
{
	List = A.List;

}

void Polinom::plusPolinoms(const Polinom& Polinom2)
{
	Polinom Res;
	this->List.reset();
	Polinom B(Polinom2);
	monom A1 = List.getcurrentdate();
	B.List.reset();
	monom B1 = B.List.getcurrentdate();
	while ((!this->List.IsEnd()) && (!B.List.IsEnd()))
	{
		if (List.getcurrentdate().power == B.List.getcurrentdate().power)
		{
			monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0)
			{
				if (res.power == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else {
					Res.List.Insert_to_tail(res);
					List.getnext();
					B.List.getnext();
				}
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}

	}
	if (List.getcurrentdate().power == B.List.getcurrentdate().power)
	{
		monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
		if (res.coeff != 0)
		{
			if (res.power == 0)
			{
				Res.Insert(res);
				List.getnext();
				B.List.getnext();
			}
			else
				Res.List.Insert_to_tail(res);
			List.getnext();
			B.List.getnext();
		}
		else
		{
			List.getnext();
			B.List.getnext();
		}
	}
	else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
	{

		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();
	}
	else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
	{
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();
	}
	while ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() != B1))
	{
		if (List.getcurrentdate().power == B.List.getcurrentdate().power)
		{
			monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0)
			{
				if (res.power == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else
					Res.List.Insert_to_tail(res);
				List.getnext();
				B.List.getnext();
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}


	}
	if ((this->List.getcurrentdate() == A1) && (B.List.getcurrentdate() != B1))
	{
		while (!B.List.IsEnd())
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();

	}
	else if ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() == B1))
	{

		while (!List.IsEnd())
		{
			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();

	}

	this->List = Res.List;
}

Polinom& Polinom :: operator=(const Polinom& Polinom2)
{
	List = Polinom2.List;
	return *this;
}

Polinom Polinom :: operator + (const Polinom& Polinom2)
{
	Polinom Res;
	this->List.reset();
	Polinom B(Polinom2);
	monom A1 = List.getcurrentdate();
	B.List.reset();
	monom B1 = B.List.getcurrentdate();
	while ((!this->List.IsEnd()) && (!B.List.IsEnd()))
	{
		if (List.getcurrentdate().power == B.List.getcurrentdate().power)
		{
			monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0)
			{
				if (res.power == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else {
					Res.List.Insert_to_tail(res);
					List.getnext();
					B.List.getnext();
				}
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}

	}
	if (List.getcurrentdate().power == B.List.getcurrentdate().power)
	{
		monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
		if (res.coeff != 0)
		{
			if (res.power == 0)
			{
				Res.Insert(res);
				List.getnext();
				B.List.getnext();
			}
			else
				Res.List.Insert_to_tail(res);
			List.getnext();
			B.List.getnext();
		}
		else
		{
			List.getnext();
			B.List.getnext();
		}
	}
	else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
	{

		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();
	}
	else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
	{
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();
	}
	while ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() != B1))
	{
		if (List.getcurrentdate().power == B.List.getcurrentdate().power)
		{
			monom res(List.getcurrentdate().power, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0)
			{
				if (res.power == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else
					Res.List.Insert_to_tail(res);
				List.getnext();
				B.List.getnext();
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().power < B.List.getcurrentdate().power)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().power > B.List.getcurrentdate().power)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}


	}
	if ((this->List.getcurrentdate() == A1) && (B.List.getcurrentdate() != B1))
	{
		while (!B.List.IsEnd())
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();

	}
	else if ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() == B1))
	{

		while (!List.IsEnd())
		{
			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();

	}

	return Res;
}

Polinom Polinom :: operator - (const Polinom& Polinom2)
{
	Polinom p1 = -1 * (Polinom2);
	return (*this + p1);
}

Polinom Polinom :: operator * (const Polinom& Polinom2)
{
	Polinom Res;
	Polinom B(Polinom2);
	List.reset();
	B.List.reset();

	while (!List.IsEnd())
	{
		while (!B.List.IsEnd())
		{
			monom res(List.getcurrentdate().power + B.List.getcurrentdate().power, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
			if (res.power > 999)
				throw "Error";
			Res.Insert(res);
			B.List.getnext();
		}
		List.getnext();
		B.List.reset();
	}

	B.List.reset();
	while (!B.List.IsEnd())
	{
		monom res(List.getcurrentdate().power + B.List.getcurrentdate().power, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
		if (res.power > 999)
			throw "Error";
		Res.Insert(res);
		B.List.getnext();
	}

	monom res(List.getcurrentdate().power + B.List.getcurrentdate().power, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
	if (res.power > 999)
		throw "Error";;
	Res.Insert(res);
	List.reset();
	
	while (!List.IsEnd())
	{
		monom res(List.getcurrentdate().power + B.List.getcurrentdate().power, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
		if (res.power > 999)
			throw "Error";
		Res.Insert(res);
		List.getnext();
	}
	return Res;
}

ostream& operator<<(ostream& os, const Polinom& P)
{
	int flag = 0;
	Polinom P1(P);
	P1.List.reset();

	while (!P1.List.IsEnd())
	{
		if (P1.List.getcurrentdate().coeff == 0)
			P1.List.getnext();
		else {
			flag = 1;
			if (P1.List.getcurrentdate().coeff > 0)
				os << '+';
			os << P1.List.getcurrentdate().coeff;
			string power = to_string(P1.List.getcurrentdate().power);

			if (power.length() == 1)
			{
				if (power == "0")
					P1.List.getnext();
				else {
					os << "z^" << power[0];
					P1.List.getnext();
				}
			}
			else if (power.length() == 2)
			{
				os << "y^" << power[0];
				if (power[1] != '0')
					os << "z^" << power[1];
				P1.List.getnext();
			}
			else if (power.length() == 3)
			{
				os << "x^" << power[0];
				if (power[1] != '0')
					os << "y^" << power[1];
				if (power[2] != '0')
					os << "z^" << power[2];
				P1.List.getnext();
			}
		}
	}
	if (P1.List.getcurrentdate().coeff == 0)
		P1.List.getnext();

	else {
		flag = 1;
		if (P1.List.getcurrentdate().coeff > 0)
			os << '+';
		os << P1.List.getcurrentdate().coeff;
		string power = to_string(P1.List.getcurrentdate().power);

		if (power.length() == 1)
		{
			if (power == "0")
				P1.List.getnext();
			else {
				os << "z^" << power[0];
				P1.List.getnext();
			}
		}
		else if (power.length() == 2)
		{
			os << "y^" << power[0];
			if (power[1] != '0')
				os << "z^" << power[1];
			P1.List.getnext();
		}
		else if (power.length() == 3)
		{
			os << "x^" << power[0];
			if (power[1] != '0')
				os << "y^" << power[1];
			if (power[2] != '0')
				os << "z^" << power[2];
			P1.List.getnext();
		}
	}
	if (flag == 0)
		os << "0";
	os << endl;
	return os;
}

bool Polinom :: operator==(const Polinom& Polinom2) const
{

	return (this->List == Polinom2.List);

}

Polinom operator * (const Polinom& A, const double a)
{
	Polinom Res;
	Polinom A1(A);
	A1.List.reset();
	while (!A1.List.IsEnd())
	{
		monom res(A1.List.getcurrentdate().power, A1.List.getcurrentdate().coeff * a);
		if (res.coeff != 0)
			Res.Insert(res);
		A1.List.getnext();
	}

	monom res(A1.List.getcurrentdate().power, A1.List.getcurrentdate().coeff * a);
	if (res.coeff != 0)
		Res.Insert(res);
	A1.List.getnext();
	return Res;

}
Polinom operator * (const double a, const Polinom& A)
{
	return  A * a;
}