#include <string>
#include <memory>
#include <vector>

class ExprAST {
public:
    // Set as virtual to properly deconstruct all inherited classes.
    // Explicitly defined as default to ensure proper deconstruction.
    virtual ~ExprAST() = default;
};

// Numberical literals
class NumberExprAST : public ExprAST {
double Val;

public:
    // Or use an Initializer List -> NumberExprAST(double Val) : Val(Val) {}
    NumberExprAST(double Val) {
        this->Val = Val;
    }
};

// Reference to variable
class VariableExprAST : public ExprAST {
std::string Name;

public:
    VariableExprAST(const std::string &Name) {
        this->Name = Name;
    }
};

// For opcode (eg. +)
class BinaryExprAST : public ExprAST {
char Op;
std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST (
        char Op, 
        std::unique_ptr<ExprAST> LHS, 
        std::unique_ptr<ExprAST> RHS
    ) {
        this->Op = Op;
        this->LHS = std::move(LHS);
        this->RHS = std::move(RHS);
    }
};

// For function calls and their arguments
class CallExprAST : public ExprAST {
std::string Callee;
std::vector<std::unique_ptr<ExprAST>> Args;

public:
    CallExprAST (
        const std::string &Callee, 
        std::vector<std::unique_ptr<ExprAST>> Args
    ) {
        this->Callee = Callee;
        this->Args = std::move(Args);
    }
};

// Function Prototype (Interface to a function)
class PrototypeAST {
std::string Name;
std::vector<std::string> Args;

public:
    PrototypeAST (
        const std::string &Name,
        std::vector<std::string> Args
    ) {
        this->Name = Name;
        this->Args = Args;
    }

    const std::string &getName() const {
        return this->Name;
    }
};

// Function definition
class FunctionAST {
std::unique_ptr<PrototypeAST> Proto;
std::unique_ptr<ExprAST> Body;

public:
    FunctionAST (
        std::unique_ptr<PrototypeAST> Proto, 
        std::unique_ptr<ExprAST> Body
    ) {
        this->Proto = std::move(Proto);
        this->Body = std::move(Body);
    }
};
