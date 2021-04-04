#include "tic_tac_toe.h"
using namespace std;

int main() 
{
	TicTacToe game;
	std::string X_or_O;
	int square;

	cout << "Let's play Tic Tac Toe!\n";
	game.display_board();
	cout << "Who will play first, X or O: ";
	cin >> X_or_O;
	game.start_game(X_or_O);
	cout << "Ok, choose a square to mark the board: \n";
	cin >> square;
	game.mark_board(square);
	game.display_board();
	while (! game.game_over())
		{
			cout << "Next player, choose a square: ";
			cin >> square;
			game.mark_board(square);
			game.display_board();
		}
	return 0;
}