#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
	float price;
	float discount;
	float tax;
	float net;
	
	cout << setprecision(2) << fixed;
	
	cout << "Enter the offer price of the item: ";
	cin >> price;
	cout << "Discount rate (%): ";
	cin >> discount;
	cout << "Tax rate (%): ";
	cin >> tax;
	
	net = (price * (1 - discount / 100)) * (1 + tax / 100);
	//net = (net * 100 + 0.5) / 100;
	net = floor(net) + (floor((net - floor(net)) * 100 + 0.5))/100;
	
	cout << endl << "The net price of the item is: " << net << endl;
	
	return 0;
}