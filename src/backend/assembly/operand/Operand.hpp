#ifndef NAIL_CL_OPERAND_HPP
#define NAIL_CL_OPERAND_HPP
#include <string>

namespace NAIL_cl::asm_obj {

    class Operand {
    public:
        enum class type {
            number,
            register_,
            memory_addr
        };

        [[nodiscard]]
        virtual type getType() const = 0;

        virtual std::string getString() = 0;

    };


} // NAIL_cl::asm_obj

#endif //NAIL_CL_OPERAND_HPP
