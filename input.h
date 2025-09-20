#pragma once
#include<queue>
#include<mutex>
#include"snake.h"

class Input
{
public:
	void operator()();//线程入口
	Direction pop();//线程安全取
	void stop()
	{
		running_ = false;
	}
private:	
	std::queue<Direction> queue_;
	std::mutex mtx_;
	bool running_{ true };
};