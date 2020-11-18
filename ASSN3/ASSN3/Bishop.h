#ifndef BISHOP
#define BISHOP

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"

class Bishop :
    public Piece
{
public:
    Bishop(const Player& player_, const Position& pos_);
    bool CanMoveTo(const Direction& dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif