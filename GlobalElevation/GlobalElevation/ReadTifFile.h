#pragma once
#include "Libraries/LibTiff/include/tiffio.h"

#include <iostream>


class ReadTifFile
{
public:
	ReadTifFile();
	~ReadTifFile();

	void importFile(const char* path);
};

