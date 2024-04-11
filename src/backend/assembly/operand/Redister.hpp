#ifndef NAIL_CL_REDISTER_HPP
#define NAIL_CL_REDISTER_HPP

#include <backend/assembly/operand/Operand.hpp>
namespace NAIL_cl::asm_obj {

    class redister : public Operand {
    public:
        enum class word_name {
            rax,
            rbx,
            rcx,
            rdx,
            rsi,
            rdi,
            rbp,
            rsp,
            r8,
            r9,
            r10,
            r11,
            r12,
            r13,
            r14,
            r15
        };

        type getType() const override {
            return Operand::type::redister_;
        }

    private:
        word_name word;
    };
} // NAIL_cl::asm_obj

#endif //NAIL_CL_REDISTER_HPP
