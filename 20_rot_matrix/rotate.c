
void copyArray(char[10][10], char[10][10]);


void rotate(char matrix[10][10]) {

    char temp[10][10] = {0};

    for (int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            temp[y][9-x] = matrix[x][y];
        }
    }

    copyArray(temp, matrix);
}

void copyArray(char src[10][10], char dst[10][10]) {

    for(int x = 0; x < 10; x++)
        for(int y = 0; y < 10; y++)
            dst[x][y] = src[x][y];
}



