#ifndef NAIL_CL_MLU_HPP
#define NAIL_CL_MLU_HPP

#include <utility>

#include "backend/assembly/instruction/math/MathInstruction.hpp"

namespace NAIL_cl::asm_obj {

    class Mlu : public instruction {
    public:
        explicit Mlu(std::shared_ptr<Operand> op) : mlu_by(std::move(op)) {}

        std::string getString() override;

        bool has_effect(std::shared_ptr<Operand>) override;

    private:
        std::shared_ptr<Operand> mlu_by;
    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_MLU_HPP
