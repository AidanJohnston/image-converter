// Application.cpp

#include <../include/Application.h>

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

    this->identifier = bytes(data.begin() + 2, data.begin() + 6);
    this->majorVersion = data[7];
    this->minorVersion = data[8];
    this->units = data[9];
    this->Xdensity = (data[10] << 8) + (data[11]);
    this->Ydensity = (data[12] << 8) + (data[13]);
    this->Xthumbnail = data[14];
    this->Ythumbnail = data[15];

    // Check if there is thumbnail data
    if (this->Xthumbnail + this->Ythumbnail == 0) {
        this->ThumbnailData = bytes();
    }
    else {
        this->ThumbnailData = bytes(data.begin() + 16, data.end());
    }
}