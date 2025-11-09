#include <stdio.h>

int main() {
    // Define the size of the matrix
    int rows = 4;
    int columns = 5;

    // Initial matrix
    int matriz[4][5] = {
        {280, 290, 310, 350, 360},
        {295, 305, 320, 370, 390},
        {300, 315, 340, 385, 395},
        {276, 330, 355, 380, 396}
    };

    int transposedM[5][4]; // Since it is tranposed the size is inverted

    // Show the initial matrix
    printf("Initial matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposedM[j][i] = matriz[i][j];
        }
    }

    // Show the transpose matrix
    printf("\nTransposed matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transposedM[i][j]);
        }
        printf("\n");
    }

    return 0;
}
