class element//элемент очереди
{
	friend class queue;//класс queue может использовать все защищённые члены класса element
protected:
	element* next;//указатель на следующий элемент
	char c;//символ, который хранит данный элемент очереди
	void shif()//шифрует символ c
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
	void de_shif()//дешифрует символ c
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
	void del()//вспомогательная функция для функции очистки очереди
	{
		if (this->next != NULL)
		{
			this->next->del();
		}
		delete(this);
	}
};

class queue//сама очередь
{
protected:
	element* FIRST;//указатель на начало очереди
	element* END;//указатель на конец очереди
public:
	queue()//по умолчанию указатели на начало и конец списка равны 0
	{
		FIRST = NULL;
		END = NULL;
	}
	void add(char symbol)//метод добавления элемета в очередь
	{
		if (FIRST == NULL)//если очередь пуста
		{
			FIRST = new element;
			FIRST->next = NULL;
			END = FIRST;
			FIRST->c = symbol;
		}
		else//если очередь не пуста
		{
			END->next = new element;
			END = END->next;
			END->next = NULL;
			END->c = symbol;
		}
	}
	void clean()//метод очистки очереди
	{
		if (FIRST != NULL)
		{
			FIRST->del();
			FIRST = NULL;
			END = NULL;
		}
	}
	void out()//метод который, выводит все элементы очереди на экран от первого к последнему
	{
		element* print = FIRST;
		while (print != NULL)
		{
			cout << print->c;
			print = print->next;
		}
	}
	void file_out()//запись очереди в файл
	{
		if (FIRST != NULL)
		{
			ofstream file(filename, ios_base::trunc | ios_base::out);//открытие файла для записи с его предварительной очисткой
			element* print = FIRST;
			while (print != NULL)
			{
				file << print->c;
				print = print->next;
			}
			file.close();
		}
	}
	void shif()//шифрует всю очередь
	{
		element* ref = FIRST;
		while (ref != NULL)
		{
			ref->shif();
			ref = ref->next;
		}
	}
	void de_shif()//дешифрует всю очередь
	{
		element* ref = FIRST;
		while (ref != NULL)
		{
			ref->de_shif();
			ref = ref->next;
		}
	}
	bool emp()//если очередь пустая возвращает true иначе false
	{
		if (FIRST == NULL)
		{
			return (true);
		}
		return(false);
	}
};
//a-97  A-65