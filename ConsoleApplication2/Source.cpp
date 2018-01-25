#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#define size 10
using namespace std;
int length = size, task;
int ShiftRight3(int *a, int *b, int *c);
int ShiftLeft3(int *a, int *b, int *c);
int IsLeapYear(int year);
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	do
	{
		cout << "Введите номер задания - ";
		cin >> task;
		switch (task)
		{
			case 1:
			{
				/*1.	Описать процедуру ShiftRight3(A, B, C), выполняющую правый циклический сдвиг :
				значение A переходит в B, значение B — в C, значение C — в A
				(A, B, C — вещественные параметры, являющиеся одновременно входными и выходными).
					С помощью этой процедуры выполнить правый циклический сдвиг для двух данных наборов из трех чисел :
				(A1, B1, C1) и(A2, B2, C2).*/
				int a, b, c;
				a = -10 + rand() % 20;
				cout << "a == " << a << endl;
				b = -10 + rand() % 20;
				cout << "b == " << b << endl;
				c = -10 + rand() % 20;
				cout << "c == " << c << endl;
				ShiftRight3(&a, &b, &c);
				cout << "ЗАМЕНА!!!" << endl;
				cout << "a == " << a << endl;
				cout << "b == " << b << endl;
				cout << "c == " << c << endl;
			} break;

			case 2:
			{
				/*2.	Описать процедуру ShiftLeft3(A, B, C), выполняющую левый циклический сдвиг 
					: значение A переходит в C, значение C — в B, значение B — в A(A, B, C — вещественные параметры, 
						являющиеся одновременно входными и выходными).С помощью этой процедуры выполнить 
					левый циклический сдвиг для двух данных наборов из трех чисел : (A1, B1, C1) и(A2, B2, C2).*/
				int a, b, c;
				a = -10 + rand() % 20;
				cout << "a == " << a << endl;
				b = -10 + rand() % 20;
				cout << "b == " << b << endl;
				c = -10 + rand() % 20;
				cout << "c == " << c << endl;
				ShiftLeft3(&a, &b, &c);
				cout << "ЗАМЕНА!!!" << endl;
				cout << "a == " << a << endl;
				cout << "b == " << b << endl;
				cout << "c == " << c << endl;
			} break;

			case 3:
			{
				/*3.	Описать функцию IsLeapYear(Y) логического типа, которая возвращает True, если 
					год Y(целое положительное число) является високосным, и False в противном случае.
					Вывести значение функции IsLeapYear для пяти данных значений параметра Y.
					Високосным считается год, делящийся на 4, за исключением тех годов, которые делятся на 100 и не делятся на 400.*/
				int year;
				cout << "Введите год - ";
				cin >> year;
				IsLeapYear(year);
				if (IsLeapYear(year) == 1)
					cout << "Високосный год!!!" << endl;
				else
					cout << "Невисокосный год!!" << endl;

			} break;

			case 4:
			{
				/*4.	Используя функцию IsLeapYear из задания 3, описать функцию MonthDays(M, Y) целого типа,
					которая возвращает количество дней для M - го месяца года Y(1 ≤ M ≤ 12, Y > 0 — целые числа).
					Вывести значение функции MonthDays для данного года Y и месяцев M1, M2, M3.*/
			} break;
		}
	} while (task > 0);
}

int ShiftRight3(int *a, int *b, int *c)
{
	int temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
	return 0;
}

int ShiftLeft3(int *a, int *b, int *c)
{
	int temp = *a;
	*a = *c;
	*c = *b;
	*b = temp;
	return 0;
}

int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}