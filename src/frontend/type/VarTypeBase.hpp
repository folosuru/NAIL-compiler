#ifndef NAIL_CL_VARTYPEBASE_HPP
#define NAIL_CL_VARTYPEBASE_HPP
#include <string>
#include <utility>
#include <variant>
#include <memory>

namespace NAIL_cl {
class VarTypeBase;
using VarType = std::shared_ptr<VarTypeBase>;

class VarTypeBase {
public:
    enum class Type_type {
        void_,
        number,
        struct_,
        array,
        unknown
    };

    virtual ~VarTypeBase() = default;

    explicit VarTypeBase(std::string s, Type_type t) : name(std::move(s)), type(t) {}

    [[nodiscard]]
    const std::string& getName() const noexcept {
        return name;
    }

    [[nodiscard]]
    Type_type getType() const noexcept {
        return type;
    }

    enum class Type_conflict_stat {
        is_struct,
        unsigned_bigger,
        other
    };

    static std::variant<std::shared_ptr<VarTypeBase>, Type_conflict_stat> getConflictType(const VarType&,
                                                                                          const VarType&);

protected:
    Type_type type;

private:
    std::string name;
};

} // NAIL_cl

#endif //NAIL_CL_VARTYPEBASE_HPP
