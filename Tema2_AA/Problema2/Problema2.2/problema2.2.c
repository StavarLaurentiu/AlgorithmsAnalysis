#include <stdio.h>

#define MAX 1001

typedef struct {
    int n;
    int matrix[MAX][MAX];
} Graph;

int TSP(Graph *g) {
    int cycle[MAX], current = 1;

    // Find a cycle of length 3
    for (int i = 1; i <= g->n; i++)
        for (int j = 1; j <= g->n; j++)
            for (int k = 1; k <= g->n; k++)
                if (g->matrix[i][j] && g->matrix[j][k] && g->matrix[k][i]) {
                    cycle[current++] = i;
                    cycle[current++] = j;
                    cycle[current++] = k;
                    goto skip;
                }

skip:

    // Find the rest of the cycle
    for (int i = 1; i <= g->n; i++)
        if (!cycle_contains(cycle, i)) {
            for (int j = 1; j <= current; j++)
                if (g->matrix[i][cycle[j]] && g->matrix[cycle[(j + 1) % g->n]][i]) {
                    // Add i to cycle
                    for (int k = current; k > j; k--)
                        cycle[k] = cycle[k - 1];
                    cycle[j] = i;
                    current++;
                    break;
                }
        }

    // Check if the cycle is hamiltonian
    if (current == g->n + 1)
        return 1;
    
    return 0;
}

