#include <stdio.h>
#include <ctype.h>
#include "testHelpers.h"


void byteblock_compare_test(CuTest* tc, const struct ByteBlock* a, const struct ByteBlock* b) 
{
	int size = TIMG_BLOCK_SIZE;

	for (int y=0;y<size;y++) {
		for (int x=0;x<size;x++) {
			CuAssertIntEquals(tc, a->data[y][x], b->data[y][x]);
		}
	}
}

void check_images_equal(CuTest* tc, struct Image* a, struct Image* b, int32_t delta)
{
	CuAssertIntEquals(tc, a->width, b->width);
	CuAssertIntEquals(tc, a->height, b->height);

	int32_t size = a->width * a->height;

	for (int i=0;i<size;i++) {
		if (delta == 0) {
			CuAssertIntEquals(tc, a->data[i].r, b->data[i].r);
			CuAssertIntEquals(tc, a->data[i].g, b->data[i].g);
			CuAssertIntEquals(tc, a->data[i].b, b->data[i].b);
		} else {
			CuAssertDblEquals(tc, a->data[i].r, b->data[i].r, delta);
			CuAssertDblEquals(tc, a->data[i].g, b->data[i].g, delta);
			CuAssertDblEquals(tc, a->data[i].b, b->data[i].b, delta);
		}
	}

}

void check_arrays_equal(CuTest* tc, uint8_t* a, uint8_t* b, uint64_t len)
{
	for (uint64_t i=0;i<len;i++) {
		CuAssertIntEquals(tc, a[i], b[i]);
	}
}
//
// source: http://stackoverflow.com/a/29865
void hexdump(void *ptr, int buflen) 
{
	unsigned char *buf = (unsigned char*)ptr;
	int i, j;
	for (i=0; i<buflen; i+=16) {
		printf("%06x: ", i);
		for (j=0; j<16; j++) 
			if (i+j < buflen)
				printf("%02x ", buf[i+j]);
			else
				printf("   ");
		printf(" ");
		for (j=0; j<16; j++) 
			if (i+j < buflen)
				printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
		printf("\n");
	}
}

