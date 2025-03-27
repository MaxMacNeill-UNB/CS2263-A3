#ifndef UTILS_H
#define UTILS_H

#include "File.h"
#include "Directory.h"

void getUserInput(char *buffer, int size);
int validateName(const char *name, Directory *parent);

#endif
