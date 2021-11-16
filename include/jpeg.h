// jpeg.h
#ifndef __JPEG_H_
#define __JPEG_H_

#include <string>
#include <vector>
#include <map>
#include <stdio.h>

class JPEG {

    private:

        FILE* fp;

        int parseSeg();


    public:

        JPEG(std::string);

};
#endif