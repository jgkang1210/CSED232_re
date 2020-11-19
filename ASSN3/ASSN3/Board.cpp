#include "Board.h"

// private member function
// initialize and make all the piece for the initial game phase
void Board::InitializePieces()
{
	// create initial pieces
	Piece* left_bishop_p = new Bishop(Player::PLAYER_LEFT, { 0, 0 });
	Piece* left_pawn_p = new Pawn(Player::PLAYER_LEFT, { 1, 1 });
	Piece* left_rook_p = new Rook(Player::PLAYER_LEFT, { 2, 0 });
	Piece* left_king_p = new King(Player::PLAYER_LEFT, { 1, 0 });
	Piece* right_pawn_p = new Pawn(Player::PLAYER_RIGHT, { 1, 2 });
	Piece* right_bishop_p = new Bishop(Player::PLAYER_RIGHT, { 2, 3 });
	Piece* right_rook_p = new Rook(Player::PLAYER_RIGHT, { 0, 3 });
	Piece* right_king_p = new King(Player::PLAYER_RIGHT, { 1, 3 });

	// initializing
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			// (0,0) left player bishop
			if (i == 0 && j == 0) {
				board[i][j].SetPiece(left_bishop_p);
			}
			// (1,1) left player pawn
			else if (i == 1 && j == 1) {
				board[i][j].SetPiece(left_pawn_p);
			}
			// (2,0) left player rook
			else if (i == 2 && j == 0) {
				board[i][j].SetPiece(left_rook_p);
			}
			// (1,0) left player king
			else if (i == 1 && j == 0) {	
				board[i][j].SetPiece(left_king_p);
			}
			// (1,2) right player pawn
			else if (i == 1 && j == 2) {
				board[i][j].SetPiece(right_pawn_p);
			}
			// (2,3) right player Bishop
			else if (i == 2 && j == 3) {				
				board[i][j].SetPiece(right_bishop_p);
			}
			// (0,3) right player Rook
			else if (i == 0 && j == 3) {				
				board[i][j].SetPiece(right_rook_p);
			}
			// (1,3) right player King
			else if (i == 1 && j == 3) {				
				board[i][j].SetPiece(right_king_p);
			}
			else board[i][j].SetPiece(nullptr);
		}
	}

	// delete the dynamic allocated piece
	// since set piece function deep copy the piece!
	delete left_bishop_p;
	delete left_pawn_p;
	delete left_rook_p;
	delete left_king_p;
	delete right_pawn_p;
	delete right_bishop_p;
	delete right_rook_p;
	delete right_king_p;
}

/// <summary>
/// Change the turn
/// 1. When player move the piece
/// 2. When player place the piece
/// </summary>
void Board::SwitchPlayer()
{
	if(this->player == Player::PLAYER_LEFT){
		this->player = Player::PLAYER_RIGHT;
	}
	else if (this->player == Player::PLAYER_RIGHT) {
		this->player = Player::PLAYER_LEFT;
	}
}

