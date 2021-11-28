#include "../include/StartOfFrame.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>


StartOfFrame::StartOfFrame(bytes data) {

    this->length = (data[0] >> 8 + data[1]);

}