// check if two rectangles intersect
#include <iostream>
#include <algorithm>

using namespace std;

class Rectangle {
    public:
        int x, y, height, width;
};

bool does_intersect(const Rectangle &R, const Rectangle &S) {
    return R.x < S.x + S.width && R.x + R.width >= S.x &&
        R.y < S.y + S.height && R.y + R.height >= S.y;
}

Rectangle intersectingRectangle(const Rectangle &R, const Rectangle &S) {
    if (does_intersect(R, S)) {
        return {
            max(R.x, S.x),
            max(R.y, S.y),
            min(R.x + R.width, S.x + S.width) - max(R.x, S.x),
            min(R.y + R.height, S.y + S.height) - max(R.y, S.y)
        };
    } else return {
        0, 0, -1, -1
    };
}

int main() {

    // test this in rev
}