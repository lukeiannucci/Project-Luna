#ifndef BISHOP_H
#define BISHOP_H
#include "ChessPiece.h"
class Bishop : public ChessPiece
{
public:
	Bishop();
	Bishop(Color color, Coordinates coordinates);
	virtual std::vector<Coordinates> possibleMoves() override;
};
#endif
