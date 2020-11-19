#include "Pawn.h"

Pawn::Pawn(const Player& player_, const Position& pos_) : Piece(player_, pos_)
{
	isPromoted = false;
}

// switch the isPromoted
// when "侯" dies and go into opponet's piece list
// we need to initialize to "子"
void Pawn::Switch(const Player& player_, const Position& pos_)
{
	Piece::SetPlayer(player_);
	Piece::SetPosition(pos_);
	if (isPromoted == true) {
		isPromoted = false;
	}
	else if (isPromoted == false) {
		isPromoted = true;
	}
}

// when left player's pawn reach to the right end
// "子" changes to "侯"
// when right player's pawn reach to the left end
// "侯" changes to "子"
void Pawn::SetPosition(const Position& pos_)
{
	Piece::SetPosition(pos_);

	// check only when the "isPromoted" is off
	if (this->isPromoted == false) {
		// when left player's pawn reach to the right end
		// "子" changes to "侯"
		if ((this->GetPlayer() == Player::PLAYER_LEFT) && (pos_.y == 3)) {
			this->isPromoted = true;
		}
		// when right player's pawn reach to the left end
		// "侯" changes to "子"
		else if ((this->GetPlayer() == Player::PLAYER_RIGHT) && (pos_.y == 0)) {
			this->isPromoted = true;
		}
	}
}

// When piece is "侯" 
// --> can move except Left player : (UPLEFT, DOWNLEFT) or Right player : (UPRIGHT, DOWNRIGHT)
// When piece is "子" 
// --> can move Left player : (RIGHT) or Right player : (LEFT)
bool Pawn::CanMoveTo(const Direction& dir) const
{
	// piece is "侯"
	if (this->isPromoted == true) {
		// left player's pawn can't move only upleft and downleft
		if (this->GetPlayer() == Player::PLAYER_LEFT) {
			if ((dir == Direction::UPLEFT) || (dir == Direction::DOWNLEFT)) {
				return false;
			}
			else return true;
		}

		// right player's pawn can't move only upright and downright
		if (this->GetPlayer() == Player::PLAYER_RIGHT) {
			if ((dir == Direction::UPRIGHT) || (dir == Direction::DOWNRIGHT)) {
				return false;
			}
			else return true;
		}
	}
	// piece is "子"
	else {
		// left player's pawn can move only right
		if (this->GetPlayer() == Player::PLAYER_LEFT) {
			if (dir == Direction::RIGHT) {
				return true;
			}
			else return false;
		}

		// right player's pawn can move only left
		else {
			if (dir == Direction::LEFT) {
				return true;
			}
			else return false;
		}
	}
	
}

// print the pawn
// two type !
void Pawn::PrintLabel(std::ostream& os) const
{
	if (this->isPromoted == true) {
		os << "侯";
	}
	else {
		os << "子";
	}
}

// print is Promoted
bool Pawn::PawnIsPromoted() const
{
	return isPromoted;
}
