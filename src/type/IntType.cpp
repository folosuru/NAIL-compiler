#include "IntType.hpp"

#include <utility>

namespace NAIL_cl {
    IntType::IntType(std::string name, int size)
    : VarType(std::move(name), Type_type::number) , size(size) {

    }
} // NAIL_cl