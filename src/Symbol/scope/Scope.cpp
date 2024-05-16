#include "Scope.hpp"
#include <nodeTree/symbol/IdentifyNode.hpp>
namespace NAIL_cl {

    std::weak_ptr<Scope> Scope::getParent() const noexcept {
        return parent;
    }

    void* Scope::resolve_object(const std::string& name) {

    }

}

