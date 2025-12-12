/*
 * A template file for my AoC 2025 submissions
 *
 * Silas Hayes-Williams, 2025
 *
 * Unlicensed, use how you wish
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf(stderr, "Please provide an input file :(\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    return 0;
}
