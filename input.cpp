#include"input.h"
#include<conio.h>//windows无回显输入
#include<SFML/Window.hpp>

Direction Input::pop()
{
	std::lock_guard<std::mutex> lock(mtx_);
	if (queue_.empty()) return Direction::None;
	auto dir = queue_.front();
	queue_.pop();
	return dir;
}

void Input::operator()()
{
	while (running_)
	{
		if (_kbhit())
		{
			//Windows 专属
			int ch = _getch();
			std::lock_guard<std::mutex> lock(mtx_);
			switch (ch)
			{
			case'w':case'W':queue_.push(Direction::Up); break;
			case's':case'S':queue_.push(Direction::Down); break;
			case'a':case'A':queue_.push(Direction::Left); break;
			case'd':case'D':queue_.push(Direction::Right); break;
			case 27: running_ = false; return;//ESC退出
			}
		}
	}
}