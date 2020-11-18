#include "Rook.h"

Rook::Rook(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{

}

bool Rook::CanMoveTo(const Direction& dir) const
{
	return false;
}

void Rook::PrintLabel(std::ostream& os) const
{

}
