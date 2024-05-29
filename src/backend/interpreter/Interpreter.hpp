#ifndef NAIL_CL_INTERPRETER_HPP
#define NAIL_CL_INTERPRETER_HPP
#include <nodeTree/Node.hpp>

namespace NAIL_cl::interpreter {
    class Interpreter {
    public:
        explicit Interpreter(NodeType);

        void exec();

        NodeType node;
    };
} // NAIL_cl::interpreter

#endif //NAIL_CL_INTERPRETER_HPP