/// <summary>
/// print the board line by line
/// </summary>
/// <param name="os"> ostream object : print all value by this object </param>
/// <param name="index"> int number : line number </param>
void Board::DrawRow(std::ostream& os, const int& index) const
{
	for (int line = 0; line < 5; line++) {
		// start
		if (line != 2) {
			os << "　　 │";
		}
		else {
			if (index == 0) os << "　1　│";
			else if (index == 1) os << "　2　│";
			else if (index == 2) os << "　3　│";
		} 

		for (int i = 0; i < 4; i++) {
			// first line
			// if up == true --> print ↑
			// if upleft == true --> print ↖
			// if upright == true --> print ↗
			// not available --> print "　"
			if (line == 0) {
				// Upleft position
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if upleft == true --> print ↖
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::UPLEFT)) {
						
						os << " ↖";
					}
					else os << " 　";
				}
				// not available --> print "　"
				else os << " 　";

				os << "　";

				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if up == true --> print ↑
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::UP)) {
						os << "↑";
					}
					else os << "　";
				}
				// not available --> print "　"
				else os << "　";

				os << "　";

				// Upright position
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if upright == true --> print ↗
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::UPRIGHT)) {
						os << "↗│";
					}
					else os << "　│";
				}
				// not available --> print "　"
				else os << "　│";
			}

			// second line
			// if left player --> print ■
			// if right player --> print □
			// no piece --> print "　"
			else if (line == 1) {
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					if ((this->board[index][i]).GetPiece()->GetPlayer() == Player::PLAYER_LEFT) {
						os << " 　■■■　│";
					}
					else {
						os << " 　□□□　│";
					}
				}
				else os << " 　　　　　│";
			}

			// third line
			// if left == true --> print ←
			// if right == true --> print →
			// not available --> print "　"
			//
			// check the piece and print Pawn, Bishop, Rook, King
			//
			else if (line == 2) {
			// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if left == true --> print ←
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::LEFT)) {
						os << " ←";
					}
					else os << " 　";

					// changed by user
					if ((this->board[index][i]).GetPiece()->GetPlayer() == Player::PLAYER_LEFT) {
						os << "■";
					}
					else os << "□";

					// print the piece
					os << *(this->board[index][i]).GetPiece();
						
					// changed by user
					if ((this->board[index][i]).GetPiece()->GetPlayer() == Player::PLAYER_LEFT) {
						os << "■";
					}
					else os << "□";

					// if right == true --> print →
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::RIGHT)) {
						os << "→│";
					}
					else os << "　│";
				}

				// no piece on the square --> print nothing
				else os << " 　　　　　│";
			}
				
			// fourth line
			// if left player --> print ■
			// if right player --> print □
			// no piece --> print "　"
			else if (line == 3) {
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if left player --> print ■
					if ((this->board[index][i]).GetPiece()->GetPlayer() == Player::PLAYER_LEFT) {
						os << " 　■■■　│";
					}
					else {
						os << " 　□□□　│";
					}
				}
				else os << " 　　　　　│";
			}

			// fifth line
			// if up == true --> print ↓
			// if downleft == true --> print ↙
			// if downright == true --> print ↘
			// not available --> print "　"
			else if (line == 4) {
				// Downleft position
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if downleft == true --> print ↙
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::DOWNLEFT)) {
						os << " ↙";
					}
					else os << " 　";
				}
				// not available --> print "　"
				else os << " 　";

				os << "　";

				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if up == true --> print ↑
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::DOWN)) {
						os << "↓";
					}
					else os << "　";
				}
				// not available --> print "　"
				else os << "　";

				os << "　";

				// Downright position
				// avoid nullptr which is emptry sqaure
				if ((this->board[index][i]).GetPiece() != nullptr) {
					// if downright == true --> print ↘
					if ((this->board[index][i]).GetPiece()->CanMoveTo(Direction::DOWNRIGHT)) {
						os << "↘│";
					}
					else os << "　│";
				}
				// not available --> print "　"
				else os << "　│";
			}
		}
		os << std::endl;
	}

}

// check if the board has that piece
bool Board::IsWithinBoard(const Position& pos) const
{	
	// true if the sqaure has piece
	if ((this->board[pos.x][pos.y]).GetPiece() != nullptr) {
		return true;
	}

	// false if their is no piece
	else {
		return false;
	}
}

// public member function
// PieceArray --> maximum 8 members, make 9 just in case
Board::Board() : left(PieceArray(9)), right(PieceArray(9))
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
	os << "　　 　　　Ａ          Ｂ          Ｃ          Ｄ" << std::endl;
	os << "　 　┌───────────┬───────────┬───────────┬───────────┐" << std::endl;
	this->DrawRow(os, 0);
	os << "　 　├───────────┼───────────┼───────────┼───────────┤" << std::endl;
	this->DrawRow(os, 1);
	os << "　 　├───────────┼───────────┼───────────┼───────────┤" << std::endl;
	this->DrawRow(os, 2);
	os << "　 　└───────────┴───────────┴───────────┴───────────┘" << std::endl;
	os << "　 　　　　Ａ          Ｂ          Ｃ          Ｄ" << std::endl;
	os << "[Left Player's Pieces]: " << left << std::endl;
	os << "[Right Player's Pieces]: " << right << std::endl;
}

void Board::ShowTurn(std::ostream& os) const
{
	if (this->player == Player::PLAYER_LEFT) {
		os << "Left player's turn" << std::endl;
	}
	else os << "Right player's turn" << std::endl;
}

