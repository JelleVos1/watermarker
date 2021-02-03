#pragma once

#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class FileSystem
{
private:
	std::vector<std::string> validExtensions = {
		".png",
		".jpg",
		".tiff",
		".jpeg"
	};

public:
	void createDirectory(std::string& directory);
	bool checkDirectory(std::string& directory);
	bool checkFile(boost::filesystem::path& filePath);
};

