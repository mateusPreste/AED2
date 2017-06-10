#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"
#include "Hash.h"

const int SIZE_MAIN = 100;


void diskHashSearch(FILE* file, int n)
{
	Line result;
	int r;

	for (int i = 0; i < SIZE_MAIN; ++i)
	{
		fseek( file, ( ( n*(SIZE_MAIN) ) * sizeof(struct Block)) + (i*sizeof(Line)), SEEK_SET );
		r = (int) fread(&result, sizeof(Line), 1, file);
		if(r != 0){
			printf("%d\n", result.cpf);
		}
	}
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


int main()
{
	srand((unsigned int) time(NULL));
	int randomNumber;

	Hash* hash = (Hash*) malloc(sizeof(Hash));

	Tree* tree = (Tree*) malloc(sizeof(Tree));
	Tree* ordTree = (Tree*) malloc(sizeof(Tree));

	initHash(hash);
	initTree(SIZE_MAIN);
	initSequential(SIZE_MAIN);

	tree->root = NULL;
	ordTree->root = NULL;
	char nome[50];
	char* pal = (char*) malloc(sizeof(49));
	rand_str(pal, 50);

	strncpy(nome, pal, sizeof nome - 1);
	nome[49] = '\0';
	char sNome[50] = "b";
	Data* data= returnData(1232, nome, sNome, 30, 2.3);

	printf("%lu\n", (long int) &initialBlock[0]);
	printf("%lu\n", (long int) sizeof(Block));

	for (int i = 0; i < SIZE_MAIN; ++i)
	{
		rand_str(pal, 50);
		strncpy(nome, pal, sizeof nome - 1);

		rand_str(pal, 50);
		strncpy(sNome, pal, sizeof nome - 1);

		randomNumber = rand();
		data = returnData(i, nome, sNome, 30, 2.3);
		insertTree(tree, data, i);
		printf("\nadd: %lu\n", ( ((long int)(&initialBlock[i]) - (long int) &initialBlock[0])/(sizeof(Block))));
		insertHash(hash, data, i);
	}

	int sorted[SIZE_MAIN];
	initTree(SIZE_MAIN);
	for (int i = 0; i < SIZE_MAIN; ++i)
	{
		randomNumber = rand()%(SIZE_MAIN*8);
		while(sequentialSearch(sorted, SIZE_MAIN, randomNumber)){
			randomNumber = rand()%(SIZE_MAIN*8);
		}

		sorted[i] = randomNumber;
		data = returnData(i, nome, sNome, 30, 2.3);
		insertTree(ordTree, returnData(randomNumber, nome, sNome, 30, 2.3), i);
	}

	showTree(tree->root);
	showHash(hash, 0);


	FILE *file;



	//(*(&bigTest+sizeof(struct Test)))->value = 5;
	//printf("\n%d", (*(&bigTest+sizeof(struct Test)))->value);

	if( (file = fopen("file.bin", "wb") )== NULL){

	} else{
		int i;
		//sequential
		for ( i = 0; i < SIZE_MAIN; ++i ) {
			struct Block *TreeTest = tree->root;
			fwrite( &TreeTest[i], sizeof( struct Block ), 1, file );
		}
		//random
		for ( i = 0; i < SIZE_MAIN; ++i ) {
			struct Block *teste = ordTree->root;
			fwrite( &teste[i], sizeof( struct Block ), 1, file );
		}
		//hash
		for ( i = 0; i < SIZE_MAIN; ++i ) {
			Line *teste = (hash->Table)[i];
			printf("\n aaa: %d", teste->cpf);
			fwrite( teste, sizeof( Line ), 1, file );
		}
	}

	fclose(file);

	printf("\n\n\n\n\n");
	struct Block result;
	int r;

	if( (file = fopen("file.bin", "rb")) == NULL){

	}else{

	}
	printf("\n\n\n\n\n show\n");
	diskTreeSearch(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), 1);
	printf("\n\n\n\n\n ord\n");
	diskTreeSearch(file, tree, tree->root, (long int) &((tree->root)[0]), 0);
	printf("\n\n\n\n\n sequential\n");
	diskSequencialSearch(file, 0, 0, nome, 1, 1);
	printf("\n\n\n\n\n greater than %d\n", sorted[2]);
	printTree(file, ordTree, ordTree->root, (long int) &((ordTree->root)[0]), sorted[2], nome, 1, 3, 1);
	printf("\n\n\n\n\n hash\n");
	diskHashSearch(file, 2);

	fclose(file);


	//showHash(hash, 0);
}
