#include <iostream>
#include <chrono>
#include <vector>
const int N = 10;

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

int main()
{
	std::vector <int> array(N);
	for (int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 50;
		//std::cout << mass[i] << " ";
	}
	std::cout << '\n';

	Timer t;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0)
		{
			array.insert(array.begin() + i + 1, array[i]);
			i++;
		}
	}

	std::cout << "time: " << t.elapsed() << std::endl;

	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}

	return 0;


}