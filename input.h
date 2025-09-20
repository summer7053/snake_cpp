#pragma once
#include<queue>
#include<mutex>
#include"snake.h"

class Input
{
public:
	void operator()();//�߳����
	Direction pop();//�̰߳�ȫȡ
	void stop()
	{
		running_ = false;
	}
private:	
	std::queue<Direction> queue_;
	std::mutex mtx_;
	bool running_{ true };
};