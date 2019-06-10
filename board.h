
#include <ostream>

class Board {

    private:
        char _cells[3][3];

    public:
        Board();

    public:
        inline       char at( unsigned i, unsigned j )       { return _cells[i][j]; }
        inline const char at( unsigned i, unsigned j ) const { return _cells[i][j]; }

    public:
        bool empty( unsigned i, unsigned j ) const;
        bool emplace( char c, unsigned i, unsigned j );

};

Board::Board() {
    for ( unsigned i = 0; i < 3; ++i ) {
        for ( unsigned j = 0; j < 3; ++j ) {
            _cells[i][j] = ' ';
        }
    }
}

#include <iostream>

bool Board::empty( unsigned i, unsigned j ) const {
    return _cells[i][j] == ' ';
}

bool Board::emplace( char c, unsigned i, unsigned j ) {
    _cells[i][j] = c;
    bool checks[4] = { true, true, true, true }; // check row/col/diagonals for 3-in-a-row
    for ( unsigned k = 0; k < 3; ++k ) {
        if ( _cells[i][k] != c ) checks[0] = false;
        if ( _cells[k][j] != c ) checks[1] = false;
        if ( _cells[k][k] != c ) checks[2] = false;
        if ( _cells[k][2-k] != c ) checks[3] = false;
    }
    for ( unsigned k = 0; k < 4; ++k ) {
        if ( checks[k] ) return true;
    }
    return false;
}

std::ostream& operator<<( std::ostream& stream, const Board& board ) {
    for ( unsigned i = 0; i < 3; ++i ) {
        for ( unsigned j = 0; j < 3; ++j ) {
            stream << ' ' << board.at(i,j) << ' ';
            if ( j < 2 ) stream << '|';
        }
        if ( i < 2 ) stream << std::endl << "-----------" << std::endl;
    }
    return stream;
}
