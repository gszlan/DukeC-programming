#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

void otworzPlik(char * filename, FILE ** f) {

    *f = fopen(filename,"r");
    if (f == NULL) {
        fprintf(stderr,"Incorrect file\n");
        exit(EXIT_FAILURE);
    }
}


void wczytajPlik(FILE *f, uint64_t *arr) {

    int letter;

    while ((letter = fgetc(f)) != EOF) {
        letter = tolower(letter);
        if (isalpha(letter)) {
            arr[letter - 'a'] += 1;
        }
    }
    if (!feof(f))
        perror("Blad odczytu pliku");
}


void policzCzestotliwosc(uint64_t * arr1, double * arr2) {
    
    uint64_t total = 0;

    for (int i =0; i < 26; i++) {
        total += arr1[i];
    }

    if (total == 0) {
        fprintf(stderr,"File is empty\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 26; i++) {
        arr2[i] = (double) arr1[i] / total;
    }
}

void znajdzKlucz(uint64_t * arr1) {

    int  mostFreqIndex = 0;
    uint64_t mostFreqValue = arr1[0];
    for(int i = 1; i < 26; i++) {
        if (arr1[i] > mostFreqValue) {
            mostFreqIndex = i;
            mostFreqValue = arr1[i];
        }
    }

    //if(mostFreqValue < 0.12) {
    //    fprintf(stderr,"Cound not find the key!\n");
    //    exit(EXIT_FAILURE);
    //}

    int key = mostFreqIndex - 4;
    key = (key < 0) ? (key + 26) : key; 
    printf("%d\n",key);
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Valid format is as follows: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *f;
    otworzPlik(argv[1],&f);

    uint64_t letters[26] = {0};
    wczytajPlik(f, letters);

    //double frequency[26] = {0};
    //policzCzestotliwosc(letters, frequency);

    znajdzKlucz(letters);

    return 0;
}



