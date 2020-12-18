#include <string.h>

#include "cell.h"
#include "engine.h"

static cell_t cell_arr[CELL_COUNT];

void engine_setup(void)
{
    /* Add neighbours to each cell */
    for (int i = 0; i < CELL_COUNT; ++i) {
        /* Column to the left */
        if (i%CELL_ARRAY_WIDTH > 0) {

        }
        /* Column to the right */
        else if (i%CELL_ARRAY_WIDTH < CELL_ARRAY_WIDTH-1) {

        }
        /* Cell directly above */
        else if (i >= CELL_ARRAY_WIDTH) {

        }
        /* Cell directly below */
        else if (i < CELL_ARRAY_WIDTH * (CELL_ARRAY_HEIGHT-1)) {

        }
    }
}

void engine_step(void)
{

}
