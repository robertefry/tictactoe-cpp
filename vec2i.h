
#include <ostream>

struct vec2i {
    int x, y;
};

std::ostream& operator<<( std::ostream& stream, const vec2i& vec ) {
    return stream << '[' << vec.x << ',' << vec.y << ']';
}
