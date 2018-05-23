#include "ReadTifFile.h"


ReadTifFile::ReadTifFile()
{
}

ReadTifFile::~ReadTifFile()
{
}


void ReadTifFile::importFile(const char* path)
{
	TIFF* tif = TIFFOpen(path, "r");

	uint32  width;
	uint32  height;

	if(tif)
	{
		int dircount = 0;
		do
		{
			dircount++;
		} while(TIFFReadDirectory(tif));

		TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
		TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);

		std::cout << path << " Width: " << width << " Heigth: " << height << std::endl;

		uint32  pixels = width * height;
		uint32* raster = (uint32 *) _TIFFmalloc(pixels * sizeof(uint32));

		if(TIFFReadRGBAImage(tif, width, height, raster, 0) == 0)
		{
			std::cout << "Can not create raster";
		}

		for(int i = 0; i < 100; i++)
		{
			std::cout << (raster[i]) << std::endl;
		}

		for(int i = 100000; i < 101000; i++)
		{
			std::cout << (raster[i]) << std::endl;
		}

		_TIFFfree(raster);

		TIFFClose(tif);
	} else
	{
		std::cout << "Can not load File";
	}
}
