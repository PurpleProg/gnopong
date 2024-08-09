#ifndef paddle_include_file
#define paddle_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define paddle_width 64
#define paddle_height 16
#define paddle_size 1026
#define paddle ((gfx_sprite_t*)paddle_data)
extern unsigned char paddle_data[1026];

#ifdef __cplusplus
}
#endif

#endif
