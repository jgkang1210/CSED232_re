#ifndef PIECEARRAY
#define PIECEARRAY

class PieceArray
{
private:
	int length;
	int maxLength;
	Piece** arr;
public:
	// constructor
	PieceArray(int maxLength_);

	// copy constructor
	PieceArray(PieceArray& piecearray_);

	// destructor
	~PieceArray();

	int GetLength() const;
	Piece* GetPieceAt(int index) const;
	void PushPiece(Piece* piece);
	Piece* PopPieceAt(int index);
};

#endif