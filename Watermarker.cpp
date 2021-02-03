#include "Watermarker.h"
#include <boost/filesystem.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void Watermarker::mark(std::string targetDirectory, std::string watermarkPath)
{
    boost::filesystem::path path;

    // Loop through all the files in the target directory
    for (auto& entry : boost::filesystem::directory_iterator(targetDirectory))
    {
        // If the file is a regular file
        if (boost::filesystem::is_regular_file(entry.path()))
        {
            // Set the boost filesystem path to the path of the file
            path = entry.path();

            // Get the original image
            cv::Mat image = cv::imread(path.string());

            // Get the watermark image
            cv::Mat watermarkImage = cv::imread(watermarkPath, cv::IMREAD_UNCHANGED);

            // Make the watermark image the same size as the original image
            cv::resize(watermarkImage, watermarkImage, image.size(), 0, 0, cv::InterpolationFlags::INTER_LINEAR);

            // Give the images 4 channels
            cv::cvtColor(image, image, cv::COLOR_RGB2RGBA);
            cv::cvtColor(watermarkImage, watermarkImage, cv::COLOR_RGB2RGBA);

            cv::Mat newImage;

            try
            {
                cv::addWeighted(watermarkImage, 0.3, image, 1, 0.0, newImage);
            }
            catch (cv::Exception & e)
            {
                std::cout << e.what() << "\n";
            }

            // Save the new file to the new watermarked_images folder
            cv::imwrite(std::string(targetDirectory + "\\watermarked_images\\" + path.filename().string()).c_str(), newImage);
        }
    }
}