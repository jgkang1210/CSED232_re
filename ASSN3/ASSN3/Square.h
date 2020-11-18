#ifndef SQAURE
#define SQAURE

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"

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