#include "cell.h"
#include "crl/single_link.h"

static int get_living_neighbours(cell_t *cell);

void cell_add_neighbour(cell_t *target, cell_t *neighbour)
{
    sl_node_t *new_node = sl_create_node();
    new_node->val = neighbour;

    sl_add_node(&target->nb_head, &target->nb_tail, new_node);
}

void cell_update(cell_t *target)
{
    // TODO: Implement Game of Life cell rules
    target->live = get_living_neighbours(target);
}

static int get_living_neighbours(cell_t *target)
{
    int count = 0;
    for (sl_node_t *walk = target->nb_head; walk; walk = walk->next)
        if (((cell_t *)walk->val)->live)
            ++count;
    return count;
}
