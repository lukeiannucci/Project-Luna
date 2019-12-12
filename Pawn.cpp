#include "Pawn.h"
Pawn::Pawn()
{
	this->piece = ChessPieces::PAWN;
	this->color = Color::UNDEFINED;
	this->coordinates = Coordinates(-1, -1);
	this->hasMoved = false;
}

Pawn::Pawn(Color color, Coordinates coordinates)
{
	this->piece = ChessPieces::PAWN;
	this->color = color;
	this->coordinates = coordinates;
	this->hasMoved = false;
}

//too much logic here and i dont like it
//i also can't do any filtering because pieces do not know where any pieces are
//I also hate the white and black checks
//this needs to be rethought
std::vector<Coordinates> Pawn::possibleMoves()
{
	std::vector<Coordinates> allPossibleMoves;
	if (this->color == Color::WHITE)
	{
		allPossibleMoves.push_back(Coordinates());
	}
	else if(this->color == Color::BLACK)
	{

	}
	else
	{

	}
	if (!hasMoved)
	{
		if (this->color == Color::WHITE)
		{
			allPossibleMoves.push_back(Coordinates(3, this->coordinates.col));
		}
		else if(this->color == Color::BLACK)
		{
			allPossibleMoves.push_back(Coordinates(4, this->coordinates.col));
		}
		else
		{
			throw "Piece should not be undefined.";
		}
	}
	std::cout << "Move me Pawn";
	return allPossibleMoves;
}