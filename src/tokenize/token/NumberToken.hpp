#ifndef NTSL_CL_NUMBERTOKEN_HPP
#define NTSL_CL_NUMBERTOKEN_HPP
#include <tokenize/token/Token.hpp>

namespace NTSL_cl::Token {

    class NumberToken : public Token{
    public:
        explicit NumberToken(std::string_view name, std::size_t line, std::int64_t pos, std::size_t number);

        const std::size_t value;

        ~NumberToken() override = default;

        [[nodiscard]]
        TokenType getType() const override;

        static Token_ptr consume(const std::string& str, const std::size_t& line, std::int64_t &pos);
    private:
    };


} // NTSL_cl::Token

#endif //NTSL_CL_NUMBERTOKEN_HPP
