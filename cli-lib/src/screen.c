#include "screen.h"
#include <stdio.h>

void screenClear(void) {
    // ANSI clear screen + move cursor home
    printf("\033[2J\033[H");
    fflush(stdout);
}

void screenInit(int raw) {
    // placeholder — not required if using keyboardInit
    (void)raw;
}

void screenShowCursor(void) {
    printf("\033[?25h");
    fflush(stdout);
}

void screenHideCursor(void) {
    printf("\033[?25l");
    fflush(stdout);
}
