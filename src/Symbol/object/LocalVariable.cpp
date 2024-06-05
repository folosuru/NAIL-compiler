#include "LocalVariable.hpp"

namespace NAIL_cl {
    LocalVariable::LocalVariable(const Token::Token_ptr& token, VarType type) :
    ObjectBase(token), type(type) {

    }
} // NAIL_cl