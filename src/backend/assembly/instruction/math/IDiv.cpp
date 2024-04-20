#include "IDiv.hpp"

#include "backend/assembly/operand/Register.hpp"
namespace NAIL_cl {
    namespace asm_obj {

        std::string iDiv::getString()  {
            return std::string("idiv ") + div_by->getString();
        }

        bool iDiv::has_effect(std::shared_ptr<Operand> op) {
            if (register_operand::is_same(op, register_operand::word_name::rax) ||
                register_operand::is_same(op, register_operand::word_name::rdx) ) {
                return true;
            }
            return false;
        }

    } // asm_obj
} // NAIL_cl