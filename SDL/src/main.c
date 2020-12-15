#include <stdlib.h>

#include "screen.h"

#define INITIAL_MONITOR 1

int main(void)
{
    if (screen_init(INITIAL_MONITOR)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
