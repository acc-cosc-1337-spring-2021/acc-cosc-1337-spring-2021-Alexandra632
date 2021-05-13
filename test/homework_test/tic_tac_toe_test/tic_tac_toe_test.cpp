#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{	
		game->mark_board(3);
		game->mark_board(2);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(5);
		game->mark_board(1);
		game->mark_board(9);
		game->mark_board(7);
		game->mark_board(8);
	}
	
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(2);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(7);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(2);
		game->mark_board(1);
		game->mark_board(5);
		game->mark_board(4);
		game->mark_board(8);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(3);
		game->mark_board(1);
		game->mark_board(6);
		game->mark_board(4);
		game->mark_board(9);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(5);
		game->mark_board(2);
		game->mark_board(6);
		game->mark_board(3);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(4);
		game->mark_board(1);
		game->mark_board(5);
		game->mark_board(3);
		game->mark_board(6);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by third row")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(7);
		game->mark_board(1);
		game->mark_board(8);
		game->mark_board(4);
		game->mark_board(9);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left ")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(2);
		game->mark_board(5);
		game->mark_board(4);
		game->mark_board(9);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from bottom left ")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(7);
		game->mark_board(2);
		game->mark_board(5);
		game->mark_board(4);
		game->mark_board(3);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test get_winner_total() function")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe3>();
	TicTacToeManager manager;
	int x_win, o_win, tie;

	//O diagonal win
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(7);
		game->mark_board(2);
		game->mark_board(5);
		game->mark_board(4);
		game->mark_board(3);
	}
	manager.save_game(game);
	
	//X top row win
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(5);
		game->mark_board(2);
		game->mark_board(6);
		game->mark_board(3);
	}
	manager.save_game(game);

	//tie game
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(3);
		game->mark_board(2);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(5);
		game->mark_board(1);
		game->mark_board(9);
		game->mark_board(7);
		game->mark_board(8);
	}
	manager.save_game(game);
	manager.get_winner_total(x_win, o_win, tie);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 1);
	REQUIRE(tie == 1);
}

/// TicTacToe4 testing

TEST_CASE("Test game over if 16 slots are selected")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{	
		game->mark_board(1);
		game->mark_board(2);
		game->mark_board(3);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(5);
		game->mark_board(8);
		game->mark_board(7);
		game->mark_board(9);
		game->mark_board(10);
		game->mark_board(11);
		game->mark_board(12);
		game->mark_board(13);
		game->mark_board(15);
		game->mark_board(14);
		game->mark_board(16);
	}
	
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X in TicTacToe4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O in TicTacToe4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(4);
		game->mark_board(5);
		game->mark_board(7);
		game->mark_board(9);
		game->mark_board(16);
		game->mark_board(13);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(2);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(16);
		game->mark_board(10);
		game->mark_board(1);
		game->mark_board(14);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(3);
		game->mark_board(1);
		game->mark_board(7);
		game->mark_board(16);
		game->mark_board(11);
		game->mark_board(4);
		game->mark_board(15);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(4);
		game->mark_board(3);
		game->mark_board(8);
		game->mark_board(1);
		game->mark_board(12);
		game->mark_board(2);
		game->mark_board(16);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(8);
		game->mark_board(2);
		game->mark_board(16);
		game->mark_board(3);
		game->mark_board(5);
		game->mark_board(4);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(5);
		game->mark_board(1);
		game->mark_board(6);
		game->mark_board(3);
		game->mark_board(7);
		game->mark_board(12);
		game->mark_board(8);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by third row of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(9);
		game->mark_board(1);
		game->mark_board(10);
		game->mark_board(4);
		game->mark_board(11);
		game->mark_board(6);
		game->mark_board(12);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by fourth row of 4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(13);
		game->mark_board(1);
		game->mark_board(14);
		game->mark_board(4);
		game->mark_board(15);
		game->mark_board(6);
		game->mark_board(16);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left of 4 square board")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(2);
		game->mark_board(6);
		game->mark_board(4);
		game->mark_board(11);
		game->mark_board(5);
		game->mark_board(16);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from bottom left of 4 square board")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(4);
		game->mark_board(2);
		game->mark_board(7);
		game->mark_board(9);
		game->mark_board(10);
		game->mark_board(3);
		game->mark_board(13);
	}
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test get_winner_total() function in TicTacToe4")
{
	std::unique_ptr<TicTacToe>game = std::make_unique<TicTacToe4>();
	TicTacToeManager manager;
	int x_win, o_win, tie;

	//O diagonal win
	game->start_game("O");
	while (!game->game_over())
	{
		game->mark_board(4);
		game->mark_board(2);
		game->mark_board(7);
		game->mark_board(9);
		game->mark_board(10);
		game->mark_board(3);
		game->mark_board(13);
	}
	manager.save_game(game);
	
	//X top row win
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(8);
		game->mark_board(2);
		game->mark_board(16);
		game->mark_board(3);
		game->mark_board(5);
		game->mark_board(4);
	}
	manager.save_game(game);

	//tie game
	game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	while (!game->game_over())
	{
		game->mark_board(1);
		game->mark_board(2);
		game->mark_board(3);
		game->mark_board(4);
		game->mark_board(6);
		game->mark_board(5);
		game->mark_board(8);
		game->mark_board(7);
		game->mark_board(9);
		game->mark_board(10);
		game->mark_board(11);
		game->mark_board(12);
		game->mark_board(13);
		game->mark_board(15);
		game->mark_board(14);
		game->mark_board(16);
	}
	manager.save_game(game);
	manager.get_winner_total(x_win, o_win, tie);

	REQUIRE(x_win == 1);
	REQUIRE(o_win == 1);
	REQUIRE(tie == 1);
}