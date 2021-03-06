#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){ /* an array is passed in */
  size_t hand_size = hand->n_cards; /* if passed in */
    
  for (size_t index = 0; index < hand_size; index++) {
    card_t currCard = *hand->cards[index];
    print_card(currCard);
  }
  
}

// check if a deck contains a particular card
int deck_contains(deck_t * d, card_t c) {
  size_t deck_size = d->n_cards;
  card_t *pc = &c;		// a pointer to card temp
   
  for (size_t index = 0; index < deck_size; index++) {
    card_t currCard = *d->cards[index];

    if (pc->value == currCard.value && pc->suit == currCard.suit) {

      return 1;
    }
  }
  return 0; // return 0
}

void shuffle(deck_t * d){

  size_t deck_size  = d->n_cards;
  card_t **cards = d->cards;  /* two **? should we declre it at all?*/

  card_t *currCard, *swapCard;

  for (int index = 0; index < deck_size; index++) {

    unsigned gen_pos = random() % deck_size; /* generating random position within a deck */

    swapCard = cards[gen_pos];		     /* is a pointer to card_t */
    currCard = cards[index];		     // pointer is equal to pointer

    cards[index] = swapCard;
    cards[gen_pos] = currCard;
  }
}

void assert_full_deck(deck_t * d) {
  size_t deck_size = d->n_cards;
  
  for (size_t index = 0;  index < deck_size; index++) {
    card_t check_card = *d->cards[index]; /* need to understand this better */
    printf("**** Checking for: %c%c ****\n", check_card.value, check_card.suit);

    unsigned cnt = 0;		/* basic counter */
    for (size_t index = 0; index < deck_size; index++) {
      card_t currCard = *d->cards[index];
      printf("Current card: %c%c\n", currCard.value, currCard.suit);
      if (check_card.value == currCard.value && check_card.suit == currCard.suit) {
	printf("Contains %c%c\n", currCard.value, currCard.suit);
	cnt++;
      }    

    printf("cnt %d\n", cnt);
    printf("\n");
    assert(cnt != 2);
    }
  }
}
