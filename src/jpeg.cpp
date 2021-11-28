// jpeg.cpp

#include "../include/JPEG.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>

JPEG::JPEG(std::string filename) {

    std::ifstream fp(filename.c_str(), std::ios::binary);
    fp.unsetf(std::ios::skipws);

    if(!fp) {
        printf("Could not open file.\n");
        exit(1);
    }
    else {
        // byte count
        fp.seekg(0, std::ios::end);
        int length = fp.tellg();
        fp.seekg(0, std::ios::beg);

        printf("Image opened size of %d bytes\n", length);

        this->data = bytes(length);

        fp.read(reinterpret_cast<char*>(this->data.data()), length);
        this->data.resize(fp.gcount());

        this->parse();
     }
}

int JPEG::parse() {
    int length = 0;
    for(int i = 0; i < this->data.size(); i++) {

        if (this->data[i] == 0xFF) {

            length = (data[i + 2] << 8) + (data[i + 3]);

            switch(this->data[i + 1]) {
                
                case 0xD8:
                    printf("0xFFD8 - SOI - Start of Image\n");
                    break;
                case 0xE0:
                    // pass from header to end of application frame data
                    this->application = Application(bytes(data.begin() + i, data.begin() + i + length));
                    break;
                case 0xDB:
                    this->quantizationTables.push_back(QuantizationTable(bytes(data.begin() + i, data.begin() + i + length)));
                    break;
                case 0xC0:
                    this->startOfFrame = StartOfFrame(bytes(data.begin() + i, data.begin() + i + length));
                    break;
                case 0xC1:
                    printf("Start of Frame 1\n");
                    break;
                case 0xC2:
                    printf("Start of Frame 2\n");
                    break;
                case 0xC3:
                    printf("Start of Frame 3\n");
                    break;
                case 0xC4:
                    this->huffmanTables.push_back(HuffmanTable(bytes(data.begin() + i, data.begin() + i + length)));
            }
    }
    }
    return 0;
}