#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

int SIZE_TREE;

void initTree(int size) {
    initialBlock = (struct Block *) malloc(sizeof(struct Block) * size);
    SIZE_TREE = size;
}


void showTree(struct Block *block) {
    if (block) {
        if (block->left) showTree(block->left);
        printf("%d\n", block->cpf);
        if (block->right) showTree(block->right);
    }
}

void insertTree(Tree *tree, Data *data, int i) {
    struct Block *block = &initialBlock[i];
    block->cpf = data->cpf;
    strcpy(block->nomeIn, data->nomeIn);
    strcpy(block->nomeOut, data->nomeOut);
    block->idade = data->idade;
    block->salario = data->salario;
    block->left = NULL;
    block->right = NULL;

    if (tree->root == NULL) {
        tree->root = initialBlock;
    } else {
        struct Block *point = tree->root;
        do {
            if (point->cpf >= data->cpf) {
                if (point->left) {
                    point = point->left;
                } else {
                    point->left = block;
                    break;
                }
            } else if (point->cpf < data->cpf) {
                if (point->right) {
                    point = point->right;
                } else {
                    point->right = block;
                    break;
                }
            }
        } while (point);
    }
}

void diskTreeSearch(FILE *file, Tree *tree, struct Block *block, long int address, int n) {
    struct Block result;
    long int position = ((address - (long int) &((tree->root)[0])) / (sizeof(Block)));
    int r;
    if (block) {
        if (block->left) diskTreeSearch(file, tree, block->left, (long int) block->left, n);
        fseek(file, ((int) position + (n * (SIZE_TREE))) * sizeof(struct Block), SEEK_SET);
        r = (int) fread(&result, sizeof(struct Block), 1, file);
        if (r != 0) {
        }
        if (block->right) diskTreeSearch(file, tree, block->right, (long int) block->right, n);
    }
}


void printRight(int r, struct Block result, int key, char keyC[50], int type, int out) {
    if (out == 0) {
        switch (type) {
            case 0:
                if (r != 0 && strcpy(result.nomeIn, keyC) == 0) {

                }
                break;
            case 1:
                if (r != 0 && strcpy(result.nomeIn, keyC) > 0) {

                }
                break;
            case 2:
                if (r != 0 && strcpy(result.nomeIn, keyC) < 0) {

                }
                break;
            case 3:
                if (r != 0 && strcpy(result.nomeIn, keyC) >= 0) {

                }
                break;
            case 4:
                if (r != 0 && strcpy(result.nomeIn, keyC) <= 0) {

                }
                break;
            default:
                break;
        }
    } else {
        switch (type) {
            case 0:
                if (r != 0 && result.cpf == key) {

                }
                break;
            case 1:
                if (r != 0 && result.cpf > key) {
                }
                break;
            case 2:
                if (r != 0 && result.cpf < key) {
                }
                break;
            case 3:
                if (r != 0 && result.cpf >= key) {
                }
                break;
            case 4:
                if (r != 0 && result.cpf <= key) {
                }
                break;
            default:
                break;
        }
    }
}

void printTree(FILE *file, Tree *tree, struct Block *block, long int address, int key, char keyC[50], int n, int type,
               int out) {
    struct Block result;
    long int position = ((address - (long int) &((tree->root)[0])) / (sizeof(Block)));
    int r;
    if (block) {
        if (block->left) {
            printTree(file, tree, block->left, (long int) block->left, key, keyC, n, type, out);
        };

        fseek(file, ((int) position + (n * (SIZE_TREE))) * sizeof(struct Block), SEEK_SET);
        r = (int) fread(&result, sizeof(struct Block), 1, file);
        printRight(r, result, key, keyC, type, out);

        if (block->right) {
            printTree(file, tree, block->right, (long int) block->right, key, keyC, n, type, out);
        };
    }
}

void diskSequencialSearch(FILE *file, int n, int key, char keyC[50], int type, int out) {
    struct Block result;
    int r;

    for (int i = 0; i < SIZE_SEQ; ++i) {
        fseek(file, (i + (n * (SIZE_SEQ))) * sizeof(struct Block), SEEK_SET);
        r = (int) fread(&result, sizeof(struct Block), 1, file);
        if (r != 0) {
            printRight(r, result, key, keyC, type, out);
        }
    }
}
