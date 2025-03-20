#include "filesystem.h"

Directory* createDirectory(Directory *parent, const char *name) 
{
Directory *newDir = (Directory *)malloc(sizeof(Directory));
if (!newDir) 
{
printf("Memory allocation failed\n");
return NULL;
}
strcpy(newDir->name, name);
newDir->parent = parent;
newDir->subdirs = NULL;
newDir->files = NULL;
newDir->next = NULL;
if (parent) 
{
newDir->next = parent->subdirs;
parent->subdirs = newDir;
}
return newDir;
}
File* createFile(Directory *parent, const char *name, int size) 
{
if (!parent) 
{
printf("Error: Parent directory not found\n");
return NULL;
}
File *newFile = (File *)malloc(sizeof(File));
if (!newFile) 
{
printf("Memory allocation failed\n");
return NULL;
}
strcpy(newFile->name, name);
newFile->size = size;
newFile->next = parent->files;
parent->files = newFile;
return newFile;
}
void listDirectory(Directory *dir, int depth) 
{
if (!dir) return;
for (int i = 0; i < depth; i++) printf("  ");
printf("[Dir] %s\n", dir->name);
File *file = dir->files;
while (file) {
for (int i = 0; i < depth + 1; i++) printf("  ");
printf("- %s (%d bytes)\n", file->name, file->size);
file = file->next;
}
Directory *subdir = dir->subdirs;
while (subdir) 
{
listDirectory(subdir, depth + 1);
subdir = subdir->next;
}
}
void freeDirectory(Directory *dir) 
{
if (!dir) return;
File *file = dir->files;
while (file) 
{
File *temp = file;
file = file->next;
free(temp);
}
Directory *subdir = dir->subdirs;
while (subdir) 
{
Directory *temp = subdir;
subdir = subdir->next;
freeDirectory(temp);
}
free(dir);
}
