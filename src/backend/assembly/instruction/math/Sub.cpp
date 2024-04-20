#include "Sub.hpp"

namespace NAIL_cl::asm_obj {
    std::string Sub::getString() {
        return std::string("sub ") + target->getString() + ", " + action->getString();
    }
}
