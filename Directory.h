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

    addDir(p, ndir);
}

void addDir(Directory *p, Directory *c) {
    if (p->subdirectoryCount == p->maxSubdirectoryCount) {
        p->subdirectories = realloc(p->subdirectories, (sizeof(Directory*) * (p->maxSubdirectoryCount + 5)));
        p->maxSubdirectoryCount += 5;
    }
    p->subdirectoryCount += 1;

    p->subdirectories[p->subdirectoryCount] = c;
}

void addFile(Directory *p, File *f) {
    if (p->fileCount == p->maxFileCount) {
        p->subdirectories = realloc(p->subdirectories, (sizeof(Directory*) * (p->maxFileCount + 5)));
        p->maxFileCount += 5;
    }
    p->fileCount += 1;

    p->subdirectories[p->fileCount] = f;
}