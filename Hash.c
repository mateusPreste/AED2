#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"



/*
typedef struct
{
	char valid;
	Data* data;
	Right* right;
} Line;
*/


void initHash(Hash* hash)
{
	Line* pos;
	for (int i = 0; i < SIZE; ++i)
	{
		Line* line = (Line*) malloc(sizeof(Line));
			line->valid = 0;
		((hash->Table)[i]) = line;

	}
}

int hashFunction(int value)
{
	return value % SIZE;
}

void showHash(Hash* hash, int pos)
{
	Line* line = (hash->Table)[pos];
	if(line->valid)
	{
		// printf("%d %x\n", line->cpf, (hash->Table)[pos]);

		pos += 1;
		if(pos < SIZE)  showHash(hash, pos);
	}
}

void insertHash(Hash* hash, Data* data, int key)
{
	int pos = hashFunction(key);

	if( ((hash->Table)[pos])->valid == 0 ){
		((hash->Table)[pos])->cpf = data->cpf;
		strcpy(((hash->Table)[pos])->nomeIn, data->nomeIn);
		strcpy(((hash->Table)[pos])->nomeOut, data->nomeOut);
		((hash->Table)[pos])->idade = data->idade;
		((hash->Table)[pos])->salario = data->salario;
		((hash->Table)[pos])->valid = 1;
	}
}

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
