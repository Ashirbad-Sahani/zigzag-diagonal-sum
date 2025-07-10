#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prime check
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

// Function to compute zigzag sum
int compute_zigzag_sum(int** matrix, int n) {
    int sum = 0;
    for (int d = 0; d <= 2 * (n - 1); d++) {
        if (d % 2 == 0) {
            for (int i = 0; i <= d; i++) {
                int j = d - i;
                if (i < n && j < n) {
                    int val = *(*(matrix + i) + j);
                    sum += is_prime(val) ? -val : val;
                }
            }
        } else {
            for (int j = 0; j <= d; j++) {
                int i = d - j;
                if (i < n && j < n) {
                    int val = *(*(matrix + i) + j);
                    sum += is_prime(val) ? -val : val;
                }
            }
        }
    }
    return sum;
}

// Main function
int main() {
    int n = 3;
    int** matrix = (int**)malloc(n * sizeof(int*));

    int data[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = data[i][j];
        }
    }

    int result = compute_zigzag_sum(matrix, n);
    printf("Zigzag Sum: %d\n", result);

    // Free memory
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
