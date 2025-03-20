#include <sdtlib.h>
#include "Directory.h"

typedef struct {
	char *name;
	Directory root;
	char *contents;
	
} File;
