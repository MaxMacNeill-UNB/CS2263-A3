#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdio.h>

void getUserInput(char *buffer, int size) 
{
fgets(buffer, size, stdin);
buffer[strcspn(buffer, "\n")] = '\0';
}


#endif
