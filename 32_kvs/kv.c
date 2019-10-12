#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


void openFile(FILE * f, static char * fname) {

  if ((f = fopen(fname, "r")) == NULL) {
      perror("Nie moge otworzycc pliku");
      exit(EXIT_FAILURE);
  }
}

void closeFile(FILE * f) {

  if (fclose(f)) {
      perror("Nie moge zamknac pliku\n");
      exit(EXIT_FAILURE);
  }
}


kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f;
  openFile(f, fname);
  // readfile
  closeFile(f);
}

void freeKVs(kvarray_t * pairs) {

    for(int i = 0; i < pairs->size; i++) {
        free(pairs->list[i]->key;
        free(pairs->list[i]->value;
        free(pairs->list[i];
    }
    free(pairs);
}

void printKVs(kvarray_t * pairs) {

    for(int i = 0; i < pairs->size; i++) {
        printf("key = '%s' value = '%s'\n",pairs->list[i]->key, pairs->list[i]->value);
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {

    for(int i = 0; i < pairs->size; i++) {
        if (!strncmp(pairs->list[i]->key, key, strlen(pairs->list[i]->key)))
            return pairs->list[i]->value;
    }
 
    return NULL;
}
