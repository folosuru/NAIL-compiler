#include "Add.hpp"

namespace NAIL_cl::asm_obj {
    std::string add::getString() {
        return std::string("add ") + target->getString() + ", " + action->getString();
    }
} // asm_obj
// NAIL_cl