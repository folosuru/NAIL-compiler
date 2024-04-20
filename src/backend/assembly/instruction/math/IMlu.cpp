#include "IMlu.hpp"

namespace NAIL_cl {
    namespace asm_obj {
        std::string iMlu::getString() {
            return std::string("imul ") + target->getString() + ", " + action->getString();
        }
    } // asm_obj
} // NAIL_cl