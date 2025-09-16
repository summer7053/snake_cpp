#include"renderer.h"
#include<iostream>
#include<windows.h>

void Renderer::clear()
{
	// ������ƶ������Ͻ�
	COORD coord = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Renderer::draw(const Snake& s, const Food& f, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			char c = '.';
			if (x == f.pos().first && y == f.pos().second) c = '*';
			for (auto [bx, by] : s.body())
			{
				if (x == bx && y == by)
				{
					c = '@';
					break;
				}
			}
			std::cout << c << ' ';
		}
		std::cout << '\n';
	}
}

void Renderer::gameOver(int score)
{
	std::cout << "Game Over! Score:" << score << "\nPress ESC to quit.\n";
}