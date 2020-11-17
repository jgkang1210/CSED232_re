#ifndef KING
#define KING

class King :
    public Piece
{
public:
    King(Player player, Position pos_);
    bool CanMoveTo(Direction dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif