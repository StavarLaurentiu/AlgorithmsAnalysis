#include <stdio.h>

#define MAX_DIM 1001 

int main() {
    int n, m[MAX_DIM][MAX_DIM];

    // Read matrix dimension
    printf("n = ");
    scanf("%d", &n);
    
    // Read matrix elements
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    // Search for two consecutive even numbers sequence
    for (int current = 0; current < n * n && m[current / n][current % n] != 0; current++) {
        // Compute index for the first number
        int current_i = current / n;
        int current_j = current % n;

         // Compute index for the second number
        int next_i = (current + 1) / n;
        int next_j = (current + 1) % n;

        if (m[current_i][current_j] % 2 == 0 && m[next_i][next_j] % 2 == 0 && 
                m[next_i][next_j] != 0)
            printf("(%d %d) -> (%d %d)\n", current_i, current_j, next_i, next_j);
    }

    return 0;
}