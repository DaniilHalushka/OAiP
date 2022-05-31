#include <iostream>
#include <Windows.h>

using namespace std;

struct queue {
    int info;
    queue* next, * prev;
} *head, *tail, *tail_del;

queue* push_head(queue* list, int x) {
    queue* t = new queue;
    if (head == NULL) {
        t->next = t->prev = NULL;
        t->info = x;
        head = tail = t;
    }
    else {
        t->prev = NULL;
        t->next = list;
        t->info = x;
        list->prev = t;
    }
    return t;
}

queue* push_tail(queue* list, int x) {
    queue* t = new queue;
    if (tail == NULL) {
        t->next = t->prev = NULL;
        t->info = x;
        head = tail = t;
    }
    else {
        t->next = NULL;
        t->prev = list;
        t->info = x;
        list->next = t;

    }
    return t;
}

void view_head(queue* list) {
    while (list != NULL) {
        cout << list->info << " ";
        list = list->next;
    }
    cout << endl;
}
void view_tail(queue* list) {
    while (list != NULL) {
        cout << list->info << " ";
        list = list->prev;
    }
    cout << endl;
}

void delete_every_2(queue* begin) {
    queue *p1, *p2;			                                                                             
    for (p1 = begin, p2 = p1->next; p2 != NULL; p2 = p1->next) {
        p1->next = p2->next;
        if (p2->next == NULL) {
            delete p2;
            break;
        }
        p2->next->prev = p2->prev;
        p1 = p2->next;																	
        delete p2;
        tail_del = p1;
    }																				
}

void del_queue(queue** p) {
    queue* t;
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    int menu = 0, element = 0, choose = 0, quantity = 0;
    while (true) {
        cout << "Выберите пункт, который надо выполнить" << "\n";
        cout << "1 – Создание очереди" << "\n";
        cout << "2 – Добавление элементов в очередь" << "\n";
        cout << "3 – Просмотр очереди" << "\n";
        cout << "4 - Выполнение индивидуального задания " << "\n";
        cout << "5 – Освобождение памяти, занятой очередью" << "\n";
        cout << "6 – Завершение программы " << "\n";
        cout << "Введите номер пункта: ";
        cin >> menu;
        switch (menu) {
        case 1: {
            system("cls");
            cout << "Из скольки элементов должна состоять очередь?" << "\n";
            cin >> quantity;
            for (int i = 0; i < quantity; i++) {
                cout << "Введите число: ";
                cin >> element;
                tail = push_tail(tail, element);
                system("cls");
            }
            break;
        }
        case 2: {
            system("cls");
            cout << "Как вы хотите добавить элементы в очередь?: " << "\n";
            cout << "1 - В начало очереди" << "\n";
            cout << "2 - В конец очереди" << "\n";
            cout << "Выберите вариант: " << "\n";
            cin >> choose;
            switch (choose) {
            case 1: {
                cout << "Сколько элементов вы хотите добавить?" << "\n";
                cin >> quantity;
                for (int i = 0; i < quantity; i++) {
                    cout << "Введите число: ";
                    cin >> element;
                    head = push_head(head, element);
                    system("cls");
                }
                break;
            }
            case 2: {
                cout << "Сколько элементов вы хотите добавить?" << "\n";
                cin >> quantity;
                for (int i = 0; i < quantity; i++) {
                    cout << "Введите число: ";
                    cin >> element;
                    tail = push_tail(tail, element);
                    system("cls");
                }
                break;
            }
                  break;
            }
            break;
        }
        case 3: {
            system("cls");
            cout << "Как вы хотите просмотреть очередь?: " << "\n";
            cout << "1 - С начала" << "\n";
            cout << "2 - С конца" << "\n";
            cout << "Выберите вариант: " << "\n";
            cin >> choose;
            switch (choose) {
            case 1: {
                cout << "Просмотр очереди с начала" << "\n";
                view_head(head);
                break;
            }
            case 2: {
                cout << "Просмотр очереди с конца" << "\n";
                view_tail(tail);
                break;
            }
            }
            break;   
        }
        case 4: {
            delete_every_2(head);
            tail = tail_del;
            system("cls");
            break;
        }
        case 5: {
            del_queue(&head);
            head = NULL;
            tail = NULL;
            system("cls");
            break;
        }
        case 6: {
            exit(0);
        }
        }
    }
}





//void create(queue** begin, queue ** end, int info) {
//    queue* t = new queue;
//    t->info = info;
//    t->next = NULL;
//    t->prev = NULL;
//    if (*begin == NULL) 		// Формирование первого элемента
//        *begin = *end = t;
//    if (*end == NULL)
//        *begin = *end = t;
//    else {// Добавление элемента в конец
//        t->prev = *end;
//        (*end)->next = t; //доделать указатели с prev
//        *end = t;
//    }
//}
