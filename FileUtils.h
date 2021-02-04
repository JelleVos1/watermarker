#pragma once

#include <string>

namespace file_utils
{
	bool createDirectory(const std::string& path, const std::string& name);
	bool validDirectory(const std::string& directory);
}