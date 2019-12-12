#ifndef CHESS_H
#define CHESS_H
#include "GameBoard.h"
#include <string>
class Chess
{
public:
	void playChess();
	bool selectPieceToMove(const Color Color);
	void gameLoop();
private:
	bool validateCoordinateInput(const std::string sCoor, Coordinates* coordinates);
	bool validateColumnInput(const char ascii, int* col);
	bool validateRowInput(const char ascii, int* row);
	int getPlayers();
	GameBoard * gameBoard;
};
#endif
