#ifndef NAIL_CL_OBJECTBASE_HPP
#define NAIL_CL_OBJECTBASE_HPP
#include <string_view>
#include <string>
#include <frontend/tokenize/token/Token.hpp>
#include <frontend/type/VarTypeBase.hpp>

namespace NAIL_cl::Object {
class ObjectBase {
public:
    [[nodiscard]]
    const std::string& getName() const;

    explicit ObjectBase(std::string);

    explicit ObjectBase(const Token::Token_ptr&);

    [[nodiscard]]
    virtual VarType getVarType() const = 0;

private:
    std::string name;
};
}


// NAIL_cl

#endif //NAIL_CL_OBJECTBASE_HPP
