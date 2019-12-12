#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <Windows.h>
const int BOARD_WIDTH = 8;
const int BOARD_LENGTH = 8;
const int SPAWN_PAWN_ROW_BLACK = 1;
const int SPAWN_PAWN_ROW_WHITE = 6;
const int SPAWN_KING_ROW_BLACK = 0;
const int SPAWN_KING_ROW_WHITE = 7;
static const char* columnHeader = "  A B C D E F G H\n";
#define xxPrintGrayBackGround SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x50 | 0x07);
#define xxPrintWhiteOnBlack SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
#define xxPrintRedOnBlack SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08 | 0x04);
const std::unordered_map<char, int> validColumnMapping = { {'A', 0},
														   {'B', 1},
														   {'C', 2},
														   {'D', 3},
														   {'E', 4},
														   {'F', 5},
														   {'G', 6},
														   {'H', 7} };

const std::unordered_map<int, int> validRowMapping = { {1,7},
														   {2, 6},
														   {3, 5},
														   {4, 4},
														   {5, 3},
														   {6, 2},
														   {7, 1},
														   {8, 0} };

//TODO
enum class ChessPieces
{
	UNDEFINED = -1,
	ROOK = 0,
	KNIGHT =  1,
	BISHOP = 2,
	QUEEN = 3,
	KING = 4,
	BISHOP_2 = 5,
	KNIGHT_2 = 6,
	ROOK_2 = 7,
	PAWN = 8
};

enum class Color
{
	UNDEFINED = -1,
	WHITE = 0,
	BLACK = 1
};

struct Coordinates
{
	int row;
	int col;

	Coordinates()
	{
		this->row = -1;
		this->col = -1;
	}

	Coordinates(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
};
static void printError(const char* errorMsg)
{
	xxPrintRedOnBlack
	std::cout << errorMsg;
	xxPrintWhiteOnBlack
}
#endif // !UTILS_H


