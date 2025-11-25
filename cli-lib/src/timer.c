#include "timer.h"
#include <unistd.h>

void sleep_ms(int ms) {
    usleep(ms * 1000);
}
