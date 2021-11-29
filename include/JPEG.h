// jpeg.h
#ifndef __JPEG_H_
#define __JPEG_H_

#include "types.h"
#include "Application.h"
#include "QuantizationTable.h"
#include "StartOfFrame.h"
#include "HuffmanTable.h"
#include "StartOfScan.h"
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
        std::vector<QuantizationTable> quantizationTables;
        StartOfFrame startOfFrame;
        std::vector<HuffmanTable> huffmanTables;
        StartOfScan startOfScan;
        bytes ecs;


        // Functions
        int parse();
        bytes removeFF00(bytes data);

    public:

        JPEG(std::string);
        JPEG() = default;

};
#endif