// return player
Player Board::GetPlayer() const
{
	return player;
}

// return the current player's piece number
int Board::PlayerPieceNum() const
{
	if (player == Player::PLAYER_LEFT) {
		return left.GetLength();
	}
	else return right.GetLength();
}

// 1. check if the piece is on that place
// 2. check the direction is correct (out of bound)
// 3. check if the piece can move that way (can only move to empty square or opponent's piece)
// 4. move the piece 
//	4-1. copy the destiny piece to current player's piece array (skip if empty space)
//	4-2. delete the destiny piece 
//	4-3. copy the selected piece to destiny square
//	4-4. delete the selected square piece
bool Board::MovePiece(const Position& pos, const Direction& dir)
{
	// 1. check if the piece is on that place
	if (IsWithinBoard(pos));
	else {
		std::cout << "No piece on that place" << std::endl;
		return false;
	}

	// position
	int x_index = pos.x;
	int y_index = pos.y;

	// moving direction
	int x_dir = 0;
	int y_dir = 0;

	// each direction change to x_dir and y_dir
	if (dir == Direction::UP) {
		x_dir = -1;
		y_dir = 0;
	}
	else if (dir == Direction::DOWN) {
		x_dir = 1;
		y_dir = 0;
	}
	else if (dir == Direction::LEFT) {
		x_dir = 0;
		y_dir = -1;
	}
	else if (dir == Direction::RIGHT) {
		x_dir = 0;
		y_dir = 1;
	}
	else if (dir == Direction::UPLEFT) {
		x_dir = -1;
		y_dir = -1;
	}
	else if (dir == Direction::UPRIGHT) {
		x_dir = -1;
		y_dir = 1;
	}
	else if (dir == Direction::DOWNLEFT) {
		x_dir = 1;
		y_dir = -1;
	}
	else if (dir == Direction::DOWNRIGHT) {
		x_dir = 1;
		y_dir = 1;
	}

	// pointer for selected piece and destiny piece
	Piece* selected = this->board[x_index][y_index].GetPiece();
	Piece* destiny = this->board[x_index + x_dir][y_index + y_dir].GetPiece();

	// 1. check if the piece is on that place
	// left player
	if (this->player == Player::PLAYER_LEFT) {
		//check wheter the player owns that piece
		if (selected->GetPlayer() != Player::PLAYER_LEFT) {
			std::cout << "You don't own this piece. Choose your piece." << std::endl;
			return false;
		}
	}
	// right player
	else if (this->player == Player::PLAYER_RIGHT) {
		//check wheter the player owns that piece
		if (selected->GetPlayer() != Player::PLAYER_RIGHT) {
			std::cout << "You don't own this piece. Choose your piece." << std::endl;
			return false;
		}
	}
	

	// 2. check the direction is correct
	// after checking the position has the correct piece
	// check it's direction is validate

	// check the move direction is correct for pawn, bishop, rook, king each
	if (selected->CanMoveTo(dir));
	else {
		std::cout << *(selected) << " can't move that way" << std::endl;
		return false;
	}

	// x_index is from 0~2
	if ((x_index + x_dir) < 0 || (x_index + x_dir) > 2) {
		std::cout << "Out of bound." << std::endl;
		return false;
	}
	// y_index is from 0~3
	if ((y_index + y_dir) < 0 || (y_index + y_dir) > 3) {
		std::cout << "Out of bound." << std::endl;
		return false;
	}


	// 3. check if the piece can move that way (can only move to empty square or opponent's piece)
	if ((destiny == nullptr) || (destiny->GetPlayer() != selected->GetPlayer()));
	else { 
		std::cout << "You can't move to your piece" << std::endl; 
		return false;
	}

	// 4. move the piece 
	//	4-1. copy the destiny piece to current player's piece array (skip if empty space)
	if (this -> player == Player::PLAYER_LEFT) {
		if (destiny != nullptr) {
			// need to change the owner of piece
			destiny->SetPlayer(Player::PLAYER_LEFT);
			this->left.PushPiece(destiny); 
		}
	}
	else {
		if (destiny != nullptr) {
			// need to change the owner of piece
			destiny->SetPlayer(Player::PLAYER_RIGHT);
			this->right.PushPiece(destiny);
		}
	}
	//	4-2. delete the destiny piece
	this->board[x_index + x_dir][y_index + y_dir].Clear();
	//	4-3. copy the selected piece to destiny square
	//  change the position
	selected->SetPosition({ x_index + x_dir, y_index + y_dir });
	//  set new piece
	this->board[x_index + x_dir][y_index + y_dir].SetPiece(selected);
	//	4-4. delete the selected square piece
	this->board[x_index][y_index].Clear();


	// after the turn switch the player
	SwitchPlayer();

	return true;
}

