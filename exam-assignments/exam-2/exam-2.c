/*
 * Title: Yatzy med mange terninger.
 * Assignment: Eksamensopgave 2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Arrays/opgave-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: November 03, 2021
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
#define YATZY_SCORE 50

struct Game_of_Yatzy {
  int total_score;
  int number_of_dices;
  int round;
  int bonus;
};

enum combinations {ones = 1, twos, threes, fours, fives, sixes, one_pair, two_Pairs, three_of_a_kind, 
                   four_of_a_kind, small_straight, large_straight, full_house, chance, yatzy};

void play_yatzy(int amount_of_dices);
void run_upper_section(struct Game_of_Yatzy *Game);
int sum_of_num(const int arr_dices[], const int num_to_find, struct Game_of_Yatzy *Game);
char * combination_to_text(const int n);
void roll_multiple_dices(int *arr_dices, struct Game_of_Yatzy *Game);

void run_lower_section(struct Game_of_Yatzy *Game);
void print_dices(int *arr_dices, struct Game_of_Yatzy *Game);
void check_onepair(int *sum, const int *arr_dices);

void pairs(int *arr_dices, struct Game_of_Yatzy *Game, const int pairs);
void two_pairs(int *arr_dices, struct Game_of_Yatzy *Game);
void straight(int *arr_dices, const int *combi_arr, struct Game_of_Yatzy *Game);
void calc_full_house(int *arr_dices, struct Game_of_Yatzy *Game);
void add_chance(int *arr_dices, struct Game_of_Yatzy *Game);
void check_yatzy(int *arr_dices, struct Game_of_Yatzy *Game); /* Need fix */

int main(void) {
  int dices_input_amount, done;
  
  srand(time(NULL));

  done = 0;

  printf("Get geady for a game of blazing fast Yatzy!\n");

  while (!done) {
    printf("How many dices do you want to play with? => ");

    if (scanf(" %d", &dices_input_amount) == 1 && dices_input_amount >= 5) {
      play_yatzy(dices_input_amount);
    } else {
      done = 1;
    }
  }

  return EXIT_SUCCESS;
}

void play_yatzy(int amount_of_dices) {

  struct Game_of_Yatzy Game = {0, amount_of_dices, 0, 0};

  run_upper_section(&Game);
  run_lower_section(&Game);

  printf("\n");

  if (Game.bonus == 1) {
    printf("You recieved %d points because you a minimum of %d points in upper section.\n", UPPER_SECTION_BONUS, UPPER_SECTION_MIN_POINTS);
  }

  printf("Final result: %d\n", Game.total_score);
  printf("\n");
}

void run_upper_section(struct Game_of_Yatzy *Game) {
  printf("--- Upper Section ---\n");

  int arr_dices[Game->number_of_dices], i, round_sum, total_sum = 0;

  for (i = 1; i <= 6; i++) {
    roll_multiple_dices(arr_dices, Game); /* Generate new array of random dices based on time */
    round_sum = sum_of_num(arr_dices, i, Game) * i; /* Adding points */

    /* Printing */
    printf("Round %d - %s: ", ++Game->round, combination_to_text(i));
    print_dices(arr_dices, Game);
    printf("= %d points\n", round_sum);

    total_sum += round_sum; 
    Game->total_score += round_sum;
  }

  if (total_sum >= UPPER_SECTION_MIN_POINTS) {
    Game->bonus = 1; /* Bonus point is true */
    Game->total_score += UPPER_SECTION_BONUS;
    printf("You recived a bonus of %d points because you managed to get more than %d points in the upper section.\n", UPPER_SECTION_BONUS, UPPER_SECTION_MIN_POINTS);
  }

  printf("Total points in upper section: %d\n", Game->total_score);

  printf("--- End of Upper Section ---\n");
}

int sum_of_num(const int arr_dices[], const int num_to_find, struct Game_of_Yatzy *Game) {
  int sum = 0, count = 0, i;
  
  for (i = 0; i <= Game->number_of_dices; i++) {
    if (arr_dices[i] == num_to_find && count < MAX_USED_DICES) {
      sum += 1;
      count++;
    }
  }
  return sum;
}

