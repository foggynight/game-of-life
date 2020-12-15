#ifndef SCREEN_H_
#define SCREEN_H_

/** screen_init: Initialize the screen.
 * @param monitor {int}: ID of the monitor to place the window on
 * @return {int}: Non-zero on failure */
int screen_init(int monitor);

/** screen_step: Update the screen.
 * @return {int}: Non-zero indicates time to quit */
int screen_step(void);

/** screen_destroy: Destroy the screen. */
void screen_destroy(void);

#endif
