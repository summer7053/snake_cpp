#pragma once
#include"snake.h"
#include"food.h"

class Renderer
{
public:
	void clear();
	void draw(const Snake& s, const Food& f, int w, int h);
	void gameOver(int score);
};