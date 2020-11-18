#ifndef KING
#define KING

#include <iostream>
#include "EnumStruct.h"
#include "Piece.h"

class King :
    public Piece
{
public:
    // default constructor
    King(const Player& player_, const Position& pos_);

    // copy constructor
    King(const King& king);

    bool CanMoveTo(const Direction& dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif