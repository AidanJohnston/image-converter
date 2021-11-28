#include "../include/StartOfFrame.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>


StartOfFrame::StartOfFrame(bytes data) {

    this->length = (data[2] << 8) + (data[3]);
    this->precision = data[4];

    this->Y = (data[5] << 8) + (data[6]);
    this->X = (data[7] << 8) + (data[8]);
    this->numComponent = data[9];

    for(int i = 0; i < this->numComponent; i++) {

        this->componets.push_back(componet());

        this->componets[i].id = data[10 + 3 * i];
        this->componets[i].hSample = data[11 + 3 * i] && 0x0F;
        this->componets[i].vSample = data[11 + 3 * i] >> 4;
        this->componets[i].quantizationDest = data[12 + 3 * i];
    }


    printf("0x%X%X - SOF - Start of Frame %d\n", data[0], data[1], data[1] && 0x0F);
    printf("\tLength: %d bytes\n", this->length);
    printf("\tPrecision: %d\n", this->precision);
    printf("\tImage Dimensions (w x h): (%d px x %d px)\n", this->X, this->Y);

    printf("\tComponents: %d ", this->numComponent);
    if(this->numComponent)
        printf("(RGB)\n");
    else
        printf("(Grayscale)\n");

    for(int i = 0; i < this->componets.size(); i++) {
        printf("\t\tID Factor Table: %d %dx%d %d\n", this->componets[i].id, this->componets[i].hSample, this->componets[i].vSample, this->componets[i].quantizationDest);
    }

}