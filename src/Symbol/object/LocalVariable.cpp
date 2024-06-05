#include "LocalVariable.hpp"

namespace NAIL_cl {
    NAIL_cl::Object::LocalVariable::LocalVariable(const Token::Token_ptr& token, VarType type) :
    ObjectBase(token), type(type) {

    }
} // NAIL_cl