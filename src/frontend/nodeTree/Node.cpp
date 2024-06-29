#include "Node.hpp"
#include "frontend/Symbol/scope/Scope.hpp"
#include <utility>

namespace NAIL_cl {
Node_parent::Node_parent(std::shared_ptr<Scope> scope,
                         Token::Token_ptr token)
    : scope(std::move(scope)), position(token) {

}
} // NAIL_cl