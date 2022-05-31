#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int choose;
    double a = 0, b = 0, z = 0, x = 0, y = 0, u = 0, c = 0, e = 0;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите z: ";
    cin >> z;

    if (z <= 0) {
        cout << "z <= 0, значит x принимает значение 3z+1" << endl;
        x = 3 * z + 1;
    }
    else {
        cout << "z > 0, значит x принимает значение sqrt(z)" << endl;
        x = sqrt(z);
    }
    cout << "Выберите проводимую операцию:" << endl;
    cout << "1 - Выбор значения 2*х" << endl;
    cout << "2 - Выбор значения x^2" << endl;
    cout << "3 - Выбор значения x/3" << endl;
    cout << "Введите нужный вариант: ";
    cin >> choose;
    switch (choose) {
    case 1:
        c = 2 * x;
        cout << "Было выбрано значение 2*x" << endl;
        break;
    case 2:
        c = pow(x, 2);
        cout << "Было выбрано значение x^2" << endl;
        break;
    case 3:
        c = x / 3;
        cout << "Было выбрано значение x/3" << endl;
        break;
    default: break;
    }
    e = exp(1.);
    y = b * cos(a * u) + sin(c / 5) + a * pow(e, c);
    cout << "Результат вычислений равен = " << y;
}