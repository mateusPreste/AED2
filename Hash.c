#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

int COLISION = 0; //save position in the error space

void initHash(Hash *hash) {
    for (int i = 0; i < SIZE; ++i) {
        Line *line = (Line *) malloc(sizeof(Line));
        line->valid = 0;
        ((hash->Table)[i]) = line;
    }
}

int hashFunction(int value) {
    return value % SIZE;
}

//deprecated
void showHash(Hash *hash, int pos) {
    Line *line = (hash->Table)[pos];
    if (line->valid) {
        pos += 1;
        if (pos < SIZE) showHash(hash, pos);
    }
}

void insertHash(Hash *hash, Data *data, int key) {
    int pos = hashFunction(key);
    Line *thisHash = ((hash->Table)[pos]);

    if (thisHash->valid == 0) {
        thisHash->cpf = data->cpf;
        strcpy(thisHash->nomeIn, data->nomeIn);
        strcpy(thisHash->nomeOut, data->nomeOut);
        thisHash->idade = data->idade;
        thisHash->salario = data->salario;
        thisHash->valid = 1;
    } else{
        thisHash = ((hash->Table)[SIZE+COLISION]);
        for (int i = 0; i < SIZE_3; ++i) {
            if(thisHash->valid == 0){
                thisHash->cpf = data->cpf;
                strcpy(thisHash->nomeIn, data->nomeIn);
                strcpy(thisHash->nomeOut, data->nomeOut);
                thisHash->idade = data->idade;
                thisHash->salario = data->salario;
                thisHash->valid = 1;
                return;
            } else{
                COLISION++;
                thisHash = ((hash->Table)[SIZE+COLISION]);
            }

        }
        printf("ERROR ON HASH CLOSING THE PROGRAM\n");
        exit(0);
    }
}

int searchHash(Hash *hash, int cpf) {
    int pos = hashFunction(cpf);
    Line *thisHash = ((hash->Table)[pos]);

    if (thisHash->cpf == cpf) {
        return pos;
    } else{
        thisHash = ((hash->Table)[SIZE+COLISION]);
        for (int i = 0; i < SIZE_3; ++i) {
            if(thisHash->valid == 0){
                return SIZE+COLISION;
            }
            else{
                COLISION++;
                thisHash = ((hash->Table)[SIZE+COLISION]);
            }
        }
        return -1;
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
