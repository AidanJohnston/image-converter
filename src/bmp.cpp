#include <stdio.h>

const int FHEADER_SIZE = 14;
const int IHEADER_SIZE = 40;
const int BYTES_PER_PIXEL = 3; /// red, green, & blue
const int height = 361;
const int width = 867;
unsigned char* createBMFHeader(int height, int stride);
unsigned char* createBMIHeader(int height, int width);


/*int main (){
    
    unsigned char image[height] [width] [BYTES_PER_PIXEL];
    char* imageFileName = (char*) "bitmapImage.bmp";

}*/


unsigned char* createBMFHeader (int height, int stride){
    int fileSize = FHEADER_SIZE + IHEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
        0,0,     // signature (always BM)
        0,0,0,0, // image file size
        0,0,0,0, // reserved
        0,0,0,0, // pixel array offset
    };

    fileHeader[0] = (unsigned char)('B');
    fileHeader[1] = (unsigned char)('M');
    fileHeader[2] = (unsigned char)(fileSize);
    fileHeader[3] = (unsigned char)(fileSize >> 8);
    fileHeader[4] = (unsigned char)(fileSize >> 16);
    fileHeader[5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FHEADER_SIZE + IHEADER_SIZE);

    return fileHeader;
}

unsigned char* createBMIHeader (int height, int width){
    static unsigned char infoHeader[] = {
        0,0,0,0, // size of the header
        0,0,0,0, // width
        0,0,0,0, // height
        0,0,     // number of color planes
        0,0,     // bits per pixel
        0,0,0,0, // compression
        0,0,0,0, // image size
        0,0,0,0, // horizontal resolution
        0,0,0,0, // vertical resolution
        0,0,0,0, // colour table colours
        0,0,0,0, // important colour count
    };

    infoHeader[0] = (unsigned char)(IHEADER_SIZE);
    infoHeader[4] = (unsigned char)(width);
    infoHeader[5] = (unsigned char)(width >> 8);
    infoHeader[6] = (unsigned char)(width >> 16);
    infoHeader[7] = (unsigned char)(width >> 24);
    infoHeader[8] = (unsigned char)(height);
    infoHeader[9] = (unsigned char)(height >> 8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}