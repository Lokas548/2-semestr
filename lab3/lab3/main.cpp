#include <iostream>
#include <chrono>
const int N = 100000;
const int M = 10000;
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

int binSearch(int mas[], int left, int right, int key)
{
	if (key == mas[left])
		return left;
	if (key < mas[left])
		return -1;
	if (key == mas[right])
		return right;
	if (key > mas[right])
		return -1;
	while (left + 1 < right)
	{
		int c = (left + right) / 2;
		if (key > mas[c])
			left = c;
		else
			right = c;
	}
	if (key == mas[right])
		return right;
	else
		return -1;
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

double Function(double x)
{
	return log(x) - 1;
}

double Bisection(double left, double right)
{
	double eps = 1e-4;
	while (1)
	{
		double x = (left + right) / 2;
		if ((abs(x - left) < eps) && (abs(x - right) < eps))
			return x;
		else if (Function(x) * Function(left) > 0)
			left = x;
		else
			right = x;
		cout << x << " ";
	}
}

int main()
{
	int mas[N];
	int a = 0;
	int b = N - 1;
	int key[M];
	double left = 0;
	double right = 3;


	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 10000 + 1;
	}

	Timer time;
	// Количество рандомных запросов

	for (int i = 0; i < M; i++) {
		key[i] = rand()% 10000 + 1;
	}

	for (int i = 0; i < M; i++){ 
			//binSearch(mas, a, b, key[i]);
			findElement(mas, key[i]);
	}
	

	//cout << "x = " << Bisection(left, right) << endl;
	cout << "Time: " << time.elapsed() << endl;
	return 0;
}