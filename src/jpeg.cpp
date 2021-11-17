// jpeg.cpp

#include "../include/jpeg.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

JPEG::JPEG(std::string filename) {

    this->fp = fopen(filename.c_str(), "rb");

    if(!this->fp) {
        printf("Could not open file.\n");
        exit(1);
    }
    else {
        printf("Image opened.\n");
        
        while(!feof(this->fp)) {
            this->parseSeg();
        }
     }

}

int JPEG::parseSeg() {

    u16 id = readWord();
    printf("%.2X\n", id);
    return 0; 
}

u16 JPEG::readWord() {
    return ((fgetc(fp) << 8) | fgetc(fp));
}