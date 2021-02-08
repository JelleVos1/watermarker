#pragma once

#include <filesystem>
#include <string_view>
#include <string>

namespace watermarker
{
	constexpr std::string_view imageExtensions[]{
		".png",
		".jpg",
		".tiff",
		".jpeg"
	};

	void markDirectory(const std::string& targetDirectory, const std::string& watermarkPath);
}