#include "Square.h"

Square::Square()
{
	piece = nullptr;
}

Square::~Square()
{
	delete piece;
}

Piece* Square::GetPiece() const
{
	return piece;
}

// dynamic allocation
// get the piece and make the piece for dynamic allocation
void Square::SetPiece(Piece* piece_)
{
	// dynamic allocation
	if (piece_ == nullptr) {
		piece = nullptr;
	}
	// pawn
	else if (typeid(*piece_) == typeid(Pawn)) {
		Pawn* pawn_piece = new Pawn(piece_->GetPlayer(), piece_->GetPosition());
		if (piece_->PawnIsPromoted() == true) {
			(*pawn_piece).Switch(pawn_piece->GetPlayer(), pawn_piece->GetPosition());
		}
		piece = pawn_piece;
	}
	// bishop
	else if (typeid(*piece_) == typeid(Bishop)) {
		piece = new Bishop(piece_->GetPlayer(), piece_->GetPosition());
	}
	// rook
	else if (typeid(*piece_) == typeid(Rook)) {
		piece = new Rook(piece_->GetPlayer(), piece_->GetPosition());
	}
	// king
	else if (typeid(*piece_) == typeid(King)) {
		piece = new King(piece_->GetPlayer(), piece_->GetPosition());
	}
}

void Square::Clear()
{
	delete piece;
	piece = nullptr;
}
