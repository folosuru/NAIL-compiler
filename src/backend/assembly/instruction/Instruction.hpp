#ifndef NAIL_CL_INSTRUCTION_HPP
#define NAIL_CL_INSTRUCTION_HPP

#include <backend/assembly/operand/Operand.hpp>
#include <memory>
#include <string>

namespace NAIL_cl::asm_obj {

    class instruction {
    public:
        virtual bool has_effect(std::shared_ptr<Operand>) = 0;

        virtual std::string getString() = 0;

    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_INSTRUCTION_HPP
