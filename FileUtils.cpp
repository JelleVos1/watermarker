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
                std::cout << "The given path is not a directory.\n";
                return false;
            }
        }
        else
        {
            std::cout << path << " does not exist\n";
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
}