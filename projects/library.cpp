#include "library.h"

// L I B R A R Y - R E A D
void Library::randomizeWord() {
  // generate random word between 1-9
  *position = rand() % 10 + 1;
  // assign category and position to chosenWord
  *chosenWord = database[*category][*position];
};
