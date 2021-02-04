#include "FileUtils.h"
#include "Watermarker.h"

#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, const char** argv)
{
    if (argc != 3)
    {
        std::cout << "Too " << ((argc < 3) ? "little" : "many") << " arguments given." << "\n";
        return 1;
    }

    std::string targetDirectory = argv[1];
    std::string watermarkImagePath = argv[2];

    // Create an output directory where the new watermarked images will be stored
    if (!file_utils::createDirectory(targetDirectory, "watermarked_images"))
    {
        return 1;
    }

    // Watermark all the images in the target directory
    Watermarker::mark(targetDirectory, watermarkImagePath);
}