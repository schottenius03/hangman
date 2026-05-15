#include "game.h"

// G A M E - S E S S I O N
void Game::printCategory() {
  // update gameOn status
  *gameOn = true;
  cout << "--------------------------------------------" << endl << endl;
  cout << "Chose a topic! " << endl;
  cout << "1. Fruits" << endl;
  cout << "2. Colours" << endl;
  cout << "Please enter your choice: ";
};
void Game::prepDisplayWord() {
  for (int i = 0; i < gameWord.size(); i++) {
    displayWord += '_';
  }
  *gameOn = true;
};
void Game::drawHangman() {
  cout << "--------------------------------------------" << endl << endl;
  switch (*attempt) {
  case 14:
    break;
  case 13:
    cout << "----------------------------------" << endl << endl;
    break;
  case 12:
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 11:
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 10:
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|                       " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 9:
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 8:
    cout << "          ----------              " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 7:
    cout << "          ----------              " << endl;
    cout << "          |/                      " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 6:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 5:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |                       " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 4:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |        |              " << endl;
    cout << "          |                       " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 3:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |        |              " << endl;
    cout << "          |       /               " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 2:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |        |              " << endl;
    cout << "          |       / \\            " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 1:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |       \\|              " << endl;
    cout << "          |       / \\            " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  case 0:
    cout << "          ----------              " << endl;
    cout << "          |/       |              " << endl;
    cout << "          |        O              " << endl;
    cout << "          |       \\|/            " << endl;
    cout << "          |       / \\            " << endl;
    cout << "         /|\\                     " << endl;
    cout << "      ---------                   " << endl;
    cout << "     /         \\                 " << endl;
    cout << "----------------------------------" << endl << endl;
    break;
  default:
    break;
  }
};
void Game::printGame() {
  // loop to print out the display word
  for (int i = 0; i < gameWord.size(); i++) {
    cout << displayWord[i] << " ";
  }
  cout << endl << endl;
  cout << "Attempts left: " << *attempt << endl;
  cout << "Letters guessed: ";
  for (int i = 0; i < letterHistory.size(); i++) {
    cout << letterHistory[i] << " ";
  }
  cout << endl;
  cout << "Please enter your guess: ";
};
void Game::updateStatus() {
  // check if in the chosen word
  for (int i = 0; i < gameWord.size(); i++) {
    if (*letter == gameWord[i]) {
      break;
    } else {
      continue;
    }
  }

  // check if letter already gueesed
  for (int j = 0; j < letterHistory.size(); j++) {
    if (*letter == letterHistory[j]) {
      *alreadyGuess = true;
      break;
    }
  }

  // outcome duplicate go back
  if (*alreadyGuess == false) {
    // update letters guess
    letterHistory += *letter;
  } else {
  }

  // update display word
  for (int k = 0; k < displayWord.size(); k++) {
    if (*letter == gameWord[k]) {
      // substitue dash with guessed letter in that position
      if (*dash == displayWord[k]) {
        displayWord[k] = *letter;
        *update = *update + 1;
      }
    }
  }
  // outcome user's guess change or not
  if (*alreadyGuess == true) {
    if (*update != 0) {
      *attempt = *attempt - 1;
    } else {
      cout << "--------------------------------------------" << endl;
      cout << "Already guessed, try another letter :)" << endl;
    }
  } else {
    if (*update == 0) {
      *attempt = *attempt - 1;
    }
  }

  // reset values for next round (could not dynamically do this with nothrow)
  *update = 0;
  *alreadyGuess = false;
};
void Game::checkGameOver() {
  // count nr of dashes
  for (int p = 0; p < gameWord.size(); p++) {
    if (*dash == displayWord[p]) {
      *dashLeft = *dashLeft + 1;
    }
  }

  if (*attempt <= 0) {
    *status = 2;
    *gameOn = false;
  } else {
    if (*dashLeft == 0) {
      *status = 1;
      *gameOn = false;
    }
  }

  // reset value for enxt round
  *dashLeft = 0;
};
// function outcome of the game.,mn bvc
void Game::printWin() {
  cout << "--------------------------------------------" << endl << endl;
  cout << "CONGRATS YOU WON! :D" << endl;
  cout << "The word was: " << gameWord << endl;
};
void Game::printLoose() {
  cout << "--------------------------------------------" << endl << endl;
  cout << "You lost :(" << endl;
  cout << "Better luck next time!" << endl;
  cout << "The word was: " << gameWord << endl;
};

void Game::resetValues() {
  // reset values
  *letterExist = false;
  *attempt = 14;
  *alreadyGuess = 0;
  *letter = ' ';
  gameWord.clear();
  displayWord.clear();
  letterHistory.clear();
  *status = 0;
};