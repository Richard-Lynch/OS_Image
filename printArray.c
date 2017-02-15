#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

void print_int_array(int** array, int width, int height){
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width*3; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void print_char_array(unsigned char** array, int width, int height){
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width*3; j++){
            printf("%c ",array[i][j]);
        }
        printf("\n");
    }
}