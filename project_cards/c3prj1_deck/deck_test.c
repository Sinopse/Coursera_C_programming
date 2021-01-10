#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck_01.h"

/* void print_hand(deck_t * hand){ /\* an array is passed in *\/ */
/*   size_t hand_size = hand->n_cards; /\* if passed in *\/ */
    
/*   for (size_t index = 0; index < hand_size; index++) { */
/*     card_t currCard = *hand->cards[index]; */
/*     print_card(currCard); */
/*   } */
  
/* } */

// check if a deck contains a particular card
int deck_contains(deck_t * d, card_t c) {
  size_t deck_size = d->n_cards;
  card_t *pc = &c;		// a pointer to card temp
   
  for (int index = 0; index < deck_size; index++) {
    card_t currCard = *d->cards[index];
    printf("Current card: %c%c\n", currCard.value, currCard.suit);
    if (pc->value == currCard.value && pc->suit == currCard.suit) {
      printf("Contains %c%c\n", currCard.value, currCard.suit);
      return 1;
    }
    else {
      //      printf("do not match\n");
      // return 0;
    }
  }
  return EXIT_SUCCESS; // return 0
}

void shuffle(deck_t * d){

  size_t deck_size  = d->n_cards;
  card_t **cards = d->cards;  /* two **? should we declre it at all?*/

  card_t currCard, swapCard;

  for (int index = 0; index < deck_size; index++) {

    unsigned gen_pos = random() % deck_size; /* generating random position within a deck */

    swapCard = *d->cards[gen_pos];		     /* can be rewritten? */
    currCard = *d->cards[index];

    cards[index] = &swapCard;
    cards[gen_pos] = &currCard;
  }
 }

void assert_full_deck(deck_t * d) {

    for (int index = 0;  index < d->n_cards; index++) {
    card_t check_card = *d->cards[index]; /* need to understand this better */
    printf("Checking for: %c%c\n", check_card.value, check_card.suit);

    
    int ans = deck_contains(d, check_card);
        
    
    printf("ans %d\n", ans);
    printf("\n");
    /* printf("Checking for duplicates: %d%d\n", currCard.value, currCard.suit); */
    /* assert(pc->value != currCard.value && pc->suit != currCard.suit); */
  }
}

  int main () {

  card_t temp;
  temp.value = '9';
  temp.suit = 'c';

  card_t temp1;
  temp1.value = 'A';
  temp1.suit = 'd';

  card_t temp2;
  temp2.value = '7';
  temp2.suit = 'd';

  card_t passed_card;		/* search for this specific card */
  passed_card.value = 'A';
  passed_card.suit = 'd';
  
  
  deck_t deck;
  deck.n_cards = 3;		/* number of cards in deck */
  unsigned deck_size = deck.n_cards;
  
  // initialize an  array of cards
  card_t *arr_cards[deck_size];

  arr_cards[0] = &temp;		/* pointer to the first element is the address */
  arr_cards[1] = &temp1;
  arr_cards[2] = &temp2;  

  deck.cards = arr_cards;

  // print_hand(&deck);
  deck_contains(&deck, passed_card);	/* need to understand this why reference */
  //shuffle(&deck);
  //assert_full_deck (&deck);

  
  return 0;
}


