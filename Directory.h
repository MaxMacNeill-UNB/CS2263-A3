#include <stdlib.h>
#include "File.h"

typedef struct Directory Directory;

struct Directory {
    char* name;
    Directory* parent;
    Directory** subdirectories;
    int subdirectoryCount;
    int maxSubdirectoryCount;
    File** files;
    int fileCount;
    int maxFileCount;
};

void addDir(Directory *p, Directory *c) {
    if (p->subdirectoryCount == p->maxSubdirectoryCount) {
        p->subdirectories = realloc(p->subdirectories, (sizeof(Directory*) * (p->maxSubdirectoryCount + 5)));
        p->maxSubdirectoryCount += 5;
    }
    p->subdirectoryCount += 1;

    p->subdirectories[p->subdirectoryCount] = c;
}

Directory *newDir(Directory *p, char* name) {
    Directory *ndir = malloc(sizeof(Directory));
    ndir->name = name;
    ndir->parent = p;
    ndir->subdirectories = malloc(sizeof(Directory*) * 5);
    ndir->subdirectoryCount = 0;
    ndir->maxSubdirectoryCount = 5;
    ndir->files = malloc(sizeof(File*) * 5);
    ndir->fileCount = 0;
    ndir->maxFileCount = 5;

    if (p) {
        addDir(p, ndir);
    }
}

void addFile(Directory *p, File *f) {
    if (p->fileCount == p->maxFileCount) {
        p->subdirectories = realloc(p->subdirectories, (sizeof(Directory*) * (p->maxFileCount + 5)));
        p->maxFileCount += 5;
    }
    p->fileCount += 1;

    p->files[p->fileCount] = f;
}

void listCurrentDirectory(Directory *d) {
	for(int i = 0; i < d->subdirectoryCount; i++) {
		printf("+ %s\n", d->subdirectories[i]->name);
	}
	for(int i =0; i < d->fileCount; i++) {
		printf("%s\n", d->files[i]->name);
	}
}

void freeDirectory(Directory *d) {
	for(int i = 0; i < d->subdirectoryCount; i++) {
		freeDirectory(d->subdirectories[i]);
	}
	free(d->subdirectories);
	for(int i =0; i < d->fileCount; i++) {
		freeFile(d->files[i]);
	}
	free(d->files);
	free(d->name);
	free(d);
}

//TODO: Implement changedirectory

void listDirectoryStructure(Directory *d) {
	for(int i = 0; i < d->subdirectoryCount; i++) {
		printf("dir:\t");
		printf("+ %s\n", d->subdirectories[i]->name);
		listDirectoryStructure(d->subdirectories[i]);
	}
	for(int i =0; i < d->fileCount; i++) {
		printf("%s\n", d->files[i]->name);
	}	
}
//recursive?