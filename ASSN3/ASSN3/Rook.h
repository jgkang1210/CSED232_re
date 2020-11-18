#ifndef ROOK
#define ROOK

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"

class Rook :
    public Piece
{
public:
    Rook(const Player& player_, const Position& pos_);
    bool CanMoveTo(const Direction& dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif