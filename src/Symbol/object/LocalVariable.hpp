#ifndef NAIL_CL_LOCALVARIABLE_HPP
#define NAIL_CL_LOCALVARIABLE_HPP
#include <Symbol/ObjectBase.hpp>
#include <type/VarTypeBase.hpp>
#include <cstdint>

namespace NAIL_cl::Object {
    class LocalVariable : public ObjectBase {
    public:
        LocalVariable(const Token::Token_ptr&, VarType type);

        [[nodiscard]]
        VarType getVarType() const override {
            return type;
        }

    private:
        int32_t offset{};
        VarType type;
    };
}  // NAIL_cl


#endif //NAIL_CL_LOCALVARIABLE_HPP
