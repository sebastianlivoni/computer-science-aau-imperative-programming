/*
 * Title: Fodboldturnering
 * Assignment: Eksamensopgave 3
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
  unsigned short matches_played; /* matches played */
  unsigned short wins; /* won */
  unsigned short draws; /* draw */
  unsigned short loss; /* loss */
  unsigned short goals_for; /* goals for */
  unsigned short goals_against; /* goals against */
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
void load_matches(FILE* file, HashTable *teams, HashTable *matches);
void assert_mem_allocation(HashTable *table);
Date convert_to_date(char *date, char *time);
int hash_map(char *str);
HashTable *create_hashtable(int size);
int next_index(int index);
int index_of_team(HashTable *teams, char *team);
void add_match(HashTable *matches, HashTable *teams, char *home, char *away, unsigned int *result, unsigned int spectators, Weekday weekday, Date date);
void print_date(Date date);
int is_empty(Team *team);
void throughput_match_results(HashTable *teams, HashTable *matches);
void add_match_result_teams(HashTable *teams, Match *match, char *home_team, char *away_team);

int main(void) {
  FILE *input_fp;
  int i;

  HashTable *matches = create_hashtable(TOTAL_MATCHES);
  HashTable *teams = create_hashtable(TOTAL_TEAMS);

  for (i = 0; i < TOTAL_TEAMS; i++) {
    Team *team = malloc(sizeof(Team));
    strcpy(team->club, "");
    teams->items[i] = team;
  }

  input_fp = open_file(INPUT_FILE_URL);

  load_matches(input_fp, teams, matches);

  throughput_match_results(teams, matches);

  Team *my_team = teams->items[6];

  printf("%s %d\n", my_team->club, my_team->pts);

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

void load_matches(FILE* file, HashTable *teams, HashTable *matches) {
  char file_line[MAX_LINE_CHARACTERS];
  char weekday_lol[10],
       date[10],
       home[10],
       away[10],
       time[10];
  
  Weekday weekday = monday;
  Date new_date;

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

HashTable *create_hashtable(int size) {
  HashTable *table = (HashTable*) malloc(sizeof(HashTable) * size);

  assert_mem_allocation(table);

  table->items = malloc(size);
  table->count = 0;

  return table;
}

void add_match(HashTable *matches, HashTable *teams, char *home, char *away, unsigned int *result, unsigned int spectators, Weekday weekday, Date date) {
  Match *new_match = malloc(sizeof(Match));

  Team *home_team = teams->items[index_of_team(teams, home)];
  Team *away_team = teams->items[index_of_team(teams, away)];
  
  /* Copying all of the data into the match struct */
  new_match->home = home_team;
  new_match->away = away_team;
  memcpy(&new_match->result, &result, sizeof(result)); /* Copy the result array into the structs array */
  new_match->spectators = spectators;
  new_match->weekday = weekday;
  new_match->date_time = date;

  matches->items[matches->count] = new_match;
  matches->count += 1;
}

void throughput_match_results(HashTable *teams, HashTable *matches) {
  int i;

  for (i = 0; i < matches->count; i++) {
    Match *match = matches->items[i];

    add_match_result_teams(teams, match, ((Team*)match->home)->club, ((Team*)match->away)->club);
    /* I princippet kunne jeg egentlig bare overføre en pointer til teamet i stedet for at oveførte navnet og derefter finde index... */
  }

}

void add_match_result_teams(HashTable *teams, Match *match, char *home_team_name, char *away_team_name) {
  Team *home_team = teams->items[index_of_team(teams, home_team_name)];
  Team *away_team = teams->items[index_of_team(teams, away_team_name)];

  home_team->matches_played += 1;
  away_team->matches_played += 1;

  home_team->goals_for += match->result[0];
  home_team->goals_against += match->result[1];

  away_team->goals_for += match->result[1];
  away_team->goals_against += match->result[0];

  if (match->result[0] > match->result[1]) {
    home_team->pts += POINTS_GAME_WON;
    home_team->wins += 1;
  } else if (match->result[1] > match->result[0]) {
    away_team->pts += POINTS_GAME_WON;
    away_team->wins += 1;
  } else {
    home_team->pts += POINTS_GAME_DRAW;
    home_team->draws += 1;
    away_team->pts += POINTS_GAME_DRAW;
    away_team->draws += 1;
  }
}

int index_of_team(HashTable *teams, char *team_name) {
  int index = hash_map(team_name);

  /* Looping through until the array is both empty and team_name is not the same */
  while (!is_empty((teams->items[index])) && strcmp(team_name, ((Team*)teams->items[index])->club) != 0) {
    index = next_index(index);
  }

  /* Now we have an index for the team_name */
  if (is_empty(teams->items[index])) {
    /* The index team name is empty and we want to set it to something for it to not be empty */
    Team *team = (Team*)teams->items[index];


    strcpy(team->club, team_name);
  }

  return index;
}

int is_empty(Team *team) {
  return strcmp(team->club, "") == 0 ? 1 : 0;
}

int next_index(int index) {
  return (index < TOTAL_TEAMS - 1) ? index + 1 : 0;
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
