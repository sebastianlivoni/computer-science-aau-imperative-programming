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

#define INPUT_FILE_URL "kampe-2020-2021.txt"
#define MAX_LINE_CHARACTERS 60
#define NUM_OF_TEAMS 12
#define MEET_EACHOTHER_TIMES 2
#define NUM_OF_MATCHES NUM_OF_TEAMS * (NUM_OF_TEAMS - 1)
#define NOT_FOUND -1
#define POINTS_GAME_WON 3
#define POINTS_GAME_DRAW 1
#define POINTS_GAME_LOST 0

struct team {
  char team_name[50];
  int points;
  int goals_scored;
  int goals_against;
};
typedef struct team team;

struct game {
  char week_day[100];
  char date[100];
  char time[100];
  char home_team[4];
  char away_team[4];
  int result[2];
  int spectators;
};
typedef struct game game;

FILE* load_file(char* file_url);
game* load_matches(FILE* file);
team* throughput_match_results(game* games);
int hash_team_name(char *team_name);
int is_empty(team team);
int next_index(int i);
int index_of_team(char *team_name, team* teams);
int add_team_scores(char *team_name, int goals_scored, int goals_against, team* teams);
void prnt_positions(team* teams);
void sort_teams(team* teams);
int cmp_sort(const void * a, const void * b);

int main(void) {
  FILE* input_fp;
  game* games;
  team* teams;
  
  input_fp = load_file(INPUT_FILE_URL);

  games = load_matches(input_fp);

  teams = throughput_match_results(games);
  sort_teams(teams);

  prnt_positions(teams);

  return EXIT_SUCCESS;
}

FILE* load_file(char* file_url) {
  FILE* file = fopen(file_url, "r");
  if (file == NULL) {
    printf("Could not open file %s!\n", file_url);
    exit(EXIT_FAILURE);
  }

  return file;
}

game* load_matches(FILE* file) {
  game *games = malloc(sizeof(game) * NUM_OF_MATCHES);
  char read_line[MAX_LINE_CHARACTERS];
  int i;

  i = 0;
  while (fgets(read_line, MAX_LINE_CHARACTERS, file)) {
    sscanf(read_line, "%s %s %s %s - %s %d - %d %d", games[i].week_day, games[i].date, games[i].time, games[i].home_team, games[i].away_team, &games[i].result[0], &games[i].result[1], &games[i].spectators);
    i++;
  }

  fclose(file);

  return games;
}

team* throughput_match_results(game* games) {
  team *teams = malloc(sizeof(team) * NUM_OF_TEAMS);
  int i;
  /* Teams initialization */
  for (i = 0; i < NUM_OF_TEAMS; i++) {
    strcpy(teams[i].team_name, "");
  }

  for (i = 0; i < NUM_OF_MATCHES; i++) {
    
    add_team_scores(games[i].home_team, games[i].result[0], games[i].result[1], teams);
    add_team_scores(games[i].away_team, games[i].result[1], games[i].result[0], teams);
  }

  return teams;
}

/* Example from file a3.c about associative arrays from Kurt Nørmarks lesson 9 */
int hash_team_name(char *team_name) {
  int name_len = strlen(team_name);
  int sum = team_name[0] + team_name[name_len/2] + team_name[name_len-1];
  return sum % NUM_OF_TEAMS;
}

int add_team_scores(char *team_name, int goals_scored, int goals_against, team* teams) {
  int index;

  index = index_of_team(team_name, teams);

  if (index == NOT_FOUND) {
    index = hash_team_name(team_name);
    while (!is_empty(teams[index])) {
      index = next_index(index);
    }

    strcpy(teams[index].team_name, team_name);
  }
  
  teams[index].goals_scored += goals_scored;
  teams[index].goals_against += goals_against;
  teams[index].points += goals_scored > goals_against ? POINTS_GAME_WON : goals_scored == goals_against ? POINTS_GAME_DRAW : POINTS_GAME_LOST;
  
  return index;
}

int index_of_team(char *team_name, team* teams) {
  int index = hash_team_name(team_name);
  while (!is_empty(teams[index]) && strcmp(team_name, teams[index].team_name) != 0) {
    index = next_index(index);
  }

  if (is_empty(teams[index])) {
    return NOT_FOUND;
  } else {
    return index;
  }
}

int is_empty(team team) {
  return strcmp(team.team_name, "") == 0 ? 1 : 0;
}

int next_index(int i) {
  return (i < NUM_OF_TEAMS - 1) ? i + 1 : 0;
}

void sort_teams(team* teams) {
  qsort(teams, NUM_OF_TEAMS, sizeof(team), cmp_sort);
}

int cmp_sort(const void * a, const void * b) {
  int val, t1_goal_difference, t2_goal_difference;
  team* t1 = (team*)a;
  team* t2 = (team*)b;

  val = t2->points - t1->points;

  if (val == 0) {
    t1_goal_difference = t1->goals_scored - t1->goals_against;
    t2_goal_difference = t2->goals_scored - t2->goals_against;
    
    return t2_goal_difference - t1_goal_difference;
  } else {
    return val;
  }
}

void prnt_positions(team* teams) {
  int i;

  printf("%18s %13s %20s %16s\n",
    "Holdnavn",
    "Point",
    "Mål-af-hold",
    "Mål-mod-hold"
  );
  for (i = 0; i < NUM_OF_TEAMS; i++) {
    printf(
      "%15s %15d %15d %15d\n",
      teams[i].team_name,
      teams[i].points,
      teams[i].goals_scored,
      teams[i].goals_against
    );
  }
}
