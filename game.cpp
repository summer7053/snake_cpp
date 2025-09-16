#include"game.h"
#include<thread>
#include<chrono>
#include<conio.h>

Game::Game(int w, int h) :w_(w), h_(h), snake_(w / 2, h / 2), food_(w, h) {}

void Game::run()
{
	std::thread inputThr(std::ref(input_));
	while (running_)
	{
		step();
		std::this_thread::sleep_for(std::chrono::milliseconds(120));
	}
	input_.stop();
	inputThr.join();

	while (true)
	{
		int ch = _getch();
		if (ch == 27) break;//ESCÍË³ö
	}
}

void Game::step()
{
	Direction dir = input_.pop();
	snake_.move(dir);
	if (snake_.checkCollision(w_, h_) || snake_.selfCollision())
	{
		running_ = false;
		renderer_.gameOver(score_);
		return;
	}
	auto [sx, sy] = snake_.body().front();
	if (sx == food_.pos().first && sy == food_.pos().second)
	{
		snake_.grow();
		food_.respawn();
		score_++;
	}
	renderer_.clear();
	renderer_.draw(snake_, food_, w_, h_);
}