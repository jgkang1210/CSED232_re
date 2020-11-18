#ifndef PIECEARRAY
#define PIECEARRAY

#include "EnumStruct.h"
#include "Piece.h"

class PieceArray
{
private:
	int length = 4;
	int maxLength;
	Piece** arr;
public:
	// constructor
	PieceArray(const int& maxLength_);

	// copy constructor
	PieceArray(const PieceArray& piecearray_);

	// destructor
	~PieceArray();

	int GetLength() const;
	Piece* GetPieceAt(const int& index) const;
	void PushPiece(Piece* piece);
	Piece* PopPieceAt(const int& index);
};

#endif