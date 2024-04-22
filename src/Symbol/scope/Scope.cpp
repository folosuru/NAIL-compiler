#include "Scope.hpp"
#include <nodeTree/symbol/IdentifyNode.hpp>
namespace NAIL_cl {

    std::weak_ptr<Scope> Scope::getParent() const noexcept {
        return parent;
    }

}

