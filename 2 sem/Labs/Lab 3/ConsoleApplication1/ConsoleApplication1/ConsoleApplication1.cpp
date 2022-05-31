#include <iostream>
#include <windows.h>

using namespace std;

double fact(int help) {
    if (help == 0) return 1;
    else return help * fact(help - 1);
}

double notRec(int help) {
    int result = 1;
    if (help == 0) return 1;
    else {
        for (int i = 1; i <= help; i++) result *= i;
        return result;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n, k, variant, result = 0;
    cout << "Введите число n: ";
    cin >> n;
    while (n < 0) {
        cout << "Введите корректно число n (n >= 0): ";
        cin >> n;
    }
    cout << "Введите число k: ";
    cin >> k;
    while ((k < 0) || (k > n)) {
        cout << "Введите корректно число k (k >= 0 и k <= n): ";
        cin >> k;
    }
    cout << "Выберите способ решения задачи: " << endl;
    cout << "1 - Рекурсивный" << endl;
    cout << "2 - Не рекурсивный" << endl;
    cin >> variant;
    switch (variant) {
    case 1: {
        result = fact(n) / (fact(k) * fact(n - k));
        break;
    }
    case 2: {
        result = notRec(n) / (notRec(k) * notRec(n - k));
        break;
    }
    default: break;
    }
    cout << endl << "Результат выполнения операции равен = " << result << endl;
}