#ifndef PIECE
#define PIECE

#include <iostream>
#include "EnumStruct.h"

class Piece
{
private:
	Player player;
	Position pos;
public:
	Piece(const Player& player_, const Position& pos_);
	Player GetPlayer() const;
	void SetPlayer(const Player& player_);
	Position GetPosition() const;
	virtual void SetPosition(const Position& pos_);

	// Pure virtual function
	virtual bool CanMoveTo(const Direction& dir) const = 0;
	virtual void PrintLabel(std::ostream& os) const = 0;

	// friend function
	friend std::ostream& operator<<(std::ostream& os, const Piece& p);
};

#endif