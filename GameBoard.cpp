#include "GameBoard.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"

ChessBoardSquare GameBoard::setKingRow(const int xCoor, const int yCoor, const Color squareColor, const bool isWhitePiece)
{
	ChessPieces piece = static_cast<ChessPieces>(yCoor);
	Color pieceColor = isWhitePiece ? Color::WHITE : Color::BLACK;
	switch (piece)
	{
	case ChessPieces::ROOK_2:
	case ChessPieces::ROOK:
	{
		return ChessBoardSquare(new Rook(pieceColor, Coordinates(xCoor, yCoor)), squareColor);
	}
	case ChessPieces::KNIGHT_2:
	case ChessPieces::KNIGHT:
	{
		return ChessBoardSquare(new Knight(pieceColor, Coordinates(xCoor, yCoor)), squareColor);
	}
	case ChessPieces::BISHOP_2:
	case ChessPieces::BISHOP:
	{
		return ChessBoardSquare(new Bishop(pieceColor, Coordinates(xCoor, yCoor)), squareColor);
	}
	case ChessPieces::QUEEN:
	{
		return ChessBoardSquare(new Queen(pieceColor, Coordinates(xCoor, yCoor)), squareColor);
	}
	case ChessPieces::KING:
	{
		return ChessBoardSquare(new King(pieceColor, Coordinates(xCoor, yCoor)), squareColor);
	}
	default:
	{
		throw;
		//std::cout << "xCoor: " << xCoor << "\nyCoor: " << yCoor << std::endl;
	}
	}
}

ChessBoardSquare GameBoard::intializeChessSquare(const int xCoor, const int yCoor, const bool isWhite)
{
	Color Color = isWhite ? Color::WHITE : Color::BLACK;
	if (xCoor == SPAWN_PAWN_ROW_WHITE)
	{
		return ChessBoardSquare(new Pawn(Color::WHITE, Coordinates(xCoor, yCoor)), Color);
	}
	if (xCoor == SPAWN_PAWN_ROW_BLACK)
	{
		return ChessBoardSquare(new Pawn(Color::BLACK, Coordinates(xCoor, yCoor)), Color);
	}
	if (xCoor == SPAWN_KING_ROW_BLACK)
	{
		return this->setKingRow(xCoor, yCoor, Color, false);
	}
	if (xCoor == SPAWN_KING_ROW_WHITE)
	{
		return this->setKingRow(xCoor, yCoor, Color, true);
	}
	return ChessBoardSquare(nullptr, Color);

}

char GameBoard::mapChessPieceToChar(const ChessPieces chessPiece)
{
	switch (chessPiece)
	{
	case ChessPieces::ROOK_2:
	case ChessPieces::ROOK:
	{
		return 'R';
	}
	case ChessPieces::KNIGHT_2:
	case ChessPieces::KNIGHT:
	{
		return 'N';
	}
	case ChessPieces::BISHOP_2:
	case ChessPieces::BISHOP:
	{
		return 'B';
	}
	case ChessPieces::QUEEN:
	{
		return 'Q';
	}
	case ChessPieces::KING:
	{
		return 'K';
	}
	case ChessPieces::PAWN:
	{
		return 'P';
	}
	default:
	{
		throw "No can do";
	}
	}
}

