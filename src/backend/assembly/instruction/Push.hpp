#ifndef NAIL_CL_PUSH_HPP
#define NAIL_CL_PUSH_HPP
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl::asm_obj {

    class push : public instruction{
    public:
        explicit push(const std::shared_ptr<Operand>& target);

        bool has_effect(std::shared_ptr<Operand>) override;

        std::string getString() override;

    private:
        std::shared_ptr<Operand> target;
    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_PUSH_HPP
