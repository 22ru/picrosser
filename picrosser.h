#ifndef PICROSSER_H
#define PICROSSER_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>


void printImage(const uint16_t *img, const int len) {
    int i, j;
    for (i = 0; i < len*2+2; i++) {
        printf("_");
    }
    printf("\n");
    for (i = 0; i < len; i++) {
        printf("|");
        for (j = 0; j < len; j++) {
            if (*(img+i) & (0x80 >> j)) printf("██");
            else printf("  ");
        }
        printf("|\n");
    }
    for (i = 0; i < len*2+2; i++) {
        printf("‾");
    }
    printf("\n");
    return;
}

void computeHori (const uint16_t *img, const int len, char * result) {
    int i = 0, j = 0, strOffset = 0, acc = 0;
    int linelen = len/2+1;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (*(img+i) & (0x80 >> j)) { // colored spot
                acc++;
                //putc('x', stdout);
            } else { // blank spot
                if (acc) {
                    //add to string
                    *(result + i*linelen + strOffset) = (char)(48 + acc);
                    acc = 0;
                    strOffset++;
                    //putc('a', stdout);
                } else {
                    //putc('o', stdout);
                }
            }
        }
        if (acc) {
            *(result + i*linelen + strOffset) = (char)(48 + acc);
            strOffset++;
        }
        *(result + i*linelen + strOffset) = (char) NULL;
        strOffset = 0;
        acc = 0;
        //putc('\n', stdout);
    }
    return;
}

#endif