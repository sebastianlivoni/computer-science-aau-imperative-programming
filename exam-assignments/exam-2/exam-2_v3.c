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

typedef struct {
  int round;
  int is_bonus;
  int amount_of_dices;
  int per_round_dices[15][100]; /* Remember to allocate memory for this */
  int round_points[TOTAL_ROUNDS];
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
int find_pair(const int *arr_dices, const int amount_of_dices, const int pair_number);

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
  Game_of_Yatzy Game;

  Game.round = 1;
  Game.is_bonus = 0;
  Game.amount_of_dices = amount_of_dices;

  do_upper_section(&Game);
  do_lower_section(&Game);
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
}

void print_round(Game_of_Yatzy *Game) {
  int i;

  printf("Round %d - %s:", Game->round, enum_combination_to_string(Game->round));
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
  generate_random_numbers(Game->per_round_dices[Game->round], Game->amount_of_dices);
  print_round(Game);
  printf("Highest three of a kind: %d\n", find_pair(Game->per_round_dices[Game->round], Game->amount_of_dices, 3));
}

int find_pair(const int *arr_dices, const int amount_of_dices, const int pair_number) {
  int i, highest_pair = 0;
  for (i = 1; i <= 6; i++) {
    if (count_num(arr_dices, i, amount_of_dices) >= pair_number) {
      highest_pair = i;
    }
  }
  return highest_pair;
}

