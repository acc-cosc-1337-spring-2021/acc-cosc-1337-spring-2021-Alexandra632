#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
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

std::ostream& operator<<(ostream& out, const TicTacToe& gameobj)
{   out << gameobj.pegs[0] << "|" << gameobj.pegs[1] << "|" << gameobj.pegs[2] << "\n";
    out << gameobj.pegs[3] << "|" << gameobj.pegs[4] << "|" << gameobj.pegs[5] << "\n";
    out << gameobj.pegs[6] << "|" << gameobj.pegs[7] << "|" << gameobj.pegs[8] << "\n";

    return out;
}

std::istream& operator<<(istream& in, TicTacToe& gameobj)
{
    int position;
    cout << "Enter a position 1-9 to mark the board: ";
    in >> position;
    gameobj.mark_board(position);
    return in;
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

