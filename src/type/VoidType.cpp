#include "VoidType.hpp"

namespace NAIL_cl {
    VoidType::VoidType() : VarTypeBase("void", VarTypeBase::Type_type::void_) {}

    VarType VoidType::get() {
        if (instance == nullptr) {
            instance = VarType(new VoidType());
        }
        return instance;
    }
} // NAIL_cl