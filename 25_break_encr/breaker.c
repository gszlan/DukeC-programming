#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void otworzPlik(char * filename, FILE ** f) {

    *f = fopen(filename,"r");
    if (f == NULL) {
        fprintf(stderr,"Incorrect file\n");
        exit(EXIT_FAILURE);
    }
}



void wczytajPlik(FILE *f, int *arr) {

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

void policzCzestotliwosc(int * arr1, double * arr2) {
    
    int total = 0;

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

int znajdzKlucz(double * arr1) {

    int mostFreqIndex = 0;
    double mostFreqValue = arr1[0];
    for(int i = 1; i < 26; i++) {
        if (arr1[i] > mostFreqValue) {
            mostFreqIndex = i;
            mostFreqValue = arr1[i];
        }
    }

    if(mostFreqValue < 0.11) {
        fprintf(stderr,"Cound not find the key!\n");
        exit(EXIT_FAILURE);
    }

    int key = mostFreqIndex - 4;
    return (key < 0) ? (key + 26) : key; 
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Valid format is as follows: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *f;
    otworzPlik(argv[1],&f);

    int letters[26] = {0};
    wczytajPlik(f, letters);

    double frequency[26] = {0};
    policzCzestotliwosc(letters, frequency);

    znajdzKlucz(frequency);

    return 0;
}



