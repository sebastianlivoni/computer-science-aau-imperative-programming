#include <stdio.h>
#include <stdlib.h>

#define MATRIX_LENGTH 5
#define INFINITY 10000
#define UNDEFINED -1
#define REMOVED -2
#define SOURCE_ELEMENT 0

int find_min_vertex(int matrix[MATRIX_LENGTH][MATRIX_LENGTH], int dist[MATRIX_LENGTH]);
char *convert_to_alpha(int n);

int main(void) {
    int i, u, neighbor, edge, alt, dist[MATRIX_LENGTH], prev[MATRIX_LENGTH];

    /* adjacency matrix */
    int matrix[MATRIX_LENGTH][MATRIX_LENGTH] = {
    /*   A  B  C  D  E    */
        {0, 6, 0, 1, 0}, /* A */ 
        {6, 0, 5, 2, 2}, /* B */
        {0, 5, 0, 0, 5}, /* C */
        {1, 2, 0, 0, 1}, /* D */
        {0, 2, 5, 1, 0}  /* E */
    };

    int unvisited_count = MATRIX_LENGTH;

    for (i = 0; i < MATRIX_LENGTH; i++) {
        dist[i] = INFINITY;
        prev[i] = UNDEFINED;
    }

    dist[SOURCE_ELEMENT] = 0;

    while (unvisited_count > 0) {
        u = find_min_vertex(matrix, dist);
        if (u != INFINITY) {

            matrix[u][u] = REMOVED;
            
            for (neighbor = 0; neighbor < MATRIX_LENGTH; neighbor++) {
                edge = matrix[u][neighbor];
                if (matrix[neighbor][neighbor] != REMOVED && edge > 0) {
                    alt = dist[u] + edge;
                    if (alt < dist[neighbor]) {
                        dist[neighbor] = alt;
                        prev[neighbor] = u;
                    }
                }
            }
        }

        unvisited_count -= 1;
    }

    printf("Vertex | Shortest distance from A | Previous vertex:\n");
    for (i = 1; i < MATRIX_LENGTH; i++) {
        printf("%3s: %15d %30s\n", convert_to_alpha(i), dist[i], convert_to_alpha(prev[i]));
    }

    printf("Then what you can do now is that you can connect E -> D and D -> A. The shortest distance from E to A is 2\n");

    return EXIT_SUCCESS;
}

char *convert_to_alpha(int n) {
    if (n == 0)
        return "A";
    else if (n == 1)
        return "B";
    else if (n == 2)
        return "C";
    else if (n == 3)
        return "D";
    else if (n == 4)
        return "E";
    else
        return "";
}

int find_min_vertex(int matrix[MATRIX_LENGTH][MATRIX_LENGTH], int dist[MATRIX_LENGTH]) {
    int i = 0, smallest_dist = INFINITY, smallest_dist_i;
    while (i < MATRIX_LENGTH) {
        if (matrix[i][i] != REMOVED && dist[i] < smallest_dist) {
            smallest_dist = dist[i];
            smallest_dist_i = i;
        }
        i++;
    }
    return smallest_dist_i;
}
