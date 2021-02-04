#include "FileUtils.h"

#include <iostream>
#include <filesystem>

namespace file_utils
{
    bool file_utils::createDirectory(const std::string& path, const std::string& name)
    {
        if (!validDirectory(path)) { return false; }

        std::filesystem::create_directory(std::filesystem::path(path + "/" + name).make_preferred());

        return true;
    }

    bool file_utils::validDirectory(const std::string& directory)
    {
        if (std::filesystem::exists(directory))
        {
            if (!std::filesystem::is_directory(directory))
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
}