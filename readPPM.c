/*
    Created by Richard Lynch 
    14/feb/17
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

void print_array(int** array, int width, int height);

int read_PPM(char fileName[])
{
// vars
char P_num[255];
char cwidth[255];
int width;
int height;
char cheight[255];
int depth;
char cdepth[255];

//open the ppm file
FILE* infile;
// char filename[] = "out.ppm";
 
//if we couldnt open the input file
if ((infile = fopen(fileName, "r")) == NULL) {
            printf("can't open %s\n", fileName);
            exit(1);
        }

fscanf(infile, "%s", P_num);
printf("P_num: %s\n", P_num);
fscanf(infile, "%s", cwidth);
printf("cwidth: %s\n", cwidth);
fscanf(infile, "%s", cheight);
printf("cheight: %s\n", cheight);
fscanf(infile, "%s", cdepth);
printf("cdepth: %s\n", cdepth);

height = atoi(cheight);
width = atoi(cwidth);
depth = atoi(cdepth);
printf("width: %d\nheight: %d\ndepth: %d\n", width, height, depth);

// int** image;
// image = malloc(sizeof(int)*width*height);
int* image[height];
for(int i=0; i<height; i++){
    image[i]=malloc(sizeof(int)*width*3);
}
char buff[255];

for(int i = 0; i<height; i++){
    for(int j = 0; j<width*3; j++){
        fscanf(infile, "%s", buff);
        image[i][j] = atoi(buff);
    }
}
print_array(image, width, height);




fclose(infile);

// done
    printf("Done reading PPM: %s\n\n", fileName);

    return 0;
}

void print_array(int** array, int width, int height){
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width*3; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
