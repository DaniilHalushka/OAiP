#include <iostream>

using namespace std;

int main()
{
    int n, m, imax = 0, imin = 0, max = 0, min = 0;
    cout << "n = "; 
    cin >> n;
    cout << "m = "; 
    cin >> m;
    double** a = new double* [n];
    for (int i = 0; i < n; i++)  a[i] = new double[m];
    cout << "Enter " << m * n << " elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if ((i == 0 && j == 0) || a[i][j] > max) { max = a[i][j]; imax = i; }
            if ((i == 0 && j == 0) || a[i][j] < min) { min = a[i][j]; imin = i; }
        }

    cout << "max element = " << max << "  min element = " << min << "\n";
    swap(a[imax], a[imin]);
  for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}