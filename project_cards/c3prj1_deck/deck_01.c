#include <stdio.h>
#include <stdlib.h>
#include "deck_01.h"

int deck_contains(deck_t * d, card_t c) {
  card_t *pc = &c; // a pointer to card temp

  card_t currCard = *d->cards[0];

  if (pc->value == currCard.value && pc->suit == currCard.suit) {
    printf("match\n");
  }
  
  
  return 0;
}


int main () {

  card_t temp;
  temp.value = '9';
  temp.suit = 'c';

  deck_t deck;
  deck.n_cards = 51;
  unsigned size = deck.n_cards;
  
  // initialize an  array of cards
  card_t *arr_cards[1];
  arr_cards[0] = &temp;		/* pointer to the first element is the address */
  printf("card: %c%c\n", arr_cards[0]->value,
	 arr_cards[0]->suit); 

  deck.cards = arr_cards; 
  
  deck_contains(&deck, temp);	/* need to understand this why reference */
  
  return 0;
}
