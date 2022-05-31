#include <iostream>
#include <cmath>

using namespace std;

void Out_Rez(double s, double y, double mod) {
    cout << "S(x) = " << s << " Y(x) = " << y << " |Y(x) - S(x)| = " << fabs(y - s) << endl;
}

double fact(int n) {
    if (n == 1)return 1;
    else return n * fact(n - 1);
}

int main()
{
    int n, k, i;
    double a, b, h, s, y, x, mod;
    cout << "Enter a, b, h, n" << endl;
    cin >> a >> b >> h >> n;
    for (x = a; x <= b; x += h)
    {
        s = y = mod = 0;
        y = sinh(x);
        cout << "For x = " << x << " : ";
        for (k = 0; k <= n; k++)
        {
            s += pow(x, (2 * k + 1)) / fact(2 * k + 1);
        }
        mod = fabs(y - s);
        Out_Rez(s, y, mod);
    }
}