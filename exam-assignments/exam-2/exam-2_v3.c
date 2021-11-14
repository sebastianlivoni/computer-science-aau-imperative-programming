/*
 * Title: Yatzy med mange terninger.
 * Assignment: Eksamensopgave 2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Arrays/opgave-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: November 7, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Configuration */
#define MIN_INPUT_DICES 5
#define UPPER_SECTION_ROUNDS 6
#define MAX_DIE_EYES 6
#define MAX_USED_DICES 5
#define TOTAL_ROUNDS 15
#define YATZY_SCORE 50
#define UPPER_SECTION_MIN_POINTS 63
#define UPPER_SECTION_BONUS 50

typedef struct {
  int round;
  int is_bonus;
  int amount_of_dices;
  int round_points[TOTAL_ROUNDS];
  int *per_round_dices[TOTAL_ROUNDS];
} Game_of_Yatzy;

/* Prototypes */

/* Input & validation */
int ask_for_input(int *amount);
void print_input_error_message(void);

/* Yatzy */
void play_game_of_yatzy(const int amount_of_dices);
void do_upper_section(Game_of_Yatzy *Game);
void generate_random_numbers(int *arr_dices, const int amount_of_dices);
int count_num(const int *arr_dices, const int n, const int amount_of_dices);
void print_round(Game_of_Yatzy *Game);
char * enum_combination_to_string(const int n);

/* Lower section */
void do_lower_section(Game_of_Yatzy *Game);

int sum_pair(const int *arr_dices, const int amount_of_dices, const int pair_number);
int sum_two_pairs(int *arr_dices, const int amount_of_dices);

int straight_sum(int *arr_dices, const int *combi_arr, const int amount_of_dices);
int find_elem(const int elem, const int array[], const int amount_of_dices);

int count_elem(const int *arr_dices, int n, const int amount_of_dices);
int sum_full_house(const int *arr_dices, const int amount_of_dices);

int sum_chance(int *arr_dices, const int amount_of_dices);
int sort_biggest_to_lowest(const void *a, const void *b);

int sum_yatzy(const int *arr_dices, const int amount_of_dices);

int main(void) {
  int amount_of_dices, done = 0;
  char exit_char;

  srand(time(NULL)); /* Initialize random number generator used for dices generation based on time as runtime value */

  printf("Hey there. Are you ready to play?\n"
         "Get geady for a game of blazing fast Yatzy!\n");

  do {
    printf("How many dices do you want to play with? => ");

    if (ask_for_input(&amount_of_dices) == 1) {
      play_game_of_yatzy(amount_of_dices);

      /* Offer user to play a new game of yatzy */
      printf("Do you want to play blazing fast Yatzy again? Enter 'y' or 'n' => ");
      scanf(" %s", &exit_char);
      if (exit_char == 'n') {
        done = 1;
      }
    } else {
      print_input_error_message();
    }
  } while (!done);

  printf("Thanks for playing blazing fast Yatzy. Good bye!\n");
}

int ask_for_input(int *amount) {
  int amount_temp;
  if (scanf("%d", &amount_temp) == 1) {
    if (amount_temp >= MIN_INPUT_DICES) {
      *amount = amount_temp;
      return 1;
    } else {
      return 0;
    }
  } else {
    scanf("%*s"); /* using '*' to read and then ignore the value instead */
    return 0;
  }
}

void print_input_error_message(void) {
  printf(
    "\033[1;31m" /* Start of Bold & Red text */
    "Invalid input. "
    "\033[0m" /* End of Bold & Red text */
    "Please type an integer bigger than or equal to %d!\n" , MIN_INPUT_DICES);
}

