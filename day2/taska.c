#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num_of_digits(long num) {
    int digits = 1;
    if(num < 0) num = -num;

    while(num > 9) {
        num = num/10;
        digits++;
    }

    return digits;
}

long long check_range(long lower, long upper) {
    printf("CHECKING RANGE [%ld, %ld]. INVALID IDS:\n", lower, upper);
    long long sum = 0;
    for(long num = lower; num <= upper; num++) {
        int digits = num_of_digits(num);

        if(digits%2 != 0) continue;

        long first;
        long second;

        first = num;
        for(int i = 0; i < digits/2; i++) {
           first = first/10;
        } 

        second = num - (first * (long) pow(10, digits/2));

        if(first == second) {
            printf("%ld\n", num);
            sum += num;
        }
    }

    return sum;
}

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

    char buff1[256];
    char buff2[256];
    char(* buff)[256];
    buff = &buff1;
    char(* swap)[256];
    swap = &buff2;

    int i = 0;
    long long sum = 0;
    char ch;
    while(1) {
        int res = fgetc(fp);
        ch = (char) res;
        if(ch == '-') {
            (*buff)[i] = '\0';
            char(* temp)[256] = buff;
            buff = swap;
            swap = temp;
            i = 0;
            continue;
        }    


        if(ch == ',' || res == EOF) {
            (*buff)[i] = '\0';
            char(* temp)[256] = buff;
            buff = swap;
            swap = temp;
            i = 0;
            // now buff1 has lower number, and buff2 has higher
            sum += check_range(strtod(buff1, NULL), strtod(buff2, NULL));

            if(res == EOF) break;
            continue;
        }

        

        (*buff)[i] = ch;
        i++;
    }
    
    printf("SUM OF ALL INVALID: %lld\n", sum);
    return 0;
}
