#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

namespace file_utils
{
	bool validDirectory(const std::string& path);
	bool createDirectory(const std::string& path, const std::string& name);
}

#endif