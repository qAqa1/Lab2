void keyboard_input()//������ ���� ������
{
	cin.sync();
	char input[5000] = {};
	cout << "������� ���������: ";
	cin.getline(input, 4999);
	for (int x = 0; input[x] != 0; x++)
	{
		massage.add(input[x]);
	}
}

void file_input()//���� ������ �� �����
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "���� " << filename << " �� c���������!" << endl << endl;
		return;
	}

	if (file.peek() == EOF)
	{
		cout << "���� ����!" << endl << endl;
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

bool exist(string filename)//�������� �� ������������� �����
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << endl << "���� '" << filename << "' �� c���������!" << endl;
		return(0);
	}
	return(1);
}

void change_file()//��������� ����� �������� �����
{
	cout << "������ ������������: " << filename << endl;
	string str;
	cout << endl << "������� ��� ������ �����: ";
	cin >> str;
	if (exist(str) == 0)
	{
		cout << endl << "��� ����� �� ���� ��������!" << endl << endl;
	}
	else
	{
		filename = str;
		cout << endl << "��� ����� ���� ������� ��������" << endl << endl;
	}
}