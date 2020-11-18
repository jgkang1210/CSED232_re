#ifndef BOARD
#define BOARD

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"
#include "PieceArray.h"
#include "Square.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

class Board
{
private:
	Square board[3][4];
	Player player;
	PieceArray left;
	PieceArray right;
	void InitializePieces();
	void SwitchPlayer();
	void DrawRow(std::ostream& os, const int& index);
	bool IsWithinBoard(const Position pos) const;

public:
	Board();
	void Draw(std::ostream& os) const;
	void ShowTurn(std::ostream& os) const;
	bool MovePiece(const Position& pos, const Direction& dir);
	bool PlayerHasPiece() const;
	bool PlacePiece(const int& pieceIndex, const Position& pos);
	bool IsGameOver() const;
};

#endif