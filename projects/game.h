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