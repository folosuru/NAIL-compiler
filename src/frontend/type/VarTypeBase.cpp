#include "VarTypeBase.hpp"
#include "IntType.hpp"

namespace NAIL_cl {
namespace {
std::shared_ptr<IntType> getBigger(std::shared_ptr<IntType> p1, std::shared_ptr<IntType> p2) {
    if (p1->size >= p2->size) {
        return p1;
    } else {
        return p2;
    }
}
}

std::variant<std::shared_ptr<VarTypeBase>, VarTypeBase::Type_conflict_stat>
VarTypeBase::getConflictType(const VarType& p1, const VarType& p2) {
    if (p1->getType() == Type_type::number && p2->getType() == Type_type::number) {
        auto p1_num = std::reinterpret_pointer_cast<IntType>(p1);
        auto p2_num = std::reinterpret_pointer_cast<IntType>(p2);
        if (p1_num->is_unsigned == p2_num->is_unsigned) {
            return getBigger(p1_num, p2_num);
        }
        // TODO: unsigned and signed conflict
        return Type_conflict_stat::unsigned_bigger;
    } else {
        return Type_conflict_stat::is_struct;
    }
    return Type_conflict_stat::other;
}
} // NAIL_cl