class element//������� �������
{
	friend class queue;//����� queue ����� ������������ ��� ���������� ����� ������ element
protected:
	element* next;//��������� �� ��������� �������
	char c;//������, ������� ������ ������ ������� �������
	void shif()//������� ������ c
	{
		if (c >= 97)
		{
			c = (((c - 97) + *ptr_bias) % 26) + 97;
		}
		else
		{
			if (c >= 65)
			{
				c = (((c - 65) + *ptr_bias) % 26) + 65;
			}
		}
	}
	void de_shif()//��������� ������ c
	{
		if (c >= 97)
		{
			c = (((c - 71) - *ptr_bias) % 26) + 97; //71 = 97 - 26
		}
		else
		{
			if (c >= 65)
			{
				c = (((c - 39) - *ptr_bias) % 26) + 65; //39 = 65 - 26
			}
		}
	}
	void del()//��������������� ������� ��� ������� ������� �������
	{
		if (this->next != NULL)
		{
			this->next->del();
		}
		delete(this);
	}
};

class queue//���� �������
{
protected:
	element* FIRST;//��������� �� ������ �������
	element* END;//��������� �� ����� �������
public:
	queue()//�� ��������� ��������� �� ������ � ����� ������ ����� 0
	{
		FIRST = NULL;
		END = NULL;
	}
	void add(char symbol)//����� ���������� ������� � �������
	{
		if (FIRST == NULL)//���� ������� �����
		{
			FIRST = new element;
			FIRST->next = NULL;
			END = FIRST;
			FIRST->c = symbol;
		}
		else//���� ������� �� �����
		{
			END->next = new element;
			END = END->next;
			END->next = NULL;
			END->c = symbol;
		}
	}
	void clean()//����� ������� �������
	{
		if (FIRST != NULL)
		{
			FIRST->del();
			FIRST = NULL;
			END = NULL;
		}
	}
	void out()//����� �������, ������� ��� �������� ������� �� ����� �� ������� � ����������
	{
		element* print = FIRST;
		while (print != NULL)
		{
			cout << print->c;
			print = print->next;
		}
	}
	void file_out()//������ ������� � ����
	{
		if (FIRST != NULL)
		{
			ofstream file(filename, ios_base::trunc | ios_base::out);//�������� ����� ��� ������ � ��� ��������������� ��������
			element* print = FIRST;
			while (print != NULL)
			{
				file << print->c;
				print = print->next;
			}
			file.close();
		}
	}
	void shif()//������� ��� �������
	{
		element* ref = FIRST;
		while (ref != NULL)
		{
			ref->shif();
			ref = ref->next;
		}
	}
	void de_shif()//��������� ��� �������
	{
		element* ref = FIRST;
		while (ref != NULL)
		{
			ref->de_shif();
			ref = ref->next;
		}
	}
	bool emp()//���� ������� ������ ���������� true ����� false
	{
		if (FIRST == NULL)
		{
			return (true);
		}
		return(false);
	}
};
//a-97  A-65