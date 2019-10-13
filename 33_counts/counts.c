#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {

    counts_t * counter = malloc(sizeof( *counter));
    counter->list = NULL;
    counter->size = 0;
    counter->unknown = 0;
    return counter;
}
void addCount(counts_t * c, const char * name) {

    if (name == NULL) {
        (c->unknown)++;
        return;
    }

    int found = 0;
    for (int i = 0; i < c->size; i++) {
        if (!strncmp(c->list[i]->key, name, strlen(name))) {
            (c->list[i]->count)++;
            found = 1;
        }
    }
    if (!found) {
        c->list = realloc(c->list, sizeof(*c->list) * (c->size + 1));
        c->list[c->size] = malloc(sizeof(**c->list));
        c->list[c->size]->key = name;
        c->list[c->size]->count = 1;
       (c->size)++; 
    }
}
void printCounts(counts_t * c, FILE * outFile) {

    for(int i = 0; i < c->size; i++) {
       fprintf(outFile, "%s: %lu\n",c->list[i]->key, c->list[i]->count); 
    }
    if (c->unknown) {
        fprintf(outFile, "<unknown> : %lu\n", c->unknown);
    }
}

void freeCounts(counts_t * c) {

    for(int i = 0; i < c->size; i++) {
        free(c->list[i]);
    }
    free(c->list);
    free(c);
}

