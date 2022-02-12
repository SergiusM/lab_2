#include <iostream>
#include <chrono>
#define N 10

void QuickSort(int a, int b, int* matrix)
{
    if (a >= b) return;
    int m = ((rand() * rand()) % (b - a + 1)) + a;
    int k = matrix[m];
    int l = a - 1;
    int r = b + 1;

    while (1) {
        do {
            l++;
        } while (matrix[l] < k);

        do {
            r--;
        } while (matrix[r] > k);

        if (l >= r) break;
        std::swap(matrix[l], matrix[r]);
    }
    r = l;
    l=l-1;
    QuickSort(a, l, matrix);
	QuickSort(r, b, matrix);
}


void BubleSort(int* mas, int n) 
{
	for (int i = 1; i < n; i++)
	{
		if (mas[i] >= mas[i - 1])
		{
			continue;
		}
		int j = i - 1;
		while (j >= 0 && mas[j] > mas[j + 1])
		{
			std::swap(mas[j], mas[j + 1]);
			j = j - 1;
		}
	}

}
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
	srand(time(0));
	int mas1[N];
	int mas2[N];

	for (int i = 0; i < N; i++)
	{
		mas1[i] = rand();
	}
	for (int i = 0; i < N; i++)
	{
		mas2[i] = mas1[i];
	}
	Timer a;
	QuickSort(0, N - 1, mas1);
	std::cout << "Time elapsed: " << a.elapsed() << std::endl;

	Timer b;
	BubleSort(mas2, N);
	std::cout << "Time elapsed: " << b.elapsed() << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << mas1[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << mas2[i] << " ";
	}
	return 0;
}
