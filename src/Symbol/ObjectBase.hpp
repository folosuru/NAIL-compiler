#ifndef NAIL_CL_OBJECTBASE_HPP
#define NAIL_CL_OBJECTBASE_HPP
#include <string_view>
#include <string>
#include <tokenize/token/Token.hpp>
namespace NAIL_cl {

    class ObjectBase {
    public:
        [[nodiscard]]
        const std::string& getName() const;

        explicit ObjectBase(std::string);

        explicit ObjectBase(const Token::Token_ptr& );
    private:
        std::string name;
    };


} // NAIL_cl

#endif //NAIL_CL_OBJECTBASE_HPP
