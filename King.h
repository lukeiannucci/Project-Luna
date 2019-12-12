#ifndef KING_H
#define KING_H
#include "ChessPiece.h"
class King : public ChessPiece
{
public:
	King();
	King(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
};
#endif
