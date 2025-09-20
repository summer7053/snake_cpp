#pragma once
#include<SFML/Graphics.hpp>
#include"snake.h"
#include"food.h"

class Renderer
{
public:
	Renderer(int w, int h, int cell = 20);
	bool isOpen() const { return window.isOpen(); }
	void clear();
	void draw(const Snake& s, const Food& f, int w, int h);
	void gameOver(int score);
	void pollEvents();//�Ѽ����¼����ݸ�SFML����Game
	bool keyPressed(Direction& dir);//�з��������true
private:
	sf::RenderWindow window;
	sf::Texture texSnake, texFood;
	sf::Sprite sprSnake, sprFood;
	int cell_, w_, h_;
	bool hasEvent_{ false };
	Direction evtDir_{ Direction::None };
};