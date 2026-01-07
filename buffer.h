#ifndef BUFFER_H
#define BUFFER_H

#include "pixel.h"

struct Buffer {
    Pixel* data;
    int width;
    int height;
};

#endif

