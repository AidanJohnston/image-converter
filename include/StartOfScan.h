#ifndef __STARTOFSCAN_H_
#define __STARTOFSCAN_H_

#include "types.h"

struct scanComponet {
    int componetSelector;
    int DCEntropyDest;
    int ACEntropyDest;
};

class StartOfScan {

    private:
        int length;
        int n;
        std::vector<scanComponet> componets;
        int ss;
        int se;
        int ah;
        int al;

    public:
        StartOfScan(bytes data);
        StartOfScan() = default; 

};

#endif