void roll_multiple_dices(int *arr_dices, struct Game_of_Yatzy *Game) {
  int i;
  for (i = 0; i < Game->number_of_dices; i++)
    arr_dices[i] = (rand() % DIE_MAX_EYES) + 1;
}

void print_round(struct Game_of_Yatzy *Game, int *arr_dices) {
  printf("Round %d - %s: ", Game->round, combination_to_text(Game->round));
}

void print_dices(int *arr_dices, struct Game_of_Yatzy *Game) {
  int i;

  printf("Round %d - %s: ", Game->round, combination_to_text(Game->round));

  for (i = 0; i < Game->number_of_dices; i++) {
    printf("%d ", arr_dices[i]);
  }
}

void run_lower_section(struct Game_of_Yatzy *Game) {

  printf("--- Lower Section ---\n");

  int arr_dices[Game->number_of_dices], n = 2, i;

  /* Pairs (one pair, two pairs, three of a kind / four of a kind) */
  for (i = 2; i <= 5; i++) {
    roll_multiple_dices(arr_dices, Game);
    Game->round++;
    if (i == 3) {
      two_pairs(arr_dices, Game);
    } else {
      pairs(arr_dices, Game, n);
      n++;
    }
  }

  const int SMALL_STRAIGHT[] = {1, 2, 3, 4, 5},
            LARGE_STRAIGHT[] = {2, 3, 4, 5, 6};

  /* Small straight */
  roll_multiple_dices(arr_dices, Game);
  Game->round++;
  straight(arr_dices, SMALL_STRAIGHT, Game);

  /* Large straight */
  roll_multiple_dices(arr_dices, Game);
  Game->round++;
  straight(arr_dices, LARGE_STRAIGHT, Game);

  /* Full house */
  roll_multiple_dices(arr_dices, Game);
  Game->round++;
  calc_full_house(arr_dices, Game);

  /* Chance */
  roll_multiple_dices(arr_dices, Game);
  Game->round++;
  add_chance(arr_dices, Game);

  /* Yatzy */
  roll_multiple_dices(arr_dices, Game);
  Game->round++;
  check_yatzy(arr_dices, Game);

  printf("--- End of Lower Section ---\n");

}

