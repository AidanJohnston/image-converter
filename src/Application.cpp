// Application.cpp

#include "../include/Application.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>


Application::Application(bytes data) {

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

    this->identifier = bytes(data.begin() + 4, data.begin() + 8);
    this->majorVersion = data[9];
    this->minorVersion = data[10];
    this->units = data[11];
    this->Xdensity = (data[12] << 8) + (data[13]);
    this->Ydensity = (data[14] << 8) + (data[15]);
    this->Xthumbnail = data[16];
    this->Ythumbnail = data[17];

    // Check if there is thumbnail data
    if (this->Xthumbnail + this->Ythumbnail == 0) {
        this->ThumbnailData = bytes();
    }
    else {
        this->ThumbnailData = bytes(data.begin() + 18, data.end());
    }
    
    printf("\tIdentifier: %c%c%c%c%c\n", this->identifier[0], this->identifier[1], this->identifier[2], this->identifier[3], this->identifier[4]);
    printf("\tVersion: %d.%d\n", this->majorVersion, this->minorVersion);
    printf("\tUnit: %d\n", this->units);
    printf("\tDensity %dx%d\n", this->Xdensity, this->Ydensity);
    printf("\tThumbnail %dx%d\n", this->Xthumbnail,  this->Ythumbnail);
}