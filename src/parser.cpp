#include "lexer.hpp"

class Parser {
    static int CurTok;

    static int getNextToken() {
        return CurTok = Lexer::gettok();
    }
};