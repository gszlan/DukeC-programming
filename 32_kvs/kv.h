#ifndef __KV_H__
#define __KV_H__

struct _kvpair_t { 
  char * key;
  char * value;

};
typedef struct _kvpair_t kvpair_t;

struct _kvarray_t { 
  kvpair_t ** list;
  size_t size;

};
typedef struct _kvarray_t kvarray_t;


kvarray_t * readKVs(const char * fname);

void freeKVs(kvarray_t * pairs);

void printKVs(kvarray_t * pairs);

char * lookupValue(kvarray_t * pairs, const char * key);

FILE * openFile(const char * fname, const char * flag);

void closeFile(FILE *f);

#endif
