#pragma once
#include<vector>
#include<utility>

enum class Direction {None, Up, Down, Left, Right };


class Snake
{
public:
	explicit Snake(int startX, int startY);

	void move(Direction dir);
	void grow() { growNext_ = true; }
	bool checkCollision(int w, int h) const;
	bool selfCollision() const;
	const std::vector<std::pair<int, int>>& body() const noexcept { return body_; }
	Direction dir() const noexcept { return dir_; }
	bool isOpposite(Direction a, Direction b);
private:
	std::vector<std::pair<int, int>> body_;
	Direction dir_ = Direction::Right;
	bool growNext_ = false;
};
