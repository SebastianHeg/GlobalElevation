#include "ReadTiffFile.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
	ReadTiffFile readTifFile;
	readTifFile.readFile("Test.tif");

	getchar();
	return 0;
}
