#include <stdio.h>
#include <string.h>
#include "encoding.h"
#include "decoding.h"

int main(int argc, char *argv[]) {
    char *mode = argv[1];
    char *infile = argv[2];
    char *outfile = argv[3];

    if (strcmp(mode, "c") == 0) {
        puts("encoding process starts");
        encode(infile, outfile);
        puts("successful encoding");

    }
    else if (strcmp(mode, "d") == 0) {
        puts("decoding process starts");
        decode(infile, outfile);
        puts("successful decoding");
    }
    else
        puts("wrong mode");

    return 0;
}