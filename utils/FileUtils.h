#pragma once

#include <string>
#include <filesystem>

namespace file_utils
{
	bool validDirectory(const std::string& path);
	bool createDirectory(const std::string& path, const std::string& name);
	__int64 countFiles(const std::string& path);
	bool exists(const std::string& path);
}