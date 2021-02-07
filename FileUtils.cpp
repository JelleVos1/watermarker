#include "FileUtils.h"

#include <iostream>
#include <filesystem>

namespace file_utils
{
    bool validDirectory(const std::string& path)
    {
        if (std::filesystem::exists(path))
        {
            if (!std::filesystem::is_directory(path))
            {
                std::cerr << "The given path is not a directory.\n";
                return false;
            }
        }
        else
        {
            std::cerr << path << " does not exist\n";
            return false;
        }

        return true;
    }

    bool createDirectory(const std::string& path, const std::string& name)
    {
        if (!validDirectory(path)) { return false; }

        std::filesystem::create_directory(std::filesystem::path(path + "/" + name).make_preferred());

        return true;
    }

    int countFiles(const std::string& path)
    {
        return std::distance(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator{});;
    }
}