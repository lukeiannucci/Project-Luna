#ifndef PAWN_H
#define PAWN_H
#include "ChessPiece.h"
class Pawn : public ChessPiece
{
public:
	Pawn();
	Pawn(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
private:
	bool hasMoved;
};
#endif