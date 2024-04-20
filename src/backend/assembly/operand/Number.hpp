#ifndef NAIL_CL_NUMBER_HPP
#define NAIL_CL_NUMBER_HPP
#include <backend/assembly/DataDef.hpp>
#include <backend/assembly/operand/Operand.hpp>
#include <cstdint>
#include <string>
namespace NAIL_cl::asm_obj {

    class Number : public Operand {
    public:
        explicit Number(std::uint64_t value) : Operand(), value(value) {}

        [[nodiscard]]
        type getType() const override {
            return type::number;
        }

        std::string getString() override;

        const std::uint64_t value;
    };

} // NAIL_cl::asm_obj

#endif //NAIL_CL_NUMBER_HPP