int cmp_fnc(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int count_elem(int *arr_dices, int n, struct Game_of_Yatzy *Game) {
  int i, count = 0;
  for (i = 0; i < Game->number_of_dices; i++) {
    if (n == arr_dices[i]) {
      count++;
    }
  }
  return count;
}

void calc_full_house(int *arr_dices, struct Game_of_Yatzy *Game) {
  int count = 0, array[Game->number_of_dices], biggest_3, biggest_2, i, j;

  print_dices(arr_dices, Game);
  for (i = 1; i <= DIE_MAX_EYES; i++) {
    count = count_elem(arr_dices, i, Game);
    array[i - 1] = count;
  }

  /* Biggest 3 */
  biggest_3 = 0;
  for (i = 0; i < DIE_MAX_EYES; i++) {
    if (array[i] >= 3) {
      biggest_3 = i;
    }
  }
  biggest_2 = 0;
  for (j = 0; j < DIE_MAX_EYES; j++) {
    if (array[j] >= 2 && biggest_3 != j) {
      biggest_2 = j;
    }
  }
  if (biggest_3 > 0 && biggest_2 > 0) {
    int score = (biggest_3 + 1) * 3 + (biggest_2 + 1) * 2;
    printf("= %d points\n", score);
    Game->total_score += score;
  } else {
    printf("= 0 points\n");
  }
}

void pairs(int *arr_dices, struct Game_of_Yatzy *Game, const int pairs) {
  /*static int pairs[6][2] = {{6,6}, {5,5}, {4,4}, {3,3}, {2,2}, {1,1}};*/
  int pair = 0, pairs_count = 0, i, j;
  for (i = 1; i <= 6; i++) {
    int local_i = 0;
    for (j = 0; j < Game->number_of_dices; j++) {
      if (arr_dices[j] == i) {
        local_i++;
      }
    }
    if (local_i >= pairs) {
      pair = i;
      pairs_count++;
    }
  }
  
  print_dices(arr_dices, Game);
  if (pair > 0) {
    Game->total_score += pair * pairs;
    printf("= %d points\n", pair * pairs);
  } else {
    printf("= 0 points\n");
  }
}

void two_pairs(int *arr_dices, struct Game_of_Yatzy *Game) {
  int i, j, add_sum, pairs = 0, pair1 = 0, pair2 = 0;

  for (i = 1; i <= 6; i++) {
    int count = 0;
    for (j = 0; j < Game->number_of_dices; j++) {
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
  add_sum = pair1 * 2 + pair2 * 2;
  Game->total_score += add_sum;
  
  print_dices(arr_dices, Game);
  if (pairs > 1) {
    printf("= %d points\n", add_sum);
  } else {
    printf("= 0 points\n");
  }
  /*printf("Pairs: %d - pair1: %d - pair2: %d\n", pairs, pair1, pair2);*/
}

int find_elem(int elem, int array[], struct Game_of_Yatzy *Game) {
  int i;

  for (i = 0; i < Game->number_of_dices; i++) {
    if (array[i] == elem) {
      return array[i];
    }
  }
  return -1;
}

void straight(int *arr_dices, const int *combi_arr, struct Game_of_Yatzy *Game) {
  int i, elem, is_straight = 1, straight_sum = 0;
  for (i = 0; i < 5; i++) {
    elem = find_elem(combi_arr[i], arr_dices, Game);
    if (elem < 1) {
      is_straight = 0;
    } else {
      straight_sum += elem;
    }
  }

  
  print_dices(arr_dices, Game);

  if (is_straight) {
    printf("= %d points\n", straight_sum);
    /*printf("Wuhu - is small/large straight! +%d points!\n", straight_sum);*/
    Game->total_score += straight_sum;
  } else {
    printf("= 0 points\n");
    /*printf("Not small/large straight!\n");*/
  }
}

void check_yatzy(int *arr_dices, struct Game_of_Yatzy *Game) {
  int i, j, is_yatzy = 0;
  for (i = 1; i <= NUM_OF_DICES; i++) {
    int count_i = 0;
    for (j = 0; j < Game->number_of_dices; j++) {
      if (arr_dices[j] == i) {
        count_i++;
      }
    }
    if (count_i >= MAX_USED_DICES) {
      is_yatzy = 1;
    } 
  }
  
  
  print_dices(arr_dices, Game);
  
  if (is_yatzy == 1) {
    printf("= %d points\n", YATZY_SCORE);
    Game->total_score += YATZY_SCORE;
  } else {
    printf("= 0 points\n");
  }
}

void add_chance(int *arr_dices, struct Game_of_Yatzy *Game) {
  int i, sum = 0;
  qsort(arr_dices, Game->number_of_dices, sizeof(int), cmp_fnc);
  for (i = Game->number_of_dices - 1; i > Game->number_of_dices - MAX_USED_DICES - 1; i--) {
    sum += arr_dices[i];
  }
  
  print_dices(arr_dices, Game);
  printf("= %d points\n", sum);
  Game->total_score += sum;
}

char * combination_to_text(const int n) {
  char * value_text;
  switch(n) {
    case 1: value_text = "Ones"; break;
    case 2: value_text = "Twos"; break;
    case 3: value_text = "Threes"; break;
    case 4: value_text = "Fours"; break;
    case 5: value_text = "Fives"; break;
    case 6: value_text = "Sixes"; break;
    case 7: value_text = "One Pair"; break;
    case 8: value_text = "Two Pairs"; break;
    case 9: value_text = "Three of a Kind"; break;
    case 10: value_text = "Four of a Kind"; break;
    case 11: value_text = "Small Straight"; break;
    case 12: value_text = "Large Straight"; break;
    case 13: value_text = "Full House"; break;
    case 14: value_text = "Chance"; break;
    case 15: value_text = "Yatzy"; break;
    default: value_text = "N/A";
  }
  return value_text;
}
