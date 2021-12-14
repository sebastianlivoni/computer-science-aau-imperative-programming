/*
 * Title: Fodboldturnering
 * Assignment:  Eksamensopgave 3
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Filer-IO/opgave-3.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: December 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INPUT_FILE_URL "kampe-2020-2021.txt"
#define MAX_LINE_CHARACTERS 60
#define TOTAL_TEAMS 12
#define TOTAL_MATCHES TOTAL_TEAMS * (TOTAL_TEAMS - 1)
#define POINTS_GAME_WON 3
#define POINTS_GAME_DRAW 1
#define POINTS_GAME_LOST 0
#define NOT_FOUND -1

typedef enum {monday, tuesday, wednesday, thursday, friday, saturday, sunday} Weekday;

typedef struct tm Date; /* Structure containing a calendar date and time broken down into its components. */

typedef struct {
  unsigned short mp; /* matches played */
  unsigned short w; /* won */
  unsigned short d; /* draw */
  unsigned short l; /* loss */
  unsigned short gf; /* goals for */
  unsigned short ga; /* goals against */
  unsigned short pts; /* points */
  char club[5]; /* club name */
} Team;

typedef struct {
  Team *home; /* Pointer to home team struct */
  Team *away; /* Pointer to away team struct */
  int result[2]; /* [0]: home_team goals, [1]: away_team goals */
  unsigned int spectators; /* more than 65,535 spectators on some stadions */
  Weekday weekday;
  Date date_time;
} Match;

typedef struct {
  void **items;
  unsigned short count;
} HashTable;

/* Prototypes */
FILE *open_file(char *file_url);
void load_data(FILE* file, HashTable *teams, HashTable *matches);
void assert_mem_allocation(HashTable *table);
Date convert_to_date(char *date, char *time);
int hash_map(char *str);
HashTable *create_table();
int next_index(int index);
int index_of_team(HashTable *teams, char *team);
void add_match(HashTable *matches, HashTable *teams, char *home, char *away, unsigned int *result, unsigned int spectators, Weekday weekday, Date date);
void print_date(Date date);
int is_empty(Team *team);

int main(void) {
  FILE *input_fp;
  int i;

  HashTable *matches = create_table();
  HashTable *teams = create_table();

  for (i = 0; i < TOTAL_TEAMS; i++) {
    Team *team = malloc(sizeof(Team));
    strcpy(team->club, "");
    teams->items[i] = team;
  }

  input_fp = open_file(INPUT_FILE_URL);

  load_data(input_fp, teams, matches);

  free(matches);
  free(teams);

  return EXIT_SUCCESS;
}

FILE *open_file(char *file_url) {
  FILE* file = fopen(file_url, "r");
  if (file == NULL) {
    printf("Could not open file %s!\n", file_url);
    exit(EXIT_FAILURE);
  } else {
    return file;
  }
}

void load_data(FILE* file, HashTable *teams, HashTable *matches) {
  Date new_date;
  
  char file_line[MAX_LINE_CHARACTERS];
  char weekday_lol[10],
       date[10],
       home[10],
       away[10],
       time[10];
  
  Weekday weekday = monday;

  unsigned int result[2],
               spectators;

  while (fgets(file_line, MAX_LINE_CHARACTERS, file)) {
    sscanf(file_line, "%s %s %s %s - %s %d - %d %d", weekday_lol, date, time, home, away, &result[0], &result[1], &spectators);
  
    new_date = convert_to_date(date, time);

    add_match(matches, teams, home, away, result, spectators, weekday, new_date);
  }
}

int hash_map(char *str) {
  unsigned short length = strlen(str),
                 sum = str[0] + str[length / 2] + str[length - 1];

  return sum % TOTAL_TEAMS;
}

HashTable *create_table() {
  /*HashTable *table = (HashTable*) malloc(sizeof(HashTable));*/
  HashTable *table = (HashTable*) malloc(sizeof(HashTable) * TOTAL_TEAMS);

  assert_mem_allocation(table);

  table->items = malloc(TOTAL_TEAMS);
  table->count = 0;

  return table;
}

void add_match(HashTable *matches, HashTable *teams, char *home, char *away, unsigned int *result, unsigned int spectators, Weekday weekday, Date date) {
  Match *match = malloc(sizeof(Match));

  int index = index_of_team(teams, home);
  
  if (index == NOT_FOUND) {
    index = hash_map(home);
    while (!is_empty((Team*)teams->items[index])) {
      index = next_index(index);
    }

    Team *team = (Team*)teams->items[index];

    strcpy(team->club, home);

    printf("Added team: %s %d\n", team->club, index);
  }

  /*match->result[0] = result[0];
  match->result[1] = result[1];
  match->spectators = spectators;
  match->weekday = weekday;
  match->date_time = date;

  matches->items[matches->count++] = match;*/
}

int index_of_team(HashTable *teams, char *team_name) {
  int index = hash_map(team_name);
  if (!is_empty(((Team*)teams->items[index]))) {
    return index;
  }
  return NOT_FOUND;
}

int is_empty(Team *team) {
  return strcmp(team->club, "") == 0 ? 1 : 0;
}

int next_index(int index) {
  return index < TOTAL_TEAMS - 1 ? index + 1 : 0;
}

Date convert_to_date(char *date, char *time) {
  Date converted_date;
  
  char str[30];
  snprintf(str, sizeof(str), "%s %s", date, time);
  strptime(str, "%d/%m %H.%S", &converted_date);
  return converted_date;
}

void assert_mem_allocation(HashTable *table) {
  if (table == NULL) {
    printf("Could not allocate memoery for table!\n");
    exit(EXIT_FAILURE);
  }
}

void print_date(Date date) {
  /*strptime("11/09 19.00", "%d/%m %H.%S", &tm);*/
  printf("%02d/%02d %02d:%02d\n", date.tm_mday, date.tm_mon + 1, date.tm_hour, date.tm_sec);
}
