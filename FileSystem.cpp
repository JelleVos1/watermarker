#include "FileSystem.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

void FileSystem::createDirectory(std::string& directory)
{
    boost::filesystem::create_directory(directory);
}

bool FileSystem::checkDirectory(std::string& directory)
{
    if (boost::filesystem::exists(directory))
    {
        if (!boost::filesystem::is_directory(directory))
        {
            std::cout << "The given path is not a directory.\n";
            return false;
        }
    }
    else
    {
        std::cout << directory << " does not exist\n";
        return false;
    }

    return true;
}

bool FileSystem::checkFile(boost::filesystem::path& filePath)
{
    // Check if the file is a regular file
    if (!boost::filesystem::is_regular_file(filePath)) { return false; }

    // Get the file extension in lower case
    std::string fileExtension = filePath.extension().string();
    boost::to_lower(fileExtension);

    // Check if the file extension matches one of the valid ones
    if (std::find(validExtensions.begin(), validExtensions.end(), fileExtension) != validExtensions.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}