#include "IntType.hpp"

#include <utility>

namespace NAIL_cl {
IntType::IntType(std::string name, int size, bool is_unsigned)
    : VarTypeBase(std::move(name), Type_type::number), size(size), is_unsigned(is_unsigned) {

}

const std::shared_ptr<IntType> IntType::int8{new IntType("int8", 1, false)};
const std::shared_ptr<IntType> IntType::int16{new IntType("int16", 2, false)};
const std::shared_ptr<IntType> IntType::int32{new IntType("int32", 4, false)};
const std::shared_ptr<IntType> IntType::int64{new IntType("int64", 8, false)};
const std::shared_ptr<IntType> IntType::uint8{new IntType("unsigned_int8", 1, true)};
const std::shared_ptr<IntType> IntType::uint16{new IntType("unsigned_int16", 2, true)};
const std::shared_ptr<IntType> IntType::uint32{new IntType("unsigned_int32", 4, true)};
const std::shared_ptr<IntType> IntType::uint64{new IntType("unsigned_int64", 8, true)};
} // NAIL_cl