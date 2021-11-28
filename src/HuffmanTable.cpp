#include "../include/HuffmanTable.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>

HuffmanTable::HuffmanTable(bytes data) {

    this->length = (data[2] << 8) + (data[3]);

    // only get first 4 least signigicant bits
    this->tableClass = data[4] && 0x0F;

    // shift right 4 to get only the first 4 most siginifcant bits
    this->destinationID = data[4] >> 4; 

    int elements = 0;
    // 16 bytes of lengths
    for(int i = 5; i < 21; i++) {
        elements += data[i];
        this->lengths.push_back(data[i]);
    }

    printf("0x%X%X - DHT - Huffman Table\n", data[0], data[1]);
    printf("\tLength: %d bytes\n", this->length);
    printf("\tTable Class: %d ", this->tableClass);

    if(this->tableClass)
        printf("(AC)\n");
    else
        printf("(DC)\n");

    printf("\tDestination: %d\n", this->destinationID);

    printf("\tLengths: (");
    for(int i = 0; i < this->lengths.size(); i++) {
        printf("%d", this->lengths[i]);

        if(i != lengths.size() - 1)
            printf(", ");
    }
    printf(")\n");

    printf("\tElements: %d\n", elements);
}