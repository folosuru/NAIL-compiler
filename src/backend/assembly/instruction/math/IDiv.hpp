#ifndef NAIL_CL_IDIV_HPP
#define NAIL_CL_IDIV_HPP

#include <utility>

#include "backend/assembly/instruction/math/MathInstruction.hpp"


namespace NAIL_cl::asm_obj {

    class iDiv : public instruction {
    public:
        explicit iDiv(std::shared_ptr<Operand> op) : div_by(std::move(op)) {}

        std::string getString() override;

        bool has_effect(std::shared_ptr<Operand>) override;

    private:
        std::shared_ptr<Operand> div_by;
    };

}  // NAIL_cl::asm_obj

#endif //NAIL_CL_IDIV_HPP
