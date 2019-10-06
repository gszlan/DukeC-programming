#include <stdio.h>
#include <stdlib.h>

void rotate(char array[10][10]);

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
            fprintf(stderr, "Row %d is to short\n", rows + 1);
            exit(EXIT_FAILURE);
        } else {
            columns = -1;
            rows++;
            continue;
        }
    }
    if (columns > 9) {
        fprintf(stderr,"Too many chars in row %d \n", rows + 1);
        exit(EXIT_FAILURE);
    }
    if (rows > 10 || (rows > 9 && columns > -1)) {
        fprintf(stderr,"Too many rows: %d\n",rows);
        exit(EXIT_FAILURE);
    }
    matrix[rows][columns] = c;
  }

  if (rows < 9) {
      fprintf(stderr,"Not enought rows\n");
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
