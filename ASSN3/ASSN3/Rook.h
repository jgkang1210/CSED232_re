#ifndef ROOK
#define ROOK

class Rook :
    public Piece
{
public:
    Rook(Player player_, Position pos_);
    bool CanMoveTo(Direction dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif