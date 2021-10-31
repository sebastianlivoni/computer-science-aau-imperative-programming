/*
 * Title: Yatzy med mange terninger.
 * Assignment: Eksamensopgave 2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Arrays/opgave-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: October 31, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_DICES 6
#define DIE_MAX_EYES 6
#define MAX_USED_DICES 5
#define UPPER_SECTION_MIN_POINTS 63
#define UPPER_SECTION_BONUS 50

struct Game_of_Yatzy {
  int total_score;
  int n_dices;
  int round;
};

void play_yatzy(void);
void run_upper_section(struct Game_of_Yatzy *Game);

int sum_of_num(const int arr_dices[], const int num);
void roll_multiple_dices(int *arr_dices);
void run_lower_section(int *sum, int arr_dices[]);
void print_dices(int *arr_dices);
void check_onepair(int *sum, const int *arr_dices);

void pairs(int *sum, int *arr_dices, const int pairs);
void two_pairs(int *sum, int *arr_dices);
/* two pairs */
void straight(int *sum, int *arr_dices, const int *combi_arr);
/* full house */
void add_chance(int *sum, const int *arr_dices);
int check_yatzy(const int *arr_dices);

int main(void) {
  srand(time(NULL));

  play_yatzy();

  /*int sum = 0;
  int arr_dices[NUM_OF_DICES];

  run_upper_section(&sum, arr_dices);

  run_lower_section(&sum, arr_dices);*/

  return EXIT_SUCCESS;
}

void play_yatzy(void) {

  printf("Get geady for a game of blazing fast Yatzy!\n");

  struct Game_of_Yatzy Game = {0, 0, 0};

  /*printf("How many dices do you want to play with? => ")
  scanf(" %d", &n_dices)*/

  run_upper_section(&Game);

}

void run_upper_section(struct Game_of_Yatzy *Game) {
  printf("--- Upper Section ---\n");

  int arr_dices[NUM_OF_DICES],
      i, round_sum, total_sum;

  for (i = 1; i <= 6; i++) {
    roll_multiple_dices(arr_dices); /* Generate new array of random dices based on time */

    /* Printing */
    printf("Round %d: %d's = ", ++Game->round, i);
    print_dices(arr_dices);
    round_sum = sum_of_num(arr_dices, i) * i; /* Adding points */
    printf("= %d points\n", round_sum);

    total_sum += round_sum;
    Game->total_score += round_sum;
  }

  if (total_sum >= UPPER_SECTION_MIN_POINTS) {
    Game->total_score += UPPER_SECTION_BONUS;
    printf("You recived a bonus of %d points because you managed to get more than %d points in the upper sectiond.\n", UPPER_SECTION_BONUS, UPPER_SECTION_MIN_POINTS);
  }

  printf("Total points in upper section: %d\n", Game->total_score);

  printf("--- End of Upper Section ---\n");
}

void run_lower_section(int *sum, int arr_dices[]) {

  const int SMALL_STRAIGHT[] = {1, 2, 3, 4, 5},
            LARGE_STRAIGHT[] = {2, 3, 4, 5, 6};

  roll_multiple_dices(arr_dices);
  print_dices(arr_dices);
  printf("\n");
  straight(sum, arr_dices, SMALL_STRAIGHT);

  roll_multiple_dices(arr_dices);
  print_dices(arr_dices);
  printf("\n");
  straight(sum, arr_dices, LARGE_STRAIGHT);

  roll_multiple_dices(arr_dices);
  arr_dices[0] = 2;
  arr_dices[1] = 2;
  arr_dices[2] = 4;
  arr_dices[3] = 4;
  arr_dices[4] = 3;
  arr_dices[5] = 3;
  arr_dices[6] = 6;
  print_dices(arr_dices);
  printf("\n");
  pairs(sum, arr_dices, 2);

  roll_multiple_dices(arr_dices);
  print_dices(arr_dices);
  printf("\n");
  pairs(sum, arr_dices, 3);

  roll_multiple_dices(arr_dices);
  print_dices(arr_dices);
  printf("\n");
  pairs(sum, arr_dices, 4);

  roll_multiple_dices(arr_dices);
  print_dices(arr_dices);
  printf("\n");
  two_pairs(sum, arr_dices);

}

