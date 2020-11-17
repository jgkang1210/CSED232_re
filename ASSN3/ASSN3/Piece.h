#ifndef PIECE
#define PIECE

class Piece
{
private:
	Player player;
	Position pos;
public:
	Piece();
	Piece(Player player_, Position pos_);
	Player GetPlayer() const;
	void SetPlayer(Player player_);
	Position GetPosition() const;
	virtual void SetPosition(Position pos_);

	// Pure virtual function
	virtual bool CanMoveTo(Direction dir) const = 0;
	virtual void PrintLabel(std::ostream& os) const = 0;
};

#endif