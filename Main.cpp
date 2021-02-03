#include <iostream>
#include "FileSystem.h"
#include "Watermarker.h"

int main(int arc, const char** argv)
{
    // Get the given argument for the target directory
    std::string targetDirectory = argv[1];

    // Get the given argument for the watermark file
    std::string watermarkPath = argv[2];

    FileSystem fileSystem;

    // Check if the target directory is valid
    if (!fileSystem.checkDirectory(targetDirectory)) { return 1; }

    // Create an output directory where the new watermarked images will be stored
    fileSystem.createOutputDirectory(targetDirectory);

    Watermarker marker;

    // Mark all the images in the target directory with the watermarkPath image
    marker.mark(targetDirectory, watermarkPath);
}