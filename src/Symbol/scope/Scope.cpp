#include "Scope.hpp"
#include <Symbol/ObjectBase.hpp>
#include <nodeTree/symbol/IdentifyNode.hpp>
namespace NAIL_cl {

    std::weak_ptr<Scope> Scope::getParent() const noexcept {
        return parent;
    }

    std::shared_ptr<Object::ObjectBase> Scope::resolve_object(const std::string& key) {
        if (auto value = symbol.find(key); symbol.end() != value) {
            return value->second;
        }
        return nullptr;
    }

    bool Scope::exist_object(const std::string & key) {
        return symbol.contains(key);
    }

}

