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

        FILE* fp;

        int parseSeg();
        u16 readWord();


    public:

        JPEG(std::string);

};
#endif