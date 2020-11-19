#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include "EnumStruct.h"
#include "Piece.h"
#include "PieceArray.h"
#include "Square.h"
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

void MovePiece(Board& board);
void PlacePiece(Board& board);

int main() {
	std::cout << "hello world" << std::endl;

	Board GameBoard;

	// starting player --> player_left
	Player player = Player::PLAYER_LEFT;

	while (1) {
		// initial board & player's piece printing
		std::cout << GameBoard << std::endl;

		// check if the game ends
		if (GameBoard.IsGameOver()) break;

		// 3 choices to choose
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "1. Move piece" << std::endl;
		std::cout << "2. Place piece" << std::endl;
		std::cout << "3. Quit" << std::endl;

		int input;
		while (1) {
			std::cin >> input;
			if (input == 1 || input == 2 || input == 3) {
				break;
			}
			else {
				std::cout << "Wrong input" << std::endl;
				std::cout << "Please give number between 1 ~ 3" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		// input == 3 --> Quiting the game
		if (input == 3) {
			std::cout << "Quit the game" << std::endl;
			break;
		}
		// input == 1 --> Moving piece
		else if (input == 1) {
			MovePiece(GameBoard);
		}
		// input == 2 --> Place piece
		else if (input == 2) {
			// check if the current player has pieces to put
			if (GameBoard.PlayerHasPiece()) {
				PlacePiece(GameBoard);
			}
			else std::cout << "You don't have pieces to put." << std::endl;
		}
	}
}

/// <summary>
/// move the piece
/// 1. select
/// 2. check the validity
/// 3. move the piece
/// </summary>
/// <param name="board"> Gameboard </param>
void MovePiece(Board& board)
{
	// loop 1 : loop untill get the correct overall input
	while (1) {
		std::cout << board << std::endl;
		std::cout << "Please enter the position of the piece to move" << std::endl;

		// loop 2 : loop untill get the correct position
		std::string input;
		Position pos;
		while (1) {
			std::cout << "Position ex) A2" << std::endl;
			std::cin >> input;
			if (input == "A1") {
				pos = { 0, 0 };
				break;
			}
			else if (input == "A2") {
				pos = { 1, 0 };
				break;
			}
			else if (input == "A3") {
				pos = { 2, 0 };
				break;
			}
			else if (input == "B1") {
				pos = { 0, 1 };
				break;
			}
			else if (input == "B2") {
				pos = { 1, 1 };
				break;
			}
			else if (input == "B3") {
				pos = { 2, 1 };
				break;
			}
			else if (input == "C1") {
				pos = { 0, 2 };
				break;
			}
			else if (input == "C2") {
				pos = { 1, 2 };
				break;
			}
			else if (input == "C3") {
				pos = { 2, 2 };
				break;
			}
			else if (input == "D1") {
				pos = { 0, 3 };
				break;
			}
			else if (input == "D2") {
				pos = { 1, 3 };
				break;
			}
			else if (input == "D3") {
				pos = { 2, 3 };
				break;
			}
			else {
				std::cout << "Wrong input" << std::endl;
				std::cout << "Please give correct position." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		std::cout << "Please enter the direction of the piece to move" << std::endl;

		// loop 2 : loop untill get the correct direction
		std::string dir_input;
		Direction dir;
		while (1) {
			std::cout << "Direction: [up, down, left, right, upleft, upright, downleft, downright]" << std::endl;
			std::cin >> dir_input;
			if (dir_input == "up") {
				dir = Direction::UP;
				break;
			}
			else if (dir_input == "down") {
				dir = Direction::DOWN;
				break;
			}
			else if (dir_input == "left") {
				dir = Direction::LEFT;
				break;
			}
			else if (dir_input == "right") {
				dir = Direction::RIGHT;
				break;
			}
			else if (dir_input == "upleft") {
				dir = Direction::UPLEFT;
				break;
			}
			else if (dir_input == "upright") {
				dir = Direction::UPRIGHT;
				break;
			}
			else if (dir_input == "downleft") {
				dir = Direction::DOWNLEFT;
				break;
			}
			else if (dir_input == "downright") {
				dir = Direction::DOWNRIGHT;
				break;
			}
			else {
				std::cout << "Wrong input" << std::endl;
				std::cout << "Please give correct direction." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		// if it is possible to move break the loop
		if (board.MovePiece(pos, dir)) {
			break;
		}
	}
}

/// <summary>
/// place the piece
/// 1. select
/// 2. check the validity
/// 3. place the piece
/// </summary>
/// <param name="board"> Gameboard </param>
void PlacePiece(Board& board)
{
	// loop 1 : loop untill placing the piece
	while (1) {
		std::cout << board << std::endl;
		std::cout << "Please enter the index of the piece to place" << std::endl;
		std::cout << "From 1 ~ " << board.PlayerPieceNum() << std::endl;

		// loop 2 : loop untill get the correct index
		int index;
		while (1) {
			std::cin >> index;
			if (index < 1 || index > board.PlayerPieceNum())
			{
				std::cout << "Wrong input" << std::endl;
				std::cout << "Please give correct number." << std::endl;
				std::cout << "From 1 ~ " << board.PlayerPieceNum() << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		}

		std::cout << "Please enter the position of the piece to move" << std::endl;

		// loop 3 : loop untill get the correct position
		// check if the position is valid
		// check if the player put the piece on the opponent's place (Wrong input)
		std::string pos_input;
		Position pos;
		while (1) {
			std::cout << "Position ex) A2" << std::endl;
			std::cin >> pos_input;
			if (pos_input == "A1") {
				if (board.GetPlayer() == Player::PLAYER_RIGHT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 0, 0 };
				break;
			}
			else if (pos_input == "A2") {
				if (board.GetPlayer() == Player::PLAYER_RIGHT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 1, 0 };
				break;
			}
			else if (pos_input == "A3") {
				if (board.GetPlayer() == Player::PLAYER_RIGHT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 2, 0 };
				break;
			}
			else if (pos_input == "B1") {
				pos = { 0, 1 };
				break;
			}
			else if (pos_input == "B2") {
				pos = { 1, 1 };
				break;
			}
			else if (pos_input == "B3") {
				pos = { 2, 1 };
				break;
			}
			else if (pos_input == "C1") {
				pos = { 0, 2 };
				break;
			}
			else if (pos_input == "C2") {
				pos = { 1, 2 };
				break;
			}
			else if (pos_input == "C3") {
				pos = { 2, 2 };
				break;
			}
			else if (pos_input == "D1") {
				if (board.GetPlayer() == Player::PLAYER_LEFT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 0, 3 };
				break;
			}
			else if (pos_input == "D2") {
				if (board.GetPlayer() == Player::PLAYER_LEFT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 1, 3 };
				break;
			}
			else if (pos_input == "D3") {
				if (board.GetPlayer() == Player::PLAYER_LEFT) {
					std::cout << "You can't put on opponent's place." << std::endl;
					continue;
				}
				pos = { 2, 3 };
				break;
			}
			else {
				std::cout << "Wrong input" << std::endl;
				std::cout << "Please give correct direction." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		// if it is possible to move break the loop
		if (board.PlacePiece(index, pos)) {
			break;
		}
	}
}