/* --- game-of-life/SDL ---
 *
 * Conway's Game of Life implemented using the SDL library.
 *
 * Copyright (C) 2020 Robert Coffey
 * Released under the GPLv2 license */

#include <stdlib.h>

#define RTB_DEFINE
#include "rtb_list.h"

#include "engine.h"
#include "screen.h"

#define INITIAL_MONITOR 1

int main(void)
{
    engine_setup();
    if (screen_init(INITIAL_MONITOR))
        return EXIT_FAILURE;

    while (!screen_step(engine_view()))
        engine_step();

    screen_destroy();
    return EXIT_SUCCESS;
}
