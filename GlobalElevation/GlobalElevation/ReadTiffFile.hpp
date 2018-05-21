#pragma once
#include <string>
#include <iostream>

#include "Libraries/LibTiff/include/tiffio.h"


class ReadTiffFile
{
public:
	ReadTiffFile();
	~ReadTiffFile();

	void readFile(const char* path);
};

