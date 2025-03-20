#include <stdlib.h>
#include "File.h"

typedef struct Directory Directory;

struct Directory {
    Directory* parent;
    Directory** subdirectories;
    int subdirectoryCount;
    int maxSubdirectoryCount;
    File** files;
    int fileCount;
    int maxFileCount;
};

Directory *newDir(Directory *p) {
    Directory *ndir = malloc(sizeof(Directory));
    ndir->parent = p;
    ndir->subdirectories = malloc(sizeof(*Directory) * 5);
    ndir->subdirectoryCount = 0;
    ndir->maxSubdirectoryCount = 5;
    ndir->files = malloc(sizeof(*File) * 5);
    ndir->fileCount = 0;
    ndir->maxFileCount = 5;
}
