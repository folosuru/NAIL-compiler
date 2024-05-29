#ifndef NAIL_CL_PRESERVEDSYMBOL_HPP
#define NAIL_CL_PRESERVEDSYMBOL_HPP
#include <string>
#include <tokenize/token/Token.hpp>

namespace NAIL_cl::Token {
    // include Operator and Keyword
    class PreservedSymbol : public Token{
    public:
        enum class Symbol_type {
            plus,                 // +
            minus,                // -
            mlu,                  // *
            div,                  // /
            comma,                // ,
            period,               // .
            semi_coron,           // ;
            coron,                // :
            equal,                // =
            small_bracket_open,   // (
            small_bracket_close,  // )
            right_arrow,          // ->

            kw_for,               // for
            kw_var                // var

        };

        explicit PreservedSymbol(std::string_view name, std::size_t line, std::int64_t pos, const TokenList& list, Symbol_type type);

        ~PreservedSymbol() override = default;

        [[nodiscard]]
        TokenType getType() const override;

        [[nodiscard]]
        Symbol_type getSymbolType() const noexcept {
            return type;
        }

        static Token_ptr consume(const std::string& str, const std::size_t &line, std::int64_t &pos, const TokenList&);

    private:
        Symbol_type type;

    };
} // NAIL_cl::Token

#endif //NAIL_CL_PRESERVEDSYMBOL_HPP
