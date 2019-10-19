#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE * f = openFile(filename, "r");
  counts_t * counts = createCounts();
  char *line = NULL;
  size_t len = 0;
  size_t nread = 0;
  while((nread = getline(&line, &len, f)) != -1) {
      line[nread - 1] = '\0';
      addCount(counts, lookupValue(kvPairs, line));
  }
  free(line);
  closeFile(f);
  return counts;
}

int main(int argc, char ** argv) {

 if (argc < 3) {
     printf("Podaj przynajmniej 2 pliki a jest %d\n",argc);
     exit(EXIT_FAILURE);
 }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
 kvarray_t * kv = readKVs(argv[1]); 

 //count from 2 to argc (call the number you count i)
 for (int i = 2; i < argc; i++ ) {

    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);

    //compute the output file name from argv[i] (call this outName)
    char * outName = NULL;
    if ((outName = calloc(sizeof(* outName), strlen(argv[i]) + 7)) == NULL) {
        printf("Nie moge zaalokowac pamiec dla nowej nazwy pliku\n");
        exit(EXIT_FAILURE);
    }
    strncpy(outName, argv[i],strlen(argv[i]));
    strcat(outName,".count");

    //open the file named by outName (call that f)
    FILE * f = openFile(outName, "w");

    //print the counts from c into the FILE f
    printCounts(c, f);

    //close f
    closeFile(f);

    //free the memory for outName and c
    free(outName);
    freeCounts(c);
 }

 //free the memory for kv
 freeKVs(kv);

  return EXIT_SUCCESS;
}
