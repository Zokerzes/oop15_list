#include "List2.h"

List2::List2()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List2::List2(const List2& L)
{
	Head = Tail = NULL;
	Count = 0;
	//Голова списка, из которого копируем
	Elem* temp = L.Head;
	//Пока не конец списка
	while (temp != 0)
	{
		//Передираем данные
		AddTail(temp->data);
		temp = temp->next;
	}
}

List2::~List2()
{
	//Удаляем все элементы
	DelAll();
}

int List2::GetCount()
{
	return Count;
}

Elem* List2::GetElem(int pos)
{
	Elem* temp = Head;
	//Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
		return 0;
	}
	int i = 1;
	//Ищем нужный нам элемент
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}

void List2::DelAll()
{
	//Пока остаются элементы, удаляем по одному с головы
	while (Count != 0)
		Del(1);
}

void List2::Del(int pos)
{
	//если параметр отсутствует или равен 0,
 //то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	//Счетчик
	int i = 1;
	Elem* Del = Head;
	while (i < pos)
	{
		//Доходим до элемента,
		//который удаляется
		Del = Del->next;
		i++;
	}
	//Доходим до элемента,
	//который предшествует удаляемому
	Elem* PrevDel = Del->prev;
	//Доходим до элемента, который следует за удаляемым 
	Elem* AfterDel = Del->next;
	//Если удаляем не голову
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	//Если удаляем не хвост
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	//Удаляются крайние?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;
	//Удаление элемента
	delete Del;
	Count--;
}

void List2::Insert(int pos)
{
	//если параметр отсутствует или равен 0,
	 //то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//Позиция от 1 до Count?
	if (pos < 1 || pos > Count + 1)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	//Если вставка в конец списка
	if (pos == Count + 1)
	{
		//Вставляемые данные
		int data;
		cout << "Input new number: ";
		cin >> data;
		//Добавление в конец списка
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		//Вставляемые данные
		int data;
		cout << "Input new number: ";
		cin >> data;
		//Добавление в начало списка
		AddHead(data);
		return;
	}
	//Счетчик
	int i = 1;
	//Отсчитываем от головы n - 1 элементов
	Elem* Ins = Head;
	while (i < pos)
	{
		//Доходим до элемента,
		//перед которым вставляемся
		Ins = Ins->next;
		i++;
	}
	//Доходим до элемента,
	//который предшествует
	Elem* PrevIns = Ins->prev;
	//Создаем новый элемент
	Elem* temp = new Elem;
	//Вводим данные
	cout << "Input new number: ";
	cin >> temp->data;
	//настройка связей
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}

void List2::AddTail(int n)
{
	//Создаем новый элемент
	Elem* temp = new Elem;
	//Следующего нет
	temp->next = 0;
	//Заполняем данные
	temp->data = n;
	//Предыдущий - бывший хвост
	temp->prev = Tail;
	//Если элементы есть?
	if (Tail != 0)
		Tail->next = temp;
	//Если элемент первый, то он одновременно
	//и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		//иначе новый элемент - хвостовой
		Tail = temp;
	Count++;
}

void List2::AddHead(int n)
{
	//новый элемент
	Elem* temp = new Elem;
	//Предыдущего нет
	temp->prev = 0;
	//Заполняем данные
	temp->data = n;
	//Следующий - бывшая голова
	temp->next = Head;
	//Если элементы есть?
	if (Head != 0)
		Head->prev = temp;
	//Если элемент первый, то он одновременно
 //и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		//иначе новый элемент - головной
		Head = temp;
	Count++;

}

void List2::Print()
{
	//Если в списке присутствуют элементы, 
 //то пробегаем по нему
 //и печатаем элементы, начиная с головного 
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

void List2::Print(int pos)
{
	//Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	Elem* temp;
	//Определяем с какой стороны
	//быстрее двигаться
	if (pos <= Count / 2)
	{
		//Отсчет с головы
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			//Двигаемся до нужного элемента
			temp = temp->next;
			i++;
		}
	}
	else
	{
		//Отсчет с хвоста
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			//Двигаемся до нужного элемента
			temp = temp->prev;
			i++;
		}
	}
	//Вывод элемента
	cout << pos << " element: ";
	cout << temp->data << endl;
}
