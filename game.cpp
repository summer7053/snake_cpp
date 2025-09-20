#include"game.h"
#include<thread>
#include<chrono>
#include<conio.h>
#include<SFML/System.hpp>

Game::Game(int w, int h) :w_(w), h_(h), snake_(w / 2, h / 2), food_(w, h),renderer_(w,h) {}
	
void Game::run()
{
	while (renderer_.isOpen())
	{
		Direction d;
		if (renderer_.keyPressed(d)) currentDir_ = d;
		step();
		sf::sleep(sf::milliseconds(80));
	}
}

void Game::step()
{
	snake_.move(currentDir_);
	if (snake_.checkCollision(w_, h_) || snake_.selfCollision())
	{
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