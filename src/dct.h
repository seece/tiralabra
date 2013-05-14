#ifndef DCT_H_
#define DCT_H_

#include "block.h"

extern const uint8_t quantization_matrix[8][8];

void dct_calculate(struct ByteBlock const* input, 
		struct FloatBlock* output); 

void quantize_floatblock(
		const struct FloatBlock* input,
		int32_t quality,
		struct ByteBlock* output);

void quantize_byteblock(
		const struct ByteBlock* input,
		int32_t quality,
		struct ByteBlock* output);
#endif
