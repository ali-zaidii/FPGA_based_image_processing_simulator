#include "blur_filter.h"
#include <cstring>

void BlurFilter::apply(const Buffer& in, Buffer& out) {
   
    memset(out.data, 0, out.width * out.height * sizeof(Pixel));
    
    for (int y = 1; y < in.height - 1; y++) {
        for (int x = 1; x < in.width - 1; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    Pixel p = in.data[(y + ky) * in.width + (x + kx)];
                    sum += p.r; 
                }
            }
            int avg = sum / 9;
            out.data[y * out.width + x] = { (uint8_t)avg, (uint8_t)avg, (uint8_t)avg };
        }
    }
} 
