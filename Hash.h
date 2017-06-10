
#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"

// const int SIZE = 2000;
#define SIZE 2000

typedef struct
{
	int cpf;
	char nomeIn[50];
	char nomeOut[50];
	int idade;
	float salario;
	char valid;
} Line;

typedef struct
{
	Line* Table[SIZE];
} Hash;

typedef struct Right
{
	struct Right* next;
	Data* data;
}Right;







void initHash(Hash* hash);

int hashFunction(int value);

void showHash(Hash* hash, int pos);

void insertHash(Hash* hash, Data* data, int key);

/*
void insertHashCol(Hash* hash, Data* data, int key)
{
	int pos = hashFunction(key);

	if(INIT)
	{
		init(hash);
		INIT = 0;
	}

	if( ((hash->Table)[pos])->valid == 0 ){
		((hash->Table)[pos])->data = data;
		((hash->Table)[pos])->valid = 1;
	} else{
		Right* thisRight = (Right*) malloc(sizeof(Right));
			thisRight->data = data;
			thisRight->next = NULL;

		if(!((hash->Table)[pos])->right)
		{
			((hash->Table)[pos])->right = thisRight;
		}
		else
		{
			Right* tail = ((hash->Table)[pos])->right;
			while(tail->next){
				tail = tail->next;
			}
			tail->next = thisRight;
		}
	}
}
*/
#endif
