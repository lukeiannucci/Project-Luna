#include "Rook.h"
Rook::Rook()
{
	this->piece = ChessPieces::ROOK;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

Rook::Rook(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::ROOK;
	this->color = color;
	this->coordinates = coordinates;
}

std::vector<Coordinates> Rook::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	std::cout << "Move me Rook";
	return allPossibleMoves;
}