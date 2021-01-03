#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck_01.h"

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
   
  for (int index = 0; index < deck_size; index++) {
    card_t currCard = *d->cards[index];
    printf("Current card: %c%c\n", currCard.value, currCard.suit);
    if (pc->value == currCard.value && pc->suit == currCard.suit) {
      printf("Contains %c%c\n", currCard.value, currCard.suit);
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
    printf("gen_pos: %d index: %d\n", gen_pos, index);


    swapCard = cards[gen_pos];		     /* is a pointer to card_t */
    currCard = cards[index];		     // pointer is equal to pointer

    printf("swapCard: %c%c\n", swapCard->value, swapCard->suit);
    printf("currCard: %c%c\n", currCard->value, currCard->suit);
    
    cards[index] = swapCard;
    cards[gen_pos] = currCard;

  /* print out contents of the array */
  for (int index = 0; index < deck_size; index++) {
    currCard = cards[index];    
    printf("Current card [%d]: %c%c\n",index, currCard->value, currCard->suit);
    
  }
  printf("\n");
  }


}

void assert_full_deck(deck_t * d) {
  size_t deck_size = d->n_cards;
  
  for (int index = 0;  index < deck_size; index++) {
    card_t check_card = *d->cards[index]; /* need to understand this better */
    printf("**** Checking for: %c%c ****\n", check_card.value, check_card.suit);

    unsigned cnt = 0;		/* basic counter */
    for (int index = 0; index < deck_size; index++) {
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

  //print_hand(&deck);
  //deck_contains(&deck, passed_card);	/* need to understand this why reference */
  shuffle(&deck);
  //assert_full_deck (&deck);

  
  return 0;
}


