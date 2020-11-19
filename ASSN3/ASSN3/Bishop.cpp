#include "Bishop.h"

Bishop::Bishop(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{

}

// Bishop can move UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT
bool Bishop::CanMoveTo(const Direction& dir) const
{
	if (dir == Direction::UPLEFT) {
		return true;
	}
	else if (dir == Direction::UPRIGHT) {
		return true;
	}
	else if (dir == Direction::DOWNLEFT) {
		return true;
	}
	else if (dir == Direction::DOWNRIGHT) {
		return true;
	}
	else return false;
}

void Bishop::PrintLabel(std::ostream& os) const
{
	os << "ßÓ";
}
