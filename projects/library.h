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