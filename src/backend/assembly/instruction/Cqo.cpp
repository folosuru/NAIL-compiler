#include "Cqo.hpp"
#include <backend/assembly/operand/Register.hpp>

namespace NAIL_cl::asm_obj {
    std::string cqo::getString() {
        return "cqo";
    }

    bool cqo::has_effect(std::shared_ptr<Operand> op) {
        if (register_operand::is_same(op, register_operand::word_name::rdx)) {
            return true;
        }
        return false;
    }
}