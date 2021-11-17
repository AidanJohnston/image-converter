// jpeg.cpp

#include "../include/jpeg.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>

JPEG::JPEG(std::string filename) {

    std::ifstream fp(filename.c_str(), std::ios::binary);

    if(!fp) {
        printf("Could not open file.\n");
        exit(1);
    }
    else {
        printf("Image opened.\n");

        // byte count
        int length = fp.tellg();

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
                    printf("0xFFE0 - APP0");
                    //parse_APP();
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

//int JPEG::parse_APP() {

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

    // Read next
    
    //long length = bytesToLong(readBytes(2));
//}

/*
bytes JPEG::readBytes(int count) {
    bytes byteArr;

    for (int i = 0; i < count; i++) {
        byteArr.append(readByte());
    }
    return byteArr;
}

u8 JPEG::readByte() {
    return fgetc(fp);
}

int JPEG::bytesToInt(bytes byteArr) {
    u8 * p;
    return std::stoul(byteArrs.c_str(), &p, 16);
}
*/