#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
using namespace std;
int task;
int ShiftRight3(int *a, int *b, int *c);
int ShiftLeft3(int *a, int *b, int *c);
int IsLeapYear(int year);
int MonthDays(int month, int year);
void PreviousDate(int year, int month, int day);
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
				int year, month;
				cout << "Введите год - ";
				cin >> year;
				cout << "Введите месяц - ";
				cin >> month;
				IsLeapYear(year);
				MonthDays(month, year);
				cout << "Дней в " << month << "-м месяце - " << MonthDays(month, year) << endl;
				
			} break;

			case 5:
			{
				/*5.	Используя функцию MonthDays из задания 4, описать процедуру PrevDate(D, M, Y), 
					которая по информации о правильной дате, включаю - щей день D, 
					номер месяца M и год Y, определяет предыдущую дату
					(пара - метры целого типа D, M, Y являются одновременно входными и выходными).
					Применить процедуру PrevDate к трем исходным датам и вывести полученные значения предыдущих дат*/
				int day, month, year;
				cout << "Введите год - ";
				cin >> year;
				cout << "Введите месяц - ";
				cin >> month;
				cout << "Введите дату - ";
				cin >> day;
				PreviousDate(year, month, day);

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

int MonthDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (IsLeapYear(year) == 1)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

void PreviousDate(int year, int month, int day)
{
	
	if (day < 1 && day >31)
	{
		cout << "Введите правильную дату";
	}
	else if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;

		if (month == 1)
			month = 12;
		else
			month = month - 1;
		day = MonthDays(month, year);
	}
	else
		day = day - 1;

	cout << "дата предыдущего дня: " << day << "." <<month << "." <<year << endl;
}