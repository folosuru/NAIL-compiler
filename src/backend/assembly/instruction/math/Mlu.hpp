#ifndef NAIL_CL_MLU_HPP
#define NAIL_CL_MLU_HPP

#include "backend/assembly/instruction/math/MathInstruction.hpp"
namespace NAIL_cl {
    namespace asm_obj {

        class Mlu : public instruction {
        public:
            Mlu(std::shared_ptr<Operand> op) : mlu_by(op) {}

            std::string getString() override;

            bool has_effect(std::shared_ptr<Operand>) override;

        private:
            std::shared_ptr<Operand> mlu_by;
        };

    } // asm_obj
} // NAIL_cl

#endif //NAIL_CL_MLU_HPP
