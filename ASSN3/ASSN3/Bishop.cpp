#include "Bishop.h"

Bishop::Bishop(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{

}

bool Bishop::CanMoveTo(const Direction& dir) const
{
	return false;
}

void Bishop::PrintLabel(std::ostream& os) const
{

}
