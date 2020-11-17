#ifndef BOARD
#define BOARD

class Board
{
private:
	Square board[3][4];
	Player player;
	PieceArray left;
	PieceArray right;
	void InitializePieces();
	void SwitchPlayer();
	void DrawRow(std::ostream& os, int index);
	bool IsWithinBoard(Position pos) const;

public:
	Board();
	void Draw(std::ostream& os) const;
	void ShowTurn(std::ostream& os) const;
	bool MovePiece(Position pos, Direction dir);
	bool PlayerHasPiece() const;
	bool PlacePiece(int pieceIndex, Position pos);
	bool IsGameOver() const;
};

#endif

