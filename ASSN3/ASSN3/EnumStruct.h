#ifndef ENUMSTRUCT
#define ENUMSTRUCT

enum class Player
{
	PLAYER_LEFT,
	PLAYER_RIGHT
};

enum class Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT
};

struct Position
{
	int x;
	int y;
};

#endif