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

void renameFile(File *file, char *nameIn) {
	realloc(file->name, sizeof(nameIn));
	file->name = strdup(nameIn);
}

void changeContents(File *file, char *contentsIn, char *dateIn) {
	realloc(file->contents, sizeof(contentsIn));
	file->contents = strdup(contentsIn);
	realloc(file->dateModified, sizeof(dateIn));
	file->dateModified = strdup(dateIn);
}



