#include <stdio.h>
#include <stdlib.h>
#include "deck_01.h"

int deck_contains(deck_t * d, card_t c) {

  size_t deck_size = d->n_cards;
  card_t *pc = &c; // a pointer to card temp
  for (int index = 0; index < deck_size; index++) {
    card_t currCard = *d->cards[index];
    if (pc->value == currCard.value && pc->suit == currCard.suit) {
      printf("match\n");
    }
    else {
      printf("do not match\n");
    }
  }
  return 0;
}


int main () {

  card_t temp;
  temp.vaplue = '9';
  temp.suit = 'c';

  card_t temp1;
  temp1.value = 'K';
  temp1.suit = 's';

  card_t passed_card;		/* search for this specific card */
  passed_card.value = 'K';
  passed_card.suit = 's';
  
  
  deck_t deck;
  deck.n_cards = 52;		/* number of cards in deck */
  unsigned deck_size = deck.n_cards;
  
  // initialize an  array of cards
  card_t *arr_cards[deck_size];

  arr_cards[0] = &temp;		/* pointer to the first element is the address */
  arr_cards[1] = &temp1;  

  deck.cards = arr_cards; 
  deck_contains(&deck, passed_card);	/* need to understand this why reference */
  
  return 0;
}
