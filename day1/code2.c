#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf(stderr, "Must provide input file\n");
        return 0;
    }

    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL) {
        perror("Error opening file");
        return 0;
    }

    char scount[8];
    long count;

    char direction;

    long val = 50;
    int code = 0;
    int prev0 = 0;
    while((direction = (char) fgetc(fp)) != EOF) {
        printf("Code: %d\tVal: %ld\n", code, val);
        fgets(scount, 8, fp);
        long diff = strtol(scount, NULL, 10);
        printf("%c%ld\t", direction, diff); 

        code += diff/100;
        diff = diff%100;

        if(diff == 0) continue;

        switch(direction) {
            case 'L':
                val -= diff;
                break;

            case 'R':
                val += diff;
                break;
        }

        if(val < 0 & !prev0) code++;
        if(val > 100) code++;
        val = val%100;
        if(val < 0) val = 100+val;
        if(prev0 = val == 0) code++;

    }

    printf("%d\n", code);
    return 0;
}

