#include <iostream>
#include <cmath>

using namespace std;

class Vector2D
{
	double i, j;
	
	public:

	void set_values(double, double);
	void set_from_mag_angle(double, double);
	void set_i(double);
	void set_j(double);
	
	double get_magnitude()
	{
		return sqrt(pow(i, 2) + pow(j, 2));
	}
	
	double get_i() { return i; }
	double get_j() { return j; }
};

void Vector2D::set_values(double a, double b)
{
	i = a;
	j = b;
}

void Vector2D::set_from_mag_angle(double a, double b)
{
	i = a * cos(b);
	j = a * sin(b);
}

void Vector2D::set_i(double a)
{
	i = a;
}

void Vector2D::set_j(double a)
{
	j = a;
}

Vector2D add(Vector2D u, Vector2D v)
{
	Vector2D addition;
	addition.set_values(u.get_i() + v.get_i(), u.get_j() + v.get_j());
	
	return addition;
}

int main()
{
	float ui, uj, vi, vj;
	Vector2D u;
	Vector2D v;
	
	cout << "Type something dumb to stop program" << endl << endl;
	while (true)
	{
		cout << "Enter the i component of vector u: ";
		cin >> ui;
		
		if (!cin.good())
		{
			break;
		}
		
		cout << "Enter the j component of vector u: ";
		cin >> uj;
		
		if (!cin.good())
		{
			break;
		}
		
		cout << "Enter the i component of vector v: ";
		cin >> vi;
		
		if (!cin.good())
		{
			break;
		}
		
		cout << "Enter the j component of vector v: ";
		cin >> vj;
		
		if (!cin.good())
		{
			break;
		}
		
		u.set_values(ui, uj);
		v.set_values(vi, vj);
		cout << "Magnitude u: " << u.get_magnitude() << endl;
		cout << "Magnitude v: " << v.get_magnitude() << endl;
		cout << "Addition of u and v: " << add(u, v).get_i() << "i, " << add(u, v).get_j() << "j" << endl << endl;
	}
	
	cout << endl;
	
	return 0;
}