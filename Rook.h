#ifndef ROOK_H
#define ROOK_H
#include "ChessPiece.h"
class Rook : public ChessPiece
{
public:
	Rook();
	Rook(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
};
#endif
