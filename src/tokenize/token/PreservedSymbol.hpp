#ifndef NTSL_CL_PRESERVEDSYMBOL_HPP
#define NTSL_CL_PRESERVEDSYMBOL_HPP
#include <string>
#include <tokenize/token/Token.hpp>

namespace NTSL_cl::Token {

    class PreservedSymbol : public Token{
    public:
        enum class Symbol_type {
            plus,
            comma,
            equal,
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
} // NTSL_cl::Token

#endif //NTSL_CL_PRESERVEDSYMBOL_HPP
