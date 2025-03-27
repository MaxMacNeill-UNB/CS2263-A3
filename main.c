#include "utils.h"

#include <stdio.h>

int main() {
  Directory * root = newDir(NULL, "root");
  int choice;
  char name[100];
  int size;
  Directory * currentDir = root;
  while (1) {
    printf("\n--- File System Menu ---\n");
    printf("1. Create Directory\n");
    printf("2. Create File\n");
    printf("3. List Directory Structure\n");
	printf("4. List Current Directory\n");
	printf("5. Change Current Directory\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", & choice);
    getchar();
    switch (choice) {
    case 1:
      printf("Enter directory name: ");
      getUserInput(name, 100);
      if (validateName(name, currentDir)) {
        newDir(currentDir, name);
      } else {
        printf("Error: Name already exists.\n");
      }
      break;
    case 2:
      File *f = createFile();
      addFile(currentDir, f);
      printf("Added file");
      break;
    case 3:
      printf("\nDirectory Structure:\n");
      listDirectoryStructure(root);
      break;
	case 4:
		listCurrentDirectory(currentDir);
	
		break;
	case 5: 
		printf("Enter a '.' to go return to the parent directory\n");
		printf("Enter the name of the subdirectory you wish to change to: ");
		
		//TODO
		
	
		break;
    case 6:
      freeDirectory(root);
      printf("Exiting program...\n");
      return 0;
    default:
      printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}