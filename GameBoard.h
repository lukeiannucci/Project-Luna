#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include "ChessBoardSquare.h"
class GameBoard
{
public:
	GameBoard();
	char mapChessPieceToChar(ChessPieces chessPiece);
	//testing only
	void movePiece(const Coordinates moveFrom, const Coordinates moveTo);
	void print();
	ChessPiece* checkValidCoordinates(const Color color, const Coordinates * coordinates);
private:
	void initializeGameBoard();
	ChessBoardSquare intializeChessSquare(const int xCoor, const int yCoor, const bool isWhite);
	ChessBoardSquare setKingRow(const int xCoor, const int yCoor, const Color squareColor, const bool isWhitePiece);
	ChessBoardSquare board[BOARD_LENGTH][BOARD_WIDTH];
};
#endif
