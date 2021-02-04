#pragma once

#include <string>
#include <filesystem>
#include <string_view>

constexpr std::string_view imageExtensions[] {
	".png",
	".jpg",
	".tiff",
	".jpeg"
};

class Watermarker
{
private:
	static bool validFile(const std::filesystem::path& filePath);

public:
	static void mark(const std::string& targetDirectory, const std::string& watermarkPath);
};