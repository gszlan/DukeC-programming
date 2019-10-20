#include "future.h"
#include "deck.h"
#include <assert.h>


void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {

    if (index + 1 > fc->n_decks) {
        fc->decks = realloc(fc->decks,sizeof(*fc->decks) * (index + 1));
        for (int i = fc->n_decks; i <= index; i++) {
            fc->decks[i].cards = NULL;
            fc->decks[i].n_cards = 0;
        }
    }

    add_card_to(&fc->decks[index], *ptr); 

}


/*
   This function takes a deck (which has been shuffled),
   and a future_cards_t (which has been filled in with
   all the pointers to placeholders) and draws cards from
   the deck and assigns their values and suits to the
   placeholders pointed to in fc.
*/
void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {

    assert(deck->n_cards >= fc->n_decks);

    int deck_index = 0;
    for (int i = 0; i < fc->n_decks; i++) {
        if (fc->decks[i].n_cards == 0) {
            continue;
        }
        for(int j = 0; j < fc->decks[i].n_cards; j++) {
            *fc->decks[i].cards[j] = *deck->cards[deck_index]; 
        }
        deck_index++;
    }
}


