#ifndef NAIL_CL_POP_HPP
#define NAIL_CL_POP_HPP
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl::asm_obj {

    class pop : public instruction {
    public:
        explicit pop(std::shared_ptr<Operand> op);

        bool has_effect(std::shared_ptr<Operand>) override;

        std::string getString() override;

    private:
        std::shared_ptr<Operand> target;
    };
} // NAIL_cl::asm_obj

#endif //NAIL_CL_POP_HPP
