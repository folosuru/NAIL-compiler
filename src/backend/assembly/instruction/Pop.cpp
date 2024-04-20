#include "Pop.hpp"
#include <backend/assembly/operand/Register.hpp>
#include <utility>

namespace NAIL_cl::asm_obj {

    bool pop::has_effect(std::shared_ptr<Operand> op) {
        if (register_operand::is_same(op, target) ||
            register_operand::is_same(op, std::make_shared<register_operand>(register_operand::word_name::rsp, data_size::qword))) {
            return true;
        }
        return false;
    }

    std::string pop::getString() {
        return std::string("pop ") + target->getString();
    }

    pop::pop(std::shared_ptr<Operand> op) : target(std::move(op)) {}
} // NAIL_cl::asm_obj