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

  
  
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}
