#ifndef QUEEN_H
#define QUEEN_H
#include "ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen();
	Queen(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
};
#endif
