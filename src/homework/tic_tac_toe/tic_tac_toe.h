#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <iostream>
#include <string>
#include <vector>

class TicTacToe
{
    protected:
        std::vector <std::string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        std::string player;
        std::string winner;
        
    public:
        TicTacToe();
        TicTacToe(int);
        virtual ~TicTacToe();
        bool game_over();
        void start_game(std::string);
        void mark_board(int);
        std::string get_player() const;
        std::string get_winner();

        friend std::ostream& operator<<(std::ostream&, const std::unique_ptr<TicTacToe>&);
        friend std::istream& operator<<(std::istream&, std::unique_ptr<TicTacToe>&);
};
#endif