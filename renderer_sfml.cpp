#include"renderer_sfml.h"
#include<sstream>

Renderer::Renderer(int w, int h, int cell) :cell_(cell), w_(w), h_(h)
{
	window.create(sf::VideoMode(w * cell, h * cell), "Snake SFML");
	window.setFramerateLimit(60);
	//生成16*16纯色纹理（绿色蛇、红色食物）
	sf::Image img;
	img.create(16, 16, sf::Color::Green);
	texSnake.loadFromImage(img);
	img.create(16, 16, sf::Color::Red);
	texFood.loadFromImage(img);
	sprSnake.setTexture(texSnake);
	sprFood.setTexture(texFood);
}

void Renderer::clear()
{
	pollEvents();
	window.clear(sf::Color{ 20,20,20 });
}

void Renderer::draw(const Snake& s, const Food& f, int, int)
{
	//画食物
	sprFood.setPosition(f.pos().first * cell_, f.pos().second * cell_);
	window.draw(sprFood);
	//画蛇
	for (auto [bx, by] : s.body())
	{
		sprSnake.setPosition(bx * cell_, by * cell_);
		window.draw(sprSnake);
	}
	window.display();
}

void Renderer::gameOver(int score)
{
	sf::Text txt;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");//系统自带
	txt.setFont(font);
	txt.setString("Game Over! Score:" + std::to_string(score));
	txt.setCharacterSize(30);
	txt.setFillColor(sf::Color::White);
	txt.setPosition(w_ * cell_ / 4.f, h_ * cell_ / 2.f);
	window.draw(txt);
	window.display();
	sf::sleep(sf::seconds(3));
	window.close();
}

void Renderer::pollEvents()
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed) window.close();
		if (ev.type == sf::Event::KeyPressed)
		{
			switch (ev.key.code)
			{
			case sf::Keyboard::W:hasEvent_ = true; evtDir_ = Direction::Up;	break;
			case sf::Keyboard::S:hasEvent_ = true; evtDir_ = Direction::Down; break;
			case sf::Keyboard::A:hasEvent_ = true; evtDir_ = Direction::Left; break;
			case sf::Keyboard::D:hasEvent_ = true; evtDir_ = Direction::Right; break;
			default:break;
			}
		}
	}
}

bool Renderer::keyPressed(Direction& dir)
{
	if (!hasEvent_) return false;
	dir = evtDir_;
	hasEvent_ = false;
	return true;
}