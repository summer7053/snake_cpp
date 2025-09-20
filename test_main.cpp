#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include"../src/snake.h"


TEST_CASE("Snake moves")
{
	Snake s(3, 3);
	auto b = s.body();
	REQUIRE(b.front().first == 5);
	s.move(Direction::Right);
	b = s.body();
	REQUIRE(b.front().first == 5);
}