#include "Rook.h"

Rook::Rook(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{

}

bool Rook::CanMoveTo(const Direction& dir) const
{
	if (dir == Direction::UP) {
		return true;
	}
	else if (dir == Direction::RIGHT) {
		return true;
	}
	else if (dir == Direction::DOWN) {
		return true;
	}
	else if (dir == Direction::LEFT) {
		return true;
	}
	else return false;
}

void Rook::PrintLabel(std::ostream& os) const
{
	os << "эт";
}