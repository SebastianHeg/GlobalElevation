//#include "ReadTifFileGDAL.h"
//
//
//ReadTifFileGDAL::ReadTifFileGDAL()
//{
//}
//
//ReadTifFileGDAL::~ReadTifFileGDAL()
//{
//}
//
//
//void ReadTifFileGDAL::importFile(const char* path)
//{
//	GDALDataset* dataset;
//	GDALAllRegister();
//
//	dataset = (GDALDataset*) GDALOpen(path, GA_ReadOnly);
//	if(dataset != NULL)
//	{
//		//GUIntBig *panHistogram;
//		//memset(panHistogram, 0, sizeof(GUIntBig) * 256);
//
//		int nXBlocks = (dataset->GetRasterXSize());
//		int nYBlocks = (dataset->GetRasterYSize());
//		GByte *data = (GByte *) CPLMalloc(nXBlocks * nYBlocks);
//
//		GDALRasterBand* rb = dataset->GetRasterBand(1);
//		rb->ReadBlock(0, 0, data);
//
//
//
//	} else
//	{
//		printf("Can not open file, dataset is empty");
//	}
//
//}
