#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H
#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include <vector>

class TicTacToe4 : public TicTacToe
{
    private:
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
    public:
        TicTacToe4();
};
#endif