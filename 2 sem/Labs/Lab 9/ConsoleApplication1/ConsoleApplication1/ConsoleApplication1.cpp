#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

double Function(double x)
{
	return pow(x, 3) - 50 * cos(x);
}

double FindRoot(double x0, double x1, double epsilon)
{
	double x2, de = 0;
	double y0 = Function(x0);
	double y1 = Function(x1);
	do
	{
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
		de = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = Function(x2);
	} while (de > epsilon);
	return x1;
}

int main()
{
	setlocale(LC_ALL, "RU");
	double a = -4, b = 3, h = 0.1, eps = 0.0000001, help;
	int n = 0;
	cout << "При параметрах:\na = " << a << "\nb = " << b << "\nh = " << h << "\nepsilon = " << eps << endl;
	for (double x = a; x <= b; x += h)
	{
		if (Function(x) * Function(x + h) < 0)
		{
			n++;
			help = FindRoot(x, x + h, eps);
			cout << "x" << n << " = " << help << endl;
			cout << Function(help) << endl;;
		}
	}
	if (n == 0) cout << "Корней нет\n";
}

