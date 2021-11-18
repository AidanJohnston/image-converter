// jpeg.h
#ifndef __QuantizationTable_H_
#define __QuantizationTable_H_

#include "types.h"
#include <vector>

class QuantizationTable {

    private:

        int n;
        int destination;
        bytes table;

    public:

        QuantizationTable(bytes data);
        QuantizationTable() = default;

};

#endif