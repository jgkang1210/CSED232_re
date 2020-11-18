#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"
#include "PieceArray.h"
#include "Square.h"
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

int main() {
	std::cout << "hello world" << std::endl;

	PieceArray sample_array(5);

	Board GameBoard;

	

	struct Position pos_ = { 1, 1 };
	Pawn sample(Player::PLAYER_LEFT, pos_);

	Piece* test = new Pawn(Player::PLAYER_LEFT, pos_);

	std::cout << "this is" << *test << "ㅎㅇ"<< std::endl;

	test->SetPosition({ 0,0 });

	std::cout << "this is" << *test << "ㅎㅇ" << std::endl;

	delete test;
}