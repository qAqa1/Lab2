/*Фантров А Бис-21
Лабораторная 2
Шифр Цезаря*/
#include<iostream>
#include<vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;
int bias = 1;//смещение
int *ptr_bias = &bias;//ссылка на смещение для ускорения работы программы
string filename = "text.txt";//имя используемого файла

#include "queue.h"//очередь и её методы
#include "menu.h"//главное меню программы

void main()
{
	setlocale(LC_ALL, "russian");
	menu();
}