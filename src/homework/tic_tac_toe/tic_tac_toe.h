#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <iostream>
#include <string>
#include <vector>

class TicTacToe
{
    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();

        std::string player;
        std::string winner;
        std::vector <std::string> pegs{" "," "," "," "," "," "," "," "," "};

    public:
        bool game_over();
        void start_game(std::string);
        void mark_board(int);
        std::string get_player() const;
        std::string get_winner();

        friend std::ostream& operator<<(std::ostream&, const TicTacToe&);
        friend std::istream& operator<<(std::istream&, TicTacToe&);
};
#endif