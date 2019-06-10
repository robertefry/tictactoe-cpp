
#include <ostream>

struct Player {
    char piece;
    Player( char piece ) : piece(piece) {}
    inline operator char() const { return piece; }
};

class PlayerSwitcher {

    private:
        Player players[2];
        mutable int index = 0;

    public:
        PlayerSwitcher() : players({Player('O'),Player('X')}) {}

    public:
        Player current() const;
        Player next() const;

};

Player PlayerSwitcher::current() const {
    return players[index];
}

Player PlayerSwitcher::next() const {
    index = ( index + 1 ) % 2;
    return players[index];
}

std::ostream& operator<<( std::ostream& stream, const Player& player ) {
    return stream << "player:" << player.piece;
}
