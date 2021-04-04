#include "tic_tac_toe.h"
using namespace std;

void TicTacToe::set_next_player()
{   if (player == "X")
        player = "O";
    else    
        player = "X";
}

bool TicTacToe::check_board_full()
{   for (int i = 0; i < 9; i++)
        {
            if (pegs[i] == " ")
                return false;
        }

    return true;
}

void TicTacToe::clear_board()
{   pegs.clear();

    for(int count = 0; count < 9; count++)
        pegs.push_back(" ");
}

bool TicTacToe::game_over()
{   return check_board_full();
}

void TicTacToe::start_game(string first_player)
{   player = first_player;

    clear_board();
}

void TicTacToe::mark_board(int position)
{   pegs[position - 1] = player;

    set_next_player();
}

string TicTacToe::get_player()const
{   return player;
}

void TicTacToe::display_board()const
{   cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << "\n";
    cout << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << "\n";
    cout << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << "\n";
}