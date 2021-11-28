#ifndef __JPEG_H_
#define __JPEG_H_

#include "types.h"

class HuffmanTable {

    private:
        int length;
        int tableClass;
        int destinationID;
        int huffCount;

    public:
        HuffmanTable(bytes data);
};

#endif