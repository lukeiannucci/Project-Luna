#include "Chess.h"
#pragma region VALIDATION
bool Chess::validateRowInput(const char ascii, int * row)
{
	if (isdigit(ascii))
	{
		//convert to int
		int digit = ascii - '0';

		//look and see if the row exists
		std::unordered_map<int, int>::const_iterator it = validRowMapping.find(digit);
		if (it != validRowMapping.end())
		{
			//store it, valid user input!
			*row = (*it).second;
			return true;
		}
	}

	//invalid row
	return false;
}

bool Chess::validateColumnInput(const char ascii, int * col)
{
	if (isalpha(ascii))
	{
		//convert it to upper case so there is no need for storing 'a' and 'A' and mapping to same value
		char uppercase = std::toupper(ascii);

		//look and see if the row exists
		std::unordered_map<char, int>::const_iterator it = validColumnMapping.find(uppercase);
		if (it != validColumnMapping.end())
		{
			//store it, valid user input!
			*col = (*it).second;
			return true;
		}
	}
	//invalid col
	return false;
}

bool Chess::validateCoordinateInput(const std::string pieceToMove, Coordinates * coordinates)
{
	//if it is not equal to two just 
	if (pieceToMove.length() != 2)
	{
		printError("\nInput needs to only be 2 characters a number and a letter (Ex: a1 or 1a)\n");
		return false;
	}
	int col = -1;
	int row = -1;
	if (validateRowInput(pieceToMove[0], &row) && validateColumnInput(pieceToMove[1], &col))
	{
		coordinates->row = row;
		coordinates->col = col;
		return true;
	}
	else if (validateRowInput(pieceToMove[1], &row) && validateColumnInput(pieceToMove[0], &col))
	{
		coordinates->row = row;
		coordinates->col = col;
		return true;
	}
	printError("\nInput needs to be one of the following letters: A-G and one of the following numbers 1-8.\n");
	return false;
}
#pragma endregion VALIDATION

#pragma region PROMPT
int Chess::getPlayers()
{
	int numberOfPlayers = 0;
	std::cout << "***Project Luna***\n";
	while (1)
	{
		std::cout << "1 or 2 players? ";
		std::cin >> numberOfPlayers;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			printError("Invalid input.\n");
		}
		else if (numberOfPlayers == 1 || numberOfPlayers == 2)
		{
			return numberOfPlayers;
		}
		else
		{
			printError("Invalid option must be 1 or 2 players.\n");
		}
	}
}

void Chess::gameLoop()
{
	std::cout << "\nHave fun!";
	std::string pieceToMoveCoordinates = "";
	//white goes first
	bool whiteTurn = true;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	while (1)
	{
		Coordinates* coordinates = new Coordinates(-1, -1);
		std::cout << "\nPlayer 1 enter coordinates of piece you would like to move: ";
		std::getline(std::cin, pieceToMoveCoordinates);
		if (validateCoordinateInput(pieceToMoveCoordinates, coordinates))
		{
			Color turn = whiteTurn ? Color::WHITE : Color::BLACK;
			ChessPiece* piece = gameBoard->checkValidCoordinates(turn, coordinates);
			if (piece != nullptr)
			{
				//fix this
				std::vector<Coordinates> test = piece->possibleMoves();
				whiteTurn = !whiteTurn;
			}
		}
		delete coordinates;
	}
}
#pragma endregion PROMPTS

bool Chess::selectPieceToMove(Color Color)
{
	return true;
}

void Chess::playChess()
{
	int players = getPlayers();
	if (players == 1)
	{
		std::cout << "Hello, I am Luna. Let's play some chess!\n";
		//todo
	}
	else if (players == 2)
	{
		this->gameBoard = new GameBoard();
		this->gameLoop();
		delete gameBoard;
	}
}