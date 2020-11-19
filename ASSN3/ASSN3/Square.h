#ifndef SQAURE
#define SQAURE

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

class Square
{
private:
	Piece* piece;

public:
	Square();
	~Square();
	Piece* GetPiece() const;
	void SetPiece(Piece* piece_);
	void Clear();
};

#endif