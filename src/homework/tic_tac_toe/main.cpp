#include "tic_tac_toe.h"
using namespace std;

int main() 
{
	TicTacToe game;
	TicTacToeManager manager;
	std::string X_or_O;
	int square;
	int x_win, o_win, tie;
	char again;

	cout << "Let's play Tic Tac Toe!\n";
	
	do
	{
		cout << "Who will play first, X or O: ";
		cin >> X_or_O;
		game.start_game(X_or_O);
		cout << game;
		cout << "Ok, choose a square to mark the board: ";
		cin >> square;
		game.mark_board(square);
		cout << game;
				
		while (square != 0 && !game.game_over())
		{
			cout << "Next player, choose a square (or enter 0 to quit): ";
			cin >> square;
			if (square == 0)
				break;
			game.mark_board(square);
			cout << game;
		}
			
		if (square != 0)
		{
			cout << "The winner is: " << game.get_winner() << "!\n";
			manager.save_game(game);
			manager.get_winner_total(x_win, o_win, tie);
			cout << "Number of X wins: " << x_win << "\n";
			cout << "Number of O wins: " << o_win << "\n";
			cout << "Number of ties: " << tie << "\n";
			cout << "Would you like to play again? If yes, enter Y. ";
			cin >> again;
		}
		else
		{
			manager.save_game(game);
			manager.get_winner_total(x_win, o_win, tie);
			cout << "Number of X wins: " << x_win << "\n";
			cout << "Number of O wins: " << o_win << "\n";
			cout << "Number of ties: " << tie << "\n";
			cout << "Would you like to play again? If yes, enter Y. ";
			cin >> again;
		}
					
	} while (again == 'Y' || again == 'y');

	cout << manager;
	

	return 0;

}