#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y, z, a, b, c, d, e, f, rez;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter z: ";
    cin >> z;
    a = pow(y, x + 1);
    b = pow(fabs(y - 2), 1 / 3.) + 3;
    c = a / b;
    d = (x + (y / 2)) / (2 * fabs(x + y));
    e = pow((x + 1), (-1 / sin(z)));
    f = d * e;
    rez = c + f;
    cout << "The result of the operation is = " << rez;
}
