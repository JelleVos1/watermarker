#include "Watermarker.h"

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

bool Watermarker::validFile(const std::filesystem::path& filePath)
{
    if (!std::filesystem::is_regular_file(filePath)) { return false; }

    // Get the file extension in lower case
    std::string fileExtension = filePath.extension().string();
    std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

    // Check if the file extension matches one of the valid ones
    return std::find(std::begin(imageExtensions), std::end(imageExtensions), fileExtension) != std::end(imageExtensions);
}

void Watermarker::mark(const std::string& targetDirectory, const std::string& watermarkPath)
{
    cv::Mat watermarkImage = cv::imread(watermarkPath, cv::IMREAD_UNCHANGED);

    // Loop through all the files in the target directory
    for (const std::filesystem::path& path : std::filesystem::directory_iterator(targetDirectory))
    {        
        if (!validFile(path)) { continue; }

        cv::Mat image = cv::imread(path.string());

        // Make the watermark image the same size as the original image
        cv::resize(watermarkImage, watermarkImage, image.size(), 0, 0, cv::InterpolationFlags::INTER_LINEAR);

        // Give the images 4 channels
        cv::cvtColor(image, image, cv::COLOR_RGB2RGBA);
        cv::cvtColor(watermarkImage, watermarkImage, cv::COLOR_RGB2RGBA);

        // Add the watermark to the original image
        cv::addWeighted(watermarkImage, 0.3, image, 1, 0.0, image);

        // Save the new image to the new folder
        cv::imwrite(
            std::filesystem::path(targetDirectory + "/watermarked_images/" + path.filename().string()).make_preferred().string(),
            image
        );
    }
}