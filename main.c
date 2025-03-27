#include "utils.h"

#include "File.h"

#include "Directory.h"

#include <stdio.h>

int main() {
  Directory * root = createDirectory(NULL, "root");
  int choice;
  char name[100];
  int size;
  Directory * currentDir = root;
  while (1) {
    printf("\n--- File System Menu ---\n");
    printf("1. Create Directory\n");
    printf("2. Create File\n");
    printf("3. List Directory\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", & choice);
    getchar();
    switch (choice) {
    case 1:
      printf("Enter directory name: ");
      getUserInput(name, 100);
      if (validateName(name, currentDir)) {
        createDirectory(currentDir, name);
      } else {
        printf("Error: Name already exists.\n");
      }
      break;
    case 2:
      printf("Enter file name: ");
      getUserInput(name, 100);
      if (validateName(name, currentDir)) {
        printf("Enter file size: ");
        scanf("%d", & size);
        getchar();
        createFile(currentDir, name, size);
      } else {
        printf("Error: Name already exists.\n");
      }
      break;
    case 3:
      printf("\nDirectory Structure:\n");
      listDirectory(root, 0);
      break;
    case 4:
      freeDirectory(root);
      printf("Exiting program...\n");
      return 0;
    default:
      printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}