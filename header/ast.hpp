#pragma once

#include <string>
#include <vector>

class ExprAST {
public:
    virtual ~ExprAST();
};

class NumberExprAST : public ExprAST {
public:
    NumberExprAST(double Val);
};

class PrototypeAST {
public:
    PrototypeAST (
        const std::string &Name,
        std::vector<std::string> Args
    );

    const std::string &getName() const;
};