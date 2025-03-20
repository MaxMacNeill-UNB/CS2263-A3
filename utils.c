#include "utils.h"
void getUserInput(char *buffer, int size) 
{
fgets(buffer, size, stdin);
buffer[strcspn(buffer, "\n")] = '\0';
}
int validateName(const char *name, Directory *parent) 
{
if (!parent) return 1;
File *file = parent->files;
while (file) 
{
if (strcmp(file->name, name) == 0) return 0;
file = file->next;
}
Directory *subdir = parent->subdirs;
while (subdir) 
{
if (strcmp(subdir->name, name) == 0) return 0;
subdir = subdir->next;
}
return 1;
}
