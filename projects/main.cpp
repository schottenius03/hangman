#include <iostream>
#include <cstdlib> // acess rand() function to generate random number
// include personal libraries
#include "screen.h"
#include "game.h"
#include "library.h"
#include "player.h"
using namespace std; // shortcut

int main() {
  // declarations
  static int gameScore = 0;
  // create instance
  Screen show;
  show.printMenu();
  // loop in menu
  while (show.runCode) {
    // user input
    cin >> *show.option;
    // match user input to class game variable
    show.readUserInput(gameScore);
    // prepare the game
    if (*show.prepGame == true) {
      // create instance of class Game
      Game session;
      // ----------
      session.resetValues();
      session.printCategory();
      // creat << e instance for class Library
      Library read;
      cin >> *read.category;
      // call function to chose a word
      read.randomizeWord();
      // save chosen word from library function to variable in class Game
      session.gameWord = *read.chosenWord;
      // set displayWord to same number of dashes as the lenght
      session.prepDisplayWord();
      while (*session.gameOn == true) {
        // draw figure
        session.drawHangman();
        // print status
        session.printGame();
        // user input
        cin >> session.letter;
        // // update values
        session.updateStatus();
        // check if game over
        session.checkGameOver();
        // determine if finish
        if (*session.status == 1) {
          session.printWin();
          show.printMenu();
        } else if (*session.status == 2) {
          session.drawHangman();
          session.printLoose();
          show.printMenu();
        } else {
          cout << "";
        }
      }
    }
  }
}
