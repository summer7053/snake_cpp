#pragma once
#include"snake.h"
#include"food.h"
//#include"input.h"
//#include"renderer.h"
#include<atomic>
#include "renderer_sfml.h"

class Game
{
public:
	Game(int w, int h);
	void run();//Ö÷Ñ­»·
	void step();//µ¥Ö¡Âß¼­
private:
	int w_, h_;
	Snake snake_;
	Food food_;
	//Input input_;
	Renderer renderer_;
	//std::atomic<bool> running_{ true };
	int score_{ 0 };
	Direction currentDir_{ Direction::None };
	
};