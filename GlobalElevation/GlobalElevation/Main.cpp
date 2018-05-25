#include "ReadTifFile.h"
#include "ReadTifFileGDAL.h"

#include <iostream>


int main()
{
	ReadTifFile readTifFile;
	//readTifFile.importFile("Resources\\KanadaHueglig.tif");

	//readTifFile.importFile("Resources\\AfrikaTeilsWasser1.tif");
	//readTifFile.importFile("Resources\\AfrikaTeilsWasser2.tif");

	//readTifFile.importFile("Resources\\Australien1.tif");
	//readTifFile.importFile("Resources\\Australien2.tif");

	readTifFile.importFile("Resources\\GebietUmHeidelberg1.tif");
	//readTifFile.importFile("Resources\\GebietUmHeidelberg2.tif");
	//readTifFile.importFile("Resources\\GebietUmHeidelberg3.tif");
	//readTifFile.importFile("Resources\\GebietUmHeidelberg4.tif");

	//ReadTifFileGDAL readTifFileGDAL;
	//readTifFileGDAL.importFile("Resources\\KanadaHueglig.tif");

	getchar();
	return 0;
}

// Auflösung in Z-Richtung (Tiefe)
// Orientierung im Bild (Ausschnittvergleich mit Google-Maps