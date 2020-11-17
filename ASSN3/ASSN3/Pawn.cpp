#include "Pawn.h"
#include "Piece.h"
#include "EnumStruct.h"
#include <iostream>

Pawn::Pawn(Player player_, Position pos_)
{
	isPromoted = 0;
	SetPlayer(player_);
	SetPosition(pos_);
}

void Pawn::Init(Player player_, Position pos_)
{
	SetPlayer(player_);
	SetPosition(pos_);
}

void Pawn::SetPosition(Position pos_)
{
	SetPosition(pos_);
}

bool Pawn::CanMoveTo(Direction dir) const
{

	return false;
}

void Pawn::PrintLabel(std::ostream& os) const
{

}
