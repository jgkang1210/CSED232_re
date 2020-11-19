#include "PieceArray.h"

PieceArray::PieceArray(const int& maxLength_) : length(0)
{
	maxLength = maxLength_;
	arr = new Piece*[maxLength_];
}

PieceArray::PieceArray(const PieceArray& piecearray_)
{
	length = piecearray_.length;
	maxLength = piecearray_.maxLength;
	arr = piecearray_.arr;
}

// delete all the member in the array
PieceArray::~PieceArray()
{
	// delete each member
	for (int i = 0; i < this->length; i++) {
		delete arr[i];
	}

	// delete the ** array
	delete[] arr;
}

// return the length of piece array
int PieceArray::GetLength() const
{
	return length;
}

// return the piece at the index
// only watch that piece (no modifying)
Piece* PieceArray::GetPieceAt(const int& index) const
{
	return arr[index];
}

/// <summary>
/// insert the piece
/// swap the piece's owner
/// </summary>
/// <param name="piece"> piece object pointer </param>
void PieceArray::PushPiece(Piece* piece)
{
	// dynamic allocation
	// pawn
	if (typeid(*piece) == typeid(Pawn)) {
		arr[length] = new Pawn(piece->GetPlayer(), piece->GetPosition());
	}
	// bishop
	else if (typeid(*piece) == typeid(Bishop)) {
		arr[length] = new Bishop(piece->GetPlayer(), piece->GetPosition());
	}
	// rook
	else if (typeid(*piece) == typeid(Rook)) {
		arr[length] = new Rook(piece->GetPlayer(), piece->GetPosition());
	}
	// king
	else if (typeid(*piece) == typeid(King)) {
		arr[length] = new King(piece->GetPlayer(), piece->GetPosition());
	}

	length++;
}

// 1. check the piece's type
// 2. copy the pop piece
// 3. delete the piece
// 4. re arrange the array
// 5. return thee pop piece
Piece* PieceArray::PopPieceAt(const int& index)
{
	Piece* pop_piece = nullptr;
	// 1. check the piece's type
	// dynamic allocation
	// pawn
	if (typeid(*arr[index - 1]) == typeid(Pawn)) {
		// 2. copy the pop piece
		pop_piece = new Pawn(arr[index - 1]->GetPlayer(), { 0,0 });
	}
	// bishop
	else if (typeid(*arr[index - 1]) == typeid(Bishop)) {
		// 2. copy the pop piece
		pop_piece = new Bishop(arr[index - 1]->GetPlayer(), {0,0});
	}
	// rook
	else if (typeid(*arr[index - 1]) == typeid(Rook)) {
		// 2. copy the pop piece
		pop_piece = new Rook(arr[index - 1]->GetPlayer(), { 0,0 });
	}
	// king
	else if (typeid(*arr[index - 1]) == typeid(King)) {
		// 2. copy the pop piece
		pop_piece = new King(arr[index - 1]->GetPlayer(), { 0,0 });
	}

	// 3. delete the piece
	delete arr[index - 1];
	length--;

	// 4. re arrange the array
	for (int i = index; i <= length; i++) {
		arr[i - 1] = arr[i];
	}
	arr[length] = nullptr;

	// 5. return thee pop piece
	return pop_piece;
}

// print all the piece in the array
std::ostream& operator<<(std::ostream& os, const PieceArray& pa)
{
	for (int i = 0; i < pa.GetLength(); i++) {
		os << *(pa.GetPieceAt(i));
		if (i != pa.GetLength() - 1) {
			os << ",";
		}
	}
	os << std::endl;
	return os;
}