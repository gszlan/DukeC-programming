#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {

  char * ptr = malloc(sizeof(*ptr) * (strlen(inputName) + 8));
  strcpy(ptr, inputName);
  strcat(ptr, ".counts");
  return ptr;
}
