queue massage;//(��)��������� ���������
#include "input.h"//������� ��� ����� ������ � ���������

void menu()//������� ���� ���������
{
	cout << "���������: ";
	if (massage.emp())//���� ������� massage �����
	{
		cout << "(�����)";
	}
	else
	{
		massage.out();
	}
	cout <<endl<< "�������� = "<< bias;
	cout << endl << endl << "������� 1 ��� ����,����� ������ ��������� �������" << endl << "������� 2 ��� ����,����� ������������ ��������� �� �����" << endl << "������� 3 ��� ����,����� ������ ��������" << endl << "������� 0 ��� ����,����� �������� ������������ ����" << endl << endl << "������� ������� ������ ��� ����,����� ����������� ���������" << endl << "������� ������� ����� ��� ����,����� ������������ ���������" << endl << "������� Enter ��� ����, ����� �������� ��������� � ����" << endl << "������� Escape ��� ����, ����� ������� ���������";
	switch (_getch())
	{
	case '1':
		system("cls");
		massage.clean();
		keyboard_input();
		system("cls");
		break;
	case '2':
		system("cls");
		massage.clean();
		file_input();
		break;
	case '3':
		system("cls");
		cout << "������� ��������: ";
		cin >> *ptr_bias;
		if (abs(*ptr_bias) > 26)
		{
			if (*ptr_bias < 0)//���� �������� ������������
			{
				*ptr_bias = *ptr_bias * -1;
				*ptr_bias = *ptr_bias % 26;
				*ptr_bias = *ptr_bias * -1;
			}
			else//���� �������� 0 ��� ������
			{
				*ptr_bias = *ptr_bias % 26;
			}

		}
		system("cls");
		break;
	case '0':
		system("cls");
		change_file();//����� ����� �����
		break;
	case 77://77 - ��� ������� ������
		system("cls");
		if (*ptr_bias < 0)//���� �������� ������������
		{
			*ptr_bias = *ptr_bias * -1;
			 massage.de_shif();
			*ptr_bias = *ptr_bias * -1;
		}
		else//���� �������� 0 ��� ������
		{
			massage.shif();
		}
		break;
	case 75://75 - ��� ������� �����
		system("cls");
		if (*ptr_bias < 0)//���� �������� ������������
		{
			*ptr_bias = *ptr_bias * -1;
			 massage.shif();
			*ptr_bias = *ptr_bias * -1;
		}
		else//���� �������� 0 ��� ������
		{
			massage.de_shif();
		}	
		break;
	case 13: //13 - ��� ������� Enter
		system("cls");
		massage.file_out();
		cout << "��������� �������� � ����" << endl << endl;
		break;
	case 27: //27 - ��� ������� Esc
		exit(0);
	default:
		system("cls");
		break;
	}
	menu();
}