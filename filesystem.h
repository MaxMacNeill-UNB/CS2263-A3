#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File 
{
char name[100];
int size;
struct File *next;
} 
File;
typedef struct Directory 
{
char name[100];
struct Directory *parent;
struct Directory *subdirs;  
struct Directory *next;     
struct File *files;         
} 
Directory;

Directory* createDirectory(Directory *parent, const char *name);
File* createFile(Directory *parent, const char *name, int size);
void listDirectory(Directory *dir, int depth);
Directory* searchDirectory(Directory *dir, const char *name);
void freeDirectory(Directory *dir);

#endif
