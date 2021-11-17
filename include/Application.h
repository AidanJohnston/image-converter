// Application.h
#ifndef __APPLICATION_H_
#define __APPLICATION_H_
#include "types.h"

class Application {

    private:

        bytes identifier;
        int majorVersion;
        int minorVersion;
        int units;
        int Xdensity;
        int Ydensity;
        int Xthumbnail;
        int Ythumbnail;
        bytes ThumbnailData;

    public:

        Application(bytes data);
        Application() = default;

};

#endif