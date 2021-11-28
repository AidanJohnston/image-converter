#include "../include/StartOfScan.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>


StartOfScan::StartOfScan(bytes data) {

    this->length = (data[2] << 8) + (data[3]);
    this->n = data[4];

    for(int i = 0; i < n; i++) {
        this->componets.push_back(scanComponet());

        this->componets[i].componetSelector = data[5 + 2 * i];
        this->componets[i].DCEntropyDest = data[6 + 2 * i] && 0x0F;
        this->componets[i].ACEntropyDest = data[6 + 2 * i] >> 4;
    }

    this->ss = data[7 + 2 * n];
    this->se = data[8 + 2 * n];
    this->ah = data[9 + 2 * n] && 0x0F;
    this->al = data[9 + 2 * n] >> 4; 

    printf("0x%X%X - SOS - Start of Scan\n", data[0], data[1]);
    printf("\tLength: %d bytes\n", this->length);
    printf("\tComponents: %d\n", this->n);

    for(int i = 0; i < this->componets.size(); i++) {
        printf("\t\tID DC AC: %d %d %d\n", this->componets[i].componetSelector, this->componets[i].DCEntropyDest, this->componets[i].ACEntropyDest);
    }

    printf("\tStart of Spectral: %d\n", this->ss);
    printf("\tEnd of Spectral: %d\n", this->se);
    printf("\tSuccessive approximation bit position high: %d\n", this->ah);
    printf("\tSuccessive approximation bit position low: %d\n", this->al);
}