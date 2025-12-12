#include <stdio.h>
#include <stdlib.h>

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
    while((direction = (char) fgetc(fp)) != EOF) {
        fgets(scount, 8, fp);
        
        long diff = strtol(scount, NULL, 10);

        printf("Diff: %2ld\tDir: %c", diff, direction); 
        switch(direction) {
            case 'R':
                val += diff;
                break;

            case 'L':
                val -= diff;
                break;
        }

        val = val%100;
        if(val < 0) val = 100+val;
        printf("\tVal: %ld", val);
        if(val == 0) code++;

        printf("\tCode: %d\n", code);
    }

    printf("%d\n", code);
    return 0;
}

