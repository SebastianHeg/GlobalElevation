#include "ReadTifFileGDAL.h"


ReadTifFileGDAL::ReadTifFileGDAL()
{
}

ReadTifFileGDAL::~ReadTifFileGDAL()
{
}


void ReadTifFileGDAL::importFile(const char* path)
{
	GDALDataset* dataset;
	GDALAllRegister();

	dataset = (GDALDataset*) GDALOpen(path, GA_ReadOnly);
	if(dataset != NULL)
	{
		//GUIntBig *panHistogram;
		//memset(panHistogram, 0, sizeof(GUIntBig) * 256);

		int nXBlocks = (dataset->GetRasterXSize());
		int nYBlocks = (dataset->GetRasterYSize());
		//GByte *data = (GByte *) CPLMalloc(nXBlocks * nYBlocks);

		//GDALRasterBand* rb = dataset->GetRasterBand(1);
		//rb->ReadBlock(0, 0, data);

		double        adfGeoTransform[6];
		std::cout << "XRasterSize: " << nXBlocks << " YRasterSize: " << nYBlocks << std::endl;

		if(dataset->GetProjectionRef() != NULL)
			printf("Projection is `%s'\n", dataset->GetProjectionRef());

		if(dataset->GetGeoTransform(adfGeoTransform) == CE_None)
		{
			printf("Origin = (%.6f,%.6f)\n",
				   adfGeoTransform[0], adfGeoTransform[3]);

			printf("Pixel Size = (%.6f,%.6f)\n",
				   adfGeoTransform[1], adfGeoTransform[5]);
		}

		GDALRasterBand  *rBand;
		int             nBlockXSize, nBlockYSize;
		int             bGotMin, bGotMax;
		double          adfMinMax[2];

		rBand = dataset->GetRasterBand(1);
		rBand->GetBlockSize(&nBlockXSize, &nBlockYSize);

		printf("Block=%dx%d Type=%s, ColorInterp=%s\n",
			   nBlockXSize, nBlockYSize,
			   GDALGetDataTypeName(rBand->GetRasterDataType()),
			   GDALGetColorInterpretationName(
			   rBand->GetColorInterpretation()));

		adfMinMax[0] = rBand->GetMinimum(&bGotMin);
		adfMinMax[1] = rBand->GetMaximum(&bGotMax);
		if(!(bGotMin && bGotMax))
			GDALComputeRasterMinMax((GDALRasterBandH) rBand, TRUE, adfMinMax);

		printf("Min=%.3fd, Max=%.3f\n", adfMinMax[0], adfMinMax[1]);

		if(rBand->GetOverviewCount() > -1)
			printf("Band has %d overviews.\n", rBand->GetOverviewCount());

		if(rBand->GetColorTable() != NULL)
			printf("Band has a color table with %d entries.\n",
				   rBand->GetColorTable()->GetColorEntryCount());

		float *pafScanline;
		int   nXSize = rBand->GetXSize();

		pafScanline = (float *) CPLMalloc(sizeof(float)*nXSize);
		rBand->RasterIO(GF_Read, 0, 0, nXSize, 1,
						 pafScanline, nXSize, 1, GDT_Float32,
						 0, 0);

		float max = 0.0f;
		float min = 1000.0f;

		for(int i = 0; i < nXSize; i++)
		{
			if(pafScanline[i] > max && pafScanline[i] > 0)
			{
				max = pafScanline[i];
			}
			if(pafScanline[i] < min && pafScanline[i] > 0)
			{
				min = pafScanline[i];
			}
			printf("%f\n", pafScanline[i]);
		}
		printf("\n\nMinValue: %f\n", min);
		printf("\n\nMaxValue: %f\n", max);

	} else
	{
		printf("Can not open file, dataset is empty");
	}

}
