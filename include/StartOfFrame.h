#ifndef __STARTOFFRAME_H_
#define __STARTPFFRAME_H_

#include "types.h"

struct componet{
    int id;
    int hSample;
    int vSample;
    int quantizationDest;
};

class StartOfFrame {


    private:
        int length;
        int precision;
        int Y;
        int X;
        int numComponent;
        std::vector<componet> componets;

    public:
        StartOfFrame(bytes data);
        StartOfFrame() = default;


};


#endif
