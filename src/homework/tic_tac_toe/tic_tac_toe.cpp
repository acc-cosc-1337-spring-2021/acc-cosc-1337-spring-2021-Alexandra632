#include "tic_tac_toe.h"
#include <cmath>
using namespace std;

TicTacToe::TicTacToe()
{
}

TicTacToe::TicTacToe(int s):pegs(s*s, " ")
{   
}

TicTacToe::~TicTacToe()
{
}

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
{   int vec_size = pegs.size();
    
    pegs.clear();
    
    for(int count = 0; count < vec_size; count++)
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

std::ostream& operator<<(ostream& out, const unique_ptr<TicTacToe>& game_ptr)
{   int vec_size = game_ptr->pegs.size();
    int peg_index = 0;
    for (int j = 0; j < sqrt(vec_size); j++)
    {
        for (int i = 0; i < sqrt(vec_size); i++)
        {
            out << game_ptr->pegs[peg_index++];
            if (i < sqrt(vec_size) - 1)
                out << "|";
        }

        out << "\n";
    }
    return out;
}

std::istream& operator<<(istream& in, unique_ptr<TicTacToe>& game_ptr)
{
    int position;
    int vec_size = game_ptr->pegs.size();
    cout << "Enter a position 1 to " << vec_size << " to mark the board: ";
    in >> position;
    game_ptr->mark_board(position);
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
{   return false;
}

bool TicTacToe::check_row_win()
{   return false;
}

bool TicTacToe::check_diagonal_win()
{   return false;
}

