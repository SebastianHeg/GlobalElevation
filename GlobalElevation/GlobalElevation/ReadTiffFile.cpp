#include "ReadTiffFile.hpp"


ReadTiffFile::ReadTiffFile()
{
}

ReadTiffFile::~ReadTiffFile()
{
}

void ReadTiffFile::readFile(const char* path)
{
	TIFF* tif = TIFFOpen(path, "r");

	TIFFClose(tif);
}
