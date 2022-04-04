#include "monom.h"
#include "polinom.h"
#include <iostream>
using namespace std;

void main()
{
	string s1 = "x^2 + 1";
	Polinom S1(s1);
	string s2 = "x-1";
	Polinom S2(s2);
	/*string s3 = "x+1";
	Polinom S3(s3);*/

	S1.plusPolinoms(S2);

	cout << S1;

	//cout << S1 + S2 + S3;
}