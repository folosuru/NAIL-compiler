#include "MathInstruction.hpp"

#include "backend/assembly/operand/Register.hpp"
namespace NAIL_cl {
    namespace asm_obj {
        math_instruction::math_instruction(std::shared_ptr<Operand> target, std::shared_ptr<Operand> add)
                : target(std::move(target)), action(std::move(add)) {

        }

        bool math_instruction::has_effect(std::shared_ptr<Operand> op) {
            return register_operand::is_same(target, op);
        }

    } // asm_obj
} // NAIL_cl