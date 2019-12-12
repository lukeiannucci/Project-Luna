#include "Bishop.h"
Bishop::Bishop()
{
	this->piece = ChessPieces::BISHOP;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

Bishop::Bishop(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::BISHOP;
	this->color = color;
	this->coordinates = coordinates;
}

std::vector<Coordinates> Bishop::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	std::cout << "Move me Bishop";
	return allPossibleMoves;
}