#ifndef __STARTOFFRAME_H_
#define __STARTPFFRAME_H_

#include "types.h"

class StartOfFrame {


    private:
        int length;
        int precision;
        int lineNumber;
        int samples;
        int components;


    public:
        StartOfFrame(bytes data);
        StartOfFrame() = default;


};


#endif
