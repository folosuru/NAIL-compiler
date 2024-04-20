#ifndef NAIL_CL_CQO_HPP
#define NAIL_CL_CQO_HPP
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl::asm_obj {
    class cqo : public instruction {
    public:
        explicit cqo() : instruction() {}

        bool has_effect(std::shared_ptr<Operand>) override;

        std::string getString() override;
    };
}

#endif //NAIL_CL_CQO_HPP
