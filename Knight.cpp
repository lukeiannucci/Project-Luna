#include "Knight.h"
Knight::Knight()
{
	this->piece = ChessPieces::KNIGHT;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

Knight::Knight(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::KNIGHT;
	this->color = color;
	this->coordinates = coordinates;
}

std::vector<Coordinates> Knight::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	std::cout << "Move me Knight";
	return allPossibleMoves;
}