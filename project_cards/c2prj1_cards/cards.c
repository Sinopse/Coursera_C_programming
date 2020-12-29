#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  default: return "NOTHING";
  }
}

char value_letter(card_t c) {
  char val = c.value;


  switch(val) {
  case 2: return '\062';
  case 3: return '\063';
  case 4: return '\064';
  case 5: return '\065';
  case 6: return '\066';
  case 7: return '\067';
  case 8: return '\070';
  case 9: return '\071';
  case 10: return '\060';
  case 11: return '\112';
  case 12: return '\121';
  case 13: return '\113';
  case 14: return '\101';
  default: return '?';
  }
}


char suit_letter(card_t c) {
  char suit = c.suit;
  switch(suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }
}

void print_card(card_t c) {

  printf("%c%c ", value_letter(c), suit_letter(c));

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  switch(value_let) {
  case '2': temp.value = 2; break;
  case '3': temp.value = 3; break;
  case '4': temp.value = 4; break;
  case '5': temp.value = 5; break;
  case '6': temp.value = 6; break;
  case '7': temp.value = 7; break;
  case '8': temp.value = 8; break;
  case '9': temp.value = 9; break;
  case '0': temp.value = 10; break;
  case 'J': temp.value = 11; break;
  case 'Q': temp.value = 12; break;
  case 'K': temp.value = 13; break;
  case 'A': temp.value = 14; break;
  default: temp.value = 0; break;
  }

  switch(suit_let) {
  case 's': temp.suit = 0; break;
  case 'h': temp.suit = 1; break;
  case 'd': temp.suit = 2; break;
  case 'c': temp.suit = 3; break;
  default: temp.suit = 0; break;
  }


  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.suit = c / 13;
  temp.value = c % 13 + 2;

  return temp;
}
