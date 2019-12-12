#ifndef CHESSBOARDSQUARE_H
#define CHESSBOARDSQUARE_H
#include "ChessPiece.h"
class ChessBoardSquare
{
public:
	ChessBoardSquare();
	ChessBoardSquare(ChessPiece * chessPiece, Color color);
	ChessPiece * getChessPiece();
	void setChessPiece(ChessPiece* chessPiece);
	~ChessBoardSquare();
private:
	ChessPiece* chessPiece;
	Color color;
};
#endif // !ChessBoardSquare_H
