#include <iostream>
#include <string>
#include <vector>

class TicTacToe
{
    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();

        std::string player;
        std::vector <std::string> pegs{" "," "," "," "," "," "," "," "," "};

    public:
        bool game_over();
        void start_game(std::string);
        void mark_board(int);
        std::string get_player() const;
        void display_board() const;
};