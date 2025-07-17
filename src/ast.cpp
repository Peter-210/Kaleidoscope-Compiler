class ExprAST {
public:
    // Set as virtual to properly deconstruct all inherited classes.
    // Explicitly defined as default to ensure proper deconstruction.
    virtual ~ExprAST() = default;
};

class NumberExprAST : public ExprAST {
double Val;
public:
    // Or use an Initializer List -> NumberExprAST(double Val) : Val(Val) {}
    NumberExprAST(double Val) {
        this->Val = Val;
    }
};
