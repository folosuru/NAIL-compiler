#ifndef NAIL_CL_REGISTER_HPP
#define NAIL_CL_REGISTER_HPP
#include <backend/assembly/DataDef.hpp>
#include <backend/assembly/operand/Operand.hpp>
#include <unordered_map>
#include <array>
#include <memory>
namespace NAIL_cl::asm_obj {

    class register_operand : public Operand {
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
            r15,

            xmm0,
            xmm1,
            xmm2,
            xmm3,
            xmm4,
            xmm5,
            xmm6,
            xmm7,
            xmm8,
            xmm9,
            xmm10,
            xmm11,
            xmm12,
            xmm13,
            xmm14,
            xmm15,
        };

        static std::unordered_map<register_operand::word_name, std::array<std::string, 4>> register_word_str;

        [[nodiscard]]
        type getType() const override {
            return Operand::type::register_;
        }

        [[nodiscard]]
        word_name getRegisterName() const noexcept {
            return word;
        }

        std::string getString() override {
            return register_word_str[word][static_cast<std::size_t>(size)];
        }

        explicit register_operand(word_name word, data_size size) : Operand(), word(word), size(size) {}

        static bool is_same(const std::shared_ptr<Operand>& op1, word_name target_word) {
            if (op1->getType() == Operand::type::register_) {
                return (std::reinterpret_pointer_cast<register_operand>(op1)->getRegisterName() == target_word);
            }
            return false;
        }

        static bool is_same(const std::shared_ptr<Operand>& op1, const std::shared_ptr<Operand>& op2) {
            if (op1->getType() == Operand::type::register_ && op2->getType() == Operand::type::register_) {
                return (std::reinterpret_pointer_cast<register_operand>(op1)->getRegisterName() ==
                        std::reinterpret_pointer_cast<register_operand>(op2)->getRegisterName());
            }
            return false;
        }

    private:
        word_name word;
        data_size size;
    };
} // NAIL_cl::asm_obj

#endif //NAIL_CL_REGISTER_HPP
