#include "King.h"
King::King()
{
	this->piece = ChessPieces::KING;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

King::King(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::KING;
	this->color = color;
	this->coordinates = coordinates;
}

std::vector<Coordinates> King::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	std::cout << "Move me King";
	return allPossibleMoves;
}