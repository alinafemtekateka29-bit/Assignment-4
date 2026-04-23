#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_seat(int **seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%02d", seat[i][j]);
            if (j < col - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    // 1. Dynamically allocate 10x10 integer array
    int rows = 10, cols = 10;
    int **seat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        seat[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize whole array to 0 using memset
    for (int i = 0; i < rows; i++) {
        memset(seat[i], 0, cols * sizeof(int));
    }

    // Assign given values
    seat[0][0] = 11;
    seat[0][3] = 24;
    seat[1][1] = 35;
    seat[2][5] = 47;
    seat[3][3] = 58;
    seat[4][9] = 69;
    seat[5][0] = 70;
    seat[5][5] = 81;
    seat[5][9] = 92;
    seat[6][4] = 13;
    seat[7][7] = 26;
    seat[8][2] = 39;
    seat[9][9] = 44;

    printf("Original Seat Map\n");
    print_seat(seat, rows, cols);
    printf("\n");

    // 3. Create backup and copy using memcpy row by row
    int **backup = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        backup[i] = (int *)malloc(cols * sizeof(int));
        memcpy(backup[i], seat[i], cols * sizeof(int));
    }

    printf("Backup Seat Map\n");
    print_seat(backup, rows, cols);
    printf("\n");

    // 4. Clear row 5 (index 5) in original seat map only
    memset(seat[5], 0, cols * sizeof(int));

    printf("Original Seat Map After Clearing Row 5\n");
    print_seat(seat, rows, cols);
    printf("\n");

    printf("Backup Seat Map After Original Was Modified\n");
    print_seat(backup, rows, cols);
    printf("\n");

    // 5. Find row with largest number of assigned seats in backup
    int max_count = -1;
    int best_row = -1;
    for (int i = 0; i < rows; i++) {
        int count = 0;
        for (int j = 0; j < cols; j++) {
            if (backup[i][j] != 0) count++;
        }
        if (count > max_count) {
            max_count = count;
            best_row = i;
        }
    }

    printf("Row With Most Assigned Seats\n");
    printf("Row: %d\n", best_row);
    printf("Count: %d\n", max_count);

    // Free all allocated memory
    for (int i = 0; i < rows; i++) {
        free(seat[i]);
        free(backup[i]);
    }
    free(seat);
    free(backup);

    return 0;
}