#ifndef NAIL_CL_SUB_HPP
#define NAIL_CL_SUB_HPP
#include "backend/assembly/instruction/math/MathInstruction.hpp"
#include "Add.hpp"
namespace NAIL_cl::asm_obj {

    class Sub : public math_instruction {
    public:
        using math_instruction::math_instruction;
        std::string getString() override;
    };
}

#endif //NAIL_CL_SUB_HPP
