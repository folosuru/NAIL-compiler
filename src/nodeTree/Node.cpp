#include "Node.hpp"
#include <Symbol/scope/Scope.hpp>
#include <utility>
namespace NAIL_cl {
    Node_parent::Node_parent(std::shared_ptr<Scope> scope) : scope(std::move(scope)) {

    }
} // NAIL_cl