#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class TicTacToeManager
{
    private:
        std::vector <std::unique_ptr<TicTacToe>> games;
        void update_winner_count(std::string);

        int x_wins = {0};
        int o_wins = {0};
        int ties = {0};

    public:
        void save_game(std::unique_ptr<TicTacToe>&);
        void get_winner_total(int&, int&, int&);

        friend std::ostream& operator<<(std::ostream&, const TicTacToeManager&);


};
#endif