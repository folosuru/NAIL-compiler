#ifndef NAIL_CL_VARTYPE_HPP
#define NAIL_CL_VARTYPE_HPP
#include <string>
#include <utility>
namespace NAIL_cl {

    class VarType {
    public:
        enum class Type_type {
            number,
            struct_,
            array,
            unknown
        };

        virtual ~VarType() = default;
        explicit VarType(std::string s, Type_type t) : name(std::move(s)), type(t) {}


        [[nodiscard]]
        const std::string& getName() const noexcept {
            return name;
        }

        [[nodiscard]]
        Type_type getType() const noexcept {
            return type;
        }
    protected:
        Type_type type;
    private:
        std::string name;
    };

} // NAIL_cl

#endif //NAIL_CL_VARTYPE_HPP
