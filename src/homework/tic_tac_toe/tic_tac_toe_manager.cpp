#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
using namespace std;

void TicTacToeManager::save_game(TicTacToe gameobj)
{
    games.push_back(gameobj);

    update_winner_count(gameobj.get_winner());
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
        ++x_wins;
    else if (winner == "O")
        ++o_wins;
    else
        ++ties;
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_wins;
    o = o_wins;
    t = ties;
}

std::ostream& operator<<(ostream& out, const TicTacToeManager& managerobj)
{
    int vec_size = managerobj.games.size();
    for (int i = 0; i < vec_size; i++)
        out << managerobj.games[i] << "\n";
        
    return out;
}