#include <string.h>

#include "cell.h"
#include "engine.h"

static cell_t cell_arr[CELL_COUNT];

void engine_setup(void)
{
    /* Add neighbours to each cell */
    for (int i = 0; i < CELL_COUNT; ++i) {
        /* Column to the left of the cell */
        if (i%CELL_ARRAY_WIDTH > 0) {

        }
        /* Column to the right of the cell */
        else if (i%CELL_ARRAY_WIDTH < CELL_ARRAY_WIDTH-1) {

        }
        /* Row above the cell */
        else if (i >= CELL_ARRAY_WIDTH) {

        }
        /* Row below the cell */
        else if (i < CELL_ARRAY_WIDTH * (CELL_ARRAY_HEIGHT-1)) {

        }
    }
}

void engine_step(void)
{

}
