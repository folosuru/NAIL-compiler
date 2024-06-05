#include "ObjectBase.hpp"
#include <utility>

namespace NAIL_cl {
const std::string& ObjectBase::getName() const {
    return name;
}

ObjectBase::ObjectBase(std::string name) : name(std::move(name)) {

}

    ObjectBase::ObjectBase(const Token::Token_ptr& token) : ObjectBase(std::string(token->getString())) {

    }
}  // NAIL_cl