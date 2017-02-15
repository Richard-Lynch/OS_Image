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

int create_PPM(char P_num[], char fileName[], int width, int height, int depth, int lineWidth)
{
// vars
// char P_num[] = "P3";
// int width = 100;
// int height = 100;
// int depth = 255;

//open the ppm file
FILE* outfile;
// char filename[] = "out.ppm";
 
//if we couldnt open the input file
if ((outfile = fopen(fileName, "wb")) == NULL) {
            printf("can't open %s\n", fileName);
            exit(1);
        }

fprintf(outfile, "%s \n", P_num);
fprintf(outfile, "%d %d \n", width, height);
fprintf(outfile, "%d \n", depth);

int perh = depth/height;
int perw = depth/width;
int perb = depth/(width+height);

for(int i = 0; i<height; i++){
    for(int j = 0; j<width; j++){
        if(abs(i-j)<lineWidth){
            fprintf(outfile, "%d %d %d ", 0, 0, 0);
        }else{
            fprintf(outfile, "%d %d %d ", abs(depth-(i*perh)), abs(depth-(j*perw)), abs(depth-(i+j)*perb));
        }
        
    }
    fprintf(outfile,"\n");
}
fclose(outfile);

// done
    printf("Done creating PPM: %s\n\n", fileName);

    return 0;
}