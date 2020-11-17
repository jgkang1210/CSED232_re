#include "Piece.h"
#include "EnumStruct.h"
#include <iostream>

Piece::Piece()
{
	player = Player::PLAYER_LEFT;
	struct Position pos_ = {1, 1};
	pos = pos_;
}

Piece::Piece(Player player_, Position pos_)
{
	player = player_;
	pos = pos_;
}

Player Piece::GetPlayer() const
{
	return player;
}

void Piece::SetPlayer(Player player_)
{
	player = player_;
}

Position Piece::GetPosition() const
{
	return pos;
}

void Piece::SetPosition(Position pos_)
{
	pos = pos_;
}
