#include <iostream>
const int N = 10;

struct List
{
	List* next;
	int number;
};

void ADD(List* head, int age)
{
	List* p = new List;
	p->number = age;

	p->next = head->next;
	head->next = p;
}

void PRINT(List* head)
{
	List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->number << std::endl;
		p = p->next;
	}
}

void DELETE(List* head)
{
	List* tmp;
	List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->number % 2 == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
}

void CLEAR(List* head)
{
	List* tmp;
	List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

void DUPLICATE(List* head)
{
	List* p = head->next;
	while (p != nullptr)
	{
		if (p->number % 2 == 1)
		{
			List* q = new List;
			q->next = p->next;
			p->next = q;
			q->number = p->number;
			p = p->next;
		}
		p = p->next;
	}
}

bool SEARCH(List* head, int key)
{
	List* p = head;
	while (p != nullptr)
	{
		p = p->next;
		if (p->number == key) {
			std::cout << key  << " ";
			return true;
		}
	}
	return false;
}

int main()
{
	int key = 1;
	List* head = new List;
	head->next = nullptr;

	for (int i = 0; i < N; i++) {
		ADD(head, i);
	}
	

	DELETE(head);
	//DUPLICATE(head);
	PRINT(head);
	SEARCH(head, key);

	CLEAR(head);

	delete head;
	return 0;
}
