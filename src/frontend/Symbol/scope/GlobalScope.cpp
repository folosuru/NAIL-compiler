#include "GlobalScope.hpp"
#include "frontend/Symbol/object/GlobalVariable.hpp"

namespace NAIL_cl {
std::shared_ptr<Object::ObjectBase> GlobalScope::createVariable(Token::Token_ptr word_ptr) {
    auto obj = std::make_shared<Object::GlobalVariable>(word_ptr, nullptr);
    symbol[std::string(word_ptr->getString())] = obj;
    return obj;
}
} // NAIL_cl