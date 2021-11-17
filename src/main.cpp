// main.cpp
#include <stdio.h>
#include "../include/JPEG.h"

int main(int argc, char* argv[]) {

    if (argc > 1) {
        JPEG jpeg = JPEG(argv[1]);
    }

    return 0;
}