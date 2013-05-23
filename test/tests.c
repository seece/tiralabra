#include <stdio.h>
#include "CuTest.h"

CuSuite* CuGetSuite();
CuSuite* CuGetDCTSuite();
CuSuite* CuGetBlockSuite();
CuSuite* CuGetImageSuite();

void RunAllTests(void) 
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, CuGetSuite());
	CuSuiteAddSuite(suite, CuGetBlockSuite());
	CuSuiteAddSuite(suite, CuGetDCTSuite());
	CuSuiteAddSuite(suite, CuGetImageSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
	CuSuiteDelete(suite);
}

int main(void) 
{
	RunAllTests();

	return 0;
}