int sum_of_num(const int arr_dices[], const int num) {
  int sum = 0,
      count = 0,
      i;
  for (i = 0; i <= NUM_OF_DICES; i++)
    if (arr_dices[i] == num && count < MAX_USED_DICES) {
      sum += 1;
      count++;
    }
  return sum;
}

void roll_multiple_dices(int *arr_dices) {
  for (int i = 0; i < NUM_OF_DICES; i++)
    arr_dices[i] = (rand() % DIE_MAX_EYES) + 1;
}

void print_dices(int *arr_dices) {
  int i;
  for (i = 0; i < NUM_OF_DICES; i++) {
    printf("%d ", arr_dices[i]);
  }
}

int find_elem(int elem, int array[]) {
  for (int i = 0; i < NUM_OF_DICES; i++) {
    if (array[i] == elem) {
      return array[i];
    }
  }
  return -1;
}

void pairs(int *sum, int *arr_dices, const int pairs) {
  /*static int pairs[6][2] = {{6,6}, {5,5}, {4,4}, {3,3}, {2,2}, {1,1}};*/
  int pair = 0, pairs_count = 0, pairs_sum = 0, pair_second = 0;
  for (int i = 1; i <= 6; i++) {
    int local_i = 0;
    for (int j = 0; j < NUM_OF_DICES; j++) {
      if (arr_dices[j] == i) {
        local_i++;
      }
    }
    if (local_i >= pairs) {
      pair = i;
      pairs_count++;
    }
  }
  if (pair > 0) {
    sum += pair * pairs;
    printf("Best pair: %d - you get +%d points\n", pair, pair * pairs);
  } else {
    printf("No pairs...\n");
  }
}

void two_pairs(int *sum, int *arr_dices) {
  int pairs = 0;
  int pair1 = 0;
  int pair2 = 0;
  for (int i = 1; i <= 6; i++) {
    int count = 0;
    for (int j = 0; j < NUM_OF_DICES; j++) {
    /*printf("%d %d\n", i, arr_dices[j]);*/
      if (i == arr_dices[j]) {
        /*printf("%d %d\n", i, arr_dices[j]);*/
        count++;
      }
    }
    if (count >= 2) {
      /*printf("Count: %d %d\n", i, count);*/
      pairs++;
      if (i > pair1) {
        pair2 = pair1;
        pair1 = i;
      } else if (i > pair2) {
        pair2 = i;
      }
    } 
  }
  int add_sum = pair1 * 2 + pair2 * 2;
  *sum = add_sum;
  if (pairs > 1) {
    printf("Two pairs %d & %d - Added sum: %d\n", pair1, pair2, add_sum);
  }
  /*printf("Pairs: %d - pair1: %d - pair2: %d\n", pairs, pair1, pair2);*/
}

void straight(int *sum, int *arr_dices, const int *combi_arr) {
  int i, elem, is_straight = 1, straight_sum = 0;
  for (i = 0; i < 5; i++) {
    elem = find_elem(combi_arr[i], arr_dices);
    if (elem < 1) {
      is_straight = 0;
    } else {
      straight_sum += elem;
    }
  }

  if (is_straight) {
    printf("Wuhu - is small/large straight! +%d points!\n", straight_sum);
    *sum = straight_sum;
  } else {
    printf("Not small/large straight!\n");
  }

}

int check_yatzy(const int *arr_dices) {
  int i, last = arr_dices[0];
  for (i = 1; i < NUM_OF_DICES; i++) {
    if (arr_dices[i] != last) {
      return 0;
    }
  }
  return 1;
}

void add_chance(int *sum, const int *arr_dices) {
  int i;
  for (i = 0; i < NUM_OF_DICES; i++) {
    *sum += arr_dices[i];
  }
}