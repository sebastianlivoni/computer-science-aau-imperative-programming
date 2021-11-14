/*
 * Title: Spillekort
 * Description: 
 * Assignment: Opgave 12.4 
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/structures-ex-calendar-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 55 /* 52 "normal" playing cards and 3 jokers */

typedef struct {
  int suit;
  int value;
} card;

card generate_deck();
int sort_deck(const void *a, const void *b);
char* suit_to_text(int suit);
char* value_to_text(int value);
card shuffle_deck(card *deck);

enum suit {clubs, diamonds, hearts, spades, joker};
enum value {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

int main(void) {
  int i;
  card deck[DECK_SIZE]; 

  srand(time(NULL));

  /* Generate random deck */
  generate_deck(deck);
  shuffle_deck(deck);

  qsort(deck, DECK_SIZE, sizeof(deck[0]), sort_deck);

  for (i = 0; i < DECK_SIZE; i++) {
    if (deck[i].suit == joker) {
      printf("Joker - %d\n", i);
    } else {
      printf("%s ", suit_to_text(deck[i].suit));
      printf("%s ", value_to_text(deck[i].value));
      printf("- %d\n", i);
    }
  }

  return 0;
}

int sort_deck(const void *a, const void *b) {
  card *card1 = (card *)a;
  card *card2 = (card *)b;

  /* Return -1 if card1 comes before card2 */
  /* Return 1 if card1 comes after card2 */
  /* Return 0 if card1 are equal to card2 */

  /* Klør ♣, ruder ♦, hjerter ♥, spar ♠ */
  if (card1->suit == card2->suit)
    return card1->value - card2->value; /* Return based on value because suit is the same */
  else if (card1->suit < card2->suit)
    return -1; /* Card1 suit is smaller than card2 which means card1 comes before card2 */
  else
    return 1; /* Otherwise card2 is bigger than card1 and comes after card1*/
}

card generate_deck(card *deck) {
  int i, j, count = 0;
  /* For each suit */
  for (i = 3; i >= 0; i--) {
    /* For each value from ace to king */
    for (j = 1; j <= 13; j++) {
      deck[count].suit = i;
      deck[count].value = j;
      count++;
    }
  }
  /* Add three jokers */
  for (i = 0; i < 3; i++) {
    deck[count].suit = joker;
    deck[count].value = 0;
    count++;
  }
  return *deck;
}

card shuffle_deck(card *deck) {
  int i, random_int;
  card temp;
  for (i = 0; i < DECK_SIZE; i++) {
    random_int = rand() % DECK_SIZE; /* Find random integer */

    /* swap the two cards */
    temp = deck[random_int];
    deck[random_int] = deck[i]; 
    deck[i] = temp;
  }

  return *deck;
}

char* suit_to_text(int suit) {
  char *return_value;
  switch(suit) {
    case 0: return_value = "♣";
      break;
    case 1: return_value = "♦";
      break;
    case 2: return_value = "♥";
      break;
    case 3: return_value = "♠";
      break;
    case 4: return_value = "Joker";
      break;
    default: return_value = "";
      break;
  }
  return return_value;
}

char* value_to_text(int value) {
  char *return_value;
  switch(value) {
    case 1: return_value = "Ace";
      break;
    case 2: return_value = "Two";
      break;
    case 3: return_value = "Three";
      break;
    case 4: return_value = "Four";
      break;
    case 5: return_value = "Five";
      break;
    case 6: return_value = "Six";
      break;
    case 7: return_value = "Seven";
      break;
    case 8: return_value = "Eight";
      break;
    case 9: return_value = "Nine";
      break;
    case 10: return_value = "Ten";
      break;
    case 11: return_value = "Jack"; 
      break;
    case 12: return_value = "Queen";
      break;
    case 13: return_value = "King";
      break;
    default: return_value = "";
      break;
  }
  return return_value;
}
