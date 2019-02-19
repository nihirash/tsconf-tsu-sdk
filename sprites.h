// Стандартные типы из evosdk

typedef unsigned char u8;
typedef   signed char i8;
typedef unsigned  int u16;
typedef   signed  int i16;
typedef unsigned long u32;
typedef   signed long i32;

// Мои типы - просто для наглядности параметров, от этого можно отказться в легкую
typedef i16 coord;
typedef u8  tilecell;
typedef u16 tileposition;
typedef u8 pal;

struct sprite {
    coord x;
    coord y;
    tilecell size_x;
    tilecell size_y;
    bool act;
    bool flip_y;
    bool flip_x; 
    tileposition start_tile;
    u8 leap;
    pal pallete;
};

/**
 * По координатом на тайловой плоскости возвращает адрес тайла - может быть удобно, чтобы не считать руками.
 * Возможно, просто сделать макросом и не грузить бедный z80 ненужными вычислениями
 **/
tileposition sprite_find_tilecell(tilecell x, tilecell y);

/**
 * Я еще думал над вариантом сигнатуры вида sprites_begin(u8 count), которая инициализирует необходимое место под спрайты, 
 * ровно в размере необходимого буфера
 **/
void sprites_begin(); 
void sprites_end();

/**
 * Полное обновление дескриптора спрайта
 **/
void set_sprite(u8 id, sprite spr);
/**
 * Нам же часто не нужно гонять туда-сюда все остальное?
 **/
void set_sprite_coords(u8 id, coord x, coord y);
void set_sprite_start_tile(tileposition start_tile);
void show_sprite(u8 id);
void hide_sprite(u8 id);

/**
 * Переключение экрана теневой-основной. Вывод спрайтов и ожидание vsync
 * 
 * Если для TSConf и TSU это не требуется - может оставить просто vsync?
 **/
void swap_screen();
void vsync();