// if player has pieces return true
bool Board::PlayerHasPiece() const
{
	// left player's turn
	if (player == Player::PLAYER_LEFT) {
		// if player has pieces return true
		if (left.GetLength() == 0) {
			return false;
		}
		else return true;
	}

	// right player's turn
	else {
		// if player has pieces return true
		if (right.GetLength() == 0) {
			return false;
		}
		else return true;
	}
}

// 1. Check the position of the board (Only Empty square can get new board)
// 2. Place the piece
//	2-1. Check the player
//	2-2. Copy the piece
//	2-3. Set the position of piece
//	2-4. Set the piece to square
bool Board::PlacePiece(const int& pieceIndex, const Position& pos)
{
	// 1. Check the position of the board (Only Empty square can get new board)
	if (IsWithinBoard(pos)) {
		std::cout << "There exists piece on that place." << std::endl;
		return false;
	}

	// position
	int x_index = pos.x;
	int y_index = pos.y;


	// 3. Place the piece
	if (this->player == Player::PLAYER_LEFT) {
		Piece* PopPiece = left.PopPieceAt(pieceIndex);
		PopPiece->SetPosition(pos);
		board[x_index][y_index].SetPiece(PopPiece);
	}
	else {
		Piece* PopPiece = right.PopPieceAt(pieceIndex);
		PopPiece->SetPosition(pos);
		board[x_index][y_index].SetPiece(PopPiece);
	}

	// after the turn switch the player
	SwitchPlayer();

	return true;
}

// 1. Kill the king
bool Board::IsGameOver() const
{
	// 1. Kill the king
	// check the left and right --> piece array
	// if there is king in the piece array --> king died

	if (this->player == Player::PLAYER_RIGHT) {
		for (int i = 0; i < left.GetLength(); i++) {
			if (typeid(*left.GetPieceAt(i)) == typeid(King)) {
				std::cout << "King died!" << std::endl;
				std::cout << "Left player win!" << std::endl;
				return true;
			}
		}
	}
	else if (this->player == Player::PLAYER_LEFT) {
		for (int i = 0; i < right.GetLength(); i++) {
			if (typeid(*right.GetPieceAt(i)) == typeid(King)) {
				std::cout << "King died!" << std::endl;
				std::cout << "Right player win!" << std::endl;
				return true;
			}
		}
	}

	// 2. King in the opponent's place for one turn
	// check the position of the king
	// if the king is at the opponet's place at the start of the player's turn --> game end
	if (this->player == Player::PLAYER_LEFT) {
		for (int i = 0; i < 3; i++) {
			// Skip if null space
			if ((this->board[i][3]).GetPiece() == nullptr) continue;
			// King's owner has to be left player
			if ((this->board[i][3]).GetPiece()->GetPlayer() == Player::PLAYER_LEFT) {
				// if king is on opponent's place
				if (typeid(*(this->board[i][3]).GetPiece()) == typeid(King)) {
					std::cout << "King last for 1 turn!" << std::endl;
					std::cout << "Left player win!" << std::endl;
					return true;
				}
			}
		}
	}
	else if (this->player == Player::PLAYER_RIGHT) {
		for (int i = 0; i < 3; i++) {
			// Skip if null space
			if ((this->board[i][0]).GetPiece() == nullptr) continue;
			// King's owner has to be right player
			if ((this->board[i][0]).GetPiece()->GetPlayer() == Player::PLAYER_RIGHT) {
				// if king is on opponent's place
				if (typeid(*(this->board[i][0]).GetPiece()) == typeid(King)) {
					std::cout << "King last for 1 turn!" << std::endl;
					std::cout << "Right player win!" << std::endl;
					return true;
				}
			}
		}
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	board.Draw(os);
	board.ShowTurn(os);
	return os;
}
