#include "PieceArray.h"

PieceArray::PieceArray(const int& maxLength_) : length(4), arr(nullptr)
{
	maxLength = maxLength_;
}

PieceArray::PieceArray(const PieceArray& piecearray_)
{
	length = piecearray_.length;
	maxLength = piecearray_.maxLength;
	arr = piecearray_.arr;
}

PieceArray::~PieceArray()
{

}

int PieceArray::GetLength() const
{
	return 0;
}

Piece* PieceArray::GetPieceAt(const int& index) const
{
	return nullptr;
}

void PieceArray::PushPiece(Piece* piece)
{

}

Piece* PieceArray::PopPieceAt(const int& index)
{
	return nullptr;
}