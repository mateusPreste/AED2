#ifndef DADOS_H
#define DADOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cpf;
	char nomeIn[50];
	char nomeOut[50];
	int idade;
	float salario;
} Data;

typedef struct Block{
	int cpf;
	char nomeIn[50];
	char nomeOut[50];
	int idade;
	float salario;

	struct Block* left;
	struct Block* right;
}Block;

Data* returnData(int cpf, char nomeIn[50], char nomeOut[50], int idade, float salario);

struct sequential;

int SIZE_SEQ;

void initSequential(int size);

int sequentialSearch(int list[], int size, int value);
/*
void diskSequencialSearch(FILE* file, int n)
{
	struct Block result;
	int r;

	for (int i = 0; i < SIZE_SEQ; ++i)
	{
		fseek( file, ((int) i+( n*(SIZE_SEQ) )) * sizeof( struct Block ), SEEK_SET );
		r = fread(&result, sizeof(struct Block), 1, file);
		if(r != 0){
			printf("%d\n", result.cpf);
		}
	}
}

*/
#endif
