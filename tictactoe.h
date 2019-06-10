
#include <iostream>
#include "board.h"
#include "players.h"
#include "vec2i.h"

class TicTacToe {

    private:
        Board board;

    public:
        void play();
        vec2i input() const;

};

void TicTacToe::play() {

    Board board;
    PlayerSwitcher players;

    std::cout << "Welcome to TicTacToe." << std::endl;
    std::cout << "Each player takes a turn to put a piece on the board." << std::endl;
    std::cout << "Put a piece on the board by pressing its corresponding number." << std::endl;
    std::cout << "When a player reaches 3-in-a-row, the game is won!" << std::endl;
    std::cout << std::endl;
    std::cout << " 1 | 2 | 3" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " 4 | 5 | 6" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " 7 | 8 | 9" << std::endl;

    Player player = players.current();
    bool winner = false;
    while ( !winner ) {
        
        player = players.current();
        std::cout << std::endl << board << std::endl;
        std::cout << player << " plays next." << std::endl;

        vec2i coords = input();
        winner = board.emplace( player, coords.x, coords.y );
        players.next();

    }

    std::cout << player << " won! Congratulations!!!" << std::endl;

}

vec2i TicTacToe::input() const {
    char c;
    std::cout << '>';
    std::cin >> c;
    if ( c < '1' || c > '9' ) {
        std::cout << "Please enter a number from 1 to 9." << std::endl;
        return input();
    }
    vec2i coords = { (c-'1') / 3, (c-'1') % 3 };
    if ( !board.empty( coords.x, coords.y ) ) {
        std::cout << "This cell already contains a 'O' or 'X', please choose another one." << std::endl;
        return input();
    }
    return coords;
} 
