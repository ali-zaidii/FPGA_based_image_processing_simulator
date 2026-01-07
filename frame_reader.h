#ifndef FRAME_READER_H
#define FRAME_READER_H

#include "buffer.h"

class FrameReader {
public:
    static Buffer readPPM(const char* filename);
};

#endif

