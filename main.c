#include "picrosser.h"

int main () {

    int imgLen = 8;
    uint16_t image[] = {(uint16_t)'a', (uint16_t)'b', (uint16_t)'c', 0xFFFF, (uint16_t)0 , (uint16_t)'f', (uint16_t)170, (uint16_t)85};

    printf("allocating %d bytes\n", (imgLen*(imgLen/2+1)*sizeof(char)));
    char *horiStrs = malloc(imgLen*(imgLen/2+1)*sizeof(char));

    printImage(&image, imgLen);
    computeHori(&image, imgLen, horiStrs);

    for (int i = 0; i < 40; i++) {
        if (i%5 == 0) {
            printf("x");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 0; i < 40; i++) {
        putc(*(horiStrs + i), stdout);
        if (*(horiStrs + i) == '\0') {
            printf("n");
        }
    }
    printf("\n");


    for (int i = 0; i < imgLen; i++) {
        printf("row %d: %s\n", i, (horiStrs + i*(imgLen/2+1)));
    }

    printf("\n");

    free(horiStrs);
    return 0;
}