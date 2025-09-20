#include"snake.h"

Snake::Snake(int startX, int startY)
{
	body_.emplace_back(startX, startY);
}
void Snake::move(Direction dir)
{
	if (dir == Direction::None)
		return; // 没有输入时不移动

	auto isOpposite = [](Direction a, Direction b) {
		return (a == Direction::Up && b == Direction::Down) ||
			(a == Direction::Down && b == Direction::Up) ||
			(a == Direction::Left && b == Direction::Right) ||
			(a == Direction::Right && b == Direction::Left);
	};
	if (isOpposite(dir, dir_))
		return; // 反向过滤
	dir_ = dir;
	auto [x, y] = body_.front();//结构出旧头坐标
	switch (dir_)
	{
	case Direction::Up: y--; break;
	case Direction::Down:y++; break;
	case Direction::Left:x--; break;
	case Direction::Right:x++; break;
	}
	body_.insert(body_.begin(), { x, y });
	if (!growNext_) body_.pop_back();
	else growNext_ = false;
}

bool Snake::checkCollision(int w, int h) const
{
	auto [x, y] = body_.front();
	return x < 0 || x >= w || y < 0 || y >= h;
}

bool Snake::selfCollision() const
{
	auto head = body_.front();
	for (std::size_t i = 1; i < body_.size(); i++)
	{
		if (body_[i] == head) return true;
	}
	return false;
}