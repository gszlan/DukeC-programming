#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct strings_type {
    char ** strings;
    size_t count;
};

typedef struct strings_type strings_t;


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}


FILE * openFile(char * name) {

  FILE * f; 
  if ((f = fopen(name,"r"))  == NULL) {
      perror("Blad otwarcia pliku");
      exit(EXIT_FAILURE);
  }
  return f;
}

strings_t * readFile(FILE *f) {

  strings_t * tmp = malloc(sizeof(strings_t)); 
  tmp->count = 0;
  tmp->strings = NULL;
  char * line = NULL;
  size_t len = 0;

  while (getline(&line, &len, f) != -1) {
      tmp->strings = realloc(tmp->strings, sizeof(char *) * (tmp->count + 1));
      tmp->strings[tmp->count] = line;
      line = NULL;
      (tmp->count)++;
  }
  free(line);
  return tmp;
}


void printData(char ** data, size_t count) {

  for(int i = 0; i < count; i++) {
    printf("%s",data[i]);
    free(data[i]);
  }
  free(data);
}


int main(int argc, char ** argv) {
  
  FILE * f;
  strings_t * strings;

  if (argc == 1) {
      strings = readFile(stdin);
      sortData(strings->strings, strings->count);
      printData(strings->strings, strings->count);
      free(strings);
  } else {
      for (int i = 1; i < argc; i++) {
          f = openFile(argv[i]);
          strings = readFile(f);
          sortData(strings->strings, strings->count);
          printData(strings->strings, strings->count);
          free(strings);
          fclose(f);
      }
  }
  return EXIT_SUCCESS;
}
