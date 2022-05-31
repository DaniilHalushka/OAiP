#include <iostream>
#include <windows.h>

using namespace std;

struct Student
{
    char surname[30], name[30], secondName[30];
    int year, group, markPhys, markMath, markInform, markChem;
    double averMark;
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numStud, i, needGroup;
    Student arr[100];
    cout << "Введите количество студентов: " << endl;
    cin >> numStud;
    for (i = 0; i < numStud; i++) {
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
    cout << endl << "Введите номер нужной группы: ";
    cin >> needGroup;
    for (i = 0; i < numStud; i++) {
            if ((arr[i].group == needGroup) && (arr[i].markPhys >= 9) && (arr[i].markMath >= 9) && (arr[i].markInform >= 9) && 
                    (arr[i].markChem >= 9)) {
                cout << "Cтудент: " << arr[i].surname << " " << arr[i].name << " " << arr[i].secondName << endl;
                cout << "Год рождения:  " << arr[i].year << endl;
                cout << "Номер группы: " << arr[i].group << endl;
                cout << "Оценка по физике: " << arr[i].markPhys << endl;
                cout << "Оценка по математике: " << arr[i].markMath << endl;
                cout << "Оценка по информатике: " << arr[i].markInform << endl;
                cout << "Оценка по химии: " << arr[i].markChem << endl;
                cout << "Средний балл: " << arr[i].averMark << endl << endl;
            }
        }
}


//void StudInfo() {
//    cout << endl <<  "Фамилия студента: ";
//    cin >> student.surname;
//    cout << endl << "Имя студента: ";
//    cin >> student.name;
//    cout << endl << "Отчество студента: ";
//    cin >> student.secondName;
//    cout << endl << "Год рождения: " ;
//    cin >> student.year;
//    cout << endl << "Группа: ";
//    cin >> student.group;
//    cout << endl << "Оценка по физике: ";
//    cin >> student.markPhys;
//    cout << endl << "Оценка по математике: ";
//    cin >> student.markMath;
//    cout << endl << "Оценка по информатике: ";
//    cin >> student.markInform;
//    cout << endl << "Оценка по химии: ";
//    cin >> student.markChem;
//    student.averMark = (student.markPhys + student.markMath + student.markInform + student.markChem) / 4.0;
//    cout << endl << "Средний балл за семестр: " << student.averMark << endl;
//}

//void ExellentStudInfo() {
//    cout << "Cтудент: " << student.surname << " " << student.name << " " << student.secondName << endl;
//    cout << "Год рождения:  " << student.year << endl;
//    cout << "Номер группы: " << student.group << endl;
//    cout << "Оценка по физике: " << student.markPhys << endl;
//    cout << "Оценка по математике: " << student.markMath << endl;
//    cout << "Оценка по информатике: " << student.markInform << endl;
//    cout << "Оценка по химии: " << student.markChem << endl;
//    cout << "Средний балл: " << student.averMark << endl;
//}