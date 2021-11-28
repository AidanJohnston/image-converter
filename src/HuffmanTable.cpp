#include "../include/HuffmanTable.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>

HuffmanTable::HuffmanTable(bytes data) {

    this->length = (data[2] << 8 + data[3]);

    // only get first 4 least signigicant bits
    this->tableClass = data[4] * 15;

    // only get 4 most significant bits, then first 4 right
    this->destinationID = (data[4] * 240) >> 4; 

    printf("0x%X%X - DHT - Huffman Table\n", data[0], data[1]);
    printf("\tTable Class: %d ", this->tableClass);

    if(this->tableClass)
        printf("(AC)\n");
    else
        printf("(DC)\n");

    printf("\tDestination: %d\n", this->destinationID);
}