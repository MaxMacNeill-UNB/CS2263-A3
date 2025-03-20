#include <sdtlib.h>
#include "Directory.h"

typedef struct {
	char *name;
	char *contents;
	int size;
	char *dateModified;
	char *dateCreated;
	
} File;
