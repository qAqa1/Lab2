/*������� � ���-21
������������ 2
���� ������*/
#include<iostream>
#include<vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;
int bias = 1;//��������
int *ptr_bias = &bias;//������ �� �������� ��� ��������� ������ ���������
string filename = "text.txt";//��� ������������� �����

#include "queue.h"//������� � � ������
#include "menu.h"//������� ���� ���������

void main()
{
	setlocale(LC_ALL, "russian");
	menu();
}