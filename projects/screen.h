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