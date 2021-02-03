#include "FileSystem.h"
#include <boost/filesystem.hpp>

void FileSystem::createOutputDirectory(std::string& targetDirectory)
{
	std::string command = "mkdir \"" + targetDirectory + "\\watermarked_images\"";

	system(command.c_str());
}

bool FileSystem::checkDirectory(std::string& targetDirectory)
{
    try
    {
        if (boost::filesystem::exists(targetDirectory))
        {
            if (!boost::filesystem::is_directory(targetDirectory))
            {
                std::cout << "The given path is invalid.\n";
                return false;
            }
        }
        else
        {
            std::cout << targetDirectory << " does not exist\n";
            return false;
        }
    }
    catch (const boost::filesystem::filesystem_error & ex)
    {
        std::cout << ex.what() << '\n';
        return false;
    }

    return true;
}
