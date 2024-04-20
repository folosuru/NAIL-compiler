#include "Number.hpp"

namespace NAIL_cl::asm_obj {
    std::string Number::getString() {
        return std::to_string(value);
    }
} // NAIL_cl::asm_obj
