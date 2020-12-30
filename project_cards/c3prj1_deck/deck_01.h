#ifndef DECK_01_H
#define DECK_01_H
typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;

struct card_tag {
  unsigned value;
  suit_t suit;
};
typedef struct card_tag card_t;

struct deck_tag {
  card_t ** cards;
  size_t n_cards;
};
typedef struct deck_tag deck_t;
#endif
