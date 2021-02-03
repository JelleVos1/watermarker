#pragma once

#include <iostream>

class FileSystem
{
public:
	void createOutputDirectory(std::string& targetDirectory);
	bool checkDirectory(std::string& targetDirectory);
};

