#include "FileUtils.h"
#include "Watermarker.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Too " << ((argc < 3) ? "little" : "many") << " arguments given." << "\n";
        return 1;
    }

    std::string targetDirectory = argv[1];
    std::string watermarkPath = argv[2];

    if (!file_utils::createDirectory(targetDirectory, "watermarked_images"))
    {
        return 1;
    }

    Watermarker::markDirectory(targetDirectory, watermarkPath);
}