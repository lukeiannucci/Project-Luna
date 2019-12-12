#ifndef KNIGHT_H
#define KNIGHT_H
#include "ChessPiece.h"
class Knight : public ChessPiece
{
public:
	Knight();
	Knight(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
};
#endif