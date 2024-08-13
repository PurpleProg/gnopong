#ifndef paddle_sprite_include_file
#define paddle_sprite_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define paddle_sprite_width 64
#define paddle_sprite_height 16
#define paddle_sprite_size 1026
#define paddle_sprite ((gfx_sprite_t*)paddle_sprite_data)
extern unsigned char paddle_sprite_data[1026];

#ifdef __cplusplus
}
#endif

#endif
