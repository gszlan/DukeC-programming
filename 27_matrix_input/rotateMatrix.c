#include <stdio.h>
#include <stdlib.h>

void copyArray(char src[10][10], char dst[10][10]) {

    for(int x = 0; x < 10; x++)
        for(int y = 0; y < 10; y++)
            dst[x][y] = src[x][y];
}


void rotate(char matrix[10][10]) {

    char temp[10][10] = {0};

    for (int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            temp[y][9-x] = matrix[x][y];
        }
    }

    copyArray(temp, matrix);
}


void printError(char * str, FILE * f) {

  fprintf(stderr,"%s", str);
  fclose(f);
  exit(EXIT_FAILURE);
}


void readMatrix(char matrix[10][10], char * filename) {

  FILE *f = fopen(filename, "r");
  if (f == NULL) {
      perror("Nie udalo sie otworzyc pliku");
      exit(EXIT_FAILURE);
  }

  int rows = 0;
  int columns = 0;
  char c;

  while( ((c = fgetc(f)) != EOF) || !feof(f)) { 
    if (c == '\n') {
        if ( columns < 10) {
            printError("Wiersz jest za krotki \n", f);
        } else {
            columns = 0;
            rows++;
            continue;
        }
    }
    if (columns > 9) {
        printError("Za duzo znakow w wierszu \n", f);
    }
    if (rows > 10 || (rows > 9 && columns > 0)) {
        printError("Za duzo wierszy", f);
    }
    matrix[rows][columns] = c;
    columns++;
  }

  if (rows < 10) {
      printError("Za malo wierszy w koncu\n", f);
  }
  if (columns != 0) {
      printError("Za krotki wiesz w koncu\n", f);
  }
  if (fclose(f)) {
      perror("Nie udalo sie zamknac pliku\n");
      exit(EXIT_FAILURE);
  }
}


void printMatrix(char matrix[10][10]) {

  for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
          printf("%c",matrix[i][j]);
      }
      printf("\n");
  }
}


int main(int argc, char** argv) {

  if (argc != 2) {
      fprintf(stderr,"Invalid number of arguments\n");
      exit(EXIT_FAILURE);
  }

  char matrix[10][10];
  
  readMatrix(matrix, argv[1]);
  rotate(matrix);
  printMatrix(matrix);

  return(EXIT_SUCCESS);

}
