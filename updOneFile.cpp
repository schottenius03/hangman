#include <cstdlib> // acess rand() function to generate random number
#include <iostream>
using namespace std; // shortcut
class Screen {
  // no private variables
public:
  // declarations
  int *option;
  bool *runCode;
  bool *prepGame;
  int *gameScore;
  // constructor
  Screen() {
    option = new (nothrow) int(0);
    runCode = new (nothrow) bool(true);
    prepGame = new (nothrow) bool(false);
    gameScore = new (nothrow) int(0);
  }
  // functions
  void printMenu();
  void readUserInput(int &gameScore); // send my reference parameter &
  void printRules(int &gameScore);
  void printStatistics(int &gameScore);
  void printExit();
  void printError();
  // deconstructor
  ~Screen() = default;
};
class Game {
private:
  string displayWord;
  string letterHistory;
  int *attempt;
  bool *letterExist;
  bool *alreadyGuess;
  int *update;
  char *dash;
  bool *win;
  int *dashLeft;

public:
  bool *gameOn;
  string gameWord; // public to save from main
  int *status;
  char *letter;
  // constructor
  Game() {
    gameOn = new (nothrow) bool(false);
    letterExist = new (nothrow) bool(false);
    attempt = new (nothrow) int(14);
    status = new (nothrow) int(0);
    alreadyGuess = new (nothrow) bool(0);
    letter = new (nothrow) char(' ');
    dash = new (nothrow) char('_');
    update = new (nothrow) int(0);
    win = new (nothrow) bool(false);
    dashLeft = new (nothrow) int(0);
    gameWord = "";
    displayWord = "";
    letterHistory = "";
  };
  // deconstructor
  ~Game() = default;
  // functions
  void printCategory();
  void prepDisplayWord();
  void drawHangman();
  void printGame();
  void updateStatus();
  void resetValues(); // did not have time for using nothrow on variables
  void checkGameOver();
  void printWin();
  void printLoose();
};
class Library {
private:
  // declarations
  int *position;
  string database[10][2] = {
      {"Fruits", "Colours"},     {"apple", "red"},       {"banana", "orange"},
      {"blueberry", "yellow"},   {"raspberry", "green"}, {"kiwi", "blue"},
      {"watermellon", "violet"}, {"grape", "indingo"},   {"avocado", "white"},
      {"mango", "black"},
  };

public:
  // declarations
  int *category;
  string *chosenWord;
  void randomizeWord();
  // constructor
  Library() {
    category = new (nothrow) int(0);
    position = new (nothrow) int(0);
    chosenWord = new (nothrow) string("");
  }
  // deconstructor
  ~Library() = default;
};

class Player {
private: 
string *username;
public:
  // constructor
  Player() {
    username = new (nothrow) string("");
  }
  // deconstructor 
  ~Player() {
    delete username;
  }
};

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
      // try catch block for user input - no time 
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

// L I B R A R Y - R E A D
void Library::randomizeWord() {
  // generate random word between 1-9
  *position = rand() % 10 + 1;
  // assign category and position to chosenWord
  *chosenWord = database[*category][*position];
};
