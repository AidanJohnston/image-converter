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
                case 0xC2:
                    this->startOfFrame = StartOfFrame(bytes(data.begin() + i, data.begin() + i + length));
                    break;
                case 0xC4:
                    this->huffmanTables.push_back(HuffmanTable(bytes(data.begin() + i, data.begin() + i + length)));
                    break;
                case 0xDA:
                    this->startOfScan = StartOfScan(bytes(data.begin() + i, data.begin() + i + length));
                    this->ecs = this->removeFF00(bytes(data.begin() + i + length, data.end() - 2));
                    break;
                case 0xD0:
                case 0xD1:
                case 0xD2:
                case 0xD3:
                case 0xD4:
                case 0xD5:
                case 0xD6:
                case 0xD7:
                    printf("0x%X%X - Restart\n", data[i], data[i + 1]);
                    break;
                case 0xD9:
                    printf("0xFFD9 - EOI - End of Image\n");
                    break;
            }
        }
    }
    printf("image Data length: %d\n", (int)this->ecs.size());
    return 0;
}

bytes JPEG::removeFF00(bytes data) {
    bytes temp;

    for (int i = 0; i < data.size(); i++) {
        temp.push_back(data[i]);

        // skip 00 after a FF
        if(data[i] == 0xFF && data[i + 1])
            i++;
    }
    return temp;
}