//Реализуйте алгоритм быстрой сортировки по его псевдокоду. Реализуйте алгоритм сортировки пузырьком из лекции 1. 
//Исследуйте при помощи класса Timer время выполнения на разных объемах входных данных(n = 10, n = 100, n = 100 000, n = 1 000 000).
//Объясните полученный результат.


#include <iostream>
#include <chrono>
const int N = 10;
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

void QUICKSORT(int a, int b, int mas[N])
{
	if (a >= b)
		return;
	int m = (a + b) / 2 + 1;
	int k = mas[m];
	int l = a - 1;
	int r = b + 1;
	while (1)
	{
		do
		{
			l++;
		} while (mas[l] < k);
		do
		{
			r--;
		} while (mas[r] > k);
		if (l >= r)
			break;
		std::swap(mas[l], mas[r]);
	}
	r = l;
	l = l - 1;
	QUICKSORT(a, l, mas);
	QUICKSORT(r, b, mas);
}

void BUBBLESORT(int mas[N], int n)
{
	bool swap = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				std::swap(mas[j], mas[j + 1]);
				swap = true;
			}
		}
		if (swap == false)
			break;
	}
}

int main()                                       //время сортировки
                                                       //b.s(n^2)        q.s(nlogn)
	                                           //_____________________________
{                                              //10    |0,0025929   0,0033267
	int mas[N];                                //100   |0,000194    0,0250766
	int first = 0;                             //1000  |0,515654    0,554732
	int last = N - 1;                          //10000 |6,03129     4,61178
	                                           //100000|242,025     17,7755

	for (int i = 0; i < N; i++)
		mas[i] = rand();

	Timer time;

	//BUBBLESORT(mas, N);
	QUICKSORT(first, last, mas);


	for (int i = 0; i < N; i++) {
		cout << mas[i] << std::endl;
	}
	cout << time.elapsed() << std::endl;

	return 0;

}