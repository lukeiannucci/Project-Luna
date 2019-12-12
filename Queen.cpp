#include "Queen.h"
Queen::Queen()
{
	this->piece = ChessPieces::QUEEN;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

Queen::Queen(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::QUEEN;
	this->color = color;
	this->coordinates = coordinates;
}

std::vector<Coordinates> Queen::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	std::cout << "Move me Queen";
	return allPossibleMoves;
}