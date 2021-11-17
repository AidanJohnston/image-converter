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

    for(int i = 0; i < this->data.size(); i++) {

        

        if (this->data[i] == 0xFF) {
            
            i++;

            switch(this->data[i]) {
                
                case 0xD8:
                    printf("0xFFD8 - SOI - Start of Image\n");
                    break;
                case 0xE0:
                    printf("0xFFE0 - APP0\n");

                    /*  Application Data
                    *   
                    *   marker/length   2 bytes  0xFFE0 / length
                    * 
                    *   Identifier      5 bytes  ("JFIF\000" = 0x4a46494600)
                    *   MajorVersion    1 byte   major version (e.g. 0x01)
                    *   MinorVersion    1 byte   minor version (e.g. 0x01 or 0x02)
                    *   Units           1 byte   units (0: densities give aspect ratio
                    *                                   1: density values are dots per inch
                    *                                   2: density values are dots per cm)
                    *   Xdensity        2 bytes  horizontal pixel density
                    *   Ydensity        2 bytes  vertical pixel density
                    *   Xthumbnail      1 byte   thumbnail horizontal pixel count
                    *   Ythumbnail      1 byte   thumbnail vertical pixel count
                    *   ThumbnailData   3n bytes thumbnail image (n = Xthumbnail * Ythumbnail)
                    */

                    // length
                    i++;
                    printf("\tlength: %d\n", (this->data[i] << 8) + (this->data[i+1]));

                    // Identifier
                    i += 2;
                    printf("\tIdentifier: %c%c%c%c%c\n", this->data[i], this->data[i+1], this->data[i+2], this->data[i+3], this->data[i+4]);

                    // major / minor version
                    i += 5;
                    printf("\tVersion: %d.%d\n", this->data[i], this->data[i+1]);

                    // units
                    i += 2;
                    printf("\tUnits: %d\n", this->data[i]);

                    // xyDensity
                    i += 1;
                    printf("\tDensity: %dx%d\n", (this->data[i] << 8) + (this->data[i+1]), (this->data[i+2] << 8) + (this->data[i+3]));

                    // Thumbnail
                    i += 4;
                    printf("\tThumbnail: %dx%d\n", this->data[i], this->data[i+1]);

                    // skip the thumbnail
                    i += 3 * this->data[i] * this->data[i+1];

                    break;
                case 0xC0:
                    printf("Start of Frame 0\n");
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
                    printf("Define Huffman Table\n");
                    break;
            }
    }
    }
    return 0;
}