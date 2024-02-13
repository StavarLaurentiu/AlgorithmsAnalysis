#include <stdio.h>

int count_visited(int visited[][8]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (visited[i][j] == 1)
                count++;
        }
    }

    return count;
}

int solve_recursive(int a[][8], int current_i, int current_j, int possible_moves[][2], 
                        int visited[][8], int empty_cells) {

    // Check if the current cell is the end cell
    if (a[current_i][current_j] == 3) {
        // Check if all the empty cells were visited ONCE (plus the starting cell)
        if (count_visited(visited) == empty_cells + 1) {
            return 1;
        }
        else
            return 0;
    }
    
    // Check if the current cell is empty
    if (visited[current_i][current_j] == 1)
        return 0;
    
    // Add the current cell to the visited list
    visited[current_i][current_j] = 1;

    // For each possible move
    for (int i = 0; i < 16; i++) {
        // Compute the new cell coordinates
        int new_i = current_i + possible_moves[i][0];
        int new_j = current_j + possible_moves[i][1];

        // Chech if the new cell is inside the board
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            // Check if the new cell is a valid move
            if (a[new_i][new_j] == 1 || a[new_i][new_j] == 3) {
                // Call the recursive function with the new cell coordinates
                if (solve_recursive(a, new_i, new_j, possible_moves, visited, empty_cells))
                    return 1;
            }
        }
    }

    // Remove the current cell from the visited list
    visited[current_i][current_j] = 0;

    // Return false if no solution was found
    return 0;
}

int chess_recursive(int a[][8]) {
    // Find the starting cell and 
    int start_i = -1, start_j = -1, empty_cells = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 2) {
                start_i = i;
                start_j = j;
            } else if (a[i][j] == 1) {
                empty_cells++;
            }
        }
    }

    // If no starting cell was found, return false
    if (start_i == -1 || start_j == -1) {
        return 0;
    }

    // Create the posible moves list
    int possible_moves[12][2] = {
            {1, 1},
            {-1, 1},
            {1, -1},
            {-1, -1},
            {1, 2},
            {-1, 2},
            {1, -2},
            {-1, -2},
            {2, 1},
            {-2, 1},
            {2, -1},
            {-2, -1}
    };

    // Create the visited list and add the starting cell
    int visited[][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Call the recursive solver function and return its result
    return solve_recursive(a, start_i, start_j, possible_moves, visited, empty_cells);
}

int main() {

    // Has solution
    int a[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // No solution
    int b[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (chess_recursive(b)) {
        printf("The chess problem has a solution\n");
    } else {
        printf("The chess problem has no solution\n");
    }

    return 0;
}