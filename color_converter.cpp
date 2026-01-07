#include "color_converter.h"

Buffer ColorConverter::rgbToGray(const Buffer& in) {
    Pixel* gray = new Pixel[in.width * in.height];

    for (int i = 0; i < in.width * in.height; i++) {
        uint8_t g = (in.data[i].r + in.data[i].g + in.data[i].b) / 3;
        gray[i] = { g, g, g };
    }

    return { gray, in.width, in.height };
}

