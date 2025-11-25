// simple keyboard helper: keyhit() and readch()
#include "keyboard.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static struct termios orig_termios;

void keyboardInit(void) {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &orig_termios);
    newt = orig_termios;
    newt.c_lflag &= ~(ICANON | ECHO); // raw, no echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void keyboardRestore(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

int keyhit(void) {
    int oldf;
    int ch;
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int readch(void) {
    int c = getchar();
    return c;
}
