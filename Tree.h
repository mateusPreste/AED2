#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"


struct Block *initialBlock;


typedef struct Block{
    int cpf;
    char nomeIn[50];
    char nomeOut[50];
    int idade;
    float salario;

    struct Block* left;
    struct Block* right;
} Block;

typedef struct {
    struct Block *root;
} Tree;

void initTree(int size);

void showTree(struct Block *block);

void insertTree(Tree *tree, Data *data, int i);

void diskTreeSearch(FILE *file, Tree *tree, struct Block *block, long int address, int n);

void printRight(int r, struct Block result, int key, char keyC[50], int type, int out);

void printTree(FILE *file, Tree *tree, struct Block *block, long int address, int key, char keyC[50], int n, int type,
               int out);

void diskSequencialSearch(FILE *file, int n, int key, char keyC[50], int type, int out);

#endif
