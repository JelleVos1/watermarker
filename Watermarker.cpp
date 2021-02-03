#include <iostream>
#include <stdlib.h>
#include <boost/filesystem.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "FileSystem.h"

int main(int arc, const char** argv)
{
    // Get the given argument for the target directory
    std::string targetDirectory = argv[1];

    FileSystem fileSystem;

    // Check if the target directory is valid
    if (!fileSystem.checkDirectory(targetDirectory)) { return 1; }

    // Create an output directory where the new watermarked images will be stored
    fileSystem.createOutputDirectory(targetDirectory);
}