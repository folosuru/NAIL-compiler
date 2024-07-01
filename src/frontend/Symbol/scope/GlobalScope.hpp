#ifndef NAIL_CL_GLOBALSCOPE_HPP
#define NAIL_CL_GLOBALSCOPE_HPP
#include "Scope.hpp"

namespace NAIL_cl {

class GlobalScope : public Scope {
    using Scope::Scope;

    std::shared_ptr<Object::ObjectBase> createVariable(Token::Token_ptr word_ptr) override;

};

} // NAIL_cl

#endif //NAIL_CL_GLOBALSCOPE_HPP