#ifndef NAIL_CL_LOCALVARIABLE_HPP
#define NAIL_CL_LOCALVARIABLE_HPP
#include <Symbol/ObjectBase.hpp>
#include <type/VarTypeBase.hpp>
#include <cstdint>
namespace NAIL_cl {

    class LocalVariable : public ObjectBase {
    public:
        LocalVariable(const Token::Token_ptr&, VarType type);

        [[nodiscard]] VarType getType() const {
            return type;
        }

    private:
        std::int32_t offset{};
        VarType type;
    };

} // NAIL_cl

#endif //NAIL_CL_LOCALVARIABLE_HPP
