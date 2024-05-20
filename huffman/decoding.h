#ifndef HUFFMAN_DECODING_H
#define HUFFMAN_DECODING_H

//Read bits from the encoding file
short readbits(bits *file) {
    if (file->size == 0) {
        if (fread(&file->buff, sizeof(char), 1, file->dest) != 1)
            return 2;
        file->size = BYTE;
    }
    file->size--;
    return ((file->buff >> file->size) & 1);
}

//Read symbol from the encoding file
char readsym(bits *file) {
    char sym = 0;
    for (short i = 0; i < BYTE; i++) {
        sym = sym << 1;
        short bit = readbits(file);
        if (bit == 2)
            return 1;
        sym = sym | bit;
    }
    return sym;
}

//Get the tree from the encoding file
tree *gettree(bits *file) {
    short bit = readbits(file);
    if (bit == 2)
        return NULL;
    if (bit == 1) {
        char sym = readsym(file);
        return tcreate(sym);
    }

    tree *left = gettree(file);
    tree *right = gettree(file);
    return merge(left, right);
}

//Read encoding symbols from the file
void readcode(FILE *out, bits *file, tree *t) {
    char sym;
    tree *start = t;
    while (start->right != NULL) {
        short bit = readbits(file);
//        printf("%d", bit);
        if (bit == 0)
            start = start->left;
        else
            start = start->right;
    }
    sym = start->sym;
    fwrite(&sym, sizeof(char), 1, out);
//    printf("|");
}

//Decoding process
void decode(char *infile, char *outfile) {
    setlocale(LC_ALL, "");
    FILE *in = fopen(infile, "rb");
    FILE *out = fopen(outfile, "wb");
    bits *file = screate(in);

    int size;
    fread(&size, sizeof(int), 1, in);

    tree *freqtree = gettree(file);
    if (freqtree == NULL) {
        puts("-->empty file");
        free(file);
        fclose(in);
        fclose(out);
        return;
    }
    printf("size: %d\n",size);
//    inorder(freqtree);
//    puts("");

    for (int i = 0; i < size; i++)
        readcode(out, file, freqtree);

    free(freqtree);
    free(file);
    fclose(in);
    fclose(out);
}

#endif //HUFFMAN_DECODING_H