void GameBoard::initializeGameBoard()
{
	for (int iLength = 0; iLength < BOARD_LENGTH; iLength++)
	{
		if (iLength == 0) std::cout << columnHeader;
		for (int iWidth = 0; iWidth < BOARD_WIDTH; iWidth++)
		{
			if (iWidth == 0) std::cout << (8 - iLength) << " ";
			if ((iLength % 2 == 0 && iWidth % 2 == 0) || (iLength % 2 == 1 && iWidth % 2 == 1))
			{
				ChessBoardSquare chessBoardSquare = this->intializeChessSquare(iLength, iWidth, true);
				this->board[iLength][iWidth] = chessBoardSquare;
				
				if (chessBoardSquare.getChessPiece() != nullptr) std::cout << this->mapChessPieceToChar(chessBoardSquare.getChessPiece()->getChessPiece());
			}
			else if ((iLength % 2 == 1 && iWidth % 2 == 0) || (iLength % 2 == 0 && iWidth % 2 == 1))
			{
				ChessBoardSquare chessBoardSquare = this->intializeChessSquare(iLength, iWidth, false);
				this->board[iLength][iWidth] = chessBoardSquare;
				
				if (chessBoardSquare.getChessPiece() != nullptr)
				{
					xxPrintGrayBackGround;
					std::cout << this->mapChessPieceToChar(chessBoardSquare.getChessPiece()->getChessPiece());
				}
				else
				{
					if (iLength % 2 == 1)
					{
						xxPrintGrayBackGround
						std::cout << " ";
						xxPrintWhiteOnBlack
						std::cout << " ";
					}
					else
					{
						std::cout << " ";
						xxPrintGrayBackGround
						std::cout << " ";
					}
				}
			}
			else
			{
				std::cout << "Length: " << iLength << "\n";
				std::cout << "Width: " << iWidth << "\n";
			}
			xxPrintWhiteOnBlack
			std::cout << ((iWidth == (BOARD_WIDTH - 1)) ? "\n" : " ");
		}
	}
	std::cout << columnHeader;
}


void GameBoard::print()
{
	for (int iLength = 0; iLength < BOARD_LENGTH; iLength++)
	{
		for (int iWidth = 0; iWidth < BOARD_WIDTH; iWidth++)
		{
			if ((iLength % 2 == 0 && iWidth % 2 == 0) || (iLength % 2 == 1 && iWidth % 2 == 1))
			{
				char piece = (this->board[iLength][iWidth].getChessPiece() == nullptr) ? 
					'W' : this->mapChessPieceToChar(this->board[iLength][iWidth].getChessPiece()->getChessPiece());
				std::cout << piece;
			}
			else if ((iLength % 2 == 1 && iWidth % 2 == 0) || (iLength % 2 == 0 && iWidth % 2 == 1))
			{
				char piece = (this->board[iLength][iWidth].getChessPiece() == nullptr) ? 
					'B' : this->mapChessPieceToChar(this->board[iLength][iWidth].getChessPiece()->getChessPiece());
				std::cout << piece;
			}
			std::cout << ((iWidth == (BOARD_WIDTH - 1)) ? "\n" : " ");
		}
	}
}

void GameBoard::movePiece(const Coordinates moveFrom, const Coordinates moveTo)
{
	//todo try and swap memory locations.
	//idea is board[x1][y1] will point to board[x2][y2] and back.
	//this way there is no need to dynamically allocate memory, i am just moving it around

	//update i think this is what i want
	ChessPiece* move = this->board[moveFrom.row][moveFrom.col].getChessPiece();
	ChessPiece* spotToMoveTo = this->board[moveTo.row][moveTo.col].getChessPiece();

	//todo put this in a valid move function
	if (spotToMoveTo == nullptr)
	{
		Coordinates temp = move->getCoordinates();
		move->setCoordinates(Coordinates(moveTo.row, moveTo.col));
		this->board[moveFrom.row][moveFrom.col].setChessPiece(spotToMoveTo);
		this->board[moveTo.row][moveTo.col].setChessPiece(move);
	}
	else if (spotToMoveTo->getColor() == move->getColor())
	{
		std::cout << "Cannot move to spot of same color.";
	}
	//got em coach
	else if (spotToMoveTo->getColor() != move->getColor())
	{
		//free
		delete spotToMoveTo;
		//now ok to set to null - other wise memory leakkkkk
		this->board[moveFrom.row][moveFrom.col].setChessPiece(nullptr);

		this->board[moveTo.row][moveTo.col].setChessPiece(move);

	}
	std::cout << "\n\n\n";
	//this->print();
}

ChessPiece* GameBoard::checkValidCoordinates(const Color color, const Coordinates* coordinates)
{
	ChessPiece* piece = this->board[coordinates->row][coordinates->col].getChessPiece();
	if (piece != nullptr && piece->getColor() != color)
	{
		std::string team = color == Color::WHITE ? "white" : "black";
		std::string error = "\nThis is not your piece to move. Please move a " + team + " piece.\n";
		printError(error.c_str());
		return nullptr;
	}
	return piece;
}

GameBoard::GameBoard()
{
	this->initializeGameBoard();
}