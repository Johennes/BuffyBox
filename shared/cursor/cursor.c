#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BBX_CURSOR_IMG_DSC
#define LV_ATTRIBUTE_IMG_BBX_CURSOR_IMG_DSC
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BBX_CURSOR_IMG_DSC uint8_t bbx_cursor_img_dsc_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0xf7, 0xff, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xf7, 0xdb, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x49, 0xff, 0xff, 0xf8, 0xdb, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x24, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x25, 0xff, 0x25, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x25, 0xff, 0x6d, 0xff, 0xff, 0xf8, 0xdb, 0x57, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x6e, 0xff, 0xff, 0xf8, 0xdb, 0x57, 0x00, 0x00, 
  0xff, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x6e, 0xff, 0xff, 0xf8, 0xff, 0x53, 
  0xff, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
  0xff, 0xff, 0x49, 0xff, 0x49, 0xff, 0xdb, 0xff, 0x92, 0xff, 0x49, 0xff, 0xb6, 0xff, 0xdb, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x49, 0xff, 0xdb, 0xff, 0xff, 0xef, 0xff, 0xff, 0x49, 0xff, 0x49, 0xff, 0xff, 0xfa, 0x6d, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xdb, 0xff, 0xff, 0xe1, 0x00, 0x00, 0xff, 0xeb, 0x6e, 0xff, 0x49, 0xff, 0xdb, 0xff, 0xff, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xda, 0x00, 0x00, 0x00, 0x00, 0xdb, 0x9d, 0xdb, 0xff, 0x49, 0xff, 0x6e, 0xff, 0xff, 0xe6, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfa, 0x6d, 0xff, 0x49, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdb, 0xb2, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0xf7, 0xdb, 0xde, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xbe, 0xf7, 0xf7, 0x59, 0xce, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x8a, 0x52, 0xff, 0x9e, 0xf7, 0xf8, 0x59, 0xce, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x04, 0x21, 0xff, 0x8a, 0x52, 0xff, 0x9e, 0xf7, 0xf8, 0x39, 0xce, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x04, 0x21, 0xff, 0x04, 0x21, 0xff, 0xaa, 0x52, 0xff, 0x9e, 0xf7, 0xf8, 0x39, 0xce, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x25, 0x29, 0xff, 0x25, 0x29, 0xff, 0x25, 0x29, 0xff, 0xcb, 0x5a, 0xff, 0x9e, 0xf7, 0xf8, 0x39, 0xce, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x45, 0x29, 0xff, 0x45, 0x29, 0xff, 0x45, 0x29, 0xff, 0x45, 0x29, 0xff, 0xcb, 0x5a, 0xff, 0x9e, 0xf7, 0xf8, 0x39, 0xce, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x66, 0x31, 0xff, 0x66, 0x31, 0xff, 0x66, 0x31, 0xff, 0x66, 0x31, 0xff, 0x66, 0x31, 0xff, 0xec, 0x62, 0xff, 0x9e, 0xf7, 0xf8, 0x39, 0xce, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x86, 0x31, 0xff, 0x86, 0x31, 0xff, 0x86, 0x31, 0xff, 0x86, 0x31, 0xff, 0x86, 0x31, 0xff, 0x86, 0x31, 0xff, 0x0c, 0x63, 0xff, 0x9e, 0xf7, 0xf8, 0x59, 0xce, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0xa6, 0x31, 0xff, 0x0c, 0x63, 0xff, 0xbe, 0xf7, 0xf8, 0x59, 0xce, 0x57, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0xc7, 0x39, 0xff, 0x2d, 0x6b, 0xff, 0xbe, 0xf7, 0xf8, 0x9a, 0xd6, 0x53, 
  0xff, 0xff, 0xff, 0xe7, 0x39, 0xff, 0xe7, 0x39, 0xff, 0xe8, 0x41, 0xff, 0x08, 0x42, 0xff, 0xe7, 0x39, 0xff, 0x1c, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
  0xff, 0xff, 0xff, 0xe8, 0x41, 0xff, 0x08, 0x42, 0xff, 0xd7, 0xbd, 0xff, 0x71, 0x8c, 0xff, 0xe8, 0x41, 0xff, 0xb2, 0x94, 0xff, 0x7a, 0xd6, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x28, 0x42, 0xff, 0xd7, 0xbd, 0xff, 0x3d, 0xef, 0xef, 0xfc, 0xe6, 0xff, 0x08, 0x42, 0xff, 0x6a, 0x52, 0xff, 0xbf, 0xff, 0xfa, 0x0c, 0x63, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xf7, 0xbd, 0xff, 0xfb, 0xde, 0xe1, 0x00, 0x00, 0x00, 0x7d, 0xef, 0xeb, 0x8e, 0x73, 0xff, 0x29, 0x4a, 0xff, 0xd7, 0xbd, 0xff, 0xfb, 0xde, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xfb, 0xde, 0xda, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0xbd, 0x9d, 0xf8, 0xc5, 0xff, 0x49, 0x4a, 0xff, 0x6d, 0x6b, 0xff, 0xdf, 0xff, 0xe6, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x7e, 0xf7, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0xff, 0xfa, 0xeb, 0x5a, 0xff, 0x69, 0x4a, 0xff, 0x9e, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xce, 0xb2, 0xdb, 0xde, 0xff, 0x79, 0xce, 0xff, 0x7d, 0xef, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0xff, 0xff, 0xf7, 0xde, 0xdb, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xf7, 0xbe, 0xf7, 0xce, 0x59, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x52, 0x8a, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x59, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x21, 0x04, 0xff, 0x52, 0x8a, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x39, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x21, 0x04, 0xff, 0x21, 0x04, 0xff, 0x52, 0xaa, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x39, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x29, 0x25, 0xff, 0x29, 0x25, 0xff, 0x29, 0x25, 0xff, 0x5a, 0xcb, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x39, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x29, 0x45, 0xff, 0x29, 0x45, 0xff, 0x29, 0x45, 0xff, 0x29, 0x45, 0xff, 0x5a, 0xcb, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x39, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x31, 0x66, 0xff, 0x31, 0x66, 0xff, 0x31, 0x66, 0xff, 0x31, 0x66, 0xff, 0x31, 0x66, 0xff, 0x62, 0xec, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x39, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x31, 0x86, 0xff, 0x31, 0x86, 0xff, 0x31, 0x86, 0xff, 0x31, 0x86, 0xff, 0x31, 0x86, 0xff, 0x31, 0x86, 0xff, 0x63, 0x0c, 0xff, 0xf7, 0x9e, 0xf8, 0xce, 0x59, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x31, 0xa6, 0xff, 0x63, 0x0c, 0xff, 0xf7, 0xbe, 0xf8, 0xce, 0x59, 0x57, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x39, 0xc7, 0xff, 0x6b, 0x2d, 0xff, 0xf7, 0xbe, 0xf8, 0xd6, 0x9a, 0x53, 
  0xff, 0xff, 0xff, 0x39, 0xe7, 0xff, 0x39, 0xe7, 0xff, 0x41, 0xe8, 0xff, 0x42, 0x08, 0xff, 0x39, 0xe7, 0xff, 0xe7, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
  0xff, 0xff, 0xff, 0x41, 0xe8, 0xff, 0x42, 0x08, 0xff, 0xbd, 0xd7, 0xff, 0x8c, 0x71, 0xff, 0x41, 0xe8, 0xff, 0x94, 0xb2, 0xff, 0xd6, 0x7a, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x42, 0x28, 0xff, 0xbd, 0xd7, 0xff, 0xef, 0x3d, 0xef, 0xe6, 0xfc, 0xff, 0x42, 0x08, 0xff, 0x52, 0x6a, 0xff, 0xff, 0xbf, 0xfa, 0x63, 0x0c, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xbd, 0xf7, 0xff, 0xde, 0xfb, 0xe1, 0x00, 0x00, 0x00, 0xef, 0x7d, 0xeb, 0x73, 0x8e, 0xff, 0x4a, 0x29, 0xff, 0xbd, 0xd7, 0xff, 0xde, 0xfb, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xde, 0xfb, 0xda, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0xd7, 0x9d, 0xc5, 0xf8, 0xff, 0x4a, 0x49, 0xff, 0x6b, 0x6d, 0xff, 0xff, 0xdf, 0xe6, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xf7, 0x7e, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xbf, 0xfa, 0x5a, 0xeb, 0xff, 0x4a, 0x69, 0xff, 0xf7, 0x9e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x39, 0xb2, 0xde, 0xdb, 0xff, 0xce, 0x79, 0xff, 0xef, 0x7d, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0xfd, 0xfd, 0xfd, 0xf7, 0xd6, 0xd6, 0xd6, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xf2, 0xf2, 0xf2, 0xf7, 0xc9, 0xc9, 0xc9, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0xf0, 0xf0, 0xf0, 0xf8, 0xc7, 0xc7, 0xc7, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x1e, 0x1e, 0x1e, 0xff, 0x51, 0x51, 0x51, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc5, 0xc5, 0xc5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x21, 0x21, 0x21, 0xff, 0x21, 0x21, 0x21, 0xff, 0x53, 0x53, 0x53, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc5, 0xc5, 0xc5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x25, 0x25, 0x25, 0xff, 0x25, 0x25, 0x25, 0xff, 0x25, 0x25, 0x25, 0xff, 0x57, 0x57, 0x57, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc5, 0xc5, 0xc5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x28, 0x28, 0x28, 0xff, 0x28, 0x28, 0x28, 0xff, 0x28, 0x28, 0x28, 0xff, 0x28, 0x28, 0x28, 0xff, 0x59, 0x59, 0x59, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc5, 0xc5, 0xc5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc5, 0xc5, 0xc5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x2f, 0x2f, 0x2f, 0xff, 0x5e, 0x5e, 0x5e, 0xff, 0xf1, 0xf1, 0xf1, 0xf8, 0xc7, 0xc7, 0xc7, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0xff, 0x61, 0x61, 0x61, 0xff, 0xf2, 0xf2, 0xf2, 0xf8, 0xc7, 0xc7, 0xc7, 0x57, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36, 0xff, 0x64, 0x64, 0x64, 0xff, 0xf2, 0xf2, 0xf2, 0xf8, 0xd0, 0xd0, 0xd0, 0x53, 
  0xff, 0xff, 0xff, 0xff, 0x3a, 0x3a, 0x3a, 0xff, 0x3a, 0x3a, 0x3a, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0xe1, 0xe1, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xf7, 
  0xff, 0xff, 0xff, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x92, 0x92, 0x92, 0xff, 0xcd, 0xcd, 0xcd, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x42, 0x42, 0x42, 0xff, 0xb8, 0xb8, 0xb8, 0xff, 0xe5, 0xe5, 0xe5, 0xef, 0xdc, 0xdc, 0xdc, 0xff, 0x41, 0x41, 0x41, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0xf4, 0xf4, 0xf4, 0xfa, 0x5f, 0x5f, 0x5f, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xba, 0xba, 0xba, 0xff, 0xda, 0xda, 0xda, 0xe1, 0x00, 0x00, 0x00, 0x00, 0xea, 0xea, 0xea, 0xeb, 0x6f, 0x6f, 0x6f, 0xff, 0x44, 0x44, 0x44, 0xff, 0xb6, 0xb6, 0xb6, 0xff, 0xda, 0xda, 0xda, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xda, 0xda, 0xda, 0xda, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb7, 0xb7, 0xb7, 0x9d, 0xbd, 0xbd, 0xbd, 0xff, 0x48, 0x48, 0x48, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0xf7, 0xf7, 0xf7, 0xe6, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xec, 0xec, 0xec, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf4, 0xf4, 0xf4, 0xfa, 0x5b, 0x5b, 0x5b, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0xc4, 0xc4, 0xb2, 0xd9, 0xd9, 0xd9, 0xff, 0xcb, 0xcb, 0xcb, 0xff, 0xea, 0xea, 0xea, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t bbx_cursor_img_dsc = {
  .header.cf = LV_COLOR_FORMAT_NATIVE_WITH_ALPHA,
  .header.w = 12,
  .header.h = 18,
  .data = bbx_cursor_img_dsc_map,
};
