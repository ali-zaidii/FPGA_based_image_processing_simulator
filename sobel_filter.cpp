#include "sobel_filter.h"
#include <cmath>
#include <cstring>

void SobelFilter::apply(const Buffer& in, Buffer& out) {
    // Initialize output buffer
    memset(out.data, 0, out.width * out.height * sizeof(Pixel));
    
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };
    
    for (int y = 1; y < in.height - 1; y++) {
        for (int x = 1; x < in.width - 1; x++) {
            int sumX = 0, sumY = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = in.data[(y + ky) * in.width + (x + kx)].r;
                    sumX += pixel * gx[ky + 1][kx + 1];
                    sumY += pixel * gy[ky + 1][kx + 1];
                }
            }
            int mag = std::min(255, (int)std::sqrt(sumX * sumX + sumY * sumY));
            out.data[y * out.width + x] = { (uint8_t)mag, (uint8_t)mag, (uint8_t)mag };
        }
    }
}

