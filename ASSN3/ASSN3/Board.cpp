#include "Board.h"

//private member function
void Board::InitializePieces()
{
	// initializing
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			// (0,0) left player bishop
			if (i == 0 && j == 0) {
				Piece* left_bishop_p = new Bishop(Player::PLAYER_LEFT, { 0, 0 });
				board[i][j].SetPiece(left_bishop_p);
			}
			else if (i == 1 && j == 1) {
				Piece* left_pawn_p = new Pawn(Player::PLAYER_LEFT, { 1, 1 });
				board[i][j].SetPiece(left_pawn_p);
			}
			else if (i == 2 && j == 0) {
				Piece* left_rook_p = new Rook(Player::PLAYER_LEFT, { 2, 0 });
				board[i][j].SetPiece(left_rook_p);
			}
			else if (i == 1 && j == 0) {
				Piece* left_king_p = new King(Player::PLAYER_LEFT, { 1, 0 });
				board[i][j].SetPiece(left_king_p);
			}

		}
	}

	// put right player's piece
	Piece* right_pawn_p = new Pawn(Player::PLAYER_RIGHT, { 1, 2 });
	Piece* right_bishop_p = new Bishop(Player::PLAYER_RIGHT, { 2, 3 });
	Piece* right_rook_p = new Rook(Player::PLAYER_RIGHT, { 2, 0 });
	Piece* right_king_p = new King(Player::PLAYER_RIGHT, { 0, 3 });

	Square right_pawn_s = Square();
	Square right_bishop_s = Square();
	Square right_rook_s = Square();
	Square right_king_s = Square();

	right_pawn_s.SetPiece(right_pawn_p);
	right_bishop_s.SetPiece(right_bishop_p);
	right_rook_s.SetPiece(right_rook_p);
	right_king_s.SetPiece(right_king_p);

	
}

void Board::SwitchPlayer()
{

}

void Board::DrawRow(std::ostream& os, const int& index)
{
	if (index == 0) {

	}
	else if (index == 1) {

	}
	else if (index == 2) {

	}
}

bool Board::IsWithinBoard(const Position pos) const
{

	return false;
}

// public member function
Board::Board() : left(PieceArray(4)), right(PieceArray(4))
{
	// initialize the piece
	InitializePieces();

	// initial player --> left player
	player = Player::PLAYER_LEFT;

	// initial pieces --> Pawn, Rook, Bishop, King
	/*PieceArray initial_array(4);
	left = initial_array;
	right = initial_array;*/
}

void Board::Draw(std::ostream& os) const
{
	os << std::endl;
	os << " A B C D" << std::endl;
	os << " ┌───────────┬───────────┬───────────┬───────────┐" << std::endl;
	//this->DrawRow(os, 0);
	os << " ├───────────┼───────────┼───────────┼───────────┤" << std::endl;
	//this->DrawRow(os, 1);
	os << " ├───────────┼───────────┼───────────┼───────────┤" << std::endl;
	//this->DrawRow(os, 2);
	os << " └───────────┴───────────┴───────────┴───────────┘" << std::endl;
	os << " A B C D" << std::endl << std::endl;
	//os << "[Left Player's Pieces]: " << left << endl;
	//os << "[Right Player's Pieces]: " << right << endl;
}

void Board::ShowTurn(std::ostream& os) const
{

}

bool Board::MovePiece(const Position& pos, const Direction& dir)
{
	
	return false;
}

bool Board::PlayerHasPiece() const
{

	return false;
}

bool Board::PlacePiece(const int& pieceIndex, const Position& pos)
{

	return false;
}

bool Board::IsGameOver() const
{

	return false;
}