void play_game_of_yatzy(const int amount_of_dices) {
  int i, total_points = 0;
  Game_of_Yatzy Game;

  Game.round = 0;
  Game.is_bonus = 0;
  Game.amount_of_dices = amount_of_dices;

  for (i = 0; i < TOTAL_ROUNDS; i++) {
    Game.per_round_dices[i] = (int*) malloc(amount_of_dices * sizeof(int)); /* Allocating amount of dices in integers in memory */
    if (Game.per_round_dices[i] == NULL) {
      printf("The program could not allocate enough memory: Error: %d\n", i);
      exit(EXIT_FAILURE);
    }
  }

  do_upper_section(&Game);
  do_lower_section(&Game);

  for (i = 0; i < TOTAL_ROUNDS; i++) {
    total_points += Game.round_points[i];
  }
  /*if (Game.is_bonus == 1) {
    total_points += 1;
    printf("You recieved %d points because you a minimum of %d points in upper section.\n", UPPER_SECTION_BONUS, UPPER_SECTION_MIN_POINTS);
  }*/
  printf("Total points: %d\n", total_points);

  for (i = 0; i < TOTAL_ROUNDS; i++) {
    free(Game.per_round_dices[i]); /* Free all in memory */
  }
}

void do_upper_section(Game_of_Yatzy *Game) {
  int i;
  for (i = 1; i <= UPPER_SECTION_ROUNDS; i++) {
    generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices); /* Add random dices to the struct for the round */
    Game->round_points[Game->round] = count_num(Game->per_round_dices[Game->round], i, Game->amount_of_dices) * i; /* Add points of round to the struct array */
    print_round(Game);
    Game->round++;
  }
}

int count_num(const int *arr_dices, const int n, const int amount_of_dices) {
  int count = 0, i;
  for (i = 0; i < amount_of_dices; i++) {
    if (arr_dices[i] == n && count < MAX_USED_DICES) {
      count++;
    }
  }
  return count; /* Return amount points */
}

void generate_random_numbers(int *arr_dices, const int amount_of_dices) {
  int i;

  for (i = 0; i < amount_of_dices; i++) {
    arr_dices[i] = (rand() % MAX_DIE_EYES) + 1; /* Generate random number and add it to the array */
  }

  qsort(arr_dices, amount_of_dices, sizeof(int), sort_biggest_to_lowest);
}

int sort_biggest_to_lowest(const void *a, const void *b) {
  return (*(int*)b - *(int*)a); /* Sort from biggest to lowest */
}

void print_round(Game_of_Yatzy *Game) {
  int i;

  printf("\033[1;37mRound %d\033[0m - %s:", Game->round + 1, enum_combination_to_string(Game->round + 1));
  for (i = 0; i < Game->amount_of_dices; i++) {
    printf(" %d", Game->per_round_dices[Game->round][i]);
  }
  printf(" = %d points.\n", Game->round_points[Game->round]);
}

