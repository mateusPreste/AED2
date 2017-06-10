#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"


Data* returnData(int cpf, char nomeIn[50], char nomeOut[50], int idade, float salario){
	Data* data = (Data*) malloc (sizeof(Data));
		data->cpf = cpf;
		strcpy(data->nomeIn, nomeIn);
		strcpy(data->nomeOut, nomeOut);
		data->idade = idade;
		data->salario = salario;
	return data;
}

struct sequential
{
	struct Block* init;
};


void initSequential(int size)
{
	SIZE_SEQ = size;
}

int sequentialSearch(int list[], int size, int value){
	for (int i = 0; i < size; ++i)
	{
		if(list[size] == value){
			return 1;
		}
	}
	return 0;
}
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
