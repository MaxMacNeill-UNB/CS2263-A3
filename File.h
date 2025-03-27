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

File *constructFile(char *nameIn, char *contentsIn, char *dateIn) {
	File *f = malloc(sizeof(File));
	
	f->name = strdup(nameIn);
	f->contents = strdup(contentsIn);
	f->dateCreated = strdup(dateIn);
	f->dateModified = NULL;
	f->size = sizeof(f->contents);
	
	return f;
}

void freeFile(File *f) {
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

//ask the user for input to create the file
File *createFile() {
	char *name = malloc(1000);
	char *contents = malloc(1000000);
	char *date = malloc(sizeof(char) * 10);
	
	printf("Please enter the name of the file: ");
	scanf("%s", &name);
	
	printf("Please enter the contents of the file: ");
	scanf("%s", &contents);
	
	printf("Please enter the current date (YYYY-MM-DD): ");
	scanf("%s", &date);
	
	return constructFile(name, contents, date);

	free(name);
	free(contents);
	free(date);
}



