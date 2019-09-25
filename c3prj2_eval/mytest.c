#include "cards.h"
#include "deck.h"
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>

void main() {

  card_t h1c1 = {5,SPADES};
  card_t h1c2 = {8,HEARTS};
  card_t h1c3 = {7,CLUBS};
  card_t h1c4 = {4,HEARTS};
  card_t h1c5 = {2,DIAMONDS};
  card_t h1c6 = {9,SPADES};
  card_t h1c7 = {3,SPADES};

  card_t *cards1[7] = {&h1c1, &h1c2, &h1c3, &h1c4, &h1c5, &h1c6, &h1c7};
  deck_t hand1 = {cards1, 7};
  deck_t * h1 = & hand1;
  print_hand(h1);printf("\n");

  print_card(*h1->cards[0]); 
  //qsort(hand1.cards[0], 7, sizeof(card_t), card_ptr_comp); 
  qsort((h1->cards[2]), 3, sizeof(card_t *), &card_ptr_comp); 
  printf("\nPo posortowaniu: \n");
  print_hand(h1);printf("\n");

}
