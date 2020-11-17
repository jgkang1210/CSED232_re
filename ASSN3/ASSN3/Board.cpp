#include "Board.h"
#include <iostream>
#include "EnumStruct.h"
#include "PieceArray.h"
#include "Square.h"

//private member function
void Board::InitializePieces()
{

}

void Board::SwitchPlayer()
{
}

void Board::DrawRow(std::ostream& os, int index)
{
}

bool Board::IsWithinBoard(Position pos) const
{
	return false;
}

// public member function
Board::Board()
{
	Square board[3][4];
	player = Player::PLAYER_LEFT;
	left = PieceArray::PieceArray();
	right = PieceArray::PieceArray();
}

void Board::Draw(std::ostream& os) const
{
}

void Board::ShowTurn(std::ostream& os) const
{
}

bool Board::MovePiece(Position pos, Direction dir)
{
	return false;
}

bool Board::PlayerHasPiece() const
{
	return false;
}

bool Board::PlacePiece(int pieceIndex, Position pos)
{
	return false;
}

bool Board::IsGameOver() const
{
	return false;
}
