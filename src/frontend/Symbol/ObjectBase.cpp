#include "ObjectBase.hpp"
#include <utility>

namespace NAIL_cl {
const std::string& Object::ObjectBase::getName() const {
    return name;
}

Object::ObjectBase::ObjectBase(std::string name) : name(std::move(name)) {

}

Object::ObjectBase::ObjectBase(const Token::Token_ptr& token)
    : NAIL_cl::Object::ObjectBase(std::string(token->getString())) {

}
}  // NAIL_cl