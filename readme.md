## Watermarker
Watermark program to watermark entire folders of images at once. This project is still under development and will be updated with more features.

### Building
To build Watermarker you can use CMake.

    mkdir build
    cd build
    cmake .. -D OpenCV_DIR=path_to_opencv_dir
    cmake --build .

### Using Watermarker
To run the program you can run the following command:

    watermarker.exe <directory with images> <watermark image>
