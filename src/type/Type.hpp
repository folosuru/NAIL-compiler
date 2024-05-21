#ifndef NAIL_CL_TYPE_HPP
#define NAIL_CL_TYPE_HPP
#include <string>
namespace NAIL_cl {

    class Type {
    public:
        enum class Type_type {
            number,
            struct_,
            array,
            unknown
        };

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

#endif //NAIL_CL_TYPE_HPP
