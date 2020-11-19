#include "Piece.h"

Piece::Piece(const Player& player_, const Position& pos_)
{
	player = player_;
	pos = pos_;
}

Player Piece::GetPlayer() const
{
	return player;
}

void Piece::SetPlayer(const Player& player_)
{
	this -> player = player_;
}

Position Piece::GetPosition() const
{
	return pos;
}

void Piece::SetPosition(const Position& pos_)
{
	this -> pos = pos_;
}

bool Piece::PawnIsPromoted() const
{
	std::cout << "only use for pawn" << std::endl;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Piece& p)
{
	p.PrintLabel(os);
	return os;
}
