#ifndef NAIL_CL_NUMBERTOKEN_HPP
#define NAIL_CL_NUMBERTOKEN_HPP
#include "Token.hpp"

namespace NAIL_cl::Token {

class NumberToken : public Token {
public:
    constexpr static TokenType static_type = TokenType::number;

    NumberToken(std::string_view name,
                std::size_t line,
                std::int64_t pos,
                const TokenList& list,
                std::size_t number);

    const std::size_t value;

    ~NumberToken() override = default;

    [[nodiscard]]
    TokenType getType() const override;

    static Token_ptr consume(const std::string& str, const std::size_t& line, std::int64_t& pos, const TokenList& list);

private:
};

} // NAIL_cl::Token

#endif //NAIL_CL_NUMBERTOKEN_HPP
