#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"
#include "Hash.h"
#include <time.h>
#include <sys\timeb.h>


const int SIZE_MAIN = 5000;
const int SZ = 30;

void diskHashSearch(FILE *file, int n) {
    Line result;
    int r;

    for (int i = 0; i < SIZE_MAIN; ++i) {
        fseek(file, ((n * (SIZE_MAIN)) * sizeof(struct Block)) + (i * sizeof(Line)), SEEK_SET);
        r = (int) fread(&result, sizeof(Line), 1, file);
        if (r != 0) {
        }
    }
}

double calcTime(double a[SZ], double ch)
{
    double average = 0;
    for (int i = 0; i < 30; ++i) {
        average += a[i];
    }
    return average/SZ;
}

void rand_str(char *dest, size_t length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index;
        index = (size_t) ((double) rand() / RAND_MAX * (sizeof charset - 1));
        *dest++ = charset[index];
    }
    *dest = '\0';
}


int main() {
    struct timeb start, endf;
    int diff;
    int i = 0;


    double time_spent,end,begin;
    double chronus[SZ];

    srand((unsigned int) time(NULL));
    int randomNumber;

    Hash *hash = (Hash *) malloc(sizeof(Hash));
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    Tree *ordTree = (Tree *) malloc(sizeof(Tree));

    initHash(hash);
    initTree(SIZE_MAIN);
    initSequential(SIZE_MAIN);

    tree->root = NULL;
    ordTree->root = NULL;
    char nome[50];
    char *pal = (char *) malloc(sizeof(49));
    rand_str(pal, 50);

    strncpy(nome, pal, sizeof nome - 1);
    nome[49] = '\0';
    char sNome[50] = "b";
    Data *data = returnData(1232, nome, sNome, 30, 2.3);

    for (int i = 0; i < SIZE_MAIN; ++i) {
        rand_str(pal, 50);
        strncpy(nome, pal, sizeof nome - 1);

        rand_str(pal, 50);
        strncpy(sNome, pal, sizeof nome - 1);

        randomNumber = rand();
        data = returnData(i, nome, sNome, 30, 2.3);
        insertTree(tree, data, i);
        insertHash(hash, data, data->cpf);
    }

    int sorted[SIZE_MAIN];
    initTree(SIZE_MAIN);
    for (int i = 0; i < SIZE_MAIN; ++i) {
        randomNumber = rand() % (SIZE_MAIN * 8);
        while (sequentialSearch(sorted, SIZE_MAIN, randomNumber)) {
            randomNumber = rand() % (SIZE_MAIN * 8);
        }

        sorted[i] = randomNumber;
        data = returnData(i, nome, sNome, 30, 2.3);
        insertTree(ordTree, returnData(randomNumber, nome, sNome, 30, 2.3), i);
    }

    //showTree(tree->root);
    //showHash(hash, 0);


    FILE *file;

    if ((file = fopen("file.bin", "wb")) == NULL) {

    } else {
        int i;
        //sequential
        for (i = 0; i < SIZE_MAIN; ++i) {
            struct Block *TreeTest = tree->root;
            fwrite(&TreeTest[i], sizeof(struct Block), 1, file);
        }
        //random
        for (i = 0; i < SIZE_MAIN; ++i) {
            struct Block *teste = ordTree->root;
            fwrite(&teste[i], sizeof(struct Block), 1, file);
        }
        //hash
        for (i = 0; i < SIZE_MAIN; ++i) {
            Line *teste = (hash->Table)[i];
            fwrite(teste, sizeof(Line), 1, file);
        }
    }

    fclose(file);

    //printf("\n\n\n\n\n");
    struct Block result;
    int r;

    if ((file = fopen("file.bin", "rb")) == NULL) {

    } else {
    ftime(&start);


        for (int u = 0; u < 30; ++u) {
            begin = clock();
            printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[u], nome, 1, 0, 1);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            chronus[u] = time_spent;
        }
    ftime(&endf);
    diff = (int) (1000.0 * (endf.time - start.time)
        + (endf.millitm - start.millitm));

    printf("\nOperation took %u milliseconds\n", diff);

    ftime(&start);

        printf("Média dos tempos da busca (igual) na Arvore = %.16f \n", calcTime(chronus, SZ));

        for (int y = 0; y < 30; ++y) {
            begin = clock();
            diskHashSearch(file, y);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        }
        printf("Média dos tempos do hash(igual) = %.16f \n", calcTime(chronus, SZ));

        ftime(&endf);
    diff = (int) (1000.0 * (endf.time - start.time)
        + (endf.millitm - start.millitm));

    printf("\nOperation took %u milliseconds\n", diff);

    ftime(&start);

        for (int g = 0; g < 30; ++g) {
            //printf("\n\n\n\n\n ord\n");
            begin = clock();
            diskSequencialSearch(file, 0, 0, nome, 0, 1);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        }
        printf("Média dos tempos da busca sequential(igual) = %.16f \n", calcTime(chronus, SZ));
ftime(&endf);
    diff = (int) (1000.0 * (endf.time - start.time)
        + (endf.millitm - start.millitm));

    printf("\nOperation took %u milliseconds\n", diff);

        for (int h = 0; h < 30; ++h) {
            begin = clock();
            //printf("\n\n\n\n\n less or equal than %d\n", sorted[2]);
            printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[h], nome, 1, 4, 1);
            //printf("\n\n\n\n\n greater or equal than %d\n", sorted[2]);
            printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[h], nome, 1, 3, 1);
            //printf("\n\n\n\n\n less than %d\n", sorted[2]);
            printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[h], nome, 1, 2, 1);
            //printf("\n\n\n\n\n greater than %d\n", sorted[2]);
            printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[h], nome, 1, 1, 1);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            chronus[h] = time_spent;
        }

        printf("Média dos tempos da busca(maior menor) na Arvore = %.16f \n", calcTime(chronus, SZ));


        for (int p = 0; p < 30; ++p) {
            //printf("\n\n\n\n\n sequential\n");
        }
        //diskTreeSearch(file, tree, tree->root, (long int) &((tree->root)[g]), 0);
        //printf("\n\n\n\n\n desord\n");
        //diskTreeSearch(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), 1);


        //printf("\n\n\n\n\n hash\n");
    }

    fclose(file);


    //showHash(hash, 0);
}
