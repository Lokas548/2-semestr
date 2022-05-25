
#include <iostream>
#include <chrono>
#include <cstdlib>
const int N = 10000;
const int M = 1000;
using namespace std;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

struct List
{
	List* next;
	int number;
};

void add(List* head, int number)
{
	List* p = new List;
	p->number = number;

	p->next = head->next;
	head->next = p;
}

void clear(List* head)
{
	List* q;
	List* p = head->next;
	while (p != nullptr)
	{
		q = p;
		p = p->next;
		delete q;
	}

}

void print(List* head)
{
	List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->number << std::endl;
		p = p->next;
	}
}

int findElement(int mas[], int key)
{
	for (int i = 0; i < N; i++) {
		if (mas[i] == key) {
			return i;
		}
	}
	return -1;
}

bool search(List* head, int key)
{
	List* p = head;
	while (p != nullptr) 
	{
		p = p->next;
		if (p->number == key) {
			return true;
		}
	}
	return false;
}


int main()
{
	srand(time(NULL));
	int key[M];
	int mas[N];
	List* head = new List;
	head->next = nullptr;
	int el = 0;

	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 1000 + 1;
	}

	for (int i = 0; i < N; i++)
	{
		el = rand() % 1000 +1;
		add(head, el);
	}


	for (int i = 0; i < M; i++) {
		key[i] = rand() % 1000 + 1;
	}

	Timer time;
	for (int i = 0; i < M; i++) {
		findElement(mas, key[i]);
		//search(head, key[i]);
	}
	cout << "Time: " << time.elapsed() << endl;

	clear(head);
	delete head;
	return 0;
}
