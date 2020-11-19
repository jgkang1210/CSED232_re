#ifndef PIECEARRAY
#define PIECEARRAY

#include <typeinfo>
#include "EnumStruct.h"
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

class PieceArray
{
private:
	int length;
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

	// friend function
	friend std::ostream& operator<<(std::ostream& os, const PieceArray& pa);
};

#endif