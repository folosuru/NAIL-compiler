#include "IMlu.hpp"


namespace NAIL_cl::asm_obj {
    std::string iMlu::getString() {
        return std::string("imul ") + target->getString() + ", " + action->getString();
    }
} // NAIL_cl::asm_obj