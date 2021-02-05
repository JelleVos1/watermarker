#ifndef WATERMARKER_H
#define WATERMARKER_H

#include <filesystem>
#include <string_view>
#include <string>

namespace Watermarker
{
	constexpr std::string_view imageExtensions[]{
		".png",
		".jpg",
		".tiff",
		".jpeg"
	};

	void mark(const std::string& targetDirectory, const std::filesystem::path& imagePath, const std::string& watermarkPath);
	void markDirectory(const std::string& targetDirectory, const std::string& watermarkPath);
}

#endif