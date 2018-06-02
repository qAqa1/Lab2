void keyboard_input()//ручной ввод текста
{
	cin.sync();
	char input[5000] = {};
	cout << "Введите сообщение: ";
	cin.getline(input, 4999);
	for (int x = 0; input[x] != 0; x++)
	{
		massage.add(input[x]);
	}
}

void file_input()//ввод текста из файла
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Файл " << filename << " не cуществует!" << endl << endl;
		return;
	}

	if (file.peek() == EOF)
	{
		cout << "Файл пуст!" << endl << endl;
		return;
	}
	char file_text[4000];
	while (!file.eof())
	{
		file.getline(file_text, 3999);
		for (int x = 0; file_text[x] != 0; x++)
		{
			massage.add(file_text[x]);
		}
	}
}

bool exist(string filename)//проверка на существование файла
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << endl << "Файл '" << filename << "' не cуществует!" << endl;
		return(0);
	}
	return(1);
}

void change_file()//изменение имяни рабочего файла
{
	cout << "Сейчас используется: " << filename << endl;
	string str;
	cout << endl << "Введите имя нового файла: ";
	cin >> str;
	if (exist(str) == 0)
	{
		cout << endl << "Имя файла не было изменено!" << endl << endl;
	}
	else
	{
		filename = str;
		cout << endl << "Имя файла было успешно изменено" << endl << endl;
	}
}