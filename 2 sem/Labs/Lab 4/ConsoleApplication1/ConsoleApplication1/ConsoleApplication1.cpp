#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Student
{
    string surname, name, secondName;
    int markPhys = 0, markMath = 0, markInform = 0, markChem = 0;
    double averMark = 0.0;
};

void quicksort(Student *arr, int begin, int end) {
    int left, right;
    double x;
    Student help;
    left = begin;
    right = end;
    x = arr[(left + right) / 2].averMark;
    do {
        while (arr[left].averMark > x)  left++;
        while (x > arr[right].averMark) right--;
        if (left <= right) {
            help = arr[left];
            arr[left] = arr[right];
            arr[right] = help;
            left++;
            right--;
        }
    } while (left <= right);
    if (begin < right) quicksort(arr, begin, right);
    if (left < end) quicksort(arr, left, end);
};

int binarySearch(Student *arr, int left, int right, double key)
{
    int middle = left + (right - left) / 2;
    if (left >= right) return middle;
    if (arr[middle].averMark < key) return binarySearch(arr, left, middle - 1, key);
    if (arr[middle].averMark > key) return binarySearch(arr, middle + 1, right, key);    
}


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    fstream fs1, fs2;
    Student arr[50], r[50];
    string helpstr;
    int menu, count = 0, number, i, j, m, chooseVariant, quantity;
    double averUniverMark = 0.0, sumAverMarks = 0.0;
    while (true) {
        cout << "Выберите пункт, который надо выполнить:" << "\n";
        cout << "1 - Создание" << "\n";
        cout << "2 - Просмотр" << "\n";
        cout << "3 - Коррекция даннных" << "\n";
        cout << "4 - Линейный поиск" << "\n";
        cout << "5 - Сортировка" << "\n";
        cout << "6 - Поиск делением пополам в отсортированном массиве" << "\n";
        cout << "7 - Завершение программы" << "\n";
        cout << "Введите номер пункта: ";
        cin >> menu;
        switch (menu) {
        case 1: {                                                                       //Создание массива структур
            system("cls");
            cout << "Выберите, как вы хотите ввести данные о студентах:" << "\n";
            cout << "1 - Ввести из готового файла" << "\n";
            cout << "2 - Ввести вручную" << "\n";
            cout << "Введите необходимый вариант: ";
            cin >> chooseVariant;
            switch (chooseVariant) {
            case 1: {                                                                   //Запись из файла
                fs1.open("info.txt", fstream::in | fstream::app);
                for (int i = 0; i < 50 && !fs1.eof(); i++) {
                    count++;
                    SetConsoleCP(1251);
                    SetConsoleOutputCP(1251);
                    fs1 >> helpstr;
                    arr[i].surname = helpstr;
                    fs1 >> helpstr;
                    arr[i].name = helpstr;
                    fs1 >> helpstr;
                    arr[i].secondName = helpstr;
                    SetConsoleCP(866);
                    fs1 >> helpstr;
                    arr[i].markPhys = stoi(helpstr);
                    fs1 >> helpstr;
                    arr[i].markMath = stoi(helpstr);
                    fs1 >> helpstr;
                    arr[i].markInform = stoi(helpstr);
                    fs1 >> helpstr;
                    arr[i].markChem = stoi(helpstr);
                    arr[i].averMark = (arr[i].markPhys + arr[i].markMath + arr[i].markInform + arr[i].markChem) / 4.0;
                    sumAverMarks += arr[i].averMark;
                }
                averUniverMark = sumAverMarks / count;
                SetConsoleCP(1251);
                SetConsoleOutputCP(1251);
                fs1.close();
                system("cls");
                break;
            }
            case 2: {                                                                       //Запись вручную
                fs1.open("info.txt", fstream::out | fstream::app);
                cout << "Введите количество студентов, которое вам надо ввести: ";
                cin >> quantity;
                for (i = 0; i < quantity; i++) {
                    cout << endl << "Фамилия студента: ";
                    cin >> arr[i].surname;
                    cout << endl << "Имя студента: ";
                    cin >> arr[i].name;
                    cout << endl << "Отчество студента: ";
                    cin >> arr[i].secondName;
                    cout << endl << "Оценка по физике: ";
                    cin >> arr[i].markPhys;
                    cout << endl << "Оценка по математике: ";
                    cin >> arr[i].markMath;
                    cout << endl << "Оценка по информатике: ";
                    cin >> arr[i].markInform;
                    cout << endl << "Оценка по химии: ";
                    cin >> arr[i].markChem;
                    arr[i].averMark = (arr[i].markPhys + arr[i].markMath + arr[i].markInform + arr[i].markChem) / 4.0;
                    cout << endl << "Средний балл за семестр: " << arr[i].averMark << endl;
                    sumAverMarks += arr[i].averMark;
                    count++;
                }
                for (i = 0; i < count; i++) {
                    fs1 << endl << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                    fs1 << arr[i].markPhys << " " << arr[i].markMath << " " << arr[i].markInform << " " << arr[i].markChem;
                }
                averUniverMark = sumAverMarks / count;
                fs1.close();
                break;
            }
            }
            break;
        }
        case 2: {                                                           //Просмотр студентов
            system("cls");
            for (int i = 0; i < count; i++) {
                cout << endl << "Номер студента: " << i + 1 << endl
                    << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl
                    << "Физика : " << arr[i].markPhys << endl
                    << "Математика : " << arr[i].markMath << endl
                    << "Информатика : " << arr[i].markInform << endl
                    << "Химия : " << arr[i].markChem << endl
                    << "Средний балл : " << arr[i].averMark << endl
                    << endl << "----------------------" << endl << endl;

            }
            cout << "Средний балл по университету = " << averUniverMark << endl << endl;
            break;
        }
        case 3: {                                                                               //Редактирование данных о студентах
            system("cls");
            fs1.close();
            cout << "Выберите, что вы хотите отредактировать:" << "\n";
            cout << "1 - Создание записи о новом студенте" << "\n";
            cout << "2 - Редактирование данных существующего студента" << "\n";
            cout << "Введите необходимый вариант: ";
            cin >> chooseVariant;
            switch (chooseVariant) {
            case 1: {
                fs1.open("info.txt", fstream::out | fstream::trunc);
                count++;
                cout << endl << "Фамилия студента: ";
                cin >> arr[count - 1].surname;
                cout << endl << "Имя студента: ";
                cin >> arr[count - 1].name;
                cout << endl << "Отчество студента: ";
                cin >> arr[count - 1].secondName;
                cout << endl << "Оценка по физике: ";
                cin >> arr[count - 1].markPhys;
                cout << endl << "Оценка по математике: ";
                cin >> arr[count - 1].markMath;
                cout << endl << "Оценка по информатике: ";
                cin >> arr[count - 1].markInform;
                cout << endl << "Оценка по химии: ";
                cin >> arr[count - 1].markChem;
                arr[count - 1].averMark = (arr[count - 1].markPhys + arr[count - 1].markMath + arr[count - 1].markInform + arr[count - 1].markChem) / 4.0;
                cout << endl << "Средний балл за семестр: " << arr[count - 1].averMark << endl;
                for (i = 0; i < count; i++) {
                    fs1 << endl << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                    fs1 << arr[i].markPhys << " " << arr[i].markMath << " " << arr[i].markInform << " " << arr[i].markChem;

                }
                fs1.close();
                break;
            }
            case 2: {
                fs1.open("info.txt", fstream::out | fstream::trunc);
                cout << "Введите номер студента, которого вы хотите изменить: ";
                cin >> number;
                for (i = number - 1; i < number; i++) {
                    cout << endl << "Фамилия студента: ";
                    cin >> arr[i].surname;
                    cout << endl << "Имя студента: ";
                    cin >> arr[i].name;
                    cout << endl << "Отчество студента: ";
                    cin >> arr[i].secondName;
                    cout << endl << "Оценка по физике: ";
                    cin >> arr[i].markPhys;
                    cout << endl << "Оценка по математике: ";
                    cin >> arr[i].markMath;
                    cout << endl << "Оценка по информатике: ";
                    cin >> arr[i].markInform;
                    cout << endl << "Оценка по химии: ";
                    cin >> arr[i].markChem;
                    arr[i].averMark = (arr[i].markPhys + arr[i].markMath + arr[i].markInform + arr[i].markChem) / 4.0;
                    cout << endl << "Средний балл за семестр: " << arr[i].averMark << endl;
                }
                for (i = 0; i < count; i++) {
                    fs1 << endl << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                    fs1 << arr[i].markPhys << " " << arr[i].markMath << " " << arr[i].markInform << " " << arr[i].markChem;
                }
                fs1.close();
                break;
            }
            }
            break;
        }
        case 4: {                                                                               //Линейный поиск
            system("cls");
            cout << endl << "Средний балл по университету = " << averUniverMark << endl << endl;
            cout << "Выберите, как организовать вывод результата:" << "\n";
            cout << "1 - В файл" << "\n";
            cout << "2 - В консоль" << "\n";
            cout << "Введите необходимый вариант: ";
            cin >> chooseVariant;
            switch (chooseVariant) {
            case 1: {
                fs2.open("result.txt", fstream::out | fstream::trunc);
                for (i = 0; i < count; i++) {
                    if (arr[i].averMark > averUniverMark) {
                        fs2 << "Студент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                        fs2 << "Оценка по физике: " << arr[i].markPhys << endl;
                        fs2 << "Оценка по математике: " << arr[i].markMath << endl;
                        fs2 << "Оценка по информатике: " << arr[i].markInform << endl;
                        fs2 << "Оценка по химии: " << arr[i].markChem << endl;
                        fs2 << "Средний балл: " << arr[i].averMark << endl;
                        fs2 << "----------------------" << endl;
                    }
                }
                fs2.close();
                break;
            }
            case 2: {
                for (i = 0; i < count; i++) {
                    if (arr[i].averMark > averUniverMark) {
                        cout << endl << "Номер студента: " << i + 1 << endl
                            << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl
                            << "Физика : " << arr[i].markPhys << endl
                            << "Математика : " << arr[i].markMath << endl
                            << "Информатика : " << arr[i].markInform << endl
                            << "Химия : " << arr[i].markChem << endl
                            << "Средний балл : " << arr[i].averMark << endl
                            << endl << "----------------------" << endl << endl;
                    }
                }
                break;
            }
                  break;
            }
            break;
        }
        case 5: {                                                                   //Сортировка
            system("cls");
            cout << "Выберите, как вы хотите отсортировать данные:" << "\n";
            cout << "1 - Сортировка прямым выбором" << "\n";
            cout << "2 - Сортировка методом Quicksort" << "\n";
            cout << "Введите необходимый вариант: ";
            cin >> chooseVariant;
            switch (chooseVariant) {
            case 1: {
                for (i = 0; i < count - 1; i++) {
                    m = i;
                    for (j = i + 1; j < count; j++)
                        if (arr[j].averMark > arr[m].averMark) m = j; {
                        r[j] = arr[m];
                        arr[m] = arr[i];
                        arr[i] = r[j];
                    }
                }
                system("cls");
                break;
            }
            case 2: {
                quicksort(arr, 0, count);
                system("cls");
                break;
            }
                  break;
            }
            break;
        }
        case 6: {
            system("cls");
            cout << endl << "Средний балл по университету = " << averUniverMark << endl << endl;
            cout << "Выберите, как организовать вывод результата:" << "\n";
            cout << "1 - В файл" << "\n";
            cout << "2 - В консоль" << "\n";
            cout << "Введите необходимый вариант: ";
            cin >> chooseVariant;
            switch (chooseVariant) {
            case 1: {
                fs2.open("result.txt", fstream::out | fstream::trunc);
                for (i = 0; i <= binarySearch(arr, 0, count, averUniverMark); i++) {
                    fs2 << "Студент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                    fs2 << "Оценка по физике: " << arr[i].markPhys << endl;
                    fs2 << "Оценка по математике: " << arr[i].markMath << endl;
                    fs2 << "Оценка по информатике: " << arr[i].markInform << endl;
                    fs2 << "Оценка по химии: " << arr[i].markChem << endl;
                    fs2 << "Средний балл: " << arr[i].averMark << endl;
                    fs2 << "----------------------" << endl;
                }
                fs2.close();
                break;
            }
            case 2: {
                for (i = 0; i <= binarySearch(arr, 0, count, averUniverMark); i++) {
                    cout << endl << "Номер студента: " << i + 1 << endl
                        << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl
                        << "Физика : " << arr[i].markPhys << endl
                        << "Математика : " << arr[i].markMath << endl
                        << "Информатика : " << arr[i].markInform << endl
                        << "Химия : " << arr[i].markChem << endl
                        << "Средний балл : " << arr[i].averMark << endl
                        << endl << "----------------------" << endl << endl;
                }
                break;
            }
                  break;
            }


            break;
            
        }
        case 7: exit(1);
        default: break;
        }
    }
    fs1.close();
    fs2.close();
}