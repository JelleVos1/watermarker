#include "Watermarker.h"
#include "FileUtils.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

namespace Watermarker
{
    bool validFile(const std::filesystem::path& path)
    {
        if (!std::filesystem::is_regular_file(path)) { return false; }

        // Get the file extension in lower case
        std::string fileExtension = path.extension().string();
        std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

        // Check if the file extension matches one of the valid ones
        return std::find(std::begin(imageExtensions), std::end(imageExtensions), fileExtension) != std::end(imageExtensions);
    }

    cv::Mat loadImage(const std::string& path)
    {
        if (!validFile(path))
        {
            if (!std::filesystem::is_directory(path))
            {
                std::cerr << path << " is invalid\n";
            }

            return cv::Mat{};
        }

        cv::Mat image = cv::imread(path, cv::IMREAD_UNCHANGED);
        if (!image.data)
        {
            std::cerr << "Not enough permissions to read file " << path << "\n";
            return cv::Mat{};
        }

        return image;
    }

    void saveImage(const std::string& path, cv::Mat& image)
    {
        if (!cv::imwrite(std::filesystem::path(path).make_preferred().string(), image))
        {
            std::cerr << "Could not save " << path << "\n";
        }
    }

    void mark(const std::string& targetDirectory, const std::filesystem::path& imagePath, cv::Mat& watermark)
    {
        cv::Mat image = loadImage(imagePath.string());

        if (!image.data) { return; }

        cv::resize(watermark, watermark, image.size());

        // Give the images 4 channels
        cv::cvtColor(image, image, cv::COLOR_RGB2RGBA);
        cv::cvtColor(watermark, watermark, cv::COLOR_RGB2RGBA);

        // Add the watermark to the original image
        cv::addWeighted(watermark, 0.3, image, 1, 0.0, image);

        saveImage(targetDirectory + "/watermarked_images/" + imagePath.filename().string(), image);
    }

    void markDirectory(const std::string& targetDirectory, const std::string& watermarkPath)
    {
        cv::Mat watermark = loadImage(watermarkPath);
        
        if (!watermark.data) { return; }

        // Loop through all the files in the target directory
        float count = 0;
        for (const std::filesystem::path& path : std::filesystem::directory_iterator(targetDirectory))
        {
            mark(targetDirectory, path, watermark);
            count++;
            std::cout << "\rMarking files progress: " << int(float(count / file_utils::countFiles(targetDirectory) * 100)) << '%';
        }

        // Clear the console
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}