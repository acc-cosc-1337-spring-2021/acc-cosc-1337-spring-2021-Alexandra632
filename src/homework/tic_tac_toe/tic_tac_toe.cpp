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
{   if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    
    if (check_board_full())
    {
        winner = "C";
        return true;
    }

    return false;
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

string TicTacToe::get_winner()
{   return winner;
}

void TicTacToe::set_winner()
{   if (player == "X")
        winner = "O";
    else    
        winner = "X";
}

bool TicTacToe::check_column_win()
{   if ((pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X") ||
        
        (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X") ||
        
        (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X") ||
        
        (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O") ||
        
        (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O") ||
        
        (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O"))
        
        return true;

    return false;
}

bool TicTacToe::check_row_win()
{   if ((pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") ||
        
        (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") ||
        
        (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X") ||
        
        (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") ||
        
        (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") ||
        
        (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O"))
        
        return true;

    return false;
}

bool TicTacToe::check_diagonal_win()
{   if ((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X") ||
        
        (pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X") ||
        
        (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O") ||
        
        (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O"))
        
        return true;

    return false;
}