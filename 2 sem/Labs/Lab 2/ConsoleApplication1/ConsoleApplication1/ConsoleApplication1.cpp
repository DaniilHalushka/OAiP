#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Student
{
    string surname, name, secondName;
    int year = 0, group = 0, markPhys = 0, markMath = 0, markInform = 0, markChem = 0;
    double averMark= 0.0;
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    fstream fs1, fs2;
    Student arr[50];
    string helpstr;
    fs2.open("result.txt", fstream::out | fstream::trunc);
    int menu, count = 0, needGroup, needVariant, number, i, chooseVariant = 0, quantity;
        while (true) {
            cout << "Выберите пункт, который надо выполнить:" << "\n";
            cout << "1 - Создание" << "\n";
            cout << "2 - Просмотр" << "\n";
            cout << "3 - Корреция даннных" << "\n";
            cout << "4 - Решение индивидуального задания" << "\n";
            cout << "5 - Завершение программы" << "\n";
            cout << "Введите номер пункта: ";
            cin >> menu;
            switch (menu) {
            case 1: {
                cout << "Выберите, как вы хотите ввести данные о студентах:" << "\n";
                cout << "1 - Ввести из готового файла" << "\n";
                cout << "2 - Ввести вручную" << "\n";
                cout << "Введите необходимый вариант: ";
                cin >> chooseVariant;
                switch (chooseVariant) {
                case 1: {
                    fs1.open("info.txt", fstream::in | fstream::out | fstream::app);
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
                        arr[i].year = stoi(helpstr);;
                        fs1 >> helpstr;
                        arr[i].group = stoi(helpstr);
                        fs1 >> helpstr;
                        arr[i].markPhys = stoi(helpstr);
                        fs1 >> helpstr;
                        arr[i].markMath = stoi(helpstr);
                        fs1 >> helpstr;
                        arr[i].markInform = stoi(helpstr);
                        fs1 >> helpstr;
                        arr[i].markChem = stoi(helpstr);
                        arr[i].averMark = (arr[i].markPhys + arr[i].markMath + arr[i].markInform + arr[i].markChem) / 4.0;
                    }
                    SetConsoleCP(1251);
                    SetConsoleOutputCP(1251);
                    fs1.close();
                    break;
                }
                case 2: {
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
                        cout << endl << "Год рождения: ";
                        cin >> arr[i].year;
                        cout << endl << "Группа: ";
                        cin >> arr[i].group;
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
                        count++;
                        for (i = 0; i < count; i++) {
                            fs1 << endl << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                            fs1 << arr[i].year << " " << arr[i].group << " "
                                << arr[i].markPhys << " " << arr[i].markMath << " " << arr[i].markInform << " " << arr[i].markChem;

                        }
                        fs1.close();
                    }
                    break;
                }
                }
                break;
            }
            case 2: {
                if (chooseVariant == 1) {
                    for (int i = 0; i < count; i++) {
                        cout << endl << "Номер студента: " << i + 1 << endl
                            << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl
                            << "Год рождения : " << arr[i].year << endl
                            << "Номер группы : " << arr[i].group << endl
                            << "Физика : " << arr[i].markPhys << endl
                            << "Математика : " << arr[i].markMath << endl
                            << "Информатика : " << arr[i].markInform << endl
                            << "Химия : " << arr[i].markChem << endl
                            << "Средний балл : " << arr[i].averMark << endl
                            << endl << "----------------------" << endl << endl;

                    }
                }
                else if (chooseVariant == 2) {
                    for (i = 0; i < count; i++) {
                        cout << endl << "Номер студента: " << i + 1 << endl
                            << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl
                            << "Год рождения : " << arr[i].year << endl
                            << "Номер группы : " << arr[i].group << endl
                            << "Физика : " << arr[i].markPhys << endl
                            << "Математика : " << arr[i].markMath << endl
                            << "Информатика : " << arr[i].markInform << endl
                            << "Химия : " << arr[i].markChem << endl
                            << "Средний балл : " << arr[i].averMark << endl
                            << endl << "----------------------" << endl << endl;
                    }
                }
                else  if ((chooseVariant != 1) && (chooseVariant != 2)) {
                    cout << "Повторите выбор" << endl;
                }
                break;
                }   
            case 3: {
                fs1.close();
                cout << "Выберите, что вы хотите отредактировать:" << "\n";
                cout << "1 - Создание записи о новом студенте" << "\n";
                cout << "2 - Редактирование данных существующего студента" << "\n";
                cout << "Введите необходимый вариант: ";
                cin >> needVariant;
                switch (needVariant) {
                case 1: {
                    fs1.open("info.txt", fstream::out | fstream::trunc);
                    count++;
                        cout << endl << "Фамилия студента: ";
                        cin >> arr[count - 1].surname;
                        cout << endl << "Имя студента: ";
                        cin >> arr[count - 1].name;
                        cout << endl << "Отчество студента: ";
                        cin >> arr[count - 1].secondName;
                        cout << endl << "Год рождения: ";
                        cin >> arr[count - 1].year;
                        cout << endl << "Группа: ";
                        cin >> arr[count - 1].group;
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
                            fs1 << arr[i].year << " " << arr[i].group << " "
                                << arr[i].markPhys << " " << arr[i].markMath << " " << arr[i].markInform << " " << arr[i].markChem;
                        
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
                        cout << endl << "Год рождения: ";
                        cin >> arr[i].year;
                        cout << endl << "Группа: ";
                        cin >> arr[i].group;
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
                        fs1 << arr[i].year << " " << arr[i].group << " " << arr[i].markPhys << " " << arr[i].markMath << " "
                            << arr[i].markInform << " " << arr[i].markChem;
                    }
                    fs1.close();
                    break;
                }
                }
                break;
            }
            case 4: {
                cout << "Введите номер интересующей вас группы: ";
                cin >> needGroup;
                for (int i = 0; i < count; i++) {
                    if ((arr[i].group == needGroup) && (arr[i].markPhys >= 9) && (arr[i].markMath >= 9) && (arr[i].markInform >= 9) &&
                        (arr[i].markChem >= 9)) {
                        fs2 << "Студент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                        fs2 << "Год рождения: " << arr[i].year << endl;
                        fs2 << "Номер группы: " << arr[i].group << endl;
                        fs2 << "Оценка по физике: " << arr[i].markPhys << endl;
                        fs2 << "Оценка по математике: " << arr[i].markMath << endl;
                        fs2 << "Оценка по информатике: " << arr[i].markInform << endl;
                        fs2 << "Оценка по химии: " << arr[i].markChem << endl;
                        fs2 << "Средний балл: " << arr[i].averMark << endl;
                        fs2 << "----------------------" << endl;
                    }
                }
                break;
            }
            case 5: exit(1);
            default: break;
        }
    }
        fs1.close();
        fs2.close();
}