#ifndef IMAGE_PPM_H_
#define IMAGE_PPM_H_
#include <stdint.h>

extern bool init_ppm_image_loader(void);
extern bool load_ppm_image(char * path, int32_t* width, int32_t height, void* data);

#endif
