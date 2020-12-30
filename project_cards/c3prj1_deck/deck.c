#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){

  for (size_t index = 0; index < 6; index++) {
    card_t c = hand[index];
    print_card(c);
  }
  
}

// check if a deck contains a particular card
int deck_contains(deck_t * d, card_t c) {
  char val = c.value;
  char suit = c.suit;
  const char card[3] = {val, suit, '\0'};  // contains value and suit of a card

  // comparison by moving from char to char via pointers
  char *pcard = card;

  for (size_t index = 0; index < n_cards; index++) {
    char ***card_from_deck = &d.cards;
    char *p = *card_from_deck;	// value and suit of the comparison

    while (*p != '\0') {
      if (*pcard == 
  
  
  
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}
