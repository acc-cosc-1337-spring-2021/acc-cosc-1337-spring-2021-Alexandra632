#include "tic_tac_toe.h"
using namespace std;

int main() 
{
	TicTacToe game;
	std::string X_or_O;
	int square;
	char again;

	cout << "Let's play Tic Tac Toe!\n";
	
	do
	{
		cout << "Who will play first, X or O: ";
		cin >> X_or_O;
		game.start_game(X_or_O);
		game.display_board();
		cout << "Ok, choose a square to mark the board: ";
		cin >> square;
		game.mark_board(square);
		game.display_board();
				
		while (square != 0 && !game.game_over())
		{
			cout << "Next player, choose a square (or enter 0 to quit): ";
			cin >> square;
			if (square == 0)
				break;
			game.mark_board(square);
			game.display_board();
		}
			
		if (square != 0)
		{
			cout << "The winner is: " << game.get_winner() << "!\n";
			cout << "Would you like to play again? If yes, enter Y. ";
			cin >> again;
		}
		else
		{
			cout << "Would you like to play again? If yes, enter Y. ";
			cin >> again;
		}
					
	} while (again == 'Y' || again == 'y');

	return 0;
}