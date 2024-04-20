#include "Push.hpp"
#include <stdexcept>
#include <backend/assembly/operand/Register.hpp>
namespace NAIL_cl {
    namespace asm_obj {
        push::push(const std::shared_ptr<Operand>& target) : target(target) {
            if (target->getType() == Operand::type::memory_addr) {
                throw std::runtime_error("push operand cannot be memory statement");
            }
        }

        bool push::has_effect(std::shared_ptr<Operand> op) {
            if (op->getType() == Operand::type::register_) {
                if (std::reinterpret_pointer_cast<register_operand>(op)->getRegisterName() == register_operand::word_name::rsp) {
                    return true;
                }
            }
            return false;
        }

        std::string push::getString() {
            return std::string("push ") + target->getString();
        }
    } // asm_obj
} // NAIL_cl