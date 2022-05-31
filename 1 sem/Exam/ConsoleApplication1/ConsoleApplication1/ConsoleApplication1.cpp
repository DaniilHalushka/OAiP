#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int i, j, n, m, a[5][5], sum = 0, max = -999999, imax = 0, jmax = 0, posl=0;
    cout << "N=";
    cin >> n;
    m = n;
    cout << "Input matrix A \n";
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if ((a[i][j] < 0) && ((i+j < n-1) || (i+j > n-1))) { sum += a[i][j]; };

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if ((i == 0 && j == 0) || a[i][j] > max) {
                max = a[i][j];
                imax = i;
                jmax = j;
            }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if ((i == j) && (i + 2 > n)) {
                posl = a[i][j];
                a[imax][jmax] = posl;
                a[i][j] = max;
            }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) 
            cout << a[i][j] << " ";
        cout << endl;
    }


    cout << sum << " " << max;
}