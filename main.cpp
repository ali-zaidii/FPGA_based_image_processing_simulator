#include "frame_reader.h"
#include "color_converter.h"
#include "blur_filter.h"
#include "sobel_filter.h"
#include "output_writer.h"

int main() {

    Buffer input = FrameReader::readPPM("input.ppm");
    Buffer gray  = ColorConverter::rgbToGray(input);

    Buffer blur  = { new Pixel[gray.width * gray.height], gray.width, gray.height };
    Buffer edge  = { new Pixel[gray.width * gray.height], gray.width, gray.height };

    Filter* f1 = new BlurFilter();
    Filter* f2 = new SobelFilter();

    f1->apply(gray, blur);
    f2->apply(blur, edge);
    OutputWriter::writePPM("gray_output.ppm", gray);
    OutputWriter::writePPM("blur_output.ppm", blur);
    OutputWriter::writePPM("output.ppm", edge);

    delete[] input.data;
    delete[] gray.data;
    delete[] blur.data;
    delete[] edge.data;
    delete f1;
    delete f2;

    return 0;
}

