#ifndef NAIL_CL_GLOBALVARIABLE_HPP
#define NAIL_CL_GLOBALVARIABLE_HPP
#include "frontend/Symbol/ObjectBase.hpp"

namespace NAIL_cl::Object {

class GlobalVariable : public ObjectBase {
public:
    GlobalVariable(const Token::Token_ptr&, VarType type);

    [[nodiscard]]
    VarType getVarType() const override {
        return type;
    }

private:
    VarType type;
};

} // NAIL_cl::Object

#endif //NAIL_CL_GLOBALVARIABLE_HPP
