#include <stdlib.h>

#define CRL_DEFINE
#include "crl/single_link.h"

#include "screen.h"

#define INITIAL_MONITOR 1

int main(void)
{
    if (screen_init(INITIAL_MONITOR))
        return EXIT_FAILURE;

    int quit = 0;
    while (!quit) {
        if (screen_step())
            quit = 1;
    }

    screen_destroy();

    return EXIT_SUCCESS;
}
