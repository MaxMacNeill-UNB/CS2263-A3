#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "Directory.h"

void getUserInput(char *buffer, int size) 
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}
//TODO: Implement 'validateName'
bool validateName(char *name, Directory *d) {
	bool result = false;
	for(int i = 0; i < d->subdirectoryCount; i++) {
		if(strcmp(name, d->subdirectories[i]->name) == 0) result = true;
	}
	return result;
}


#endif
