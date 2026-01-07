#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include "filter.h"

class BlurFilter : public Filter {
public:
    void apply(const Buffer& in, Buffer& out) override;
};

#endif

