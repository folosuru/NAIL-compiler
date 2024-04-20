#ifndef NAIL_CL_ADD_HPP
#define NAIL_CL_ADD_HPP
#include "backend/assembly/instruction/math/MathInstruction.hpp"

namespace NAIL_cl::asm_obj {

    class add : public math_instruction {
    public:
        using math_instruction::math_instruction;
        std::string getString() override;
    };

}// NAIL_cl::asm_obj

#endif //NAIL_CL_ADD_HPP
