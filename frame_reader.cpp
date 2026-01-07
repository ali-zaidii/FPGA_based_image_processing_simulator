#include "frame_reader.h"
#include <fstream>
#include <string>
#include <iostream>

Buffer FrameReader::readPPM(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << std::endl;
        return { nullptr, 0, 0 };
    }
    
    std::string magic;
    int w, h, max;
    
    file >> magic;  
    
    
    while (file.peek() == '#') {
        std::string comment;
        std::getline(file, comment);
    }
    
    file >> w >> h >> max;
    
    
    file.get();
    
    Pixel* data = new Pixel[w * h];
    
    if (magic == "P6") {
        
        for (int i = 0; i < w * h; i++) {
            data[i].r = file.get();
            data[i].g = file.get();
            data[i].b = file.get();
        }
    } else if (magic == "P3") {
        
        for (int i = 0; i < w * h; i++) {
            int r, g, b;
            file >> r >> g >> b;
            data[i].r = (uint8_t)r;
            data[i].g = (uint8_t)g;
            data[i].b = (uint8_t)b;
        }
    } else {
        std::cerr << "Error: Unsupported PPM format: " << magic << std::endl;
        delete[] data;
        return { nullptr, 0, 0 };
    }
    
    file.close();
    
    std::cout << "Read " << magic << " image: " << w << "x" << h << std::endl;
    
    return { data, w, h };
}
