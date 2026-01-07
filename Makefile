CXX = g++
CXXFLAGS = -Wall -Iinclude

SRC = src/main.cpp src/frame_reader.cpp src/color_converter.cpp \
      src/blur_filter.cpp src/sobel_filter.cpp src/output_writer.cpp

TARGET = pipeline

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

