#include "ChessBoardSquare.h"
ChessBoardSquare::ChessBoardSquare()
{
	this->chessPiece = nullptr;
	this->color = Color::UNDEFINED;
}

ChessBoardSquare::ChessBoardSquare(ChessPiece* chessPiece, Color color)
{
	this->chessPiece = chessPiece;
	this->color = color;
}

ChessBoardSquare::~ChessBoardSquare()
{
	//delete this->chessPiece;
}

ChessPiece * ChessBoardSquare::getChessPiece()
{
	return this->chessPiece;
}

void ChessBoardSquare::setChessPiece(ChessPiece* chessPiece)
{
	this->chessPiece = chessPiece;
}