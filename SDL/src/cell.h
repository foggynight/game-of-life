#ifndef CELL_H_
#define CELL_H_

#include "crl/single_link.h"

/* Struct representing a cell. */
typedef struct cell {
    int live; // Is the cell alive this turn
    int next; // Should the cell be alive next turn
    struct sl_node_t *neighbours; // List of neighbouring cells
} cell_t;

void cell_add_neighbour(cell_t *neighbour);
void cell_update(cell_t *cell);

#endif
