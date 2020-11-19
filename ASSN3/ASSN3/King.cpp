#include "King.h"

King::King(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{

}

King::King(const King& king) : Piece(king.GetPlayer(), king.GetPosition())
{

}

bool King::CanMoveTo(const Direction& dir) const
{
	return true;
}

void King::PrintLabel(std::ostream& os) const
{
	os << "шн";
}
