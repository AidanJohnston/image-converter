// jpeg.h
#ifndef __JPEG_H_
#define __JPEG_H_

#include "types.h"
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

class JPEG {

    private:

        // Vars
        bytes data;

        // Functions
        int parse();
        int parse_APP();
        int parse_DQT();
        int parse_SOF();
        int parse_DHT();
        int prase_SOS();

        bytes readBytes(int count);
        u8 readByte();
        int bytesToInt(bytes byteArr);


    public:

        JPEG(std::string);

};
#endif