#include <string>

// The lexer reads the input stream and determines which characters are important.
// Characters are grouped to become tokens which are understood by the compiler.

class Lexer {
private:
  // Existing tokens in the Kaleidoscope Language
  // Assigned with a neg num as an id
  enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
  };

  // Filled in when token is "tok_identifier" or "tok_number"
  std::string IdentiferStr;
  double NumVal;

public:
  int gettok() {
    int LastChar = ' ';

    // Skip whitespace characters
    while (isspace(LastChar)) {
      LastChar = getchar();
    }

    // Determine token type (EOF, def, extern, identifier)
    if (isalpha(LastChar)) {
      IdentiferStr = LastChar;
      while (isalnum(LastChar = getchar())) {
        IdentiferStr += LastChar;
      }

      if (IdentiferStr == "def") {
        return tok_def;
      }
      if (IdentiferStr == "extern") {
        return tok_extern;
      }
      return tok_identifier;
    }

    // Determine token type (number)
    if (isdigit(LastChar) || LastChar == '.') {
      std::string NumStr;
      do {
        NumStr += LastChar;
        LastChar = getchar();
      } while (isdigit(LastChar) || LastChar == '.');

      NumVal = strtod(NumStr.c_str(), 0);
      return tok_number;
    }

    // Ignore comments (#)
    if (LastChar == '#') {
      do {
        LastChar = getchar();
      } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

      if (LastChar != EOF) {
        return gettok();
      }

      if (LastChar == EOF) {
        return tok_eof;
      }

      // Operator Character (eg. +)
      int ThisChar = LastChar;
      LastChar = getchar();
      return ThisChar;
    }
  }
};