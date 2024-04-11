#ifndef NAIL_CL_OPERAND_HPP
#define NAIL_CL_OPERAND_HPP
namespace NAIL_cl::asm_obj {

    class Operand {
    public:
        enum class type {
            number,
            redister_,
            memory_addr
        };

        virtual type getType() const = 0;
    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_OPERAND_HPP
