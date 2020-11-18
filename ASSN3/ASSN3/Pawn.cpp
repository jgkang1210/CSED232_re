#include "Pawn.h"

Pawn::Pawn(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{
	isPromoted = false;
}

void Pawn::Init(const Player& player_, const Position& pos_)
{
	Piece::SetPlayer(player_);
	Piece::SetPosition(pos_);
}


void Pawn::SetPosition(const Position& pos_)
{
	//if(...) {this -> isPromoted = true;} opponent --> true
	Piece::SetPosition(pos_);
}

bool Pawn::CanMoveTo(const Direction& dir) const
{

	return false;
}

void Pawn::PrintLabel(std::ostream& os) const
{
	if (this->isPromoted == true) {
		os << "侯)";
	}
	else {
		os << "子";
	}
}
