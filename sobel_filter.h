#ifndef SOBEL_FILTER_H
#define SOBEL_FILTER_H

#include "filter.h"

class SobelFilter : public Filter {
public:
    void apply(const Buffer& in, Buffer& out) override;
};

#endif

