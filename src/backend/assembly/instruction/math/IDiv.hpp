#ifndef NAIL_CL_IDIV_HPP
#define NAIL_CL_IDIV_HPP

#include "backend/assembly/instruction/math/MathInstruction.hpp"

namespace NAIL_cl {
    namespace asm_obj {

        class iDiv : public instruction {
        public:
            explicit iDiv(std::shared_ptr<Operand> op) : div_by(op) {}

            std::string getString() override;

            bool has_effect(std::shared_ptr<Operand>) override;

        private:
            std::shared_ptr<Operand> div_by;
        };

    } // asm_obj
} // NAIL_cl

#endif //NAIL_CL_IDIV_HPP
