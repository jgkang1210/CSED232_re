#ifndef PAWN
#define PAWN

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"

class Pawn :
    public Piece
{
private:
    bool isPromoted = false;
public:
    Pawn(const Player& player_, const Position& pos_);
    void Switch(const Player& player_, const Position& pos_);
    void SetPosition(const Position& pos_);
    bool CanMoveTo(const Direction& dir) const;
    void PrintLabel(std::ostream& os) const;
    bool PawnIsPromoted() const;
};

#endif