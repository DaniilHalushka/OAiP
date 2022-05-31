#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

struct Stack {
	int info;	     // Информационная часть элемента, например int
	Stack* next;    // Адресная часть – указатель на следующий элемент 
} *begin;


void push(Stack **top, int inform) {
	Stack* new_el; //Создаем новый указатель (элемент)
	new_el = new Stack(); //выделяем память для него
	new_el->info = inform; //Записываем inform в info элемента
	new_el->next = *top; //Проводим связь от нового элемента к вершине
	*top = new_el; //Вершиной теперь является новый элемент
}

void view(Stack* p) {
	if (p == NULL) cout << "Стека не существует" << "\n";
	while (p != NULL) {		//пока мы не дошли до последнего элемента, где указатель next = NULL
		cout <<  p->info << endl;
		p = p->next;		// тут переставаяем указатель на следующий элемент стека
	}
}

void del_stack(Stack** p) {
	Stack* t;		// создаём указатель на структуру
	while (*p != NULL) {	// пока наш next не равен NULL (не дошли до последнего элемента)
		t = *p;		//тут мы создаём вспомогательный указатель, чтобы работать с ним, т.к. р мы потом передаём другое значение
		*p = (*p)->next;	//тут передаём текущему р значение указателя (адрес ячейки памяти) следующего элемента
		delete t;		// удаляем наш текущий элемент
	}
}

void delete_every_2(Stack* begin) {
	Stack *p1, *p2;			//создаем вспомогательные указатели для работы со структурой
																					//p1 идёт с начала, р2 - следующий за первым;
	for (p1 = begin, p2 = p1->next; p2 != NULL; p2 = p1->next) {		//пока указатели не примут значение NULL;
																					//сдвигание указателя р2 на следующий за р1;																				
		p1->next = p2->next;														//next следующего за р1 переходит в послеследующий (сдвиг на 2)
		p1 = p2->next;																//теперь р1 - следующий за р2	
		delete p2;																	//удаляем наш р2 (который текущий четный элемент)
		if (p1 == NULL) break;														//если p1 стал NULL, то мы завершаем цикл (заодно и функцию)
	}																				//итерация цикла (сдвиг указателя)
}

void pop(Stack** p) {
	Stack* t;		// создаём указатель на структуру
	t = *p;		//тут мы создаём вспомогательный указатель, чтобы работать с ним, т.к. р мы потом передаём другое значение
	*p = (*p)->next;	//тут передаём текущему р значение указателя (адрес ячейки памяти) следующего элемента
	delete t;		// удаляем наш текущий элемент
}


void sort_by_key(Stack* p) {						//по сути та же пузырьковая сортировка
	Stack *t = NULL, *t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)	//начало с begin, пока не NULL, итерация перемещением указателя
			if (t1->info > t1->next->info) {		//если ближайший больше того, который идет после, то меняем значения
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;						
	} while (p->next != t);			//и так до начального
}

void sort_by_adresses(Stack** p) {
	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;		//если ячейка памяти послеследующего элемента принимает значение NULL, то прерываем выполнение функции
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)		//начало с t1(begin), пока послеследующий не NULL, итерация сдвигом указателя
			if (t1->next->info > t1->next->next->info) {		//если ключ следующего больше ключа послеследующего, то начинаем
				r = t1->next->next;								//вспомогательному указателю передаём адрес послеследующего
				t1->next->next = r->next;						//сам же послеследующий у нас принимает значение послепослеследующего
				r->next = t1->next;								//послепослеследующий принимает значение следующего за начальным
				t1->next = r;									//следующий за начальным становится послеследующим
			}
		t = t1->next;											//теперь у нас t следующий за t1
	} while ((*p)->next->next != t);							//пока ячейка памяти не примет значение, которое у третьего элемента
}




int main()
{
	setlocale(LC_ALL, "ru");
	int menu = 0, choose = 0, element = 0;
	Stack *begin = NULL; //в начале программы у нас нет стека, вершины тоже нет, даем ей значение NULL
	while (true) {
		cout << "Выберите пункт, который надо выполнить:" << "\n";
		cout << "1 - Создание стека" << "\n";
		cout << "2 - Просмотр стека" << "\n";
		cout << "3 - Добавление элемента в стек" << "\n";
		cout << "4 - Сортировка стека" << "\n";
		cout << "5 - Решение индивидуального задания" << "\n";
		cout << "6 - Удаление стека" << "\n";
		cout << "7 - Завершение программы" << "\n";
		cout << "Введите номер пункта: ";
		cin >> menu;
		switch (menu) {
		case 1: {
			system("cls");
			cout << "Как вы хотите создать стек?: " << "\n";
			cout << "1 - Вручную " << "\n";
			cout << "2 - Задать рандомно" << "\n";
			cout << "Выберите вариант: " << "\n";
			cin >> choose;
			switch (choose) {
			case 1: {
				system("cls");
				cout << "Введите количество элементов, которые вы хотите внести в стек: " << "\n";
				cin >> choose;
				for (int i = 0; i < choose; i++) {
					cout << "Введите элемент № " << i + 1 << "\n";
					cin >> element;
					push(&begin, element);
				}
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				cout << "Введите количество элементов, которые вы хотите внести в стек: " << "\n";
				cin >> choose;
				srand(time(NULL));
				for (int i = 0; i < choose; i++) {
					int element = rand() % 20;
					push(&begin, element);
				}
				system("cls");
				break;
			}
				  break;
			}
			break;
		}
		case 2: {
			system("cls");
			view(begin);
			break;
		}
		case 3: {
			system("cls");
			cout << "Введите элемент, который вы хотите внести в стек: " << "\n";
			cin >> element;
			push(&begin, element);
			break;
		}
		case 4: {
			system("cls");
			cout << "Как вы хотите отсортировать стек?: " << "\n";
			cout << "1 - По ключу" << "\n";
			cout << "2 - По адресам" << "\n";
			cout << "Выберите вариант: " << "\n";
			cin >> choose;
			switch (choose) {
			case 1: {
				sort_by_key(begin);
				break;
			}
			case 2: {
				push(&begin, 0);
				sort_by_adresses(&begin);
				pop(&begin);
			}
				  break;
			}
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			delete_every_2(begin);
			cout << "В стеке был удалён каждый второй элемент" << "\n";
			break;
		}
		case 6: {
			system("cls");
			del_stack(&begin);
			cout << "Стек удалён" << "\n";
			break;
		}
		case 7: {
			exit(0);
		}
		}
	}
}
