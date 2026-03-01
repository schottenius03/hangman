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
}