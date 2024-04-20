#ifndef NAIL_CL_MATHINSTRUCTION_HPP
#define NAIL_CL_MATHINSTRUCTION_HPP
#include "backend/assembly/instruction/Instruction.hpp"
namespace NAIL_cl {
    namespace asm_obj {

        class math_instruction : public instruction {
        public:
            math_instruction(std::shared_ptr<Operand> target, std::shared_ptr<Operand> add);

            bool has_effect(std::shared_ptr<Operand>) override;

            virtual std::string getString() = 0;

        protected:
            std::shared_ptr<Operand> target;
            std::shared_ptr<Operand> action;
        };

    } // asm_obj
} // NAIL_cl

#endif //NAIL_CL_MATHINSTRUCTION_HPP
