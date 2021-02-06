#include "FileUtils.h"
#include "Watermarker.h"

#include <iostream>
#include <string>
#include <chrono>

int main(int argc, const char** argv)
{
    auto start = std::chrono::high_resolution_clock::now();

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

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Finished in " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << "s\n";
}