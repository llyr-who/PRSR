#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>


int main()
{
    Scanner scn;
    scn.setInput("x*x*x*x + y*y*y*y"); // wrong gradients
    EvalState state;
    state.setValue("x", 1);
    state.setValue("y", 2);
    ExpressionGraph g(ParseExpression(scn), state);
    std::cout << scn.getBuffer() << std::endl;
    state.output();
    return 0;
}