char * enum_combination_to_string(const int n) {
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

void do_lower_section(Game_of_Yatzy *Game) {
  int i;
  const int SMALL_STRAIGHT[] = {1, 2, 3, 4, 5},
            LARGE_STRAIGHT[] = {2, 3, 4, 5, 6};

  /* One Pair, Two Pairs, Three of a Kind & Four of a Kind */
  for (i = 1; i <= 4; i++) {
    generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
    if (i == 2) {
      Game->round_points[Game->round] = sum_two_pairs(Game->per_round_dices[Game->round], Game->amount_of_dices);
    } else {
      Game->round_points[Game->round] = sum_pair(Game->per_round_dices[Game->round], Game->amount_of_dices, (i == 1) ? i + 1 : i);
    }
    print_round(Game);
    Game->round++;
  }

  /* Small Straight */
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  Game->round_points[Game->round] = straight_sum(Game->per_round_dices[Game->round], SMALL_STRAIGHT, Game->amount_of_dices);
  print_round(Game);
  Game->round++;

  /* Large Straight */
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  Game->round_points[Game->round] = straight_sum(Game->per_round_dices[Game->round], LARGE_STRAIGHT, Game->amount_of_dices);
  print_round(Game);
  Game->round++;

  /* Full House */
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  Game->round_points[Game->round] = sum_full_house(Game->per_round_dices[Game->round], Game->amount_of_dices);
  print_round(Game);
  Game->round++;

  /* Chance */
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  Game->round_points[Game->round] = sum_chance(Game->per_round_dices[Game->round], Game->amount_of_dices);
  print_round(Game);
  Game->round++;

  /* Yatzy */
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  Game->round_points[Game->round] = sum_yatzy(Game->per_round_dices[Game->round], Game->amount_of_dices);
  print_round(Game);
}

int sum_pair(const int *arr_dices, const int amount_of_dices, const int pair_number) {
  int i, highest_pair = 0;
  for (i = 1; i <= 6; i++) {
    if (count_num(arr_dices, i, amount_of_dices) >= pair_number) {
      highest_pair = i;
    }
  }
  return highest_pair * pair_number;
}

int sum_two_pairs(int *arr_dices, const int amount_of_dices) {
  int i, j, pairs = 0, pair1 = 0, pair2 = 0;

  for (i = 1; i <= 6; i++) {
    int count = 0;
    for (j = 0; j < amount_of_dices; j++) {
      if (i == arr_dices[j]) {
        count++;
      }
    }
    if (count >= 2) {
      pairs++;
      if (i > pair1) {
        pair2 = pair1;
        pair1 = i;
      } else if (i > pair2) {
        pair2 = i;
      }
    } 
  }
  if (pair1 > 0 && pair2 > 0)
    return pair1 * 2 + pair2 * 2; /* Return sum */ 
  else 
    return 0;
}

int straight_sum(int *arr_dices, const int *combi_arr, const int amount_of_dices) {
  int i, elem, is_straight = 1, sum = 0;
  for (i = 0; i < 5; i++) {
    elem = find_elem(combi_arr[i], arr_dices, amount_of_dices);
    if (elem < 1) {
      is_straight = 0;
    } else {
      sum += elem;
    }
  }
  if (is_straight)
    return sum;
  else
    return 0;
}

int find_elem(const int elem, const int array[], const int amount_of_dices) {
  int i;

  for (i = 0; i < amount_of_dices; i++) {
    if (array[i] == elem) {
      return array[i];
    }
  }
  return -1;
}

int count_elem(const int *arr_dices, int n, const int amount_of_dices) {
  int i, count = 0;
  for (i = 0; i < amount_of_dices; i++) {
    if (n == arr_dices[i]) {
      count++;
    }
  }
  return count;
}

int sum_full_house(const int *arr_dices, const int amount_of_dices) {
  int count = 0, *array, biggest_3, biggest_2, i, j, score = 0;

  array = (int*) malloc(sizeof(int) * amount_of_dices);

  for (i = 1; i <= MAX_DIE_EYES; i++) {
    count = count_elem(arr_dices, i, amount_of_dices);
    array[i - 1] = count;
  }

  /* Biggest 3 */
  biggest_3 = 0;
  for (i = 0; i < MAX_DIE_EYES; i++) {
    if (array[i] >= 3) {
      biggest_3 = i;
    }
  }
  biggest_2 = 0;
  for (j = 0; j < MAX_DIE_EYES; j++) {
    if (array[j] >= 2 && biggest_3 != j) {
      biggest_2 = j;
    }
  }
  if (biggest_3 > 0 && biggest_2 > 0) {
    score = (biggest_3 + 1) * 3 + (biggest_2 + 1) * 2;
  } else {
    score = 0;
  }
  return score; /* Return score */
}

int sum_chance(int *arr_dices, const int amount_of_dices) {
  int i, sum = 0;

  /* Arr_dices is already sorted from highest to lowest */
  for (i = 0; i < MAX_USED_DICES; i++) {
    sum += arr_dices[i];
  }

  return sum;
}

int sum_yatzy(const int *arr_dices, const int amount_of_dices) {
  int i, j;
  for (i = 1; i <= MAX_DIE_EYES; i++) {
    int count_i = 0;
    for (j = 0; j < amount_of_dices; j++) {
      if (arr_dices[j] == i) {
        count_i++;
      }
    }
    if (count_i >= MAX_USED_DICES) {
      return YATZY_SCORE; /* Yes, we have yatzy */
    } 
  }
  return 0; /* Nope, no yatzy */
}
