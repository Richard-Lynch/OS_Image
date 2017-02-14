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

char filename[] = "test.jpeg";

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
            fprintf(stderr, "can't open %s\n", filename);
            exit(1);
        }
        
jpeg_stdio_src(&cinfo, infile);
jpeg_read_header(&cinfo, TRUE);

// JSAMPARRAY 
 

// at the end




// done
    printf("Goodbye\n\n");

    return 0;
}