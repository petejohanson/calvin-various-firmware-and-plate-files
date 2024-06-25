#pragma once

#include "progmem.h"
#include "ocean_boat_animation.c"

static uint16_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_animation(uint8_t frame) {
    oled_write_raw_P(animation[frame], sizeof(animation[frame]));
}

bool oled_task_user(void) {
    render_animation((timer_read() / 200) % 44);
    return false;
}