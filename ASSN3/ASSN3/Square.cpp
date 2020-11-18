#include "Square.h"

Square::Square()
{
	piece = nullptr;
}

Square::~Square()
{
	delete piece;
}

Piece* Square::GetPiece() const
{
	return piece;
}

void Square::SetPiece(Piece* piece_)
{
	piece = piece_;
}

void Square::Clear()
{
	delete piece;
	piece = nullptr;
}
