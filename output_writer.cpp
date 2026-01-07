#include "output_writer.h"
#include <fstream>

void OutputWriter::writePPM(const char* filename, const Buffer& buf) {
   
    std::ofstream file(filename, std::ios::binary);
    
    file << "P6\n";
    file << buf.width << " " << buf.height << "\n";
    file << "255\n";
    
    for (int i = 0; i < buf.width * buf.height; i++) {
        file.put(buf.data[i].r);
        file.put(buf.data[i].g);
        file.put(buf.data[i].b);
    }
    
    file.close();
}
