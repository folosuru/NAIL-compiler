#ifndef NAIL_CL_LOCALSCOPE_HPP
#define NAIL_CL_LOCALSCOPE_HPP
#include "Scope.hpp"

namespace NAIL_cl {

class LocalScope : public Scope {
public:
    explicit LocalScope(std::weak_ptr<Scope> parent = {});

    std::shared_ptr<Object::ObjectBase> createVariable(Token::Token_ptr word_ptr) override;
};

} // NAIL_cl

#endif //NAIL_CL_LOCALSCOPE_HPP
