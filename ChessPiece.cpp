#include "ChessPiece.h"

#pragma region CONSTRUCTORS
ChessPiece::ChessPiece()
{
	this->piece = ChessPieces::UNDEFINED;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
}

ChessPiece::ChessPiece(ChessPieces piece, Color color, Coordinates coordinates)
{
	this->piece = piece;
	this->color = color;
	this->coordinates = coordinates;
}
#pragma endregion CONSTRUCTORS

#pragma region GETTERS
ChessPieces ChessPiece::getChessPiece()
{
	return this->piece;
}

Color ChessPiece::getColor()
{
	return this->color;
}

Coordinates ChessPiece::getCoordinates()
{
	return this->coordinates;
}
#pragma endregion GETTERS

#pragma region SETTERS
void ChessPiece::setChessPiece(ChessPieces piece)
{
	this->piece = piece;
}

void ChessPiece::setColor(Color color)
{
	this->color = color;
}

void ChessPiece::setCoordinates(Coordinates coordinates)
{
	this->coordinates = coordinates;
}
#pragma endregion SETTERS