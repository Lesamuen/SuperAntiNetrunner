#include "dice.h"
#include "random"
#include "iostream"

int r (int num, int size)
{
    std::random_device rd;
    std::mt19937 rng = std::mt19937(rd());
	std::uniform_int_distribution<int> uid(1, size);
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += uid(rng);
    }
    std::cout << sum << std::endl;
    return sum;
}