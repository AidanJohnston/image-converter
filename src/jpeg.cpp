// jpeg.cpp

#include "../include/jpeg.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

JPEG::JPEG(std::string filename) {

    fp = fopen(filename.c_str(), "rb");

    if(!fp) {
        printf("Could not open file.\n");
        exit(1);
    }
    else {
        printf("Image opened.\n");
    }

}

int JPEG::parseSeg() {


    return 0;
}