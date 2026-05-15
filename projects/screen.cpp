#include "screen.h"

// S C R E E N - S H O W
void Screen::printMenu() {
  cout << "--------------------------------------------" << endl << endl;
  cout << "HANGMAN" << endl;
  cout << "1. Play" << endl;
  cout << "2. Rules" << endl;
  cout << "3. Staistics" << endl;
  cout << "4. Exit" << endl;
  cout << "Please enter your choice: ";
};
void Screen::readUserInput(int &gameScore) {
  switch (*option) {
  case 0:
    printMenu();
    break;
  case 1:
    // update game score
    gameScore++;
    *prepGame = true;
    break;
  case 2:
    printRules(gameScore);
    break;
  case 3:
    printStatistics(gameScore);
    break;
  case 4:
    printExit();
    break;
  default:
    printError();
    break;
  };
};
void Screen::printRules(int &gameScore) {
  cout << "--------------------------------------------" << endl << endl;
  cout << "R U L E S" << endl << endl;
  cout << "1. The player choose a topic of the word." << endl;
  cout << "2. A word is generated and is shown in a line of dahses, each line "
          "represents a letter. "
       << endl;
  cout << "3. The player guess letter by letter." << endl;
  cout << "4. If correct, the location of the letter replaces the dashes"
       << endl;
  cout << "5. If incorrect, the player loose a life and the first symbol of "
          "the hangman will be drawn."
       << endl
       << endl;
  cout << "Enter |0 Menu| |1 Play| |2 Rules| |3 Statistics| |4 Exit|" << endl
       << endl;
  cout << "Number of games: " << gameScore << endl << endl;
  cout << "Please enter your choice: ";
};
void Screen::printStatistics(int &gameScore) {
  cout << "--------------------------------------------" << endl << endl;
  cout << "Statistics" << endl << endl;
  cout << "Number of games: " << gameScore << endl << endl;
  cout << "Enter |0 Menu| |1 Play| |2 Rules| |3 Statistics| |4 Exit|" << endl
       << endl;
  cout << "Please enter your choice: ";
};
void Screen::printExit() {
  cout << "--------------------------------------------" << endl << endl;
  cout << "System shutting down." << endl;
  cout << "See yaa later!" << endl;
  *runCode = false;
};
void Screen::printError() {
  cout << "--------------------------------------------" << endl << endl;
  cout << "Invalid opption, try again." << endl << endl;
  cout << "Enter your choice: ";
};