#include <stdio.h>
#include <string.h>
#include "encoding.h"
#include "decoding.h"

int main(int cnt, char *arr[]) {
    if (strcmp(arr[1], "c") == 0) {
        puts("encoding process starts");
        encode(arr[2], arr[3]);
        puts("successful encoding");

    }
    else if (strcmp(arr[1], "d") == 0) {
        puts("decoding process starts");
        decode(arr[2], arr[3]);
        puts("successful decoding");
    }
    else
        puts("wrong mode");

    return 0;
}
