#include <stdio.h>
#include <stdlib.h>

void copyArray(char[10][10], char[10][10]);

void rotate(char matrix[10][10]) {

    char temp[10][10] = {0};

    for (int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            temp[y][9-x] = matrix[x][y];
        }
    }

    copyArray(temp, matrix);
}

void copyArray(char src[10][10], char dst[10][10]) {

    for(int x = 0; x < 10; x++)
        for(int y = 0; y < 10; y++)
            dst[x][y] = src[x][y];
}



void readMatrix(char matrix[10][10], char * filename) {

  FILE *f = fopen(filename, "r");
  if (f == NULL) {
      perror("Nie udalo sie otworzyc pliku");
      exit(EXIT_FAILURE);
  }

  int rows = 0;
  int columns = -1;
  char c;

  while( (c = fgetc(f)) != EOF ) { 
    columns++;
    if (c == '\n') {
        if ( columns < 9) {
            fprintf(stderr, "Wiersz %d jest za krotki\n", rows + 1);
            exit(EXIT_FAILURE);
        } else {
            columns = -1;
            rows++;
            continue;
        }
    }
    if (columns > 9) {
        fprintf(stderr,"Za duzo znakow w wierszu %d \n", rows + 1);
        exit(EXIT_FAILURE);
    }
    if (rows > 10 || (rows > 9 && columns > -1)) {
        fprintf(stderr,"Za duzo wierszy : %d\n",rows);
        exit(EXIT_FAILURE);
    }
    matrix[rows][columns] = c;
  }

  if (rows < 9) {
      fprintf(stderr,"Za malo wierszy w koncu\n");
      exit(EXIT_FAILURE);
  }
  if (columns < 9) {
      fprintf(stderr, "Za krotki wiersz w koncu\n");
      exit(EXIT_FAILURE);
  }
  if (fclose(f)) {
      perror("Nie udalo sie zamknac pliku");
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
