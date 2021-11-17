// jpeg.h
#ifndef __JPEG_H_
#define __JPEG_H_

#include "types.h"
#include "../include/Application.h"
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

class JPEG {

    private:

        // Vars
        bytes data;

        // App Info
        Application application;

        // Functions
        int parse();

    public:

        JPEG(std::string);

};
#endif