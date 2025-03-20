#include <stdlib.h>
#include <string.h>

typedef struct File File;

struct File {
	char *name;
	char *contents;
	int size;
	char *dateModified;
	char *dateCreated;
};

File *constructFile(char *nameIn, char *contentsIn, int sizeIn, char *dateIn) {
	File *f = malloc(sizeof(File));
	
	f->name = malloc(sizeof(nameIn));
	f->contents = malloc(sizeof(contentsIn));
	f->dateModified = malloc(sizeof(dateIn));
	
	f->name = strdup(nameIn);
	f->contents = strdup(contentsIn);
	f->dateCreated = strdup(dateIn);
	f->dateModified = NULL;
	f->size = sizeIn;
	
	return f;
}

void destructFile(File *f) {
	free(f->name);
	free(f->contents);
	free(f->dateModified);
	free(f);
}

int *renameFile(File *file, char *nameIn) {
	int *result = realloc(file->name, sizeof(nameIn));
	file->name = strdup(nameIn);
	return result;
}

int *changeFileContents(File *file, char *contentsIn, char *dateIn) {
	free(file->contents);
	file->contents = strdup(contentsIn);
	
	free(file->dateModified);
	file->dateModified = strdup(dateIn);
}



