#include "ObjectBase.hpp"
#include <utility>

namespace NAIL_cl {
const std::string& ObjectBase::getName() const {
    return name;
}

ObjectBase::ObjectBase(std::string name) : name(std::move(name)) {

}
}  // NAIL_cl