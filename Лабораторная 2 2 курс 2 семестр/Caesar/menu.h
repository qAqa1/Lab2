queue massage;//(де)шифруемое сообщение
#include "input.h"//функции для ввода данных в программу

void menu()//главное меню программы
{
	cout << "Сообщение: ";
	if (massage.emp())//если очередь massage пуста
	{
		cout << "(Пусто)";
	}
	else
	{
		massage.out();
	}
	cout <<endl<< "Смещение = "<< bias;
	cout << endl << endl << "Нажмите 1 для того,чтобы ввести сообщение вручную" << endl << "Нажмите 2 для того,чтобы использовать сообщение из файла" << endl << "Нажмите 3 для того,чтобы ввести смещение" << endl << "Нажмите 0 для того,чтобы изменить используемый файл" << endl << endl << "Нажмите Стрелку вправо для того,чтобы зашифровать сообщение" << endl << "Нажмите Стрелку влево для того,чтобы разшифровать сообщение" << endl << "Нажмите Enter для того, чтобы записать сообщение в файл" << endl << "Нажмите Escape для того, чтобы закрыть программу";
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
		cout << "Введите смещение: ";
		cin >> *ptr_bias;
		if (abs(*ptr_bias) > 26)
		{
			if (*ptr_bias < 0)//если смещение отрицательно
			{
				*ptr_bias = *ptr_bias * -1;
				*ptr_bias = *ptr_bias % 26;
				*ptr_bias = *ptr_bias * -1;
			}
			else//если смещение 0 или больше
			{
				*ptr_bias = *ptr_bias % 26;
			}

		}
		system("cls");
		break;
	case '0':
		system("cls");
		change_file();//смена имяни файла
		break;
	case 77://77 - код стрелки вправо
		system("cls");
		if (*ptr_bias < 0)//если смещение отрицательно
		{
			*ptr_bias = *ptr_bias * -1;
			 massage.de_shif();
			*ptr_bias = *ptr_bias * -1;
		}
		else//если смещение 0 или больше
		{
			massage.shif();
		}
		break;
	case 75://75 - код стрелки влево
		system("cls");
		if (*ptr_bias < 0)//если смещение отрицательно
		{
			*ptr_bias = *ptr_bias * -1;
			 massage.shif();
			*ptr_bias = *ptr_bias * -1;
		}
		else//если смещение 0 или больше
		{
			massage.de_shif();
		}	
		break;
	case 13: //13 - код клавиши Enter
		system("cls");
		massage.file_out();
		cout << "Сообщение записано в файл" << endl << endl;
		break;
	case 27: //27 - код клавиши Esc
		exit(0);
	default:
		system("cls");
		break;
	}
	menu();
}