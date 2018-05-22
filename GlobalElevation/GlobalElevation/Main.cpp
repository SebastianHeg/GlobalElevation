#include "ReadTifFile.h"

#include <iostream>


int main()
{
	ReadTifFile readTifFile;
	readTifFile.importFile("Test.tif");

	getchar();
	return 0;
}