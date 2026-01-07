#ifndef FILTER_H
#define FILTER_H

#include "buffer.h"

class Filter {
public:
    virtual void apply(const Buffer& in, Buffer& out) = 0;
    virtual ~Filter() {}
};

#endif

