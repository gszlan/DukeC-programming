#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


FILE * openFile(const char * fname) {

  FILE * f;  
  if ((f = fopen(fname, "r")) == NULL) {
      perror("Nie moge otworzycc pliku");
      exit(EXIT_FAILURE);
  }
  return f;

}

void closeFile(FILE * f) {

  if (fclose(f)) {
      perror("Nie moge zamknac pliku\n");
      exit(EXIT_FAILURE);
  }
}

kvpair_t * readValues(char * line) {

    size_t len = strlen(line);
    char * ptr = index(line, '=');
    if (ptr == NULL) { 
        return NULL;
    }

    kvpair_t *pair;
    if ((pair = malloc(sizeof(*pair))) == NULL) {
        perror("Nie moge zaalokowac pamieci na kvpair");
        exit(EXIT_FAILURE);
    }
    size_t keyLen = ptr - line;
    if ((pair->key = calloc(keyLen + 1, sizeof(*pair->key))) == NULL) {
        perror("Nie moge zaalokowac pamieci na key");
        exit(EXIT_FAILURE);
    }
    size_t valueLen = len - keyLen - 1;
    if ((pair->value = calloc(valueLen + 1, sizeof(*pair->value))) == NULL) {
        perror("Nie moge zaalokowac pamieci na value");
        exit(EXIT_FAILURE);
    }
    strncpy(pair->key, line, keyLen);
    strncpy(pair->value, ++ptr, valueLen);
    return pair;
}


void addPair(kvarray_t *array, kvpair_t * pair) {

    array->list = realloc(array->list, sizeof(*array->list) * (array->size + 1));
    array->list[array->size] = pair;
    array->size = array->size + 1;
}

kvarray_t * readKVs(const char * fname) {
  
  FILE * f = openFile(fname);
  
  char *line = NULL;
  size_t len = 0;
  size_t nread;
  kvpair_t *pair = NULL;
  kvarray_t *kvarray = NULL;

  if ((kvarray = malloc(sizeof(*kvarray))) == NULL) {
      perror("Nie moge zaalokowac pamieci");
      exit(EXIT_FAILURE);
  }
  kvarray->list = NULL;
  kvarray->size = 0;
  while((nread = getline(&line, &len, f)) != -1) {
    if ((pair = readValues(line)) != NULL) {
        addPair(kvarray,pair);
    }
  }
  free(line);

  closeFile(f);
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {

    for(int i = 0; i < pairs->size; i++) {
        //free(pairs->list[i].key);
        //free(pairs->list[i].value);
        free(pairs->list[i]->key);
        free(pairs->list[i]->value);
        free(pairs->list[i]);
    }
    free(pairs->list);
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
