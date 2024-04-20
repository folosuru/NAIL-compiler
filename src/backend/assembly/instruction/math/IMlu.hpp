#ifndef NAIL_CL_IMLU_HPP
#define NAIL_CL_IMLU_HPP
#include "MathInstruction.hpp"
namespace NAIL_cl {
    namespace asm_obj {

        class iMlu : public math_instruction {
            using math_instruction::math_instruction;
            std::string getString() override;
        };

    } // asm_obj
} // NAIL_cl

#endif //NAIL_CL_IMLU_HPP
