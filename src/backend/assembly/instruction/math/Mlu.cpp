#include "Mlu.hpp"

#include "backend/assembly/operand/Register.hpp"

namespace NAIL_cl::asm_obj {
    bool Mlu::has_effect(std::shared_ptr<Operand> op) {
        if (register_operand::is_same(op, register_operand::word_name::rax) ||
            register_operand::is_same(op, register_operand::word_name::rdx) ) {
            return true;
        }
        return false;

    }
    std::string Mlu::getString() {
        return std::string("mul ") + mlu_by->getString();
    }
} // NAIL_cl::asm_obj
