/*
 * Title: En tilfældig menu
 * Description: Definer tre forskellige enumeration typer for hhv. forret, hovedret og dessert.d
 * Assignment: Opgave 8.1 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/types-enumeration-typer-3-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 27, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEAL_SIZE 4

void print_meal(void);
int gen_random_int(void);

enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_har};
enum dessert {pandekager_med_is, gulerodskage, choklademousse, citronfromage};

int main(void) {

  srand(time(NULL));

  for(int i = 0; i <= 30; i++) {
    print_meal();
  }



}

void print_meal(void) { 
  printf("Forret: ");
  switch((enum forret) gen_random_int()) {
    case guacamole:
      printf("Guacamole");
      break;
    case tarteletter:
      printf("Tarteletter");
      break;
    case lakserulle:
      printf("Lakserulle");
      break;
    case graeskarsuppe:
      printf("Græskarsuppe");
      break;
  }

  printf(" - Hovedret: ");
  switch((enum hovedret) gen_random_int()) {
    case gyldenkaal:
      printf("Gyldenkådl");
      break;
    case hakkeboef:
      printf("Hakkebøf");
      break;
    case gullash:
      printf("Gullash");
      break;
    case forloren_har:
      printf("Forloren Hare");
      break;
  }
  printf(" - Dessert: ");
  switch((enum dessert) gen_random_int()) {
    case pandekager_med_is:
      printf("Pandekager med is");
      break;
    case gulerodskage:
      printf("Gulerodskage");
      break;
    case choklademousse:
      printf("Choklademousse");
      break;
    case citronfromage:
      printf("Citronfromage");
      break;
  }

  printf("\n");

}

int gen_random_int(void) {
  return (rand() % MEAL_SIZE);
}