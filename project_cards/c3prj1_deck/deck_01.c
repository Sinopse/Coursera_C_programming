#include <stdio.h>
#include <stdlib.h>
#include "deck_01.h"

int deck_contains(deck_t * d, card_t c) {
  char val = c.value;
  char suit = c.suit;
  const char card[3] = {val, suit, '\0'};  // contains value and suit of a card

  printf("%s\n", card);
  /* // comparison by moving from char to char via pointers */
  /* char *pcard = card; */

  /* for (size_t index = 0; index < n_cards; index++) { */
  /*   char ***card_from_deck = &d.cards; */
  /*   char *p = *card_from_deck;	// value and suit of the comparison */

  /*   while (*p != '\0') { */
  /*     if (*pcard == *p) { */
	
  return 0;
}


int main () {

  card_t temp;
  temp.value = '9';
  temp.suit = 'c';

  deck_t deck;
  char *arr[] = {"0s", "Kh", "9c"}; // type should be card_t (member access?)
  deck.cards = arr;
  deck.n_cards = 3;
  
  deck_contains(deck.cards, temp);
  
  return 0;
}
