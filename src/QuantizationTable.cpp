// QuantizationTable.cpp

#include "../include/QuantizationTable.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>


QuantizationTable::QuantizationTable(bytes data) {

    /*  Quantization Table Data
     *  marker   2 bytes   FFDB
     *  length   2 bytes   16?
     * 
     *  destination     1 byte    (0: luminance, 1: chrominance)
     *  table           n^2 bytes (noramlly 8x8, n = length - 3)
     */

    int length = (data[2] << 8) + (data[3]);
    this->n = (int)sqrt(length - 3);

    this->destination = data[4];
    this->table = bytes(data.begin() + 5, data.end());

    printf("0x%X%X - DQT - Quantization Table\n", data[0], data[1]);
    printf("\tLength: %d bytes\n", length);
    printf("\tDestination %d ", this->destination);
    if (this->destination) 
        printf("(chrominance)\n");
    else 
        printf("(luminance)\n");

    printf("\tTable %dx%d\n", this->n, this->n);
    
    /* Print the table
    for(int i = 0; i < n; i++) {
        printf("\t");
        for(int j = 0; j < n; j++) {
            printf("%d\t", this->table[i*n + j]);
        }
        printf("\n");
    }
    */
}