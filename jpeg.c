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
#include <jpeglib.h>
#include "printArray.c"

char filename[] = "test.jpg";

int main(int argc, char *argv[])
{
// read args
    int firstarg;
    // if (argc < 2 || (firstarg = atoi(argv[1])) <= 0)
    // { //convert the first arg to an int
    //     //if there is not arg entered
    //     printf("No Args Entered");
    //     exit(1);
    // }
    printf("got in to the main anyway\n");

    //create somejpeg vars
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    // Each scanline is an array of datatype JSAMPLE ( typically unsigned char )
    // scanline contains values of each pixel adjacently, ie "R1,G1,B1,R2,G2,B2,..."
    // to create a 2-D array, create a list of pointers to the start of scanlines, 
    // so each line does not need to be adjacent in memory
    // pointers to JSAMPLE rows are of type JSAMROW
    // and the pointer to the array of JSAMPROWs is of type JSAMPARRAY

    //open the jpeg file
    FILE* infile;
    
    //if we couldnt open the input file
    if ((infile = fopen(filename, "rb")) == NULL) {
                printf("can't open %s\n", filename);
                return(1);
            }
    printf("file opened\n");
            
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);

    jpeg_start_decompress(&cinfo);

    JSAMPROW image[cinfo.output_height];

    for(int i=0; i<cinfo.output_height; i++){
        image[i]=malloc(sizeof(JSAMPLE)*cinfo.output_width*cinfo.output_components);
    }
    int i = 0;
    while(cinfo.output_scanline<cinfo.output_height){
        jpeg_read_scanlines(&cinfo, image[i],1);
    }
    print_char_array(image,cinfo.output_width, cinfo.output_height);

// done
    printf("Goodbye\n\n");
    fclose(infile);
    while(true);

    return 0;
}