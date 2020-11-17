#ifndef PAWN
#define PAWN

class Pawn :
    public Piece
{
private:
    bool isPromoted = false;
public:
    Pawn(Player player_, Position pos_);
    void Init(Player player_, Position pos_);
    void SetPosition(Position pos_);
    bool CanMoveTo(Direction dir) const;
    void PrintLabel(std::ostream& os) const;
};

#endif