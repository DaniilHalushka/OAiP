#include <iostream>

using namespace std;

double fact(int n) {
    if (n == 1) return 1;
    else return n * fact(n - 1);
}

int main()
{
    double a, b, x, h, r, sum, y, z, mr;
    int k, n;
    cout << "Input a, b, h, n" << endl;
    cin >> a >> b >> h >> n;
    for (x = a; x <= b; x += h) {
        mr = y = sum = 0;
        y = sinh(x);
        for (k = 0; k <= n; k++) {
            z = 2 * k + 1;
            r = (pow(x, z) / fact(z));
            sum += r;
        }
        mr = fabs(y - sum);
        cout << "x = " << x << endl;
        cout << "s = " << sum << endl;
        cout << "y = " << y << endl;
        cout << "mr = " << mr << endl;
    }
}
