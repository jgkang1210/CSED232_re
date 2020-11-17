#ifndef BISHOP
#define BISHOP

class Bishop :
    public Piece
{
public:
    Bishop(Player player_, Position pos_);
    bool CanMoveTo(Direction dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif