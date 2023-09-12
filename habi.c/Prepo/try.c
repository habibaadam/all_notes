#include <stdio.h>

int main() {
    typedef struct point point;
    struct point {
        int x;
        int y;
    };
    point p = {.y = 2, .x = 1};

    return (0);
}