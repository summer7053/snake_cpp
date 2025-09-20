#pragma once
#include<utility>

class Food
{
public:
	Food(int w, int h);
	void respawn();
	const std::pair<int, int>& pos() const noexcept { return pos_; }

private:
	int w_, h_;
	std::pair<int, int> pos_;
};