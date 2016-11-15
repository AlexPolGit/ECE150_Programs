#include <iostream>
#include <cmath>

using namespace std;

struct Fraction
{
	int numerator;
	int denominator;
};
/*
void simplifyFraction(struct Fraction* f)
{
	
}

struct Fraction addFractions(struct Fraction* f1, struct Fraction* f2)
{
	
}

struct Fraction subFractions(struct Fraction* f1, struct Fraction* f2)
{
	
}
*/
struct Fraction mulFractions(struct Fraction* f1, struct Fraction* f2)
{
	struct Fraction frac;
	
	frac.numerator = f1->numerator * f2->numerator;
	frac.denominator = f1->denominator * f2->denominator;
	
	return frac;
}
/*
struct Fraction divFractions(struct Fraction* f1, struct Fraction* f2)
{
	
}
*/
int main()
{
	struct Fraction frac;
	struct Fraction* f1 = &frac;
	
	cout << "Enter a second fraction numerator: ";
	cin >> f1->numerator;
	cout << "Denominator: ";
	cin >> f1->denominator;
	
	struct Fraction* f2 = &frac;
	
	cout << "Enter a fraction numerator: ";
	cin >> f1->numerator;
	cout << "Denominator: ";
	cin >> f1->denominator;
	
	cout << "Entered: " << f1->numerator << "/" << f1->denominator << endl;

	return 0;
}