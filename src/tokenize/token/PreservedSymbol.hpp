#ifndef NAIL_CL_PRESERVEDSYMBOL_HPP
#define NAIL_CL_PRESERVEDSYMBOL_HPP
#include <string>
#include <tokenize/token/Token.hpp>

namespace NAIL_cl::Token {

    class PreservedSymbol : public Token{
    public:
        enum class Symbol_type {
            plus,
            minus,
            comma,
            mlu,
            div,
            semi_coron,
            coron,
            period,

            assign,

            equal,
            small_bracket_open,
            small_breacket_close
        };

        explicit PreservedSymbol(std::string_view name, std::size_t line, std::int64_t pos, Symbol_type type);

        ~PreservedSymbol() override = default;

        [[nodiscard]]
        TokenType getType() const override;

        [[nodiscard]]
        Symbol_type getSymbolType() const noexcept {
            return type;
        }

        static Token_ptr consume(const std::string& str, const std::size_t &line, std::int64_t &pos);

    private:
        Symbol_type type;

    };
} // NAIL_cl::Token

#endif //NAIL_CL_PRESERVEDSYMBOL_HPP
