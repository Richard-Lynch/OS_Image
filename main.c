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
#include "createPPM.c"
#include "readPPM.c"

char name[] = "test.ppm";

int main(int argc, char *argv[])
{
    create_PPM("P3", name, 10, 10, 255, 2);
    read_PPM(name);




// done
    printf("Goodbye\n\n");

    return 0;
}