/*
 * Title: Opgave 11.4 
 * Description: 
 * Assignment: Opgave 1 side 587 i Problem Solving and Program Design in C, eighth edition.
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/recursion-opgaver-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define MAX_X 5
#define MAX_Y 5

int blob_count(int x, int y, int grid[MAX_X][MAX_Y]);
int is_within_grid(int x, int y, int grid[MAX_X][MAX_Y]);
int do_round(int x, int y, int grid[MAX_X][MAX_Y]);

int main(void) {

  /*int grid_original[5][5] = {
    {1, 1, 0, 0, 1},
    {0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 0, 1, 1},
  };*/
  int grid_original[5][5] = {
    {1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 1},
  };

  printf("Blob count: %d\n", blob_count(4, 4, grid_original));

}

int blob_count(int x, int y, int grid[MAX_X][MAX_Y]) {
  int count = 0;
  if (is_within_grid(x, y, grid)) {
    if (grid[x][y] == 1) {
      count++;
      grid[x][y] = 0;
      count += do_round(x, y, grid);
    }
    return count;
  } else {
    return 0;
  } 
}

int do_round(int x, int y, int grid[MAX_X][MAX_Y]) {
  int count = 0; x--; y--;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      count += blob_count(x + i, y + j, grid);
    }
  }
  return count;
}

int is_within_grid(int x, int y, int grid[MAX_X][MAX_Y]) {
  if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y) return 0;
  else return 1;
}