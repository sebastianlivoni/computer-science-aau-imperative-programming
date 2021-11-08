/*
 * Title: Yatzy med mange terninger.
 * Assignment: Eksamensopgave 2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Arrays/opgave-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: November 01, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIE_EYES 6
#define MAX_USED_DICES 5
#define ROUNDS 6

struct Game_of_Yatzy {
  int total_score;
  int round;
  int bonus;
  int number_of_dices;
  int round_arr_dices[15][50];
  int round_points[15];
};

enum combinations {enum_ones = 1, enum_twos, enum_threes, enum_fours, enum_fives, enum_sixes, enum_one_pair, enum_two_Pairs, enum_three_of_a_kind, 
                   enum_four_of_a_kind, enum_small_straight, enum_large_straight, enum_full_house, enum_chance, enum_yatzy};

void play_game_yatzy(void);
void roll_multiple_dices(struct Game_of_Yatzy *Game);
void print_round(struct Game_of_Yatzy *Game, int points);
int upper_round(struct Game_of_Yatzy *Game);
int count_num(struct Game_of_Yatzy *Game, int n);
void print_dices(struct Game_of_Yatzy *Game);
char *enum_combination_to_string(const int n);

typedef int (*f)(struct Game_of_Yatzy*);
f combinations[ROUNDS] = {upper_round, upper_round, upper_round, upper_round, upper_round, upper_round};

int main(void) {
  srand(time(NULL));
  
  play_game_yatzy();
}

void play_game_yatzy(void) {
  int points, i;

  struct Game_of_Yatzy Game = {0, 1, 1, 5}; /* total score: 0, round: 1, bonus: 1, number_of_dices: 5 */

  for (i = 1; i <= ROUNDS; i++, Game.round++) {
    roll_multiple_dices(&Game);
    points = combinations[i - 1](&Game);
    Game.round_points[i - 1] = points;
    print_round(&Game, points);
  }
}

int upper_round(struct Game_of_Yatzy *Game) {
  return count_num(Game, Game->round); /* Return points */
}

void print_round(struct Game_of_Yatzy *Game, int points) {
  printf("Round %d - %s: ", Game->round, enum_combination_to_string(Game->round));
  print_dices(Game);
  printf("= %d points\n", points);
}

int count_num(struct Game_of_Yatzy *Game, int n) {
  int count = 0, i;
  for (i = 0; i < Game->number_of_dices; i++) {
    if (Game->round_arr_dices[Game->round][i] == n && count < MAX_USED_DICES) {
      count++;
    }
  }
  return count * n; /* Return amount points */
}

void print_dices(struct Game_of_Yatzy *Game) {
  int i;
  for (i = 0; i < Game->number_of_dices; i++) {
    printf("%d ", Game->round_arr_dices[Game->round][i]);
  }
}

void roll_multiple_dices(struct Game_of_Yatzy *Game) {
  int i, random_dice;

  for (i = 0; i < Game->number_of_dices; i++) {
    random_dice = (rand() % MAX_DIE_EYES) + 1;

    Game->round_arr_dices[Game->round][i] = random_dice;
  }
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
