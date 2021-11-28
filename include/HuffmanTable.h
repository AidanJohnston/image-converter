#ifndef __HUFFMANTABLE_H_
#define __HUFFMANTABLE_H_

#include "types.h"
#include "vector"

class HuffmanTable {

    private:
        int length;
        int tableClass;
        int destinationID;
        int huffCount;
        std::vector<int> lengths;

    public:
        HuffmanTable(bytes data);
        HuffmanTable() = default;
};

#endif