#ifndef NAIL_CL_IMLU_HPP
#define NAIL_CL_IMLU_HPP
#include "MathInstruction.hpp"

namespace NAIL_cl::asm_obj {

    class iMlu : public math_instruction {
        using math_instruction::math_instruction;
        std::string getString() override;
    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_IMLU_HPP
