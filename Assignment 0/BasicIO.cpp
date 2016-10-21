#include <iostream>

using namespace std;

int main()
{
	char name[20];
	char email[20];
	char city[20];
	char province[20];
	char country[20];
	
	int dob;
	long id;
	
	cout << "First Name: ";
	cin >> name;
	cout << "Date of birth (mmddyy): ";
	cin >> dob;
	cout << "Student number: ";
	cin >> id;
	cout << "Email address: ";
	cin >> email;
	cout << "City: ";
	cin >> city;
	cout << "Province/state: ";
	cin >> province;
	cout << "County: ";
	cin >> country;
	cout << "Thank you! sign-up is complete!" << endl << endl;
	
	cout << "This is your sign-up receipt:" << endl;
	cout << "FIRST NAME: " << name << endl;
	cout << "DATE OF BIRTH (MMDDYY): " << dob << endl;
	cout << "STUDENT NUMBER: " << id << endl;
	cout << "EMAIL ADRESS: " << email << endl;
	cout << "CITY: " << city << endl;
	cout << "PROVINCE/STATE: " << province << endl;
	cout << "COUNTRY: " << country << endl;
	
	return 0;
}