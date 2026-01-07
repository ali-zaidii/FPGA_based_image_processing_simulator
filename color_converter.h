#ifndef COLOR_CONVERTER_H
#define COLOR_CONVERTER_H

#include "buffer.h"

class ColorConverter {
public:
    static Buffer rgbToGray(const Buffer& in);
};

#endif

