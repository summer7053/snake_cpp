#include"food.h"
#include<random>

Food::Food(int w, int h) :w_(w), h_(h)
{
	respawn();
}

void Food::respawn()
{
	static std::mt19937 rng
	{
		std::random_device{}()
	};
	std::uniform_int_distribution<int> dx(0, w_ - 2), dy(0, h_ - 2);
	pos_ = { dx(rng),dy(rng) };
}