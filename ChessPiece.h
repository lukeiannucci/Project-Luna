#ifndef CHESSPIECE_H
#define CHESSPIECE_H 
#include "Utils.h"

//i think i want this whole thing to be an interface
class ChessPiece
{
public:
	//Constructors
	ChessPiece();
	ChessPiece(ChessPieces piece, Color color, Coordinates coordinates);

	virtual std::vector<Coordinates> possibleMoves() = 0;

	//getters
	ChessPieces getChessPiece();
	Color getColor();
	Coordinates getCoordinates();

	//setters
	void setChessPiece(ChessPieces piece);
	void setColor(Color color);
	void setCoordinates(Coordinates coordinates);

protected:
	ChessPieces piece;
	Color color;
	Coordinates coordinates;
};
#endif