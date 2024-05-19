#ifndef HUFFMAN_ENCODING_H
#define HUFFMAN_ENCODING_H

#include <locale.h>
#include "structs.h"

#define BYTE 8

//Make a frequency list that sorts in non-decreasing order and contains symbols
list *makelist(FILE *input, int size) {
    list *freql = lcreate(tcreate(0));
    list *start = freql;
    char sym;

    fseek(input, 0, SEEK_END);
    int num = ftell(input);
    rewind(input);

    for (int i = 0; i < num; i++) {
        sym = fgetc(input);
        char newsym = 0;
        freql = start;
        while (freql->next && (newsym == 0)) {
            list *left = freql;
            freql = freql->next;

            if (freql->data->sym == sym) {
                freql->data->freq++;
                list *right = freql->next;

                while(right  && (freql->data->freq > right->data->freq)) {
                    freql->next = right->next;
                    right->next = freql;
                    left->next = right;

                    left = right;
                    right = freql->next;
                }
                newsym = 1;
            }
        }

        freql = start;

        if (!newsym) {
            insert(freql, lcreate(tcreate(sym)));
            size++;
        }
    }

    rewind(input);
    freql->data->freq = size;
    return freql;
}

//Make a tree of codes of the symbols
tree *maketree(list *freql) {
    while (freql->next->next) {
        tree *left = pop(freql);
        tree *right = pop(freql);
        tree *node = merge(left, right);
        insert(freql, lcreate(node));
    }
    return freql->next->data;
}

//Creation a code for each symbol
void codesym(tree *node, bins **codes, short size, unsigned int code, int *ind) {
    if (node->right == NULL) {
        codes[(*ind)++] = bcreate(node->sym, code, size);
//        for (int i = size-1; i >= 0; i--)
//            printf("%d", (code >> i) & 1);
//        printf(" %c\n", node->sym);
        return;
    }

    codesym(node->left, codes, size + 1, code << 1, ind);
    codesym(node->right, codes, size + 1, (code << 1) | 1, ind);
}

//Write bits on the encoding file
void writebits(bits *file, short bit) {
    if (file->size == BYTE) {
//        printf("|");
        fwrite(&(file->buff), sizeof(char), 1, file->dest);
        file->buff = 0;
        file->size = 0;
    }
    file->buff = bit | (file->buff << 1);
//    printf("%hi", bit);
    file->size++;
}

//Write symbol on the encoding file
void writesym(bits *file, char sym) {
    for (short i = BYTE - 1; i >= 0; i--) {
        short bit = (sym >> i) & 1;
        writebits(file, bit);
    }
}

//Write the tree to the encoding file
void writetree(bits *file, tree *freqt) {
    if(freqt->right == NULL) {
        writebits(file, 1);
        writesym(file, freqt->sym);
        return;
    }

    writebits(file, 0);
    writetree(file, freqt->left);
    writetree(file, freqt->right);
}

//Write data to the encoding file
void writecode(bits *file, bins **codes, char sym, int size) {
    for (int i = 0; i < size; i++)
        if (sym == codes[i]->sym) {
            for (short j = codes[i]->size - 1; j >= 0; j--) {
                short bit = (codes[i]->code >> j) & 1;
                writebits(file, bit);
            }
            break;
        }
}

//Encoding process
void encode(char *infile, char *outfile) {
    setlocale(LC_ALL, "");
    FILE *in = fopen(infile, "rb");
    FILE *out = fopen(outfile, "wb");
    bits *file = screate(out);

    int size = 0;
    list *freqlist = makelist(in, size);

    if (freqlist->next == NULL) {
        puts("-->empty file");
        free(freqlist);
        fclose(in);
        fclose(out);
        return;
    }

    int ind = 0, code = 0;
    short num = 0;
    size = freqlist->data->freq;
//    printf("unique symbols: %d\n", size);
    bins **codes = (bins **) malloc(size * sizeof(bins *));
    tree *freqtree = maketree(freqlist);
    codesym(freqtree, codes, num, code, &ind);

    fwrite(&(freqtree->freq), sizeof(int), 1, out);
    writetree(file, freqtree);

//    puts("");
//    inorder(freqtree);
    printf("size: %d bytes\n", freqtree->freq);

    char sym;
    for (int i = 0; i < freqtree->freq; i++) {
        sym = fgetc(in);
        writecode(file, codes, sym, size);
    }

    file->buff = file->buff << (BYTE - file->size);
    fwrite(&(file->buff), sizeof(char), 1, file->dest);

    free(freqtree);
    free(freqlist);
    free(codes);
    free(file);

    fclose(in);
    fclose(out);
}

#endif //HUFFMAN_ENCODING_H
