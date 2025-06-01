#include "kernel.h"
#include "shell.h"

extern int textColor;

int main() {
    interrupt(0x10, 0x0200, 0, 0, 0);
    clearScreen(0x07);  // Set awal warna putih
    shell();
    return 0;
}

void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E00 + str[i],0 , 0, 0); // ← GUNAKAN textColor di AH
        i++;
    }
}

void readString(char *buf) {
    int i = 0;
    char c;
    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0) & 0xFF;

        if (c == 0x0D) { // Enter
            buf[i] = '\0';
            printString("\r\n");
            break;
        } else if (c == 0x08 && i > 0) { // Backspace
            i--;
            printString("\b \b");
        } else if (c >= 32 && c <= 126 && i < 255) {
            buf[i++] = c;
            interrupt(0x10, 0x0E00 + c, 0, 0, 0);
        }
    }
}

void clearScreen(int color) {
    int i;
    for (i = 0; i < 25 * 80; i++) {
        putInMemory(0xB800, i * 2, ' ');
        putInMemory(0xB800, i * 2 + 1, color);
    }
}
